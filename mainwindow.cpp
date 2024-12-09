#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "livraison.h"
#include "email.h"
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QRegularExpression>
#include <QPdfWriter>
#include <QPainter>
#include "mainwindow.h"
#include <QTcpSocket>
#include <QTextStream>
#include <QDebug>
#include <QCoreApplication>
#include <QSslSocket>
#include "piechartwidget.h"

#include "arduino.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    liv() // Assuming liv is a valid class object
{
    ui->setupUi(this);
    ui->tableView->setModel(liv.afficher());

    // Configuration de la tableView pour afficher des données
    ui->tableView->setModel(liv.afficher()); // Charger les données initiales dans le TableView

    // Initialisation du widget QML pour la carte
    ui->quickWidget_MapView->setResizeMode(QQuickWidget::SizeRootObjectToView); // Adapter le QML à la taille du widget
    ui->quickWidget_MapView->setSource(QUrl(QStringLiteral("qrc:/Qmlmaps.qml"))); // Charger le fichier QML
    ui->quickWidget_MapView->show();

    // Récupération de l'objet racine dans le QML
    QObject *qmlObject = ui->quickWidget_MapView->rootObject();
    if (qmlObject) {
        // Connexion des signaux C++ aux slots QML
        connect(this, SIGNAL(setCenterPosition(QVariant, QVariant)), qmlObject, SLOT(setCenterPosition(QVariant, QVariant)));
        connect(this, SIGNAL(setLocationMarking_2(QVariant, QVariant)), qmlObject, SLOT(setLocationMarking_2(QVariant, QVariant)));
        connect(this, SIGNAL(setLocationMarking_1(QVariant, QVariant)), qmlObject, SLOT(setLocationMarking_1(QVariant, QVariant)));

        // Initialisation de la position centrale et du marqueur
        emit setCenterPosition(36.8666, 10.1895); // Centre sur Tunis
        emit setLocationMarking_1(36.8666, 10.1895); // Ajouter un marqueur sur Tunis
        emit setLocationMarking_2(33.8869, 9.5375); // Ajouter un marqueur sur Tunis

    } else {
        qWarning() << "Impossible de récupérer l'objet racine du fichier QML.";
    }



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
            query.prepare("SELECT * FROM LIVRAISON WHERE RFID = :code");
            query.bindValue(":code", A.code);
            if (query.exec() && query.next())
            {
                int count = query.value(0).toInt();
                if (count > 0)
                {
                    // UID exists in the database
                    QSqlQuery nomquery;
                    query.prepare("SELECT NOM FROM LIVRAISON WHERE RFID = :code");
                    query.bindValue(":code", A.code);
                    if (query.exec() && query.next())
                    {
                        nom = query.value(0).toString();
                        nom=nom+"/";
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
                        QSqlQuery query3;
                        query3.prepare("UPDATE LIVRAISON SET PRESENCE='present' WHERE RFID=:code");
                        query3.bindValue(":code",A.code);
                        query3.exec();
                        ui->tableView->setModel(liv.afficher());
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
/*
void MainWindow::readFromArduino() {
QString      nom="";
  QByteArray data = A.read_from_arduino();
  QString uid = QString::fromUtf8(data).trimmed(); // Convertir les données en chaîne

  if (!uid.isEmpty()) {
      //qDebug() << "UID reçu:" << uid;
      if (uid != "/") {
          A.code += uid;
      }

   A.code.remove("/");
   }

  qDebug() << A.code << endl;

      QSqlQuery query;
      query.prepare("SELECT COUNT(*) FROM CLIENTS WHERE RFID = :code");
      query.bindValue(":code", A.code);

      if (query.exec() && query.next()) {
          int count = query.value(0).toInt();
          if (count > 0) {
              // UID exists in the database
              QSqlQuery nomquery;
              query.prepare("SELECT NOM_CL FROM CLIENTS WHERE RFID = :code");
              query.bindValue(":code", A.code);


              if (query.exec() && query.next()) {
                    nom = query.value(0).toString(); // Assuming 'nomquery' is the correct query
                  nom=nom+"/";
                   // Convert QString to QByteArray
                      QByteArray dataToSend = nom.toUtf8(); // Convert the QString to QByteArray
                    qDebug()<<nom<<endl;
                      // Send each character to the Arduino
                   for (char c : dataToSend) {
                       QByteArray byteArray;
                       byteArray.append(c); // Create a QByteArray for the character
                       A.write_to_arduino(byteArray); // Send the character to Arduino
                   }

               }

             QMessageBox::information(this, "Succès", "L'UID existe  !");


               A.code = "";
                 nom="";
          } else {
              // UID does not exist
               QMessageBox::warning(this, "Erreur", "L'UID n'existe pas !");
               A.code = "";
                nom="";
          }
      } else {
          QMessageBox::warning(this, "Erreur", "Erreur lors de la vérification de l'UID.");
           A.code = "";
      }


  A.code = ""; // Reset the code after processing
}*/
MainWindow::~MainWindow() {
  delete ui;
  A.close_arduino();

}


#include <QRegularExpression> // Inclure l'en-tête pour QRegularExpression

void MainWindow::on_ajouterbutton_clicked()
{
    QString nom = ui->linenom->text();
    QString prenom = ui->lineprenom->text();
    QString adresse = ui->lineadresse->text();

    // Contrôle de saisie pour le nom
    QRegularExpression nomRegex("^[A-Za-z]+$"); // Vérifie que le nom contient uniquement des lettres
    if (nom.isEmpty() || !nomRegex.match(nom).hasMatch()) {
        QMessageBox::warning(this, QObject::tr("Nom invalide"),
                             QObject::tr("Le nom doit être non vide et contenir uniquement des lettres."),
                             QMessageBox::Cancel);
        return; // Empêche l'ajout si le nom est invalide
    }

    // Contrôle de saisie pour le prénom
    QRegularExpression prenomRegex("^[A-Za-z]+$"); // Vérifie que le prénom contient uniquement des lettres
    if (prenom.isEmpty() || !prenomRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(this, QObject::tr("Prénom invalide"),
                             QObject::tr("Le prénom doit être non vide et contenir uniquement des lettres."),
                             QMessageBox::Cancel);
        return; // Empêche l'ajout si le prénom est invalide
    }

    // Contrôle de saisie pour l'adresse
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, QObject::tr("Adresse invalide"),
                             QObject::tr("L'adresse ne doit pas être vide."),
                             QMessageBox::Cancel);
        return; // Empêche l'ajout si l'adresse est vide
    }

    livraison newLivraison(nom, prenom, adresse); // Créer un objet livraison
    bool test = newLivraison.ajouter(); // Essayer d'ajouter à la base de données

    if (test) {

        // Rafraîchir la vue du tableau pour afficher la nouvelle entrée
        ui->tableView->setModel(liv.afficher());

        QMessageBox::information(nullptr, QObject::tr("Ok"),
                                 QObject::tr("Ajout effectué \n"
                                             "Click Cancel to exit"),
                                 QMessageBox::Cancel);
    } else {
        // Si l'ajout échoue
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit"),
                              QMessageBox::Cancel);
    }
}


void MainWindow::on_delete_2_clicked()
{
    bool ok;
    int id = ui->linedelete->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, QObject::tr("Input Error"),
                             QObject::tr("Please enter a valid ID.\n"
                                         "Click Cancel to exit."),
                             QMessageBox::Cancel);
        return;
    }

    bool test = liv.supprimer(id);
    if (test) {
        ui->tableView->setModel(liv.afficher());
        QMessageBox::information(this, QObject::tr("Success"),
                                 QObject::tr("Suppression effectuée.\n"
                                             "Click Cancel to exit."),
                                 QMessageBox::Cancel);
        ui->linedelete->clear(); // Clear the input after successful deletion
    } else {
        QMessageBox::critical(this, QObject::tr("Failure"),
                              QObject::tr("Suppression non effectuée.\n"
                                          "Click Cancel to exit."),
                              QMessageBox::Cancel);
    }
}



