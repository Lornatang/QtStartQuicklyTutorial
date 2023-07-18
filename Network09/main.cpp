#include <QApplication>

#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    QWebEngineView view;
    view.load(QUrl("http://www.qter.org"));
    view.show();
    return a.exec();
}
