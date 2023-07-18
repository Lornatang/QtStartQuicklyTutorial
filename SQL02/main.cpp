#include <QApplication>

#include "connection.h"
#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    if (!createConnection())
        return 1;

    MainWindow w;
    w.show();

    return app.exec();
}
