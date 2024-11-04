#ifndef CLIENT_H
#define CLIENT_H

#include "connection.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class client
{
private:
    int CIN;
    QString NOM_CL;
    QString PRENOM_CL;
    int TEL_CL;
    QString ADRESSE_CL;
    QString GENDER;
    int AGE;
    QString EMAIL;

public:
    client();
    client(int CIN, QString NOM_CL, QString PRENOM_CL, int TEL_CL, QString ADRESSE_CL, QString GENDER, int AGE, QString EMAIL)
    {
        this->CIN = CIN;
        this->NOM_CL = NOM_CL;
        this->PRENOM_CL = PRENOM_CL;
        this->TEL_CL = TEL_CL;
        this->ADRESSE_CL = ADRESSE_CL;
        this->GENDER = GENDER;
        this->AGE = AGE;
        this->EMAIL = EMAIL;
    }

    // Setters
    void setCIN(int cin) { CIN = cin; }
    void setNom(QString nom) { NOM_CL = nom; }
    void setPrenom(QString prenom) { PRENOM_CL = prenom; }
    void setTel(int tel) { TEL_CL = tel; }
    void setAdresse(QString adresse) { ADRESSE_CL = adresse; }
    void setGender(QString gender) { GENDER = gender; }
    void setAge(int age) { AGE = age; }
    void setEmail(QString email) { EMAIL = email; }

    // Getters
    int getCIN() { return CIN; }
    QString getNom() { return NOM_CL; }
    QString getPrenom() { return PRENOM_CL; }
    int getTel() { return TEL_CL; }
    QString getAdresse() { return ADRESSE_CL; }
    QString getGender() { return GENDER; }
    int getAge() { return AGE; }
    QString getEmail() { return EMAIL; }

    bool Ajouterclient();
    QSqlQueryModel* Afficherclients();
    bool Modifierclient();
    bool Supprimerclient(const QString &CIN);
    bool Supprimerclients();
    QSqlQueryModel *Rechercherclient(const QString &text);

};

#endif // CLIENT_H
