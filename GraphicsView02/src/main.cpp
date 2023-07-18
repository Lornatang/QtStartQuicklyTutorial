#include <QApplication>

#include "mainwidget.h"

int main(int argc, char *argv[]) {
    // 管理图形用户界面应用程序的控制流和主要设置
    QApplication app(argc, argv);
    // 窗体程序的入口函数
    MainWidget window;
    // 显示窗体程序
    window.show();
    // 执行QT程序
    return app.exec();
}
