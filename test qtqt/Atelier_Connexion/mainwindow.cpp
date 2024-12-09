#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h" // Include the client header
#include "connection.h"
#include "CustomSqlQueryModel.h"
#include <QDebug>
#include "BackgroundColorDelegate.h"
#include "AnimatedPopup.h"
#include "ConfettiWidget.h"
#include <QPrinter>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include <QTextStream>
#include <QPdfWriter>
#include <QAxObject>
#include <QChart>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QChartView>
#include <QVBoxLayout>
#include <QBuffer>
#include <QImage>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>




using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QStackedWidget* stackedWidget = ui->stackedWidget;
    QWidget* page = stackedWidget->widget(2);
    QTableView* tableView = page->findChild<QTableView*>("tableView");

    if (tableView) {

        client client;
        Connection c;

        if (c.createconnect()) {
            QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                     QObject::tr("Connection successful.\nClick Cancel to exit."),
                                     QMessageBox::Cancel);

            tableView->setModel(client.Afficherclients());
            tableView->resizeColumnsToContents();
            tableView->horizontalHeader()->setStretchLastSection(true);




            QPalette palette;
            palette.setColor(QPalette::Background,QColor("#00FF9C"));


            tableView->setItemDelegateForColumn(10, new BackgroundColorDelegate(palette));


            QPalette palette2;
            palette2.setColor(QPalette::Background,QColor("#FF4545"));


            tableView->setItemDelegateForColumn(11, new BackgroundColorDelegate(palette2));






        } else {
            QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                  QObject::tr("Connection failed.\nClick Cancel to exit."),
                                  QMessageBox::Cancel);
        }
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Failed to find the table view for Client data."),
                              QMessageBox::Cancel);
    }

    connect(ui->ajouter_4, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
    connect(ui->ajouter_5, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
    connect(ui->ajouter_12, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
    connect(ui->ajouter_11, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
    connect(ui->ajouter_5, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
    connect(ui->gostat, &QPushButton::clicked, this, [this]() { navigateToPage(3); });
    connect(ui->ajouter_4, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
    connect(ui->gostat2, &QPushButton::clicked, this, [this]() { navigateToPage(3); });
    connect(ui->gostat, &QPushButton::clicked, this, &MainWindow::on_gostat_clicked);
    connect(ui->gostat2, &QPushButton::clicked, this, &MainWindow::on_gostat2_clicked);

    connect(ui->badd, &QPushButton::clicked, this, [this]() { navigateToPage(1); });
    connect(ui->blist, &QPushButton::clicked, this, [this]() { navigateToPage(2); });
    connect(ui->bstat, &QPushButton::clicked, this, [this]() { navigateToPage(3); });




    //pdf connecter
      connect(ui->pdf, &QPushButton::clicked, this, &MainWindow::exportToPDF);
     //excel connecter
      connect(ui->excel, &QPushButton::clicked, this, &MainWindow::exportToExcel);
    //recherche connecter
      connect(ui->search_bar, &QLineEdit::textChanged, this, &MainWindow::Rechercherclient);
    //tri connecter
      connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_sortComboBox_currentIndexChanged(int)));

      QDate selectedDate = ui->calendarWidget->selectedDate();
      updateCalendarAndEventDetails(selectedDate);


//arduino
 /*     int ret=A.connect_arduino();
          switch(ret)
          {case(0):QMessageBox::information(this,"connexion arduino avec succées",A.getarduino_port_name());
              connect(A.get_serial(), &QSerialPort::readyRead, this, &MainWindow::readFromArduino);

              break;
           case(1):QMessageBox::information(this,"il n'y a pas port connecté",A.getarduino_port_name());
              break;
           case(-1):QMessageBox::information(this,"connexion arduino avec echoué",A.getarduino_port_name());
          }
         QObject::connect(A.get_serial(), SIGNAL(readyRead()), this, SLOT(update()));

*/

      if (A.connect_arduino() == 0) {
          qDebug() << "Arduino connecté sur le port:" << A.getarduino_port_name();
      } else {
          qDebug() << "Échec de la connexion à l'Arduino.";
      }
      connect(A.get_serial(), &QSerialPort::readyRead, this, &MainWindow::readFromArduino);

}
void MainWindow::readFromArduino()
{
    QString      nom="";
    QByteArray data = A.read_from_arduino();
    QString uid = QString::fromUtf8(data).trimmed(); // Convertir les données en chaîne
    if (!uid.isEmpty())
    {
        //qDebug() << "UID reçu:" << uid;
        if (uid != "/")
        {
            A.code += uid;
        }
        else
        {
            A.code.remove("/");
            QSqlQuery query;
            query.prepare("SELECT COUNT(*) FROM CLIENT WHERE RFID = :code");
            query.bindValue(":code", A.code);
            if (query.exec() && query.next())
            {
                int count = query.value(0).toInt();
                if (count > 0)
                {
                    // UID exists in the database
                    QSqlQuery nomquery;
                    query.prepare("SELECT NOM_CL FROM CLIENT WHERE RFID = :code");
                    query.bindValue(":code", A.code);
                    if (query.exec() && query.next())
                    {
                        nom = query.value(0).toString();
                        // Convert QString to QByteArray
                        QByteArray dataToSend = nom.toUtf8(); // Convert the QString to QByteArray
                        qDebug()<<nom<<endl;
                            // Send each character to the Arduino
                        for (char c : dataToSend)
                        {
                            QByteArray byteArray;
                            byteArray.append(c); // Create a QByteArray for the character
                            A.write_to_arduino(byteArray); // Send the character to Arduino
                        }
                        QMessageBox::information(this, "Succès", "L'UID existe  !");
                        A.code = "";
                        nom="";
                    }
                    else
                    {
                    // UID does not exist
                        QMessageBox::warning(this, "Erreur", "L'UID n'existe pas !");
                        A.code = "";
                        nom="";
                    }

                }
            }
        }

    }

}


MainWindow::~MainWindow() {
    delete ui;
    A.close_arduino();

}




QString getRandomReward() {
    QFile file("C:/Users/msi/Desktop/Cpp project application/test qtqt/test qtqt/Atelier_Connexion/rewards.txt");
    QStringList rewards;

    // Debug: Check if the file exists
    if (!QFile::exists("C:/Users/msi/Desktop/Cpp project application/test qtqt/test qtqt/Atelier_Connexion/rewards.txt")) {
        qDebug() << "File does not exist!";
        return "No rewards available.";
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file!";
        return "No rewards available.";
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        rewards.append(line);
    }
    file.close();



    if (rewards.isEmpty()) {
        return "No rewards available.";
    }

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Get a random index
    int randomIndex = std::rand() % rewards.size();

    return rewards.at(randomIndex);
}


void MainWindow::on_browse_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Choose"), "", tr("Images (*.png *.jpg *.jpeg *.bmp *.gif)"));
    if (!filename.isEmpty()) {
        imagePath = filename; // Store the image path
        QImage image;
        bool valid = image.load(filename);

        if (valid) {
            image = image.scaledToWidth(ui->imageLabel->width(), Qt::SmoothTransformation);
            ui->imageLabel->setPixmap(QPixmap::fromImage(image));

            QBuffer buffer(&imagesByteArray);
            buffer.open(QIODevice::WriteOnly);
            image.save(&buffer, "PNG"); // Save the image to imagesByteArray
        } else {
            qDebug() << "Erreur de chargement de l'image";
        }
    }
}

void MainWindow::on_ajouter_clicked()
{
    QString nom = ui->nom->text();
    QString prenom = ui->prnom->text();
    QString gender = ui->comboBox_2->currentText();
    QString telStr = ui->nbrphone->text();
    int tel = telStr.toInt();
    QString adresse = ui->adresse->text();
    QString email = ui->mail->text();
    QString ageStr = ui->age->text();
    int age = ageStr.toInt();
    QDate dateReg = ui->date_reg->date();

    // Input validation
    QRegExp nameRx("^[a-zA-Z]+$"); // Only letters
    QRegExp telRx("^\\d{8}$"); // Exactly 8 digits
    QRegExp emailRx("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$"); // Email format

    if (!nameRx.exactMatch(nom) || !nameRx.exactMatch(prenom)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Le nom et le prénom doivent contenir uniquement des lettres."), QMessageBox::Cancel);
    } else if (!telRx.exactMatch(telStr)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Le numéro de téléphone doit être composé de 8 chiffres."), QMessageBox::Cancel);
    } else if (!emailRx.exactMatch(email)) {
        QMessageBox::critical(this, tr("Erreur"), tr("L'email doit être au format valide."), QMessageBox::Cancel);
    } else {
        // Create client object
        client client(0, nom, prenom, tel, adresse, gender, age, email, imagesByteArray, dateReg);

        // Attempt to add client
        if (client.Ajouterclient()) {
            // Use the custom model to update the table view if addition was successful
            CustomSqlQueryModel *model = new CustomSqlQueryModel(this);
            model->setQuery("SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE,+ 'Update', 'Delete' AS Action FROM client");
            ui->tableView->setModel(model);

            QMessageBox::information(this, tr("Succès"), tr("Ajout effectué."), QMessageBox::Cancel);

            // Check if the client is every 5th client
            QSqlQuery query("SELECT MAX(ID_CL) FROM client");
            if (query.next()) {
                int id_cl = query.value(0).toInt();
                if (id_cl % 2 == 0) {
                    QString reward = getRandomReward();
                    QString message = tr("Congrats! You're our client number %1. You won: %2").arg(id_cl).arg(reward);
                    AnimatedPopup *popup = new AnimatedPopup(message, this);
                    popup->showAnimated();

                    ConfettiWidget *confetti = new ConfettiWidget(this);
                    confetti->show();
                }
            }

            // Clear input fields after addition
            ui->nom->clear();
            ui->prnom->clear();
            ui->comboBox_2->setCurrentIndex(-1);
            ui->nbrphone->clear();
            ui->adresse->clear();
            ui->mail->clear();
            ui->age->clear();
            ui->date_reg->setDate(QDate::currentDate()); // Reset date field
            ui->imageLabel->clear(); // Clear the image label
            imagesByteArray.clear(); // Clear the image byte array
        } else {
            QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de l'ajout du client."), QMessageBox::Cancel);
        }
    }
    QDate selectedDate = ui->calendarWidget->selectedDate();
    updateCalendarAndEventDetails(selectedDate);
}



void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    if (!index.isValid()) {
        qDebug() << "Invalid index";
        return;
    }
    QString value = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();

    Connection c;
    c.closeconnection();
    QSqlQuery qry;

    qry.prepare("SELECT NOM_CL, PRENOM_CL, GENDER, TEL_CL, ADRESSE_CL, AGE, EMAIL, DATE_REG, IMAGE FROM client WHERE ID_CL = :ID_CL");
    qry.bindValue(":ID_CL", value);

    if (qry.exec()) {
        if (qry.next()) {
            ui->id->setText(value);
            if (index.column() == 10) {
                QMessageBox::StandardButton reply;
                reply = QMessageBox::question(this, "Update Client", "Are you sure you want to update this client?",
                                              QMessageBox::Yes | QMessageBox::No);
                if (reply == QMessageBox::Yes) {
                    ui->nom->setText(qry.value(0).toString());
                    ui->prnom->setText(qry.value(1).toString());
                    ui->comboBox_2->setCurrentText(qry.value(2).toString());
                    ui->nbrphone->setText(qry.value(3).toString());
                    ui->adresse->setText(qry.value(4).toString());
                    ui->age->setText(qry.value(5).toString());
                    ui->mail->setText(qry.value(6).toString());
                    ui->date_reg->setDate(qry.value(7).toDate());

                    // Load image from database and set to the label
                    QByteArray imageBytes = qry.value(8).toByteArray();
                    QPixmap pixmap;
                    pixmap.loadFromData(imageBytes);
                    ui->imageLabel->setPixmap(pixmap); // Assuming you have an image label to display the image

                    ui->id->setText(value);
                    ui->stackedWidget->setCurrentIndex(1);
                }
            }
        }
    }
    if (index.column() == 11) {
        QString clientId = ui->tableView->model()->data(ui->tableView->model()->index(index.row(), 0)).toString();

        // Confirm the deletion
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Delete Client", "Are you sure you want to delete this client?",
                                      QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            client clientToDelete; // Create an instance of client
            if (clientToDelete.Supprimerclient(clientId)) {
                QMessageBox::information(this, "Deleted", "Client successfully deleted.");
                ui->tableView->setModel(clientToDelete.Afficherclients()); // Refresh the table view
            } else {
                QMessageBox::critical(this, "Error", "Failed to delete client.");
            }
        }
    }
    // Close the database connection
    c.closeconnection();
    QDate selectedDate = ui->calendarWidget->selectedDate();
    updateCalendarAndEventDetails(selectedDate);
}

