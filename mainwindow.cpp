#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "connection.h"
#include "statistique.h"

#include <QMessageBox>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlError>
#include <QDesktopServices>
#include <QSqlTableModel>
//new
#include "qr_code.h"
#include <QFileDialog>
#include <QLabel>

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>

#include <QMessageBox>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlError>
#include <QDesktopServices>
#include <QSqlTableModel>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QFileDialog>
#include <QModelIndexList>
#include <QImage>
#include <QString>
#include <QTableView>
#include <QAbstractItemModel>
#include "FenetreHistorique.h"  // Inclure la classe FenetreHistorique





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //updateChartFournisseurByPrice();
    ui->tableView->setModel(Fm.afficher_Fournisseur());
    Fm.afficher_Fournisseur();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_button_clicked()
{
    int id_Forni = ui->id_for->text().toInt();
    int prixProd = ui->prix_for->text().toInt();
    QString tel = ui->tel_for->text();  // Changement en QString
    QString nom = ui->nom_for->text();
    QString adresseForni = ui->adresse_for->text();
    QString email = ui->email_for->text();

    // Validation checks
    if (id_Forni <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID du fournisseur doit être un entier positif.");
        return;
    }
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom ne doit pas être vide.");
        return;
    }
    if (tel.length() != 8 || !tel.toInt()) { // Vérification sur 8 chiffres
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit être un entier de 8 chiffres.");
        return;
    }
    if (adresseForni.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse ne doit pas être vide.");
        return;
    }
    QRegularExpression emailRegex(R"(^[\w.-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
    QRegularExpressionMatch match = emailRegex.match(email);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse email est invalide.");
        return;
    }
    if (prixProd <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le prix doit être un entier positif.");
        return;
    }

    Fournisseur Fm(id_Forni, prixProd, tel, nom, adresseForni, email);
    bool test = Fm.ajouter_Fournisseur();

    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView->setModel(Fm.afficher_Fournisseur());

        ui->id_for->clear();
        ui->prix_for->clear();
        ui->tel_for->clear();
        ui->nom_for->clear();
        ui->adresse_for->clear();
        ui->email_for->clear();
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView->setModel(Fm.afficher_Fournisseur());
    }
}



void MainWindow::on_Delete_buton_clicked()
{
    int id = ui->id_for->text().toInt();

    // Validation checks
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID du fournisseur doit être un entier positif.");
        return;
    }

    if (!Fm.idExists(id)) {
        QMessageBox::warning(this, QObject::tr("Error"),
                             QObject::tr("ID not found in the database.\n"
                                         "Please enter a valid ID.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
        return;
    }

    // Attempt to delete the record
    bool test = Fm.supprimer_Fournisseur(id);



    // Check if the deletion was successful
    if (test) {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Suppression effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }


    ui->tableView->setModel(Fm.afficher_Fournisseur());

    ui->id_for->clear();
}


void MainWindow::on_Update_button_clicked()
{
    int id_Forni = ui->id_for->text().toInt();
    int prixProd = ui->prix_for->text().toInt();
    int tel = ui->tel_for->text().toInt();
    QString nom = ui->nom_for->text();
    QString adresseForni = ui->adresse_for->text();
    QString email = ui->email_for->text();

    // Validation checks
    if (id_Forni <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "L'ID du fournisseur doit être un entier positif.");
        return;
    }
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "Le nom ne doit pas être vide.");
        return;
    }
    if (tel <= 0 || QString::number(tel).length() != 8) {
        QMessageBox::warning(this, "Erreur de saisie", "Le numéro de téléphone doit être un entier de 10 chiffres.");
        return;
    }
    if (adresseForni.isEmpty()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse ne doit pas être vide.");
        return;
    }
    QRegularExpression emailRegex(R"(^[\w.-]+@[\w.-]+\.[a-zA-Z]{2,}$)");
    QRegularExpressionMatch match = emailRegex.match(email);
    if (!match.hasMatch()) {
        QMessageBox::warning(this, "Erreur de saisie", "L'adresse email est invalide.");
        return;
    }
    if (prixProd <= 0) {
        QMessageBox::warning(this, "Erreur de saisie", "Le prix doit être un entier positif.");
        return;
    }


    Fournisseur Fm(id_Forni, prixProd,  QString::number(tel), nom, adresseForni, email);


    if (!Fm.idExists(id_Forni)) {
        QMessageBox::warning(this, QObject::tr("Error"),
                             QObject::tr("ID not found in the database.\n"
                                         "Please enter a valid ID.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView->setModel(Fm.afficher_Fournisseur());
        return;
    }

    // Attempt to modify the record
    bool test = Fm.modifier_Fournisseur(id_Forni);

    // Check if the modification was successful
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectuée.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


        ui->tableView->setModel(Fm.afficher_Fournisseur());


        ui->id_for->clear();
        ui->prix_for->clear();
        ui->tel_for->clear();
        ui->nom_for->clear();
        ui->adresse_for->clear();
        ui->email_for->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Modification non effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tableView->setModel(Fm.afficher_Fournisseur());
    }
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    int row = index.row();
    QString prixValue = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR WHERE PRIX_PROD = :val");
    query.bindValue(":val", prixValue);

    if (query.exec() && query.next()) {
        ui->id_for->setText(query.value(0).toString());           // ID_FOURNI
        ui->prix_for->setText(prixValue);                         // PRIX_PROD
        ui->tel_for->setText(query.value(2).toString());          // TEL
        ui->nom_for->setText(query.value(3).toString());          // NOM
        ui->adresse_for->setText(query.value(4).toString());      // ADRESSEFOURNI
        ui->email_for->setText(query.value(5).toString());        // EMAIL
    } else {
        QMessageBox::warning(this, "Erreur", "Fournisseur introuvable");
    }

}


