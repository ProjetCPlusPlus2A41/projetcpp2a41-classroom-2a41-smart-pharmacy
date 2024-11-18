#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fournisseur.h"
#include <QMessageBox>
#include <QTableView>
#include "qr_code.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Add_button_clicked();

    void on_Delete_buton_clicked();

    void on_Update_button_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_chercher_Fournisseur_textChanged(const QString &arg1);

    void on_radioButton_ID_clicked();

    void on_radioButton_Nom_clicked();

    void on_radioButton_Adresse_clicked();

    void on_radioButton_Prix_clicked();

    void on_PDF_clicked();

    void on_HIS_clicked();

   void on_stats_clicked();

   void on_PDF_2_clicked();

   void on_QR_button_clicked();

   private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    Fournisseur Fm;
     QString extractDataFromTable(QTableView* tableView); // Fonction pour extraire les données d'une QTableView
};
#endif // MAINWINDOW_H
