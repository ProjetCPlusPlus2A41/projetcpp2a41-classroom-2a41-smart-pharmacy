#include "FenetreHistorique.h"

FenetreHistorique::FenetreHistorique(const QString &productNames, QWidget *parent)
    : QDialog(parent)
{
    // Création de l'interface de la fenêtre
    label = new QLabel(productNames, this);  // Afficher le NOMP (nom produit)
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);

    setLayout(layout);
    setWindowTitle("Historique des Produits");
    resize(300, 200);  // Ajustez la taille de la fenêtre selon votre besoin
}