void MainWindow::on_modifier_clicked()
{
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedIndexes();

    if (selectedIndexes.size() == 0) {
        QMessageBox::warning(this, tr("Aucune sélection"), tr("Veuillez sélectionner une ligne à modifier."), QMessageBox::Ok);
        return;
    } else if (selectedIndexes.size() > 1) {
        QMessageBox::warning(this, tr("Sélection multiple"), tr("Veuillez sélectionner une seule ligne à modifier."), QMessageBox::Ok);
        return;
    }

    int id_cl = selectedIndexes.at(0).sibling(selectedIndexes.at(0).row(), 0).data().toInt();

    QString nom = ui->nom->text();
    QString prenom = ui->prnom->text();
    QString gender = ui->comboBox_2->currentText();
    int tel = ui->nbrphone->text().toInt();
    QString adresse = ui->adresse->text();
    int age = ui->age->text().toInt();
    QString email = ui->mail->text();
    QDate dateReg = ui->date_reg->date();
    QByteArray image = imagesByteArray; // Use the imagesByteArray for the image

    // Input validation
    QRegExp nameRx("^[a-zA-Z]+$"); // Only letters
    QRegExp telRx("^\\d{8}$"); // Exactly 8 digits
    QRegExp emailRx("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$"); // Email format

    if (!nameRx.exactMatch(nom) || !nameRx.exactMatch(prenom)) {
        QMessageBox::critical(this, tr("Erreur"), tr("Le nom et le prénom doivent contenir uniquement des lettres."), QMessageBox::Cancel);
        return;
    } else if (!telRx.exactMatch(ui->nbrphone->text())) {
        QMessageBox::critical(this, tr("Erreur"), tr("Le numéro de téléphone doit être composé de 8 chiffres."), QMessageBox::Cancel);
        return;
    } else if (!emailRx.exactMatch(email)) {
        QMessageBox::critical(this, tr("Erreur"), tr("L'email doit être au format valide."), QMessageBox::Cancel);
        return;
    }

    // Check if an image is already loaded; if not, keep the existing image
    if (image.isEmpty() && !ui->imageLabel->pixmap()->isNull()) {
        QSqlQuery qry;
        qry.prepare("SELECT IMAGE FROM client WHERE ID_CL = :ID_CL");
        qry.bindValue(":ID_CL", id_cl);
        if (qry.exec() && qry.next()) {
            image = qry.value(0).toByteArray();
        }
    }

    if (nom.isEmpty() || prenom.isEmpty() || gender.isEmpty() || adresse.isEmpty() || email.isEmpty() || ui->imageLabel->pixmap()->isNull()) {
        QMessageBox::critical(this, tr("Erreur"), tr("Veuillez remplir tous les champs et sélectionner une image."), QMessageBox::Cancel);
        return;
    }

    client client(id_cl, nom, prenom, tel, adresse, gender, age, email, image, dateReg);

    if (client.Modifierclient()) {
        ui->tableView->setModel(client.Afficherclients());
        QMessageBox::information(this, tr("Succès"), tr("Modification effectuée."), QMessageBox::Cancel);
        ui->nom->clear();
        ui->prnom->clear();
        ui->comboBox_2->setCurrentIndex(-1);
        ui->nbrphone->clear();
        ui->adresse->clear();
        ui->mail->clear();
        ui->age->clear();
        ui->date_reg->setDate(QDate::currentDate()); // Reset date field
        ui->imageLabel->clear(); // Clear image label
        imagesByteArray.clear(); // Clear the image byte array
    } else {
        QMessageBox::critical(this, tr("Erreur"), tr("Erreur lors de la modification du client."), QMessageBox::Cancel);
    }
    QDate selectedDate = ui->calendarWidget->selectedDate();
    updateCalendarAndEventDetails(selectedDate);
}



