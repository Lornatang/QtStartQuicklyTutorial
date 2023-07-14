#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) { ui->setupUi(this); }

MainWindow::~MainWindow() { delete ui; }

void MainWindow::paintEvent(QPaintEvent*) {
    //    QRectF rectangle(10.0, 20.0, 80.0, 60.0);  //矩形
    //    int startAngle = 30 * 16;                  //起始角度
    //    int spanAngle = 120 * 16;                  //跨越度数
    //    QPainter painter(this);
    //    painter.drawArc(rectangle, startAngle, spanAngle);

    //    //线性渐变
    //    QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
    //    //插入颜色
    //    linearGradient.setColorAt(0, Qt::yellow);
    //    linearGradient.setColorAt(0.5, Qt::red);
    //    linearGradient.setColorAt(1, Qt::green);
    //    //指定渐变区域以外的区域的扩散方式
    //    linearGradient.setSpread(QGradient::RepeatSpread);
    //    //使用渐变作为画刷
    //    QPainter painter(this);
    //    painter.setBrush(linearGradient);
    //    painter.drawRect(10, 20, 90, 40);

    //    //辐射渐变
    //    QRadialGradient radialGradient(QPointF(100, 190), 50, QPointF(275, 200));
    //    radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
    //    radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
    //    painter.setBrush(radialGradient);
    //    painter.drawEllipse(QPointF(100, 190), 50, 50);

    //    //锥形渐变
    //    QConicalGradient conicalGradient(QPointF(250, 190), 60);
    //    conicalGradient.setColorAt(0.2, Qt::cyan);
    //    conicalGradient.setColorAt(0.9, Qt::black);
    //    painter.setBrush(conicalGradient);
    //    painter.drawEllipse(QPointF(250, 190), 50, 50);

    //    QPainter painter(this);
    //    //设置一个矩形
    //    QRectF rect(20, 20, 300, 200);
    //    //为了更直观地看到字体的位置，我们绘制出这个矩形
    //    painter.drawRect(rect);
    //    painter.setPen(QColor(Qt::red));
    //    //我们这里先让字体水平居中
    //    painter.drawText(rect, Qt::AlignHCenter, "lcy");

    //    QFont font("宋体", 15, QFont::Bold, true);
    //    //设置下划线
    //    font.setUnderline(true);
    //    //设置上划线
    //    font.setOverline(true);
    //    //设置字母大小写
    //    font.setCapitalization(QFont::SmallCaps);
    //    //设置字符间的间距
    //    font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
    //    //使用字体
    //    painter.setFont(font);
    //    painter.setPen(Qt::green);
    //    painter.drawText(120, 80, "lcy");
    //    painter.translate(50, 50);
    //    painter.rotate(90);
    //    painter.drawText(0, 0, "helloqt");

    //    QPainterPath path;
    //    path.addEllipse(100, 100, 50, 50);
    //    path.lineTo(200, 200);

    //    QPainterPath path2;
    //    path2.addPath(path);
    //    path2.translate(100, 0);

    //    QPainter painter(this);
    //    painter.setPen(Qt::blue);
    //    painter.setBrush(Qt::red);
    //    painter.drawPath(path);
    //    painter.drawPath(path2);

    //    QPainterPath path;
    //    path.lineTo(100, 100);
    //    path.lineTo(200, 100);
    //    QPainter painter(this);
    //    painter.drawPath(path);

    QPainterPath path;
    path.addRect(50, 50, 40, 40);
    //移动到(100, 100)点
    path.moveTo(100, 100);
    path.lineTo(200, 200);
    QPainter painter(this);
    painter.drawPath(path);
}
