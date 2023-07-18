#ifndef BUTTERFLY_H
#define BUTTERFLY_H

#include <math.h>

#include <QApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QPainter>

const static double PI = 3.1416;

class Butterfly : public QObject, public QGraphicsItem {
    Q_OBJECT
  public:
    // 关键字explicit用于防止类构造函数的隐式自动转换
    // Qt类的构造函数都会有一个parent参数, 默认初始值为0
    explicit Butterfly(QObject* parent = nullptr);

    // 定时器实现动画的原理是在定时器的timerEvent()中对QGraphicsItem进行重绘
    void timerEvent(QTimerEvent* event);

    // 为图元限定区域范围，所有继承自QGraphicsItem的自定义图元都必须实现此函数
    QRectF boundingRect() const;

  signals:
  public slots:

  protected:
    // 重绘函数
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);

  private:
    bool fly_uping;  // 表示蝴蝶正在向上飞, 设置为true表示正在向上飞，false则表示正在向下飞
    QPixmap fly_up;  // 表示蝴蝶向上飞
    QPixmap fly_down;  // 表示蝴蝶向下飞
    qreal angle;       // 浮点数
};

#endif  // BUTTERFLY_H
