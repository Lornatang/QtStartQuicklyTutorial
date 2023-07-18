#include "mainwindow.h"

#include "./ui_mainwindow.h"
#include "connection.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {
    //    QSqlQuery query;
    //    query.exec("select * from student");
    //    qDebug() << "exec next() :";
    //    // 开始就先执行一次next()函数，那么query指向结果集的第一条记录
    //    if (query.next()) {
    //        // 获取query所指向的记录在结果集中的编号
    //        int rowNum = query.at();
    //        // 获取每条记录中属性（即列）的个数
    //        int columnNum = query.record().count();
    //        // 获取"name"属性所在列的编号，列从左向右编号，最左边的编号为0
    //        int fieldNo = query.record().indexOf("name");
    //        // 获取id属性的值，并转换为int型
    //        int id = query.value(0).toInt();
    //        // 获取name属性的值
    //        QString name = query.value(fieldNo).toString();
    //        // 将结果输出
    //        qDebug() << "rowNum is : " << rowNum << " id is : " << id << " name is : " << name
    //                 << " columnNum is : " << columnNum;
    //    }
    //    // 定位到结果集中编号为2的记录，即第三条记录，因为第一条记录的编号为0
    //    qDebug() << "exec seek(2) :";
    //    if (query.seek(2)) {
    //        qDebug() << "rowNum is : " << query.at() << " id is : " << query.value(0).toInt()
    //                 << " name is : " << query.value(1).toString();
    //    }
    //    // 定位到结果集中最后一条记录
    //    qDebug() << "exec last() :";
    //    if (query.last()) {
    //        qDebug() << "rowNum is : " << query.at() << " id is : " << query.value(0).toInt()
    //                 << " name is : " << query.value(1).toString();
    //    }
    QSqlQuery query;
    int id = ui->spinBox->value();
    query.exec(QString("select name from student where id =%1").arg(id));
    query.next();
    QString name = query.value(0).toString();
    qDebug() << name;
}