void MainWindow::exportToPDF()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), QDir::currentPath(), tr("PDF files (*.pdf)"));
    if (filePath.isEmpty()) {
        return;
    }

    QAbstractItemModel *model = ui->tableView->model();
    if (!model) {
        qDebug() << "Model not set for the table view!";
        return;
    }

    QPrinter printer;
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(filePath);
    printer.setOrientation(QPrinter::Landscape);

    QSizeF pageSize = printer.pageRect().size();
    pageSize.rwidth() *= 1.3; // Increase width by 30%
    pageSize.rheight() *= 1.4; // Increase height by 40%
    printer.setPageSize(QPageSize(pageSize, QPageSize::Point));

    QPainter painter;
    painter.begin(&printer);
    bool success = true;

    int columnPadding = 80;

    QFont titleFont = painter.font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    painter.setFont(titleFont);
    painter.setPen(Qt::red);
    QString titleText = "TABLEAU DE GESTION DES CLIENTS";
    int titleWidth = painter.fontMetrics().width(titleText);
    int titleXPos = (printer.pageRect().width() - titleWidth) / 2;
    int titleYPos = 50;
    painter.drawText(titleXPos, titleYPos, titleText);

    // Draw header row
    int headerYPos = 100;
    QFont headerFont = painter.font();
    headerFont.setPointSize(8);
    headerFont.setBold(true);
    painter.setFont(headerFont);
    painter.setPen(Qt::black);
    for (int col = 0; col < model->columnCount(); ++col) {
        QString headerData = model->headerData(col, Qt::Horizontal).toString();
        if (headerData == "Action") {
            continue;
        }
        int xPos = col * 100 + (col + 1) * columnPadding;
        painter.drawText(xPos, headerYPos, headerData);
    }

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString data = model->data(index).toString();
            if (model->headerData(col, Qt::Horizontal).toString() == "Action") {
                continue;
            }
            int xPos = col * 100 + (col + 1) * columnPadding;
            int yPos = (row + 1) * 20 + headerYPos;

            painter.drawText(xPos, yPos, data);
        }
    }

    painter.end();

    if (printer.newPage() || success) {
        QMessageBox::information(this, "Export Status", "Your data has been exported successfully.");
    } else {
        QMessageBox::critical(this, "Export Status", "Failed to export data to PDF.");
    }
}


