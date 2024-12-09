#include "client.h"
#include <QDebug>

client::client()
{

}

bool client::Ajouterclient()
{
    QSqlQuery query;

    query.prepare("INSERT INTO client (NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, IMAGE, DATE_REG) "
                  "VALUES (:NOM_CL, :PRENOM_CL, :TEL_CL, :ADRESSE_CL, :GENDER, :AGE, :EMAIL, :IMAGE, :DATE_REG)");

    query.bindValue(":NOM_CL", NOM_CL);
    query.bindValue(":PRENOM_CL", PRENOM_CL);
    query.bindValue(":TEL_CL", TEL_CL);
    query.bindValue(":ADRESSE_CL", ADRESSE_CL);
    query.bindValue(":GENDER", GENDER);
    query.bindValue(":AGE", AGE);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":IMAGE", IMAGE);
    query.bindValue(":DATE_REG", DATE_REG);

    return query.exec();
}

QSqlQueryModel* client::Afficherclients()
{
    QSqlQueryModel* modal = new QSqlQueryModel();

    modal->setQuery("SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update', 'Delete' AS Action FROM client");
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CL"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CL"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CL"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_CL"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_CL"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("GENDER"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("AGE"));
    modal->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    modal->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_REG"));
    modal->setHeaderData(9, Qt::Horizontal, QObject::tr("IMAGE"));
    modal->setHeaderData(10, Qt::Horizontal, QObject::tr("Action"));
    modal->setHeaderData(11, Qt::Horizontal, QObject::tr("Action")); // Set header for the new column

    return modal;
}


bool client::Modifierclient()
{
    QSqlQuery query;

    if (!query.prepare("UPDATE client SET NOM_CL = :NOM_CL, PRENOM_CL = :PRENOM_CL, TEL_CL = :TEL_CL, ADRESSE_CL = :ADRESSE_CL, GENDER = :GENDER, AGE = :AGE, EMAIL = :EMAIL, IMAGE = :IMAGE, DATE_REG = :DATE_REG WHERE ID_CL = :ID_CL")) {
        qDebug() << "Prepare failed:" << query.lastError();
        return false;
    }

    query.bindValue(":NOM_CL", NOM_CL);
    query.bindValue(":PRENOM_CL", PRENOM_CL);
    query.bindValue(":TEL_CL", TEL_CL);
    query.bindValue(":ADRESSE_CL", ADRESSE_CL);
    query.bindValue(":GENDER", GENDER);
    query.bindValue(":AGE", AGE);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":IMAGE", IMAGE);
    query.bindValue(":DATE_REG", DATE_REG);
    query.bindValue(":ID_CL", ID_CL);

    if (!query.exec()) {
        qDebug() << "Exec failed:" << query.lastError();
        return false;
    }

    return true;
}

bool client::Supprimerclient(const QString &ID_CL)
{
    QSqlQuery query;

    query.prepare("DELETE FROM client WHERE ID_CL = :ID_CL");
    query.bindValue(":ID_CL", ID_CL);

    return query.exec();
}

bool client::Supprimerclients()
{
    QSqlQuery query;

    query.prepare("DELETE FROM client WHERE ID_CL = :ID_CL");
    query.bindValue(":ID_CL", ID_CL);

    return query.exec();
}

QSqlQueryModel *client::Rechercherclient(const QString &text)
{
    QSqlQueryModel *modal = new QSqlQueryModel();

    QString queryStr = QString("SELECT ID_CL, NOM_CL, PRENOM_CL, TEL_CL, ADRESSE_CL, GENDER, AGE, EMAIL, DATE_REG, IMAGE, 'Update' AS Action, 'Delete' AS Action "
                               "FROM client WHERE ID_CL LIKE '%%1%' OR NOM_CL LIKE '%%1%' OR PRENOM_CL LIKE '%%1%' OR TEL_CL LIKE '%%1%' OR ADRESSE_CL LIKE '%%1%' OR GENDER LIKE '%%1%' OR AGE LIKE '%%1%' OR EMAIL LIKE '%%1%' OR DATE_REG LIKE '%%1%'")
                           .arg(text);

    modal->setQuery(queryStr);
    modal->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_CL"));
    modal->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_CL"));
    modal->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM_CL"));
    modal->setHeaderData(3, Qt::Horizontal, QObject::tr("TEL_CL"));
    modal->setHeaderData(4, Qt::Horizontal, QObject::tr("ADRESSE_CL"));
    modal->setHeaderData(5, Qt::Horizontal, QObject::tr("GENDER"));
    modal->setHeaderData(6, Qt::Horizontal, QObject::tr("AGE"));
    modal->setHeaderData(7, Qt::Horizontal, QObject::tr("EMAIL"));
    modal->setHeaderData(8, Qt::Horizontal, QObject::tr("DATE_REG"));
    modal->setHeaderData(9, Qt::Horizontal, QObject::tr("IMAGE"));
    modal->setHeaderData(10, Qt::Horizontal, QObject::tr("Action"));
    modal->setHeaderData(11, Qt::Horizontal, QObject::tr("Action"));

    return modal;
}

