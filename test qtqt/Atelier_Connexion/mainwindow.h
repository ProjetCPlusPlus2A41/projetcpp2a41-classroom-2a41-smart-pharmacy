#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QMessageBox>
#include "arduino.h"
class client;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();
    void on_tableView_activated(const QModelIndex &index);
    void on_modifier_clicked();

    void navigateToPage(int pageIndex);
    void exportToPDF();
    void exportToExcel();
    void Rechercherclient(const QString &text);
    void on_sortComboBox_currentIndexChanged(int index);
    void displayCharts_clientByGender();
    void on_gostat_clicked();
    void on_gostat2_clicked();
    void on_browse_clicked();
    void on_calendarWidget_clicked(const QDate &date);
    void updateCalendarAndEventDetails(const QDate &date);
    void on_gocal1_clicked();
    void on_gocal2_clicked();
    void on_gocal3_clicked();
    void readFromArduino() ;


private:
    Ui::MainWindow *ui;
    QByteArray imagesByteArray;
    QString imagePath;
    arduino A;
};

#endif // MAINWINDOW_H