void MainWindow::on_chercher_Fournisseur_textChanged(const QString &arg1)
{
    QString val=ui->chercher_Fournisseur->text();
    ui->tableView->setModel(Fm.recherche_Fournisseur(val)) ;

}


void MainWindow::on_radioButton_ID_clicked()
{

    ui->tableView->setModel(Fm.Trier_Fournisseur("ID_FOURNI")) ;
}


void MainWindow::on_radioButton_Nom_clicked()
{

    ui->tableView->setModel(Fm.Trier_Fournisseur("NOM")) ;
}


void MainWindow::on_radioButton_Adresse_clicked()
{

    ui->tableView->setModel(Fm.Trier_Fournisseur("ADRESSEFOURNI")) ;
}


void MainWindow::on_radioButton_Prix_clicked()
{

    ui->tableView->setModel(Fm.Trier_Fournisseur("PRIX_PROD")) ;
}


void MainWindow::on_PDF_clicked()
{
    QString currentPath = QDir::currentPath();
    if (!QDir().exists(currentPath + "/PDFS")) {
        QDir().mkdir(currentPath + "/PDFS");  // Créer le répertoire "PDFS" s'il n'existe pas
    }

    QPdfWriter pdf(currentPath + "/PDFS/Fournisseur.pdf");
    QPainter painter(&pdf);

    int i = 4000;
    QImage image(currentPath + "/icons/Logo.png");
    if (!image.isNull()) {
        painter.drawImage(QRectF(100, 400, 800, 800), image);
    } else {
        qDebug() << "Erreur : l'image n'a pas pu être chargée.";
    }

    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(3300, 1200, "Liste des Fournisseurs");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    painter.drawRect(1500, 200, 7300, 2600);
    painter.drawRect(0, 3000, 9600, 500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(800, 3300, "ID Fournisseur");
    painter.drawText(1800, 3300, "Nom");
    painter.drawText(3000, 3300, "Adresse");
    painter.drawText(5000, 3300, "Email");
    painter.drawText(7000, 3300, "Téléphone");
    painter.drawText(8500, 3300, "Prix Produit");

    QSqlQuery query;
    query.prepare("SELECT ID_FOURNI, NOM, ADRESSEFOURNI, EMAIL, TEL, PRIX_PROD FROM FOURNISSEUR");
    if (query.exec()) {
        while (query.next()) {
            painter.drawText(800, i, query.value(0).toString());       // id_Forni
            painter.drawText(1800, i, query.value(1).toString());      // nom
            painter.drawText(3000, i, query.value(2).toString());      // adresseForni
            painter.drawText(5000, i, query.value(3).toString());      // email
            painter.drawText(7000, i, query.value(4).toString());      // tel
            painter.drawText(8500, i, query.value(5).toString());      // prixProd
            i = i + 500;
        }
    } else {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
    }

    painter.end();  // Fin du QPainter avant d'afficher le PDF

    int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>... Voulez-vous afficher le PDF ?", QMessageBox::Yes | QMessageBox::No);
    if (reponse == QMessageBox::Yes) {
        QDesktopServices::openUrl(QUrl::fromLocalFile(currentPath + "/PDFS/equipement.pdf"));
    }

}



void MainWindow::on_HIS_clicked()
{
    // Récupérer l'index de la ligne sélectionnée dans le tableView
    QModelIndexList selectedIndexes = ui->tableView->selectionModel()->selectedRows();

    // Vérifier si une ligne est sélectionnée
    if (selectedIndexes.isEmpty()) {
        QMessageBox::warning(this, "Sélection", "Veuillez sélectionner un fournisseur dans le tableau.");
        return;
    }


    // Récupérer l'index de la première colonne (ID_FOURNI, si c'est celle qu'on utilise)
    int rowIndex = selectedIndexes.first().row();

    // Trouver dynamiquement l'index de la colonne PRIX_PROD
    int prixProdColumn = -1;
    for (int col = 0; col < ui->tableView->model()->columnCount(); ++col) {
        if (ui->tableView->model()->headerData(col, Qt::Horizontal).toString() == "PRIX_PROD") {
            prixProdColumn = col;
            break;
        }
    }

    if (prixProdColumn == -1) {
        QMessageBox::warning(this, "Erreur", "La colonne 'PRIX_PROD' n'a pas été trouvée.");
        return;
    }
    QVariant prixProdValue = ui->tableView->model()->data(ui->tableView->model()->index(rowIndex, prixProdColumn));
    int prix_prod = prixProdValue.toInt();

    // Préparer la requête pour obtenir les produits associés à l'ID du fournisseur
    QSqlQuery query;
    query.prepare("SELECT p.NOMP, p.QTE, p.PRIXUNITAIRE FROM PRODUITS p "
                  "INNER JOIN FOURNISSEUR f ON f.PRIX_PROD = p.PRIXUNITAIRE "
                  "WHERE f.PRIX_PROD = :prix_prod");
    query.bindValue(":prix_prod", prix_prod);

    QString productDetails;  // String pour stocker les détails des produits (Nom, Quantité, Prix Unitaire)

    if (query.exec()) {
        // Parcourir les résultats de la requête
        while (query.next()) {
            QString productName = query.value("NOMP").toString();
            int quantity = query.value("QTE").toInt();
            double price = query.value("PRIXUNITAIRE").toDouble();

            // Formater les informations du produit pour l'affichage
            productDetails += QString("Produit: %1\nQuantité: %2\nPrix Unitaire: %3\n\n")
                                  .arg(productName)
                                  .arg(quantity)
                                  .arg(price);
        }

        // Si des produits sont trouvés, afficher la fenêtre avec les détails
        if (!productDetails.isEmpty()) {
            FenetreHistorique *fenetre = new FenetreHistorique(productDetails, this);
            fenetre->exec();  // Ouvrir la fenêtre modale
        } else {
            QMessageBox::information(this, "Historique", "Aucun produit trouvé pour ce fournisseur.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Une erreur est survenue lors de la récupération des produits.");
    }
}


QString MainWindow::extractDataFromTable(QTableView* tableView) {
    QString data;
    QAbstractItemModel* model = tableView->model();

    if (!model) {
        return data; // Modèle vide
    }

    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            data += model->data(index).toString() + " ";
        }
        data += "\n"; // Passer à la ligne suivante
    }

    return data.trimmed(); // Supprimer les espaces ou retours inutiles
}



