#ifndef LIVRAISON_H
#define LIVRAISON_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>

class livraison
{
public:
    // Default constructor
    livraison();

    // Parameterized constructor
    livraison(QString adresse, QString nom, QString prenom);

    // Setters
    void setIdLiv(int id) { idliv = id; }
    void setAdresse(QString adresse) { Adresse = adresse; }
    void setNom(QString n) { nom = n; }
    void setPrenom(QString p) { prenom = p; }


    // Getters
    int getIdLiv() const { return idliv; }
    QString getAdresse() const { return Adresse; }
    QString getNom() const { return nom; }
    QString getPrenom() const { return prenom; }
    //METHODE
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int code);
    bool updater();
    QSqlQueryModel *recherche(QString);
    QSqlQueryModel *trier();
    livraison* livraisonpdf(QString);

    // stat
    QMap<QString, int> obtenirStatistiques();



private:
    int idliv;
    QString Adresse;
    QString nom;
    QString prenom;
};

#endif // LIVRAISON_H
