#ifndef STATISTIQUE_H
#define STATISTIQUE_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QChartView>

class Statistique : public QDialog
{
    Q_OBJECT
public:
    explicit Statistique(QWidget *parent = nullptr);
    void addChartView(QChartView *chartView);

private:
    QVBoxLayout *layout;  // Layout pour ajouter des éléments
};

#endif // STATISTIQUE_H
