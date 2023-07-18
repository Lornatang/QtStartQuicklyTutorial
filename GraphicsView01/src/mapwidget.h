#ifndef MAPWIDGET_H
#define MAPWIDGET_H

#include <math.h>

#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGridLayout>
#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QObject>
#include <QSlider>
#include <QTextStream>

class MapWidget : public QGraphicsView {
    Q_OBJECT
  public:
    MapWidget();

    void readMap();
    // 用于实现场景坐标系与地图坐标之间的映射，以获得某点的经纬度值。
    QPointF mapToMap(QPointF);

  public slots:
    void slotZoom(int);

  private:
    QPixmap map;
    qreal zoom;
    QLabel* viewCoord;
    QLabel* sceneCoord;
    QLabel* mapCoord;
    double x1, y1;
    double x2, y2;

  protected:
    // 完成地图显示功能
    void drawBackground(QPainter* painter, const QRectF& rect);
    void mouseMoveEvent(QMouseEvent* event);
};

#endif  // MAPWIDGET_H
