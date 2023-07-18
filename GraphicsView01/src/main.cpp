#include <QApplication>

#include "butterfly.h"
#include "mainwindow.h"
#include "mapwidget.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // 会飞蝴蝶中主函数流程为: 1.先创建场景
    //                     2.设置场景大小
    //                     3.设置元素初始化坐标
    //                     4.将元素加入场景当中
    //                     5.创建视图
    //                     6.在视图中加入场景
    //                     7.拉伸视图大小
    //                     8.展示视图

    QGraphicsScene* scene = new QGraphicsScene;
    // setSceneRect(-width/2,-height/2,width,height)
    scene->setSceneRect(QRectF(-200, 200, 400, 400));

    Butterfly* butterfly = new Butterfly;
    butterfly->setPos(-200, 0);               // 起始坐标设置为-100,0
    scene->addItem(butterfly);                // 将蝴蝶这个元素加入场景当中
    QGraphicsView* view = new QGraphicsView;  // 新建一个视图
    view->setScene(scene);                    // 在视图中设置场景
    view->resize(400, 400);                   // 拉伸视图
    view->show();                             // 显示视图
    return app.exec();

    //    QFont font("ARPL KaitiM GB", 12);
    //    font.setBold(true);
    //    app.setFont(font);
    //    MapWidget mapWidget;
    //    mapWidget.show();
    //    return app.exec();

    //    MainWindow w;
    //    w.show();
    //    return app.exec();
}
