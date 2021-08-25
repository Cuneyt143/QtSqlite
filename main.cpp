#include <QCoreApplication>
#include <QString>
#include <QtSql>
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QModelIndex>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlDriver>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("D:/Program Files/DB.Browser.for.SQLite-3.12.2-win64/DB Browser for SQLite/database/vay.db");

    if(!db.open())
    {
        qDebug() << ("Failed to open the database.");
    }
    else
    {
        qDebug() << ("Connected..");
    }

    //QSqlQuery query;
    /*QSqlQuery query("CREATE TABLE people (id INTEGER PRIMARY KEY, name TEXT)");  Tablo oluşturur

    if(!query.isActive())
    {
        qWarning() << "ERROR:" << query.lastError().text();
    }*/



    /*
    QString isim = "şila";
    query.prepare("INSERT INTO people(name)" "VALUES(:name)");
    query.bindValue(":name", isim);
    query.exec();
    */


    QSqlTableModel model;
    model.setTable("people");
    model.setFilter("id = 1");
    model.setSort(2, Qt::DescendingOrder);
    model.select();

    for( int i = 0; i < model.rowCount(); i++)
    {
        QString isim = model.record(i).value("name").toString();
        qDebug() << isim;


    }




    //query.prepare("SELECT name FROM people WHERE id = 0");   //çalışmadı
    //query.addBindValue(mInputText->text().toInt());

    //QSqlQueryModel model;
    //model.setQuery("SELECT * FROM Missions");
/*
    for(int i = 0; i < model.rowCount(); ++i) {
        int id = model.record(i).value("id").toInt();
        QString name = model.record(i).value("Mission Name").toString();
        qDebug() << id << name;
    }*/

    //model.setData(model.index(2, 1), 75000);
    //model.submit();
    return a.exec();
}
