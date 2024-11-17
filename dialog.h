#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
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

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void createBarChart();
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
