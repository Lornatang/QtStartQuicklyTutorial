#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTranslator>

int main(int argc, char* argv[]) {
    QCoreApplication app(argc, argv);

    //    QTranslator translator;
    //    const QStringList uiLanguages = QLocale::system().uiLanguages();
    //    for (const QString& locale : uiLanguages) {
    //        const QString baseName = "SQL01_" + QLocale(locale).name();
    //        if (translator.load(":/i18n/" + baseName)) {
    //            app.installTranslator(&translator);
    //            break;
    //        }
    //    }

    //    qDebug() << "Available drivers:";
    //    QStringList drivers = QSqlDatabase::drivers();
    //    foreach (QString driver, drivers)
    //        qDebug() << driver;
    //    return app.exec();

    //添加数据库驱动
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库名称
    db.setDatabaseName(":memory:");
    //打开数据库
    if (!db.open()) {
        return -1;
    }

    //以下执行相关sql语句
    QSqlQuery query;

    //新建student表，id设置为主键，还有一个name项
    query.exec("create table student(id int primary key,name varchar)");

    //向表中插入3条记录
    query.exec("insert into student values(1,'xiaogang')");
    query.exec("insert into student values(2,'xiaoming')");
    query.exec("insert into student values(3,'xiaohong')");

    //查找表中id >=2 的记录的id项和name项的值
    query.exec("select id,name from student where id >= 2");

    // query.next()指向查找到的第一条记录，然后每次后移一条记录
    while (query.next()) {
        // query.value(0)是id的值，将其转换为int型
        int value0 = query.value(0).toInt();
        QString value1 = query.value(1).toString();
        //输出两个值
        qDebug() << value0 << value1;
    }

    return app.exec();
}
