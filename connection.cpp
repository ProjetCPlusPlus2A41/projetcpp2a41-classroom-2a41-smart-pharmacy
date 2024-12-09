#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Project2A");//inserer le nom de la source de données // Project2A
db.setUserName("ghofrane");//inserer nom de l'utilisateur //ghofrane
db.setPassword("1234");//inserer mot de passe de cet utilisateur //1234

if (db.open())
test=true;





    return  test;
}
