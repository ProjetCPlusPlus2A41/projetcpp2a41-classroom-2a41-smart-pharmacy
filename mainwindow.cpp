#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fournisseur.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui->tableView->setModel(Fm.afficher_Fournisseur());
}

void MainWindow::on_pushButton_clicked()
{
    // Get the input values
    int id_Forni = ui->id__ajout->text().toInt();
    int prixProd = ui->prix_ajout->text().toInt();
    int tel = ui->tel_ajout->text().toInt();
    QString nom = ui->lineNom->text();
    QString adresseForni = ui->adresse_ajout->text();
    QString email = ui->email_ajout->text();
    QString recus = ui->recus_ajout->text();


    Fournisseur Fm(id_Forni, prixProd, tel, nom, adresseForni, email, recus);
    bool test = Fm.ajouter_Fournisseur();

    // Check if the addition was successful
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

        // Update the table view
        ui->tableView->setModel(Fm.afficher_Fournisseur());


        ui->id__ajout->clear();
        ui->prix_ajout->clear();
        ui->tel_ajout->clear();
        ui->lineNom->clear();
        ui->adresse_ajout->clear();
        ui->email_ajout->clear();
        ui->recus_ajout->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Ajout non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

         ui->tableView->setModel(Fm.afficher_Fournisseur());
    }
}


void MainWindow::on_pushButtonsupprimer_clicked()
{
    int id = ui->id__ajout->text().toInt();


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

    ui->id__ajout->clear();
}


void MainWindow::on_tableView_activated (const QModelIndex &index)
{
    int row = index.row();
    QString idValue = ui->tableView->model()->data(ui->tableView->model()->index(row, 0)).toString();
    QSqlQuery query;
    query.prepare("SELECT * FROM FOURNISSEUR WHERE ID_FOURNI = :val");
    query.bindValue(":val", idValue);
    if (query.exec() && query.next()) {
        ui->id__ajout->setText(idValue);
        ui->prix_ajout->setText(query.value(1).toString());
        ui->tel_ajout->setText(query.value(2).toString());
        ui->lineNom->setText(query.value(3).toString());
        ui->adresse_ajout->setText(query.value(4).toString());
        ui->email_ajout->setText(query.value(5).toString());
        ui->recus_ajout->setText(query.value(6).toString());
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    int id_Forni = ui->id__ajout->text().toInt();
    int prixProd = ui->prix_ajout->text().toInt();
    int tel = ui->tel_ajout->text().toInt();
    QString nom = ui->lineNom->text();
    QString adresseForni = ui->adresse_ajout->text();
    QString email = ui->email_ajout->text();
    QString recus = ui->recus_ajout->text();


    Fournisseur Fm(id_Forni, prixProd, tel, nom, adresseForni, email, recus);


    if (!Fm.idExists(id_Forni)) {
        QMessageBox::warning(this, QObject::tr("Error"),
                             QObject::tr("ID not found in the database.\n"
                                         "Please enter a valid ID.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
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


        ui->id__ajout->clear();
        ui->prix_ajout->clear();
        ui->tel_ajout->clear();
        ui->lineNom->clear();
        ui->adresse_ajout->clear();
        ui->email_ajout->clear();
        ui->recus_ajout->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Error"),
                              QObject::tr("Modification non effectuée.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

