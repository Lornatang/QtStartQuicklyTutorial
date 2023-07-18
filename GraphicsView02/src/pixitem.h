#ifndef PIXITEM_H
#define PIXITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class PixItem : public QGraphicsItem {
public:
    // 图元函数
    PixItem(QPixmap *pixmap);

    // 轮廓的垂直边界最小矩形
    QRectF boundingRect() const;

    // 重绘图像，例如调用了图像旋转函数就需要重新绘制一次图像
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    // 作为图元显示的图片
    QPixmap pix;
};

#endif  // PIXITEM_H
