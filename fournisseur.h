#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include<QSqlQueryModel>
#include <QSqlQuery>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int, int, int, QString, QString, QString, QString);
    Fournisseur(int, int, QString, QString, QString, QString);

    //getters
    int get_id_Forni();
    int get_prixProd();
    int get_nbrAchat();
    int get_tel();
    QString get_nom();
    QString get_adresseForni();
    QString get_email();
    QString get_recus();

    //setters
    void set_id_Forni(int);
    void set_prixProd(int);
    void set_nbrAchat(int);
    void set_tel(int);
    void set_nom(QString);
    void set_adresseForni(QString);
    void set_email(QString);
    void set_recus(QString);

    //CRUD
    bool ajouter_Fournisseur();
    QSqlQueryModel* afficher_Fournisseur();
    bool modifier_Fournisseur(int);
    bool supprimer_Fournisseur(int);
    bool idExists(int id);

private:
    int id_Forni, prixProd, tel;
    QString nom, adresseForni, email, recus;
};

#endif // FOURNISSEUR_H