void MainWindow::exportToExcel()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export Excel", "", "*.xlsx");
    if (!fileName.isEmpty()) {
        QAxObject* excel = new QAxObject("Excel.Application");
        QAxObject* workbooks = excel->querySubObject("Workbooks");
        QAxObject* workbook = workbooks->querySubObject("Add");
        QAxObject* sheets = workbook->querySubObject("Worksheets");
        QAxObject* sheet = sheets->querySubObject("Item(int)", 1);

        QAbstractItemModel *model = ui->tableView->model();

        QAxObject* rangeTitle = sheet->querySubObject("Range(const QString&)", "A1:C1");
        rangeTitle->dynamicCall("Merge()"); // Merge cells for the title
        rangeTitle->setProperty("Value", "TABLEAU DE GESTION DES CLIENTS");
        QAxObject* titleFont = rangeTitle->querySubObject("Font");
        titleFont->setProperty("Bold", true);
        titleFont->setProperty("Color", QColor(Qt::red));

        for (int col = 0; col < model->columnCount(); ++col) {
            QString headerData = model->headerData(col, Qt::Horizontal).toString();

            if (headerData == "Action") {
                continue;
            }

            QAxObject* cell = sheet->querySubObject("Cells(int,int)", 2, col + 1);
            cell->dynamicCall("SetValue(const QVariant&)", headerData);
            // Apply bold font to header cell
            QAxObject* headerFont = cell->querySubObject("Font");
            headerFont->setProperty("Bold", true);
        }

        for (int i = 0; i < model->rowCount(); ++i) {
            int excelCol = 1;
            for (int j = 0; j < model->columnCount(); ++j) {
                if (model->headerData(j, Qt::Horizontal).toString() == "Action") {
                    continue;
                }

                QModelIndex index = model->index(i, j);
                QString data = model->data(index).toString();
                QAxObject* cell = sheet->querySubObject("Cells(int,int)", i + 3, excelCol);
                cell->dynamicCall("SetValue(const QVariant&)", data);
                excelCol++;
            }
        }

        QAxObject* usedRange = sheet->querySubObject("UsedRange");
        if (usedRange) {
            QAxObject* rows = usedRange->querySubObject("Rows");
            QAxObject* columns = usedRange->querySubObject("Columns");
            if (rows && columns) {
                rows->setProperty("RowHeight", 20);
                columns->setProperty("ColumnWidth", 20);
            }
            delete usedRange;
        }

        workbook->dynamicCall("SaveAs(const QString&)", QDir::toNativeSeparators(fileName));
        workbook->dynamicCall("Close()");
        excel->dynamicCall("Quit()");
        delete excel;

        QMessageBox::information(this, "Export Status", "Your data has been exported successfully.");
    } else {
        QMessageBox::critical(this, "Export Status", "Failed to export data to Excel.");
    }
}



