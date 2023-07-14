#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::mousePressEvent(QMouseEvent* e) {
    QString mouseText = "(%1,%2)";
    ui->pushButton->setText(mouseText.arg(e->x(), (e->y())));
}

void MainWindow::keyPressEvent(QKeyEvent* e) {
    int x = ui->pushButton->x();
    int y = ui->pushButton->y();
    switch (e->key()) {
        case Qt::Key_W: ui->pushButton->move(x, y - 10); break;
        case Qt::Key_S: ui->pushButton->move(x, y + 10); break;
        case Qt::Key_A: ui->pushButton->move(x - 10, y); break;
        case Qt::Key_D: ui->pushButton->move(x + 10, y); break;
    }
}
