#include "gestionproduit.h"
#include "ui_gestionproduit.h"
#include "produit.h"
#include "dialog.h"
#include "chatbot.h"
GestionProduit::GestionProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GestionProduit)
{
    ui->setupUi(this);
    ui->pushButton_2->setText("(" + QString::number(this->nombreProduitExpirer) + ") Notifications");
    this->timerId = startTimer(1000);
    connect(ui->pushButton_10, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->pushButton_9, &QPushButton::clicked, this, [this]() {
        ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [this]() {

        ui->stackedWidget->setCurrentIndex(2);

    });

     ui->tableView->setModel(p.afficher());
     ui->tableView->hideColumn(6);
     ui->tableView->hideColumn(7);
     connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &GestionProduit::trierTableView);
     connect(ui->pdf, &QPushButton::clicked, this, &GestionProduit::exporterEnPDF);
     connect(ui->excel,&QPushButton::clicked, this, &GestionProduit::exporterEnExcel);
}
int GestionProduit::MAJProduitEpirer(){
    if(this->nombreProduitExpirer < this->p.getExpiredProducts().size()){
        return this->p.getExpiredProducts().size();
    }
    return this->nombreProduitExpirer;
}
void GestionProduit::timerEvent(QTimerEvent *event)
{
    int oldExpiredProductsNumber = this->nombreProduitExpirer;
    this->nombreProduitExpirer = MAJProduitEpirer();
    if(this->nombreProduitExpirer != oldExpiredProductsNumber){
        ui->pushButton_2->setText("(" + QString::number(this->nombreProduitExpirer) + ") Notifications");
    }
}
GestionProduit::~GestionProduit()
{
    delete ui;
}

void GestionProduit::on_Add_button_2_clicked()
{
    QString name = ui->nameline_2->text();
    float price  = ui->priceLIne_2->text().toFloat();
    int qte = ui->qteliine_2->text().toInt();
    QDate date = ui->dateEdit_2->date();
    QString form = ui->form->currentText();

    produit p(name, price, qte, date,form);
    bool test = p.ajouter();

    if (test) // If query executed successfully
    {
        ui->tableView->setModel(p.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else // If query execution failed
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void GestionProduit::on_delete_button_2_clicked() {
    int id = ui->deleteline->text().toInt();

    // Check for valid ID input
    if (id <= 0) {
        QMessageBox::critical(nullptr, QObject::tr("Invalid ID"),
                              QObject::tr("Please enter a valid product ID greater than 0."),
                              QMessageBox::Cancel);
        return;
    }

    // Call the supprimer method
    bool test = p.supprimer(id);

    if (test) {
        // Update the table view with the new model after deletion
        ui->tableView->setModel(p.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Suppression effectuée\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
}



void GestionProduit::on_lineEdit_13_textChanged(const QString &search)
{
    // Cast the model to QSqlTableModel
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());
    if (!model) {
        qWarning("Failed to cast model to QSqlTableModel.");
        return;
    }

    // If search field is empty, remove any filter to display all records
    if (search.isEmpty()) {
        model->setFilter(""); // Remove the filter to show all entries
    } else {
        // Apply a case-insensitive filter
        model->setFilter(QString("LOWER(NOM) LIKE '%%1%'").arg(search.toLower()));  // Convert search to lowercase
    }

    // Refresh the model to apply the filter
    model->select();
}

void GestionProduit::trierTableView(int index) {
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());

    if (model) {
        if (index == 0) {  // Si l'index est 0, réinitialiser le tri
            model->setSort(-1, Qt::AscendingOrder);
        } else {
            switch (index) {
                case 1:  // Trier par "Nom" en ordre croissant (insensible à la casse)
                    model->setSort(model->fieldIndex("Nom"), Qt::AscendingOrder);
                    break;
                case 2:  // Trier par "Quantite" en ordre décroissant
                    model->setSort(model->fieldIndex("qte"), Qt::DescendingOrder);
                    break;
                default:
                    return;
            }
        }
        model->select();  // Rafraîchir la vue avec les données triées
    }
}


void GestionProduit::exporterEnPDF() {
    QString filename = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "PDF Files (*.pdf)");

    if (filename.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Nom de fichier non spécifié.");
        return;
    }

    QPdfWriter writer(filename);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);

    QPainter painter(&writer);
    int margin = 30;
    painter.translate(margin, margin);

    QFont headerFont("Arial", 12, QFont::Bold);
    QFont dataFont("Arial", 10);
    painter.setFont(headerFont);

    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());

    if (model) {
        int yOffset = 50;
        int rowHeight = 200;
        int columnWidth = 500; // Augmenté pour un meilleur espacement des colonnes

        // Dessiner les en-têtes des colonnes
        for (int col = 0; col < model->columnCount(); ++col) {
            painter.drawText(col * columnWidth, yOffset, model->headerData(col, Qt::Horizontal).toString());
        }
        yOffset += rowHeight;

        // Dessiner les lignes de données
        painter.setFont(dataFont);
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QString cellText = model->data(model->index(row, col)).toString();
                painter.drawText(col * columnWidth, yOffset, cellText);
            }
            yOffset += rowHeight;
        }
    }

    painter.end();

    QMessageBox::information(this, "Succès", "Données exportées avec succès en PDF.");
}
void GestionProduit::exporterEnExcel() {
    // Sélectionner un emplacement pour sauvegarder le fichier Excel
    QString filename = QFileDialog::getSaveFileName(this, "Exporter en Excel", "", "Excel Files (*.xlsx)");

    if (filename.isEmpty()) {
        return; // Si aucun fichier n'est sélectionné, on quitte la fonction
    }

    // Obtenir le modèle de données du QTableView
    QSqlTableModel *model = qobject_cast<QSqlTableModel*>(ui->tableView->model());
    if (!model) {
        return; // Si le modèle n'est pas valide, on quitte la fonction
    }

    // Initialiser Excel via QAxObject
    QAxObject *excel = new QAxObject("Excel.Application", this);
    excel->setProperty("Visible", false); // Rendre Excel invisible pendant l'exportation

    // Créer un nouveau classeur
    QAxObject *workbooks = excel->querySubObject("Workbooks");
    QAxObject *workbook = workbooks->querySubObject("Add");
    QAxObject *sheet = workbook->querySubObject("Worksheets(int)", 1); // Sélectionner la première feuille

    // Exporter les en-têtes du modèle
    for (int col = 0; col < model->columnCount(); ++col) {
        QString headerText = model->headerData(col, Qt::Horizontal).toString();
        QString cell = QString("%1%2").arg(QChar('A' + col)).arg(1); // Ex: "A1", "B1", ...
        QAxObject *cellObject = sheet->querySubObject("Range(const QString&)", cell);
        cellObject->setProperty("Value", headerText);
        delete cellObject;
    }

    // Exporter les données du tableau
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QString cellText = model->data(model->index(row, col)).toString();
            QString cell = QString("%1%2").arg(QChar('A' + col)).arg(row + 2); // Ligne 2 pour les données
            QAxObject *cellObject = sheet->querySubObject("Range(const QString&)", cell);
            cellObject->setProperty("Value", cellText);
            delete cellObject;
        }
    }

    // Sauvegarder le fichier Excel
    workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(filename));

    // Fermer Excel
    workbook->dynamicCall("Close()");
    excel->dynamicCall("Quit()");

    // Libérer la mémoire
    delete sheet;
    delete workbook;
    delete workbooks;
    delete excel;
}

