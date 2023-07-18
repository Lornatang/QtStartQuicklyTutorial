#include "startitem.h"

StartItem::StartItem() { pix.load("../GraphicsView01/resources/flashitem_images/start.jpg"); }
QRectF StartItem::boundingRect() const {
    return QRectF(-pix.width() / 2, -pix.height() / 2, pix.width(), pix.height());
}
void StartItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    painter->drawPixmap(boundingRect().topLeft(), pix);
}
