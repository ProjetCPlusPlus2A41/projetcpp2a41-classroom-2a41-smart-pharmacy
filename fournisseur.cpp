#include "fournisseur.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include "mainwindow.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QBarSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarSet>

Fournisseur::Fournisseur() {}

Fournisseur::Fournisseur(int id_Forni, int prixProd, QString tel, QString nom, QString adresseForni, QString email)
{
    this->id_Forni = id_Forni;
    this->prixProd = prixProd;
    this->tel = tel;
    this->nom = nom;
    this->adresseForni = adresseForni;
    this->email = email;
}

Fournisseur::Fournisseur(int prixProd, QString tel, QString nom, QString adresseForni, QString email)
{
    this->prixProd = prixProd;
    this->tel = tel;
    this->nom = nom;
    this->adresseForni = adresseForni;
    this->email = email;
}

// Getters
int Fournisseur::get_id_Forni() { return id_Forni; }
int Fournisseur::get_prixProd() { return prixProd; }
QString Fournisseur::get_tel() { return tel; }
QString Fournisseur::get_nom() { return nom; }
QString Fournisseur::get_adresseForni() { return adresseForni; }
QString Fournisseur::get_email() { return email; }

// Setters
void Fournisseur::set_id_Forni(int id_Forni) { this->id_Forni = id_Forni; }
void Fournisseur::set_prixProd(int prixProd) { this->prixProd = prixProd; }
void Fournisseur::set_tel(QString tel) { this->tel = tel; }
void Fournisseur::set_nom(QString nom) { this->nom = nom; }
void Fournisseur::set_adresseForni(QString adresseForni) { this->adresseForni = adresseForni; }
void Fournisseur::set_email(QString email) { this->email = email; }

// CRUD

bool Fournisseur::ajouter_Fournisseur()
{
    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR (ID_FOURNI, PRIX_PROD, TEL, NOM, ADRESSEFOURNI, EMAIL)"
                  "VALUES (:ID_FOURNI, :PRIX_PROD, :TEL, :NOM, :ADRESSEFOURNI, :EMAIL)");
    query.bindValue(":ID_FOURNI", id_Forni);
    query.bindValue(":PRIX_PROD", prixProd);
    query.bindValue(":TEL", tel);
    query.bindValue(":NOM", nom);
    query.bindValue(":ADRESSEFOURNI", adresseForni);
    query.bindValue(":EMAIL", email);
    return query.exec();
}

bool Fournisseur::modifier_Fournisseur(int id1)
{
    QSqlQuery query;
    query.prepare("UPDATE FOURNISSEUR SET PRIX_PROD=:PRIX_PROD, TEL=:TEL, NOM=:NOM, ADRESSEFOURNI=:ADRESSEFOURNI, EMAIL=:EMAIL WHERE ID_FOURNI=:ID_FOURNI");
    query.bindValue(":ID_FOURNI", id1);
    query.bindValue(":PRIX_PROD", prixProd);
    query.bindValue(":TEL", tel);
    query.bindValue(":NOM", nom);
    query.bindValue(":ADRESSEFOURNI", adresseForni);
    query.bindValue(":EMAIL", email);
    return query.exec();
}

QSqlQueryModel* Fournisseur::afficher_Fournisseur()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT PRIX_PROD, TEL, NOM, ADRESSEFOURNI, EMAIL FROM FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRIX_PROD"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));
    return model;
}


bool Fournisseur::supprimer_Fournisseur(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("DELETE FROM FOURNISSEUR WHERE ID_FOURNI = :ID_FOURNI");
    query.bindValue(":ID_FOURNI",res);

    return query.exec();
}

bool Fournisseur::idExists(int id)
{
    QString res = QString::number(id);

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM FOURNISSEUR WHERE ID_FOURNI = :id");
    query.bindValue(":id", res);
    query.exec();

    if (query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

QSqlQueryModel* Fournisseur::recherche_Fournisseur(QString val)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQueryModel* modelA = new QSqlQueryModel();
    QSqlQuery query;

    // Préparation de la requête SQL pour ne chercher que par le champ NOM
    query.prepare("SELECT ID_FOURNI, PRIX_PROD, TEL, NOM, ADRESSEFOURNI, EMAIL FROM FOURNISSEUR WHERE NOM LIKE :nom ORDER BY ID_FOURNI");

    // Ajout du joker pour effectuer une recherche partielle sur le nom
    QString searchValue = "%" + val + "%";
    query.bindValue(":nom", searchValue);

    // Exécution de la requête et gestion des erreurs
    if (query.exec())
    {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNI"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX_PROD"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
        return model;
    }


    modelA=afficher_Fournisseur();
    return modelA;
}

QSqlQueryModel* Fournisseur::Trier_Fournisseur(QString val)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQueryModel* modelA = new QSqlQueryModel();
    QSqlQuery query;
    QString queryString;

    if (val == "ID_FOURNI")
    {
        query.prepare("SELECT ID_FOURNI, PRIX_PROD, TEL, NOM, ADRESSEFOURNI, EMAIL FROM FOURNISSEUR ORDER BY ID_FOURNI");
        if (query.exec())
        {
            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNI"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX_PROD"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
            return model;
        }


    }
    else if (val == "PRIX_PROD"){
        query.prepare( "SELECT  PRIX_PROD,ID_FOURNI, TEL, NOM, ADRESSEFOURNI, EMAIL FROM FOURNISSEUR ORDER BY PRIX_PROD");
        if (query.exec())
        {
            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("PRIX_PROD"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_FOURNI"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
            return model;
        }
    }
    else if (val == "NOM")
    {
        query.prepare( "SELECT  NOM,ID_FOURNI,PRIX_PROD,TEL , ADRESSEFOURNI, EMAIL FROM FOURNISSEUR ORDER BY NOM");
        if (query.exec())
        {
            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_FOURNI"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_PROD"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
            return model;
        }
    }
    else if (val == "ADRESSEFOURNI")
    {
        query.prepare( "SELECT ADRESSEFOURNI, ID_FOURNI, PRIX_PROD, TEL, NOM, EMAIL FROM FOURNISSEUR ORDER BY ADRESSEFOURNI");
        if (query.exec())
        {
            model->setQuery(query);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID_FOURNI"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRIX_PROD"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("NOM"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
            return model;
        }

    }
    modelA=afficher_Fournisseur();
    return modelA;
}