void MainWindow::on_stats_clicked()
{
    // Préparation de la requête SQL pour récupérer le nombre de fournisseurs par plage de prix
    QSqlQuery query;
    query.prepare("SELECT PRIX_PROD, COUNT(ID_FOURNI) AS nombre_de_fournisseurs FROM FOURNISSEUR GROUP BY PRIX_PROD");
    query.exec();

    QBarSeries *series = new QBarSeries();

    while (query.next()) {
        int prixProd = query.value(0).toInt();
        int count = query.value(1).toInt();

        // Crée un set de barres pour chaque plage de prix
        QBarSet *set = new QBarSet(QString::number(prixProd) + "€");
        *set << count;

        series->append(set);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre de fournisseurs par prix de produit");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->setTitleText("Prix du produit (€)");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de fournisseurs");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    // Crée et affiche le graphique dans un QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(800, 500);  // Taille du graphique

    // Création de la fenêtre Statistique
    Statistique *statistiqueWindow = new Statistique(this);
    statistiqueWindow->addChartView(chartView);  // Ajoute le graphique à la fenêtre Statistique

    // Affichage de la fenêtre Statistique
    statistiqueWindow->exec();
}


#include "qr_code1.h"


#include <QMessageBox>
#include <QDir>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlError>
#include <QDesktopServices>
#include <QSqlTableModel>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QChart>
#include <QFileDialog>
#include <QModelIndexList>
#include <QImage>
#include <QString>
#include <QTableView>
#include <QAbstractItemModel>