void GestionProduit::on_pushButton_11_clicked()
{
    Dialog *dialog = new Dialog(this);  // Create the dialog (replace "sat" with the actual dialog class name)
           dialog->exec();  // Show the dialog as a modal window
}


void GestionProduit::on_pushButton_12_clicked()
{
    chatbot *cb = new chatbot();
    cb->setAttribute(Qt::WA_DeleteOnClose); // Ensures memory is freed when closed
    //this->hide();
    cb->show(); // Shows the window without blocking the main thread
}


void GestionProduit::on_pushButton_2_clicked()
{
    // Get the expired products
    std::vector<produit> prodExpirer = this->p.getExpiredProducts();

    // Clear the previous buttons from the layout (assuming it's a QVBoxLayout or similar)
    QLayout *layout = ui->expiredProductsLayout; // Replace with your actual layout name
    if (layout)
    {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr)
        {
            delete item->widget(); // Delete the widget if it exists
            delete item;           // Delete the layout item
        }
    }

    // Dynamically create buttons for each expired product
    for (int i = 0; i < prodExpirer.size(); ++i)
    {
        produit currentProduct = prodExpirer.at(i);

        QPushButton *button = new QPushButton(
            "Produit: " + currentProduct.getNom() +
            "\nID: " + QString::number(currentProduct.getIdProduit()) +
            "\nExpiration: " + currentProduct.getDateExpiration().toString(), this);

        button->setObjectName("productButton" + QString::number(i)); // Optional: Set object name
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: rgba(240, 255, 240, 0.9);"
            "    color: #4CAF50;"
            "    border: 1px solid rgba(76, 175, 80, 0.5);"
            "    padding: 12px 24px;"
            "    margin: 5px;"
            "    border-radius: 12px;"
            "    font-size: 16px;"
            "    font-weight: bold;"
            "}"
            "QPushButton:hover {"
            "    background-color: rgba(230, 255, 230, 1);"
            "}"
            "QPushButton:pressed {"
            "    background-color: rgba(200, 255, 200, 1);"
            "    border: 1px solid #4CAF50;"
            "}"
        );

        // Add the button to the layout
        if (layout)
            layout->addWidget(button);

        // Connect a signal to handle button clicks
        connect(button, &QPushButton::clicked, [=]() {
            currentProduct.SetReadProduct(currentProduct.getIdProduit());
            // Create the message text
            QString message = "Produit: " + currentProduct.getNom() +
                              "\nID: " + QString::number(currentProduct.getIdProduit()) +
                              "\nExpiration: " + currentProduct.getDateExpiration().toString();

            // Show the QMessageBox
            QMessageBox::information(nullptr,
                                     QObject::tr("Product Information"),
                                     message,
                                     QMessageBox::Cancel);

            // Debug output
            qDebug() << "Product button clicked: ID=" << currentProduct.getIdProduit();
        });

    }

    // Update the notifications button text
    this->nombreProduitExpirer = 0;
    ui->pushButton_2->setText("(" + QString::number(this->nombreProduitExpirer) + ") Notifications");
}

