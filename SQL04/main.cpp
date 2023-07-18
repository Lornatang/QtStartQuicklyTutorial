#include <QApplication>

#include "connection.h"
#include "mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString& locale : uiLanguages) {
        const QString baseName = "SQL04_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    if (!createConnection()) {
        return 1;
    }

    MainWindow w;
    w.show();
    return a.exec();
}
