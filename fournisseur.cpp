#include "fournisseur.h"

Fournisseur::Fournisseur()
{

}

Fournisseur::Fournisseur(int id_Forni, int prixProd, int tel, QString nom, QString adresseForni, QString email, QString recus)
{
    this->id_Forni = id_Forni;
    this->prixProd = prixProd;
    this->tel = tel;
    this->nom = nom;
    this->adresseForni = adresseForni;
    this->email = email;
    this->recus = recus;
}

Fournisseur::Fournisseur(int prixProd, int tel, QString nom, QString adresseForni, QString email, QString recus)
{
    this->prixProd = prixProd;
    this->tel = tel;
    this->nom = nom;
    this->adresseForni = adresseForni;
    this->email = email;
    this->recus = recus;
}

//getters
int Fournisseur::get_id_Forni(){return id_Forni;}
int Fournisseur::get_prixProd(){return prixProd;}
int Fournisseur::get_tel(){return tel;}
QString Fournisseur::get_nom(){return nom;}
QString Fournisseur:: get_adresseForni(){return adresseForni ;}
QString Fournisseur:: get_email(){return email;}
QString Fournisseur:: get_recus(){return recus;}

//setters
void Fournisseur:: set_id_Forni(int id_Forni)
{
    this->id_Forni=id_Forni;
}
void Fournisseur:: set_prixProd(int prixProd)
{
    this->prixProd=prixProd;
}
void Fournisseur:: set_tel(int tel)
{
    this->tel=tel;
}
void Fournisseur::set_nom(QString nom)
{
    this ->nom=nom;
}
void Fournisseur:: set_adresseForni(QString adresseForni)
{
    this ->adresseForni=adresseForni;
}
void Fournisseur:: set_email(QString email)
{
    this->email=email;
}
void Fournisseur:: set_recus(QString recus)
{
    this->recus=recus;
}

//CRUD

bool Fournisseur::ajouter_Fournisseur()
{
    QString id_Forni_String=QString::number(id_Forni);
    QString prixProd_String=QString::number(prixProd);
    QString tel_String=QString::number(tel);
    QSqlQuery query;
    query.prepare("INSERT INTO FOURNISSEUR (ID_FOURNI, PRIX_PROD, TEL, NOM, ADRESSEFOURNI, EMAIL, RECUS)"
                  "VALUES (:ID_FOURNI, :PRIX_PROD, :TEL, :NOM, :ADRESSEFOURNI, :EMAIL, :RECUS)");
    query.bindValue(":ID_FOURNI", id_Forni_String);
    query.bindValue(":PRIX_PROD",prixProd_String);
    query.bindValue(":TEL", tel_String);
    query.bindValue(":NOM", nom);
    query.bindValue(":ADRESSEFOURNI", adresseForni);
    query.bindValue(":EMAIL", email);
    query.bindValue(":RECUS", recus);
    return  query.exec();
}

bool Fournisseur::modifier_Fournisseur(int id1)
{
    QSqlQuery query;

    QString res = QString::number(id1);
    QString prixProd_String=QString::number(prixProd);
    QString tel_String=QString::number(tel);

    query.prepare("UPDATE FOURNISSEUR SET PRIX_PROD=:PRIX_PROD, TEL=:TEL, NOM=:NOM, ADRESSEFOURNI=:ADRESSEFOURNI, EMAIL=:EMAIL, RECUS=:RECUS WHERE ID_FOURNI=:ID_FOURNI");
    query.bindValue(":ID_FOURNI", res);
    query.bindValue(":PRIX_PROD",prixProd_String);
    query.bindValue(":TEL", tel_String);
    query.bindValue(":NOM", nom);
    query.bindValue(":ADRESSEFOURNI", adresseForni);
    query.bindValue(":EMAIL", email);
    query.bindValue(":RECUS", recus);
    return query.exec();
}

QSqlQueryModel * Fournisseur::afficher_Fournisseur()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM FOURNISSEUR");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_FOURNI"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRIX_PROD"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TEL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSEFOURNI"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("EMAIL"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("RECUS"));
    return model ;

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
