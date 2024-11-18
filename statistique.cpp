#include "statistique.h"
#include <QChartView>
#include <QVBoxLayout>

Statistique::Statistique(QWidget *parent)
    : QDialog(parent)
{
    // Création d'un layout pour la fenêtre
    layout = new QVBoxLayout(this);
    setLayout(layout);
    setWindowTitle("Statistiques des Fournisseurs");
    resize(800, 600);  // Ajustez la taille de la fenêtre selon votre besoin
}

void Statistique::addChartView(QChartView *chartView)
{
    layout->addWidget(chartView);  // Ajoute le graphique au layout de la fenêtre
}