void MainWindow::on_PDF_2_clicked()

{
    // Get the selected row
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(nullptr, QObject::tr("Error"), QObject::tr("Veuillez sélectionner un fournisseur."), QMessageBox::Ok);
        return;
    }

    // Get the data from the selected row
    int id_Forni = ui->tableView->model()->index(selectedRows.at(0).row(), 0).data().toInt();
    QString nom = ui->tableView->model()->index(selectedRows.at(0).row(), 1).data().toString();
    QString adresseForni = ui->tableView->model()->index(selectedRows.at(0).row(), 2).data().toString();
    QString email = ui->tableView->model()->index(selectedRows.at(0).row(), 3).data().toString();
    int prixProd = ui->tableView->model()->index(selectedRows.at(0).row(), 4).data().toInt();
    int tel = ui->tableView->model()->index(selectedRows.at(0).row(), 5).data().toInt();

    // Construct the QR code string
    QString qrString = QString("ID Fournisseur: %1\nNom: %2\nAdresse: %3\nEmail: %4\nPrix Produit: %5\nTéléphone: %6")
                           .arg(id_Forni).arg(nom).arg(adresseForni).arg(email).arg(prixProd).arg(tel);

    try {
        // Generate QR code
        Qrcode::QrCode qr = Qrcode::QrCode::encodeText(qrString.toUtf8().constData(), Qrcode::QrCode::Ecc::HIGH);

        // Calculate the size of the QR code image
        const int scale = 4; // Adjust scale factor as needed
        const int border = 4; // Adjust border size as needed
        const int qrSize = qr.getSize();
        const int imageSize = (qrSize + 2 * border) * scale;

        // Create QImage to hold the QR code
        QImage qrImage(imageSize, imageSize, QImage::Format_RGB888);
        qrImage.fill(Qt::white); // Fill the image with white color

        // Set pixels for QR code modules
        for (int y = 0; y < qrSize; y++) {
            for (int x = 0; x < qrSize; x++) {
                if (qr.getModule(x, y)) { // Black for "true" modules
                    for (int i = 0; i < scale; i++) {
                        for (int j = 0; j < scale; j++) {
                            int pixelX = (border + x) * scale + i;
                            int pixelY = (border + y) * scale + j;
                            qrImage.setPixelColor(pixelX, pixelY, Qt::black);
                        }
                    }
                }
            }
        }

        // Ask the user to select a file path
        QString filePath = QFileDialog::getSaveFileName(this, tr("Save QR Code Image"), "", tr("PNG Files (*.png)"));

        if (filePath.isEmpty()) {
            QMessageBox::information(nullptr, QObject::tr("Cancelled"), QObject::tr("No file selected. QR code was not saved."), QMessageBox::Ok);
        } else if (qrImage.save(filePath)) {
            QMessageBox::information(nullptr, QObject::tr("Success"), QObject::tr("Image saved successfully."), QMessageBox::Ok);
        } else {
            QMessageBox::warning(nullptr, QObject::tr("Save Error"), QObject::tr("Failed to save the QR code image."), QMessageBox::Ok);
        }
    } catch (const std::exception &e) {
        QMessageBox::critical(nullptr, QObject::tr("QR Code Error"), QObject::tr("Failed to generate QR code: %1").arg(e.what()), QMessageBox::Ok);
    }
}

void MainWindow::on_QR_button_clicked()
{
    QTableView* tableView = ui->tableView;

    // Extraire les données du tableau
    QString data = extractDataFromTable(tableView);
    if (data.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucune donnée à convertir en QR Code !");
        return;
    }

    // Chemin de sortie pour le QR Code
    QString outputPath = QDir::currentPath() + "/QR_codes/Fournisseur_QRCode.png";

    // Initialisation et génération du QR Code
    QRCodeGenerator generator;
    bool success = generator.generateQRCode(data, outputPath);

    if (success) {
        QMessageBox::information(this, "QR Code", "Le QR Code a été généré avec succès et enregistré dans : " + outputPath);
        QDesktopServices::openUrl(QUrl::fromLocalFile(outputPath)); // Ouvrir l'image
    } else {
        QMessageBox::warning(this, "QR Code", "Erreur lors de la génération du QR Code.");
    }
}

