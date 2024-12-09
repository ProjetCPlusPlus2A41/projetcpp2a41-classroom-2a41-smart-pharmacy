#ifndef CLIENT_H
#define CLIENT_H

#include "connection.h"
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QDate>

class client
{
private:
    int ID_CL;
    QString NOM_CL;
    QString PRENOM_CL;
    int TEL_CL;
    QString ADRESSE_CL;
    QString GENDER;
    int AGE;
    QString EMAIL;
    QByteArray IMAGE; // type: blob
    QDate DATE_REG; // type: date

public:
    client();
    client(int ID_CL, QString NOM_CL, QString PRENOM_CL, int TEL_CL, QString ADRESSE_CL, QString GENDER, int AGE, QString EMAIL, QByteArray IMAGE, QDate DATE_REG)
    {
        this->ID_CL = ID_CL;
        this->NOM_CL = NOM_CL;
        this->PRENOM_CL = PRENOM_CL;
        this->TEL_CL = TEL_CL;
        this->ADRESSE_CL = ADRESSE_CL;
        this->GENDER = GENDER;
        this->AGE = AGE;
        this->EMAIL = EMAIL;
        this->IMAGE = IMAGE;
        this->DATE_REG = DATE_REG;
    }

    // Setters
    void setID_CL(int id_cl) { ID_CL = id_cl; }
    void setNom(QString nom) { NOM_CL = nom; }
    void setPrenom(QString prenom) { PRENOM_CL = prenom; }
    void setTel(int tel) { TEL_CL = tel; }
    void setAdresse(QString adresse) { ADRESSE_CL = adresse; }
    void setGender(QString gender) { GENDER = gender; }
    void setAge(int age) { AGE = age; }
    void setEmail(QString email) { EMAIL = email; }
    void setImage(QByteArray image) { IMAGE = image; }
    void setDateReg(QDate date_reg) { DATE_REG = date_reg; }

    // Getters
    int getID_CL() { return ID_CL; }
    QString getNom() { return NOM_CL; }
    QString getPrenom() { return PRENOM_CL; }
    int getTel() { return TEL_CL; }
    QString getAdresse() { return ADRESSE_CL; }
    QString getGender() { return GENDER; }
    int getAge() { return AGE; }
    QString getEmail() { return EMAIL; }
    QByteArray getImage() { return IMAGE; }
    QDate getDateReg() { return DATE_REG; }

    bool Ajouterclient();
    QSqlQueryModel* Afficherclients();
    bool Modifierclient();
    bool Supprimerclient(const QString &ID_CL);
    bool Supprimerclients();
    QSqlQueryModel *Rechercherclient(const QString &text);
};

#endif // CLIENT_H
