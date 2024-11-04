/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H*/
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "fournisseur.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void on_pushButtonAjout_clicked();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonsupprimer_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQueryModel *model;
    Fournisseur Fm;

    bool connectToDatabase();
    void loadFournisseurs();
};

#endif // MAINWINDOW_H
