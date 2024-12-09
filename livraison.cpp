#include "livraison.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>

livraison::livraison()
{

}

livraison::livraison( QString nom, QString prenom, QString adresse)
{

    this->Adresse = adresse;
    this->nom = nom;
    this->prenom = prenom;
}

bool livraison::ajouter() {
    QSqlQuery query;

    // Corrected the spelling of 'INSERT' and fixed the SQL syntax
    query.prepare("INSERT INTO LIVRAISON (IDLIVRAISON, NOM, PRENOM, ADRESSE) "
                  "VALUES (IDLIVRAISON.NEXTVAL, :nom, :prenom, :adresse)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", Adresse);

    // Execute the query and return whether it was successful
    return query.exec();
}

bool livraison::supprimer(int code) {
    QSqlQuery query;

    query.prepare("DELETE FROM LIVRAISON WHERE IDLIVRAISON = :id");
    query.bindValue(":id", code);  // Bind the integer directly

    return query.exec();
}


QSqlQueryModel* livraison::afficher() {
    QSqlTableModel* model = new QSqlTableModel();

    model->setTable("LIVRAISON");


    // Prepare and execute the query


    if (!model->select()) { }

        model->setEditStrategy(QSqlTableModel::OnFieldChange);
        // Set the headers
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("idliv"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}



QSqlQueryModel *livraison::recherche(QString i)
 {
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM LIVRAISON WHERE IDLIVRAISON LIKE '"+i+"%' OR NOM LIKE '"+i+"%' OR PRENOM LIKE '"+i+"%'");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idlivraison"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));

    //model->setHeaderData(12,Qt::Horizontal,QObject::tr("password"));

return model;
}


//tri
QSqlQueryModel *livraison::trier()
 {
     QSqlQuery * q = new  QSqlQuery ();
            QSqlQueryModel * model = new  QSqlQueryModel ();
            q->prepare("SELECT * FROM LIVRAISON ORDER BY IDLIVRAISON ASC");
            q->exec();
            model->setQuery(*q);
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("idliv"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));

            //model->setHeaderData(12,Qt::Horizontal,QObject::tr("password"));
            return model;
}
livraison* livraison::livraisonpdf(QString val)
{
 QSqlQuery query;
     query.prepare("Select * FROM livraison where IDLIVRAISON='"+val+"'");
        if(query.exec())
        {     while(query.next())
            {
             setIdLiv(query.value(0).toInt());
             setNom(query.value(1).toString());
              setPrenom(query.value(2).toString());
             setAdresse(query.value(5).toString());

            }
        }
     return this;
}

QMap<QString, int> livraison::obtenirStatistiques() {
    QMap<QString, int> stats;
    QSqlQuery query;
    query.prepare("SELECT adresse, COUNT(*) FROM livraison GROUP BY adresse");
    if (!query.exec()) {
        return stats;  // Retourner un map vide en cas d'erreur
    }

    while (query.next()) {
        QString adresse = query.value(0).toString();
        int count = query.value(1).toInt();
        stats.insert(adresse, count);
    }

    return stats;
}

