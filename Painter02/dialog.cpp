#include "dialog.h"

#include "./ui_dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog) { ui->setupUi(this); }

Dialog::~Dialog() { delete ui; }

void Dialog::paintEvent(QPaintEvent*) {
    //    // 简单绘制图片
    //    QPainter painter(this);
    //    QPixmap pix;
    //    pix.load("../Painter02/beacon_logo.png");
    //    painter.drawPixmap(0, 0, 230, 24, pix);

    //    // 平移图片
    //    painter.translate(100, 100);  //将（100，100）设为坐标原点
    //    painter.drawPixmap(0, 0, 230, 24, pix);

    //    // 缩放图片
    //    qreal width = pix.width();  //获得以前图片的宽和高
    //    qreal height = pix.height();
    //    // 将图片的宽和高都扩大两倍，并且在给定的矩形内保持宽高的比值不变
    //    pix = pix.scaled(width * 2, height * 2, Qt::KeepAspectRatio);
    //    painter.drawPixmap(70, 70, pix);

    //    // 旋转图片
    //    painter.translate(230 / 2, 24 / 2);    //让图片的中心作为旋转的中心
    //    painter.rotate(90);                    //顺时针旋转90度
    //    painter.translate(-230 / 2, -24 / 2);  //使原点复原
    //    painter.drawPixmap(100, 100, 230, 24, pix);

    //    // 扭曲图片
    //    painter.shear(0.5, 0);  //横向扭曲
    //    painter.drawPixmap(100, 0, 230, 24, pix);

    //    // 平移变换
    //    QPainter painter(this);
    //    painter.setBrush(Qt::yellow);
    //    painter.drawRect(0, 0, 50, 50);
    //    painter.translate(100, 100);  //将点（100，100）设为原点
    //    painter.setBrush(Qt::red);
    //    painter.drawRect(0, 0, 50, 50);
    //    painter.translate(-100, -100);
    //    painter.drawLine(0, 0, 20, 20);

    //    // 缩放变换
    //    QPainter painter(this);
    //    painter.setBrush(Qt::yellow);
    //    painter.drawRect(0, 0, 100, 100);
    //    painter.scale(2, 2);  //放大两倍
    //    painter.setBrush(Qt::red);
    //    painter.drawRect(50, 50, 50, 50);

    //    // 扭曲变换
    //    QPainter painter(this);
    //    painter.setBrush(Qt::yellow);
    //    painter.drawRect(0, 0, 50, 50);
    //    painter.shear(0, 1);  //纵向扭曲变形
    //    painter.setBrush(Qt::red);
    //    painter.drawRect(50, 0, 50, 50);

    //    // 旋转变换
    //    QPainter painter(this);
    //    painter.drawLine(0, 0, 100, 0);
    //    painter.rotate(30);  //以原点为中心，顺时针旋转30度
    //    painter.drawLine(0, 0, 100, 0);
    //    painter.rotate(-30);  // 反向旋转
    //    painter.translate(100, 100);
    //    painter.rotate(30);
    //    painter.drawLine(0, 0, 100, 0);

    //    QPainter painter(this);
    //    painter.save();  //保存坐标系状态
    //    painter.translate(100, 100);
    //    painter.drawLine(0, 0, 50, 50);
    //    painter.restore();  //恢复以前的坐标系状态
    //    painter.drawLine(0, 0, 50, 50);

    //    // 放大
    //    QPainter painter(this);
    //    painter.drawRect(0, 0, 50, 50);
    //    painter.scale(1, 2);
    //    painter.drawRect(50, 50, 50, 50);

    //    QPainter painter(this);
    //    painter.drawLine(0, 0, 100, 0);
    //    painter.rotate(45);
    //    painter.setPen(Qt::red);
    //    painter.drawLine(0, 0, 100, 0);

    //    QPainter painter(this);
    //    QPixmap pix(200, 200);
    //    pix.fill(Qt::red);  //背景填充为红色
    //    painter.drawPixmap(0, 0, pix);

    //    QPainter painter(this);
    //    QPixmap pix(200, 200);
    //    pix.fill(Qt::red);
    //    //新建QPainter类对象，在pix上进行绘图
    //    QPainter pp(&pix);
    //    //在pix上的（0，0）点和（50，50）点之间绘制直线
    //    pp.drawLine(0, 0, 50, 50);
    //    painter.drawPixmap(100, 100, pix);

    //    QPainter painter(this);
    //    QPixmap pix(200, 200);
    //    //放大前输出画布的大小
    //    qDebug() << pix.size();
    //    pix.fill(Qt::red);
    //    QPainter pp(&pix);
    //    //画布的坐标扩大2倍
    //    pp.scale(2, 2);
    //    //在画布上的（0，0）点和（50，50）点之间绘制直线
    //    pp.drawLine(0, 0, 50, 50);
    //    //放大后输出画布的大小
    //    qDebug() << pix.size();
    //    painter.drawPixmap(0, 0, pix);

    QPainter painter(this);
    QPixmap pix(200, 200);
    qDebug() << pix.size();
    //窗口坐标扩大2倍
    painter.scale(2, 2);
    pix.fill(Qt::red);
    QPainter pp(&pix);
    pp.drawLine(0, 0, 50, 50);
    qDebug() << pix.size();
    painter.drawPixmap(0, 0, pix);
}

void Dialog::mousePressEvent(QMouseEvent* event) { qDebug() << event->pos(); }
