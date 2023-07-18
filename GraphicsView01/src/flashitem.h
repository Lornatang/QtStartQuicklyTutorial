#ifndef FLASHITEM_H
#define FLASHITEM_H

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QTimer>

class FlashItem : public QObject, public QGraphicsItem {
    Q_OBJECT
  public:
    explicit FlashItem(QObject* parent = 0);
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = nullptr);
    void timerEvent(QTimerEvent* event);

  private:
    bool flash;
    QTimer* timer;
};
#endif  // FLASHITEM_H