void MainWindow::Rechercherclient(const QString &text)
{
    client c;
    QSqlQueryModel *model = c.Rechercherclient(text);
    ui->tableView->setModel(model);
}




QSqlQueryModel *clientModel;

void MainWindow::on_sortComboBox_currentIndexChanged(int index)
{
    clientModel = new QSqlQueryModel(); // Create a new model each time

    QString queryStr;

    switch (index) {
        case 1: // Sort by Prénom (A-Z)
            queryStr = "SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update' AS Action, 'Delete' AS Action FROM client ORDER BY PRENOM_CL ASC";
            break;
        case 2: // Sort by Age (Ascending)
            queryStr = "SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update' AS Action, 'Delete' AS Action FROM client ORDER BY AGE ASC";
            break;
        case 3: // Sort by ID_CL (Ascending)
            queryStr = "SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update' AS Action, 'Delete' AS Action FROM client ORDER BY ID_CL ASC";
            break;
        case 4: // Sort by Date Registration (Newest to Oldest)
            queryStr = "SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update' AS Action, 'Delete' AS Action FROM client ORDER BY DATE_REG DESC";
            break;
        default:
            queryStr = "SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update' AS Action, 'Delete' AS Action FROM client";
            break;
    }

    clientModel->setQuery(queryStr);

    clientModel->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CL"));
    clientModel->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CL"));
    clientModel->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CL"));
    clientModel->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_CL"));
    clientModel->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_CL"));
    clientModel->setHeaderData(5, Qt::Horizontal, QObject::tr("GENDER"));
    clientModel->setHeaderData(6, Qt::Horizontal, QObject::tr("AGE"));
    clientModel->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    clientModel->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_REG"));
    clientModel->setHeaderData(9, Qt::Horizontal, QObject::tr("IMAGE"));
    clientModel->setHeaderData(10, Qt::Horizontal, QObject::tr("Action"));
    clientModel->setHeaderData(11, Qt::Horizontal, QObject::tr("Action"));

    ui->tableView->setModel(clientModel);
}


void MainWindow::displayCharts_clientByGender()
{
    QtCharts::QChart *chart = new QtCharts::QChart();

    chart->setBackgroundBrush(QBrush(Qt::white));

    QtCharts::QPieSeries *series = new QtCharts::QPieSeries();

    QSqlQuery query;
    query.exec("SELECT GENDER, COUNT(*) FROM client GROUP BY GENDER");

    int totalClients = 0;

    while (query.next()) {
        QString gender = query.value(0).toString();
        int count = query.value(1).toInt();
        series->append(gender + ": " + QString::number(count), count);
        totalClients += count;
    }

    chart->addSeries(series);

    chart->setTitle(QString("<div style='text-align: center;'><font size='4'>Total number of clients = %1</font></div><div style='text-align: center;'><font size='4'>Clients by Gender</font></div>").arg(totalClients));

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    chartView->setMinimumSize(700, 550);


    QPixmap pixmap = chartView->grab();



    ui->stat_gender->setPixmap(pixmap);
}

