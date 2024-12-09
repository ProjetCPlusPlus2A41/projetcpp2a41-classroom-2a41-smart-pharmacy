#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "livraison.h"
#include <QVariant>
#include <QtCore>
#include <QtGui>
#include <QtQuick>
#include "arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterbutton_clicked();

    void on_delete_2_clicked();

    void on_recherche_clicked();



    void readFromArduino() ;

    void on_trier_clicked();

    void on_pushButton_clicked();

    void on_email_clicked();

    void on_stat_clicked();

    void on_quitter_clicked();

private:
    Ui::MainWindow *ui;
    livraison liv ;
    arduino A;
signals:
    void setCenterPosition(QVariant, QVariant );
    void setLocationMarking_1(QVariant, QVariant );
     void setLocationMarking_2(QVariant, QVariant );
};

#endif // MAINWINDOW_H
