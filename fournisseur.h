#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDesktopServices>
#include <QtCharts/QChartView>

class Fournisseur
{
public:
    Fournisseur();
    Fournisseur(int, int, QString, QString, QString, QString);
    Fournisseur(int, QString, QString, QString, QString);

    // Getters
    int get_id_Forni();
    int get_prixProd();
    QString get_tel();
    QString get_nom();
    QString get_adresseForni();
    QString get_email();

    // Setters
    void set_id_Forni(int);
    void set_prixProd(int);
    void set_tel(QString);
    void set_nom(QString);
    void set_adresseForni(QString);
    void set_email(QString);

    // CRUD
    bool ajouter_Fournisseur();
    QSqlQueryModel* afficher_Fournisseur();
    bool modifier_Fournisseur(int);
    bool supprimer_Fournisseur(int);
    bool idExists(int id);

    // Fonction
    QSqlQueryModel * recherche_Fournisseur(QString);
    QSqlQueryModel * Trier_Fournisseur(QString);

    // Fonction statistique
    QChartView * statistiquesParPrix();

private:
    int id_Forni, prixProd;
    QString tel;
    QString nom, adresseForni, email;
};

#endif // FOURNISSEUR_H
