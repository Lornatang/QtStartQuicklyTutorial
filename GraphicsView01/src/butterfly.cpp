#include "butterfly.h"

Butterfly::Butterfly(QObject* parent) : QObject(parent) {
    // 标记蝴蝶翅膀位置的变量赋初值
    fly_uping = true;
    fly_up.load("../GraphicsView01/resources/butterfly_images/fly_up.jpg");
    fly_down.load("../GraphicsView01/resources/butterfly_images/fly_down.jpg");
    startTimer(100);
}

QRectF Butterfly::boundingRect() const {
    qreal adjust = 2.f;
    // QRectF传入[ qreal left, qreal top, qreal width, qreal height ]
    return QRectF(-fly_up.width() / 2 - adjust, -fly_up.height() / 2 - adjust, fly_up.width() + adjust * 2,
                  fly_up.height() + adjust * 2);
}

void Butterfly::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    if (fly_uping) {
        // drawPixmap传入[ QPointF(xp, yp)，图片 ]
        painter->drawPixmap(boundingRect().topLeft(), fly_up);
        fly_uping = !fly_uping;
    } else {
        painter->drawPixmap(boundingRect().topLeft(), fly_down);
        fly_uping = !fly_uping;
    }
}

void Butterfly::timerEvent(QTimerEvent* event) {
    // 边界控制
    qreal edge_right = scene()->sceneRect().right() + boundingRect().width() / 2;     // 限定蝴蝶飞舞的右边界
    qreal edge_top = scene()->sceneRect().top() + boundingRect().height() / 2;        // 限定蝴蝶飞舞的上边界
    qreal edge_bottom = scene()->sceneRect().bottom() + boundingRect().height() / 2;  // 限定蝴蝶飞舞的下边界

    // 超过右边界，水平回到最左边
    if (pos().x() >= edge_right)
        setPos(scene()->sceneRect().left(), pos().y());
    // 超过上边界，回到底边
    if (pos().y() <= edge_top)
        setPos(pos().x(), scene()->sceneRect().bottom());
    // 超过底边，回到上边界
    if (pos().y() >= edge_bottom)
        setPos(pos().x(), scene()->sceneRect().top());

    angle += (qrand() % 10) / 20.0;
    qreal dx = fabs(sin(angle * PI) * 10.0);
    qreal dy = fabs(qrand() % 20) - 10.0;

    // setPos传入 [ qreal ax, qreal ay ]
    // mapToParent传入 [ qreal ax, qreal ay ]
    setPos(mapToParent(dx, dy));
}