//metiers avancées
void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    // Define startOfDay and endOfDay
    QDateTime startOfDay = QDateTime(date);
    QDateTime endOfDay = startOfDay.addDays(1);

    QTextCharFormat format = ui->calendarWidget->dateTextFormat(date);
    QColor backgroundColor = format.background().color();

    // Hide all labels initially
    ui->ID_client_label_cal->setVisible(false);
    ui->NOM_client_label_cal->setVisible(false);
    ui->PRENOM_client_label_cal->setVisible(false);
    ui->EMAIL_client_label_cal->setVisible(false);
    ui->TEL_client_label_cal->setVisible(false);
    ui->GENDER_client_label_cal->setVisible(false);
    ui->AGE_client_label_cal->setVisible(false);
    ui->DATE_REG_client_label_cal->setVisible(false);
    ui->ADRESSE_client_label_cal->setVisible(false);

    if (backgroundColor == QColor("green")) {
        // Handle the green color case (display information)
        QSqlQuery idQuery;
        idQuery.prepare("SELECT ID_CL FROM client WHERE DATE_REG >= ? AND DATE_REG < ?");
        idQuery.addBindValue(startOfDay);
        idQuery.addBindValue(endOfDay);

        if (!idQuery.exec()) {
            qDebug() << "Failed to execute query:" << idQuery.lastError().text();
            return;
        }

        if (idQuery.next()) {
            // Extract idClient from the query result
            QString idClient = idQuery.value(0).toString();

            // Format the string with HTML to make "ID:" red
            QString formattedIDText = "<span style='color: red;'>ID:</span> " + idClient;

            // Create a QSqlQuery to fetch all information related to the retrieved idClient
            QSqlQuery query;
            query.prepare("SELECT NOM_CL, PRENOM_CL, EMAIL, AGE, GENDER, TEL_CL, DATE_REG, ADRESSE_CL FROM client WHERE ID_CL = ?");
            query.addBindValue(idClient);

            if (!query.exec()) {
                qDebug() << "Failed to execute query:" << query.lastError().text();
                return;
            }

            if (query.next()) {
                // Extract fields from the query result with HTML formatting
                QString nomClient = "<span style='color: red;'>Nom:</span> " + query.value(0).toString();
                QString prenom = "<span style='color: red;'>Prenom:</span> " + query.value(1).toString();
                QString email = "<span style='color: red;'>Email:</span> " + query.value(2).toString();
                QString age = "<span style='color: red;'>Age:</span> " + query.value(3).toString();
                QString gender = "<span style='color: red;'>Gender:</span> " + query.value(4).toString();
                QString telephone = "<span style='color: red;'>Telephone:</span> " + query.value(5).toString();

                QDate dateReg = query.value(6).toDate();
                QString formattedDateReg = "<span style='color: red;'>Date Registration:</span> " + dateReg.toString("dd/MM/yyyy");

                QString adresse = "<span style='color: red;'>Adresse:</span> " + query.value(7).toString();

                // Set the retrieved values to corresponding labels
                ui->ID_client_label_cal->setText(formattedIDText);
                ui->NOM_client_label_cal->setText(nomClient);
                ui->PRENOM_client_label_cal->setText(prenom);
                ui->EMAIL_client_label_cal->setText(email);
                ui->TEL_client_label_cal->setText(telephone);
                ui->GENDER_client_label_cal->setText(gender);
                ui->AGE_client_label_cal->setText(age);
                ui->DATE_REG_client_label_cal->setText(formattedDateReg);
                ui->ADRESSE_client_label_cal->setText(adresse);

                // Make labels visible
                ui->ID_client_label_cal->setVisible(true);
                ui->NOM_client_label_cal->setVisible(true);
                ui->PRENOM_client_label_cal->setVisible(true);
                ui->EMAIL_client_label_cal->setVisible(true);
                ui->TEL_client_label_cal->setVisible(true);
                ui->GENDER_client_label_cal->setVisible(true);
                ui->AGE_client_label_cal->setVisible(true);
                ui->DATE_REG_client_label_cal->setVisible(true);
                ui->ADRESSE_client_label_cal->setVisible(true);
            }
        }
    } else if (backgroundColor == QColor("yellow") || backgroundColor == QColor("orange") || backgroundColor == QColor("red")) {
        // Handle other colors (export data to PDF)
        QString colorCode;
        if (backgroundColor == QColor("yellow")) {
            colorCode = "Code Yellow";
        } else if (backgroundColor == QColor("orange")) {
            colorCode = "Code Orange";
        } else if (backgroundColor == QColor("red")) {
            colorCode = "Code Red";
        }

        // Create a QSqlQuery to fetch all clients for the clicked date
        QSqlQuery query;
        query.prepare("SELECT NOM_CL, PRENOM_CL, EMAIL, AGE, GENDER, TEL_CL, DATE_REG, ADRESSE_CL FROM client WHERE DATE_REG >= ? AND DATE_REG < ?");
        query.addBindValue(startOfDay);
        query.addBindValue(endOfDay);

        if (!query.exec()) {
            qDebug() << "Failed to execute query:" << query.lastError().text();
            return;
        }

        QString filePath = QFileDialog::getSaveFileName(this, tr("Save PDF"), QDir::currentPath(), tr("PDF files (*.pdf)"));
        if (filePath.isEmpty()) {
            return;
        }

        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(filePath);
        printer.setOrientation(QPrinter::Landscape);

        QPainter painter;
        painter.begin(&printer);

        // Title
        QFont titleFont = painter.font();
        titleFont.setPointSize(16);
        titleFont.setBold(true);
        painter.setFont(titleFont);
        painter.setPen(Qt::red);
        QString titleText = "Client Details - " + colorCode;
        int titleWidth = painter.fontMetrics().width(titleText);
        int titleXPos = (printer.pageRect().width() - titleWidth) / 2;
        int titleYPos = 50;
        painter.drawText(titleXPos, titleYPos, titleText);

        // Table Headers
        int headerYPos = 100;
        QFont headerFont = painter.font();
        headerFont.setPointSize(8);
        headerFont.setBold(true);
        painter.setFont(headerFont);
        painter.setPen(Qt::black);
        QStringList headers = {"Nom", "Prenom", "Email", "Age", "Gender", "Telephone", "Date Registration", "Adresse"};
        int columnXPos = 50;
        int columnWidth = (printer.pageRect().width() - 100) / headers.size();
        for (const QString& header : headers) {
            painter.drawText(columnXPos, headerYPos, header);
            columnXPos += columnWidth;
        }

        // Draw Data
        QFont dataFont = painter.font();
        dataFont.setPointSize(8);
        dataFont.setBold(false);
        painter.setFont(dataFont);
        int rowYPos = headerYPos + 30;

        while (query.next()) {
            columnXPos = 50;
            QStringList clientDetails = {query.value(0).toString(), query.value(1).toString(), query.value(2).toString(), query.value(3).toString(), query.value(4).toString(), query.value(5).toString(), query.value(6).toString(), query.value(7).toString()};
            for (const QString& detail : clientDetails) {
                painter.drawText(columnXPos, rowYPos, detail);
                columnXPos += columnWidth;
            }
            rowYPos += 20;

            if (rowYPos + 20 > printer.pageRect().height()) {
                printer.newPage();
                rowYPos = headerYPos + 30;
            }
        }

        painter.end();

        QMessageBox::information(this, "Export Status", "The data has been exported successfully.");
    } else {
        // Hide all labels for non-green dates and non-color background
        ui->ID_client_label_cal->setVisible(false);
        ui->NOM_client_label_cal->setVisible(false);
        ui->PRENOM_client_label_cal->setVisible(false);
        ui->EMAIL_client_label_cal->setVisible(false);
        ui->TEL_client_label_cal->setVisible(false);
        ui->GENDER_client_label_cal->setVisible(false);
        ui->AGE_client_label_cal->setVisible(false);
        ui->DATE_REG_client_label_cal->setVisible(false);
        ui->ADRESSE_client_label_cal->setVisible(false);
    }
}




