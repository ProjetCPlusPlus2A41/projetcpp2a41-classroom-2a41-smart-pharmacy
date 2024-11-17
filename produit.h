#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlTableModel>
#include <QDate>
#include <QSqlError>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlRecord>
#include <QFileDialog>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtCharts>
class produit
{
public:
    produit();
    produit(int);
    produit(QString,float,int,QDate,QString);
    int getIdProduit()const;
    int getQty()const;
    QString getNom()const;
    float getPrixUnitaire()const;
    void setIdproduit(int);
    void setQty(int);
    void setNom(QString);
    void setPrixUnitaire(float);
    void setDateExpiration(QDate);
    QDate getDateExpiration()const;

    //fonction de base
    bool ajouter();
    QSqlTableModel * afficher();
    bool supprimer(int);
    bool search(QString);
    bool sort(int);
    std::vector<produit> getExpiredProducts();
    bool SetReadProduct(int)const;
private:
    int idProduit;
    unsigned int qty;
    QString Nom;
    float prixUnitaire;
    QDate date ;
    QString form ;



};

#endif // PRODUIT_H
