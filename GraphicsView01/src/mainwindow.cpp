#include "mainwindow.h"

#include <QGraphicsItemAnimation>
#include <QList>
#include <QTimeLine>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    // 创建主窗体的所有动作
    createActions();
    // 创建主窗体的菜单栏
    createMenus();
    scene = new QGraphicsScene;
    scene->setSceneRect(-200, -200, 400, 400);
    // 初始化场景
    initScene();
    QGraphicsView* view = new QGraphicsView;
    view->setScene(scene);
    view->setMinimumSize(400, 400);
    view->show();
    setCentralWidget(view);
    resize(550, 450);
    setWindowTitle(tr("Graphics Items"));
}
MainWindow::~MainWindow() {}
void MainWindow::createActions() {
    // 创建主窗体的所有动作
    newAct = new QAction(tr("新建"), this);
    clearAct = new QAction(tr("清除"), this);
    exitAct = new QAction(tr("退出"), this);
    addEllipseItemAct = new QAction(tr("加入 椭圆"), this);
    addPolygonItemAct = new QAction(tr("加入 多边形"), this);
    addTextItemAct = new QAction(tr("加入 文字"), this);
    addRectItemAct = new QAction(tr("加入 长方形"), this);
    addAlphaItemAct = new QAction(tr("加入 图片"), this);
    connect(newAct, SIGNAL(triggered()), this, SLOT(slotNew()));
    connect(clearAct, SIGNAL(triggered()), this, SLOT(slotClear()));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(addEllipseItemAct, SIGNAL(triggered()), this, SLOT(slotAddEllipseItem()));
    connect(addPolygonItemAct, SIGNAL(triggered()), this, SLOT(slotAddPolygonItem()));
    connect(addTextItemAct, SIGNAL(triggered()), this, SLOT(slotAddTextItem()));
    connect(addRectItemAct, SIGNAL(triggered()), this, SLOT(slotAddRectItem()));
    connect(addAlphaItemAct, SIGNAL(triggered()), this, SLOT(slotAddAlphaItem()));
    addFlashItemAct = new QAction(tr("加入闪烁圆"), this);
    connect(addFlashItemAct, SIGNAL(triggered()), this, SLOT(slotAddFlashItem()));
    addAnimItemAct = new QAction(tr("加入 移动星星"), this);
    connect(addAnimItemAct, SIGNAL(triggered()), this, SLOT(slotAddAnimationItem()));
}
void MainWindow::createMenus() {
    QMenu* fileMenu = menuBar()->addMenu(tr("文件"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(clearAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    QMenu* itemMenu = menuBar()->addMenu(tr("元素"));
    itemMenu->addAction(addEllipseItemAct);
    itemMenu->addAction(addPolygonItemAct);
    itemMenu->addAction(addTextItemAct);
    itemMenu->addAction(addRectItemAct);
    itemMenu->addAction(addAlphaItemAct);
    itemMenu->addAction(addFlashItemAct);
    itemMenu->addAction(addAnimItemAct);
}
void MainWindow::initScene() {
    // 初始化场景
    for (int i = 0; i < 3; i++)
        slotAddEllipseItem();
    for (int i = 0; i < 3; i++)
        slotAddPolygonItem();
    for (int i = 0; i < 3; i++)
        slotAddTextItem();
    for (int i = 0; i < 3; i++)
        slotAddRectItem();
    for (int i = 0; i < 3; i++)
        slotAddAlphaItem();
    for (int i = 0; i < 3; i++)
        slotAddFlashItem();
    for (int i = 0; i < 3; i++)
        slotAddAnimationItem();
}
void MainWindow::slotNew() {
    // 新建一个显示窗体
    slotClear();
    initScene();
    MainWindow* newWin = new MainWindow;
    newWin->show();
}
void MainWindow::slotClear() {
    // 清除场景中的所有图元
    QList<QGraphicsItem*> listItem = scene->items();
    while (!listItem.empty()) {
        scene->removeItem(listItem.at(0));
        listItem.removeAt(0);
    }
}
void MainWindow::slotAddEllipseItem() {
    // 在场景中加入椭圆形图元
    QGraphicsEllipseItem* item = new QGraphicsEllipseItem(QRectF(0, 0, 80, 60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}
void MainWindow::slotAddPolygonItem() {
    QVector<QPoint> v;
    v << QPoint(30, -15) << QPoint(0, -30) << QPoint(-30, -15) << QPoint(-30, 15) << QPoint(0, 30) << QPoint(30, 15);
    QGraphicsPolygonItem* item = new QGraphicsPolygonItem(QPolygonF(v));
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}
void MainWindow::slotAddTextItem() {
    // 在场景中添加一个文字图元
    QFont font("Times", 16);
    QGraphicsTextItem* item = new QGraphicsTextItem("Hello Qt!");
    item->setFont(font);
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setDefaultTextColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}
void MainWindow::slotAddRectItem() {
    // 添加长方形图元
    QGraphicsRectItem* item = new QGraphicsRectItem(QRectF(0, 0, 60, 60));
    QPen pen;
    pen.setColor(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setPen(pen);
    item->setBrush(QColor(qrand() % 256, qrand() % 256, qrand() % 256));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}
void MainWindow::slotAddAlphaItem() {
    // 添加一个透明蝴蝶图片
    QGraphicsPixmapItem* item = scene->addPixmap(QPixmap("image.png"));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}
void MainWindow::slotAddFlashItem() {
    // 添加闪烁图元
    FlashItem* item = new FlashItem;
    scene->addItem(item);
    item->setPos((qrand() % int(scene->sceneRect().width())) - 200, (qrand() % int(scene->sceneRect().height())) - 200);
}
void MainWindow::slotAddAnimationItem() {
    // 添加动画星星
    StartItem* item = new StartItem;
    QGraphicsItemAnimation* anim = new QGraphicsItemAnimation;
    anim->setItem(item);
    QTimeLine* timeLine = new QTimeLine(4000);
    timeLine->setCurveShape(QTimeLine::SineCurve);
    timeLine->setLoopCount(0);
    anim->setTimeLine(timeLine);
    int y = (qrand() % 400) - 200;
    for (int i = 0; i < 400; i++) {
        anim->setPosAt(i / 400.0, QPointF(i - 200, y));
    }
    timeLine->start();
    scene->addItem(item);
}
