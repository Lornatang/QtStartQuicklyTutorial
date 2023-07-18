#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlQuery>

static bool createConnection() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");
    if (!db.open())
        return false;
    QSqlQuery query;
    query.exec(QString("create table student (id int primary key, name vchar)"));
    query.exec(QString("insert into student values (0,'刘明')"));
    query.exec(QString("insert into student values (1,'陈刚')"));
    query.exec(QString("insert into student values (2,'王红')"));
    return true;
}
#endif  // CONNECTION_H
