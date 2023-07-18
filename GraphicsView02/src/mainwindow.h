#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    // QObject是Qt 对象模型机制的核心类
    Q_OBJECT

public:
    // 构造函数，默认给QWidget赋值为空
    MainWindow(QWidget *parent = nullptr);

    // 析构函数，用于销毁类
    ~MainWindow();

private:
    // 定义UI界面
    Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
