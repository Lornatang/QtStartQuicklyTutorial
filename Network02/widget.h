#ifndef WIDGET_H
#define WIDGET_H

#include <QCoreApplication>
#include <QDebug>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QTextCodec>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget {
    Q_OBJECT

  public:
    Widget(QWidget* parent = nullptr);
    ~Widget();

  private:
    Ui::Widget* ui;

  private slots:
    void lookedUp(const QHostInfo& host);
};
#endif  // WIDGET_H
