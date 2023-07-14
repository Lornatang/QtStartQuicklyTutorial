#ifndef WIDGET_H
#define WIDGET_H

#include <QDateTime>
#include <QTimer>
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

  private slots:
    void timerUpdate();

  private:
    Ui::Widget* ui;
    int id1, id2, id3;

  protected:
    void timerEvent(QTimerEvent*);
};
#endif  // WIDGET_H
