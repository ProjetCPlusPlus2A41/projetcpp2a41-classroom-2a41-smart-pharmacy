#ifndef GESTIONPRODUIT_H
#define GESTIONPRODUIT_H

#include <QMessageBox>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QComboBox>
#include <QTableView>
#include <QDebug>
#include <QAxObject>
#include <QFileDialog>
#include <QFontMetrics>
#include <QHeaderView>
#include <QPageSize>
#include <QSqlTableModel>
#include <QFont>
#include <QPdfWriter>
#include <QPainter>

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QtCharts>
#include "produit.h"
namespace Ui {
class GestionProduit;
}

class GestionProduit : public QDialog
{
    Q_OBJECT

public:
    explicit GestionProduit(QWidget *parent = nullptr);

    ~GestionProduit();

private slots:
    void on_Add_button_2_clicked();

    void on_delete_button_2_clicked();

    void on_lineEdit_13_textChanged(const QString &search);

    void trierTableView(int index);
    void exporterEnPDF();
    void exporterEnExcel();
    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::GestionProduit *ui;
    produit p ;
    int MAJProduitEpirer();
    int nombreProduitExpirer = MAJProduitEpirer();
    int timerId;
    void timerEvent(QTimerEvent *event);
    //QSqlTableModel *model;
};

#endif // GESTIONPRODUIT_H
