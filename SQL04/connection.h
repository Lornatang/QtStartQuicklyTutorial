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
    query.exec("create table student (id int primary key, name vchar,course int)");
    query.exec("insert into student values(1,'lcy0',1)");
    query.exec("insert into student values(2,'lcy1',1)");
    query.exec("insert into student values(3,'lcy2',2)");

    query.exec("create table course (id int primarykey, name vchar, teacher vchar)");
    query.exec("insert into course values(1,'Math','lcylinux1')");
    query.exec("insert into course values(2,'English','lcylinux2')");
    query.exec("insert into course values(3,'Computer','lcylinux3')");
    return true;
}
#endif  // CONNECTION_H
