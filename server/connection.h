#ifndef CONNECTION_H
#define CONNECTION_H
#include <QTime>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRelation>

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("pokedata.db");
    if (!db.open()) {
        QMessageBox::critical(0, "Cannot open pokedata",
            "Unable to establish a pokedata connection.", QMessageBox::Cancel);
        return false;
    }
    QSqlQuery query(db);
    query.exec("create table pokedata (username String primary key, "
               "password String, rate int, primarypoke int, seniorpoke int, win int, fail int)");
    //query.exec("insert into pokedata values('admin', '123456', 0, 3, 0)");
    //query.exec("insert into pokedata values('wzp', '8799', 0, 3, 0)");
    query.exec("create table pokemondata(username String ,"
               "pokename String,  pokelevel int, pokeexp int, pokeskill1 int, pokeskill2 int, pokeskill3 int,id int)");
    return true;
}

static QString randomCreate(){
    int pokea=qrand()%3 + 1;
    switch(pokea){
        case 1:
            return "Bulbasaur";
        case 2:
            return "Charmander";
        case 3:
            return "Squirtle";
        default:
            return "0";
    }
}

#endif // CONNECTION_H