void MainWindow::on_recherche_clicked()
{
    QString val  = ui->lineEdit->text();
    ui->tableView->setModel(liv.recherche(val));
}



void MainWindow::on_trier_clicked()
{
    ui->tableView->setModel(liv.trier());
}


void MainWindow::on_pushButton_clicked()
{

    QPdfWriter pdf("C:/Users/USER/Desktop/Atelier_Connexion/livraisonpdf.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial", 25));
                          painter.drawText(1500,1100,"Liste des livraison");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 15));

                          painter.drawRect(100,100,7300,2600);

                          painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/USER/Desktop/Atelier_Connexion/livraisonpdf.pdf"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(50,3300,"idlivraison");
                          painter.drawText(850,3300,"Nom");
                          painter.drawText(1550,3300,"Prenom");
                          painter.drawText(2300,3300,"adresse");




                          QSqlQuery query;
                          query.prepare("select * from LIVRAISON");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(50,i,query.value(0).toString());
                              painter.drawText(850,i,query.value(1).toString());
                              painter.drawText(1550,i,query.value(2).toString());
                              painter.drawText(2220,i,query.value(3).toString());
                              painter.drawText(3000,i,query.value(5).toString());
                              painter.drawText(4800,i,query.value(6).toString());
                              painter.drawText(5560,i,query.value(7).toString());
                              painter.drawText(6000,i,query.value(8).toString());
                              painter.drawText(6950,i,query.value(9).toString());
                              painter.drawText(7900,i,query.value(10).toString());
                              painter.drawText(8600,i,query.value(11).toString());


                             i = i + 500;
                          }

                                  QMessageBox::information(nullptr,QObject::tr("Export PDF"),QObject::tr("Export effectué avec succès \n click cancel to exit")
                                          ,QMessageBox::Cancel);
}




