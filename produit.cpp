#include "produit.h"

// Constructors
produit::produit() {}

produit::produit(int idProduit) {
    this->idProduit = idProduit;
}

produit::produit (QString Nom, float prixUnitaire, int qty,QDate Date,QString form) {
    this->Nom = Nom;
    this->prixUnitaire = prixUnitaire;
    this->qty = qty;
    this->date = Date ;
    this->form = form ;
}

// Getters
int produit::getIdProduit() const{
    return this->idProduit;
}

int produit::getQty()const {
    return this->qty;
}

QString produit::getNom()const {
    return this->Nom;
}

float produit::getPrixUnitaire()const {
    return this->prixUnitaire;
}

// Setters
void produit::setIdproduit(int id) {
    this->idProduit = id;
}

void produit::setQty(int quantity) {
    this->qty = quantity;
}

void produit::setNom(QString name) {
    this->Nom = name;
}

void produit::setPrixUnitaire(float prix) {
    this->prixUnitaire = prix;
}

bool produit::ajouter() {
    QSqlQuery query;

    // Convert numeric fields to QString
    QString prixUnitaireConvertir = QString::number(prixUnitaire, 'f', 2);
    QString qtyConvertit = QString::number(qty);

    // Convert the date to a string format compatible with TO_DATE
    QString dateString = date.toString("dd-MM-yyyy");

    // Corrected SQL query with proper VALUES placement
    query.prepare("INSERT INTO PRODUITS (IDPRODUIT, NOM, PRIXUNITAIRE, QTY, DATEDEXPIRATION, FORMEPHARMACEUTIQUE) "
                  "VALUES (IDPRODUIT.NEXTVAL, :Nom, :prixUnitaire, :qty, TO_DATE(:date, 'DD-MM-YYYY'), :form)");

    // Binding values
    query.bindValue(":Nom", Nom);
    query.bindValue(":prixUnitaire", prixUnitaireConvertir);
    query.bindValue(":qty", qtyConvertit);
    query.bindValue(":date", dateString);
    query.bindValue(":form", form);

    return query.exec();
}




bool produit::supprimer(int code) {
    QSqlQuery query;

    query.prepare("DELETE FROM PRODUITS WHERE IDPRODUIT = :id");
    query.bindValue(":id", code);  // Bind the integer directly

    return query.exec();
}


QSqlTableModel* produit::afficher() {
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("PRODUITS");
    model->setEditStrategy(QSqlTableModel::OnFieldChange); // Met à jour la base de données à chaque modification de cellule
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idProduit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prixUnitaire"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("qte"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
    return model;
}
bool produit::search(QString nom) {
    QSqlQuery query;
    query.prepare("SELECT * FROM PRODUITS WHERE NOM = :nom");
    query.bindValue(":nom", nom);

    if (query.exec()) {
        return query.next(); // Returns true if a result is found, false otherwise
    } else {
        return false; // Returns false if the query execution failed
    }
}

bool produit::SetReadProduct(int idProduit)const{
    QSqlQuery query;
    query.prepare("UPDATE PRODUITS SET READ= :read WHERE IDPRODUIT = :idProduit");
    query.bindValue(":idProduit", idProduit);
    query.bindValue(":read", 1);
    return query.exec();
}
void produit::setDateExpiration(QDate dateExpiration){
    this->date = dateExpiration;
}
std::vector<produit> produit::getExpiredProducts(){

    std::vector<produit> produitsExpire;
    QSqlQuery query;
    query.prepare("SELECT IDPRODUIT,NOM,QTY,DATEDEXPIRATION FROM PRODUITS WHERE DATEDEXPIRATION <= CURRENT_DATE AND READ = 0");
    if(query.exec()){
        while(query.next()){
            produit p;
            p.setIdproduit(query.value(0).toInt());
            p.setQty(query.value(2).toInt());
            p.setNom(query.value(1).toString());
            p.setDateExpiration(query.value(3).toDate());
            produitsExpire.push_back(p);
        }

    }
    return produitsExpire;
}
QDate produit::getDateExpiration()const{
    return this->date;
}
