#include "flashitem.h"

FlashItem::FlashItem(QObject* parent) {
    flash = true;  //为颜色切换标识。
    setFlag(ItemIsMovable);
    startTimer(1000);  //启动定时器
}
QRectF FlashItem::boundingRect() const {
    qreal adjust = 2;
    return QRectF(-10 - adjust, -10 - adjust, 43 + adjust, 43 + adjust);
}
void FlashItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);  //深灰色
    painter->drawEllipse(-7, -7, 40, 40);
    painter->setPen(QPen(Qt::black, 0));
    //闪烁区边线为黑色
    painter->setBrush(flash ? (Qt::red) : (Qt::yellow));
    painter->drawEllipse(-10, -10, 40, 40);
}
void FlashItem::timerEvent(QTimerEvent* event) {
    flash = !flash;
    update();
}