void MainWindow::updateCalendarAndEventDetails(const QDate &date) {
    // Create a QSqlQuery to fetch the idClient for the clicked date from the database
    QSqlQuery idQuery;
    idQuery.prepare("SELECT ID_CL FROM client WHERE DATE_REG >= ? AND DATE_REG < ?");
    QDateTime startOfDay = QDateTime(date);
    QDateTime endOfDay = startOfDay.addDays(1);
    idQuery.addBindValue(startOfDay);
    idQuery.addBindValue(endOfDay);

    if (!idQuery.exec()) {
        qDebug() << "Failed to execute query:" << idQuery.lastError().text();
        return;
    }

    if (idQuery.next()) {
        // Extract idClient from the query result
        QString idClient = idQuery.value(0).toString();

        // Format the string with HTML to make "ID:" red
        QString formattedIDText = "<span style='color: red;'>ID:</span> " + idClient;

        // Create a QSqlQuery to fetch all information related to the retrieved idClient
        QSqlQuery query;
        query.prepare("SELECT NOM_CL, PRENOM_CL, EMAIL, AGE, GENDER, TEL_CL, DATE_REG, ADRESSE_CL FROM client WHERE ID_CL = ?");
        query.addBindValue(idClient);

        if (!query.exec()) {
            qDebug() << "Failed to execute query:" << query.lastError().text();
            return;
        }

        if (query.next()) {
            // Extract fields from the query result with HTML formatting
            QString nomClient = "<span style='color: red;'>Nom:</span> " + query.value(0).toString();
            QString prenom = "<span style='color: red;'>Prenom:</span> " + query.value(1).toString();
            QString email = "<span style='color: red;'>Email:</span> " + query.value(2).toString();
            QString age = "<span style='color: red;'>Age:</span> " + query.value(3).toString();
            QString gender = "<span style='color: red;'>Gender:</span> " + query.value(4).toString();
            QString telephone = "<span style='color: red;'>Telephone:</span> " + query.value(5).toString();

            QDate dateReg = query.value(6).toDate();
            QString formattedDateReg = "<span style='color: red;'>Date Registration:</span> " + dateReg.toString("dd/MM/yyyy");

            QString adresse = "<span style='color: red;'>Adresse:</span> " + query.value(7).toString();

            // Set the retrieved values to corresponding labels
            ui->ID_client_label_cal->setText(formattedIDText);
            ui->NOM_client_label_cal->setText(nomClient);
            ui->PRENOM_client_label_cal->setText(prenom);
            ui->EMAIL_client_label_cal->setText(email);
            ui->TEL_client_label_cal->setText(telephone);
            ui->GENDER_client_label_cal->setText(gender);
            ui->AGE_client_label_cal->setText(age);
            ui->DATE_REG_client_label_cal->setText(formattedDateReg);
            ui->ADRESSE_client_label_cal->setText(adresse);

            // Make labels visible
            ui->ID_client_label_cal->setVisible(true);
            ui->NOM_client_label_cal->setVisible(true);
            ui->PRENOM_client_label_cal->setVisible(true);
            ui->EMAIL_client_label_cal->setVisible(true);
            ui->TEL_client_label_cal->setVisible(true);
            ui->GENDER_client_label_cal->setVisible(true);
            ui->AGE_client_label_cal->setVisible(true);
            ui->DATE_REG_client_label_cal->setVisible(true);
            ui->ADRESSE_client_label_cal->setVisible(true);
        }
    } else {
        // No data found for the clicked date, hide labels
        ui->ID_client_label_cal->setVisible(false);
        ui->NOM_client_label_cal->setVisible(false);
        ui->PRENOM_client_label_cal->setVisible(false);
        ui->EMAIL_client_label_cal->setVisible(false);
        ui->TEL_client_label_cal->setVisible(false);
        ui->GENDER_client_label_cal->setVisible(false);
        ui->AGE_client_label_cal->setVisible(false);
        ui->DATE_REG_client_label_cal->setVisible(false);
        ui->ADRESSE_client_label_cal->setVisible(false);
    }

    // Clear existing date text formats in the calendar
    ui->calendarWidget->setDateTextFormat(QDate(), QTextCharFormat());

    // Create a QSqlQuery to fetch the DATE_REG values and count from the database
    QSqlQuery calendarQuery("SELECT DATE_REG, COUNT(*) FROM client GROUP BY DATE_REG");

    QMap<QDate, int> dateRegs;
    // Iterate through the query results
    while (calendarQuery.next()) {
        // Extract the DATE_REG value and count from the query
        QDate dateReg = calendarQuery.value(0).toDate();
        int count = calendarQuery.value(1).toInt();
        dateRegs[dateReg] = count;
    }

    // Set the color for each date based on the number of registrations
    for (auto it = dateRegs.cbegin(); it != dateRegs.cend(); ++it) {
        QDate date = it.key();
        int count = it.value();

        QTextCharFormat format;
        if (count == 1) {
            format.setBackground(QColor("green")); // Set background color to green
        } else if (count >= 2 && count <= 3) {
            format.setBackground(QColor("yellow")); // Set background color to yellow
        } else if (count >= 4 && count <= 5) {
            format.setBackground(QColor("orange")); // Set background color to orange
        } else if (count > 5) {
            format.setBackground(QColor("red")); // Set background color to red
        }
        ui->calendarWidget->setDateTextFormat(date, format);
    }
}






void MainWindow::on_gocal1_clicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    updateCalendarAndEventDetails(selectedDate);

    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_gocal2_clicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    updateCalendarAndEventDetails(selectedDate);

    ui->stackedWidget->setCurrentIndex(4);
}
void MainWindow::on_gocal3_clicked()
{
    QDate selectedDate = ui->calendarWidget->selectedDate();
    updateCalendarAndEventDetails(selectedDate);

    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_gostat_clicked()
{
    displayCharts_clientByGender();
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_gostat2_clicked()
{
    displayCharts_clientByGender();
    ui->stackedWidget->setCurrentIndex(3);
}


void MainWindow::navigateToPage(int pageIndex)
{
    ui->stackedWidget->setCurrentIndex(pageIndex);
}
