#ifndef FENETREHISTORIQUE_H
#define FENETREHISTORIQUE_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class FenetreHistorique : public QDialog
{
    Q_OBJECT

public:
    explicit FenetreHistorique(const QString &productNames, QWidget *parent = nullptr);

private:
    QLabel *label;
};

#endif // FENETREHISTORIQUE_H