void MainWindow::on_email_clicked()
{ QString destinataire = ui->destinataireEmail->text();
    QString objet = ui->objetEmail->text();
    QString corps = ui->bodyEmail->text();

    // Vérification de la validité des champs
    if (destinataire.isEmpty() || objet.isEmpty() || corps.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis avant d'envoyer l'email.");
        return;
    }

    // Appel de la fonction d'envoi d'email
    mailer::sendEmail(destinataire, objet, corps);

    // Supposons que l'envoi est réussi
    QMessageBox::information(this, "Succès", "Email envoyé avec succès.");

    // Vider les champs
    ui->destinataireEmail->clear();
    ui->objetEmail->clear();
    ui->bodyEmail->clear();

}

void MainWindow::on_stat_clicked()
{
    livraison l;
    QMap<QString, int> stats = l.obtenirStatistiques();

    if (stats.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Impossible de récupérer les statistiques.");
        return;
    }

    // Créer une nouvelle fenêtre pour afficher le pie chart
    QMainWindow* statWindow = new QMainWindow(this);
    statWindow->setWindowTitle("Statistiques par Adresse");

    // Utiliser le PieChartWidget pour afficher les données
    PieChartWidget* chartWidget = new PieChartWidget(stats, statWindow);
    statWindow->setCentralWidget(chartWidget);

    // Afficher la fenêtre de statistiques
    statWindow->resize(600, 600);
    statWindow->show();
}


void MainWindow::on_quitter_clicked()
{
    // Define your condition
    bool conditionMet = true; // Replace with your actual condition

    if (conditionMet) {
        // Ask for user confirmation (optional)
        QMessageBox::StandardButton reply = QMessageBox::question(
            this, // Parent widget
            "Quit Application",
            "Do you really want to quit?",
            QMessageBox::Yes | QMessageBox::No
        );

        if (reply == QMessageBox::Yes) {
            qDebug() << "Condition met, quitting application...";
            QSqlQuery query3;
            query3.prepare("UPDATE LIVRAISON SET PRESENCE='absent'");
            query3.exec();
            QApplication::quit(); // Gracefully exit the application
        } else {
            qDebug() << "Quit canceled by user.";
        }
    } else {
        qDebug() << "Condition not met, staying in application.";
    }
}
