#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QFrame>
#include <QGraphicsBlurEffect>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>

#include "pixitem.h"

class MainWidget : public QWidget {
    Q_OBJECT
    // QObject是Qt 对象模型机制的核心类


public:
    // 构造函数，默认给QWidget赋值为空
    MainWidget(QWidget *parent = nullptr);

    // 析构函数，用于销毁类
    ~MainWidget();

    // 创建控制帧，控制图像高斯、旋转、缩放等
    void createControlFrame();

public
    slots:
            // 高斯滤波函数的信号槽
            void slotGaussianBlur(int);

    // 旋转函数的信号槽
    void slotRotate(int);

    // 缩放函数的信号槽
    void slotScale(int);

    // 裂变函数的信号槽
    void slotShear(int);

    // 形变函数的信号槽
    void slotTranslate(int);

private:
    bool isIsp;
    // 图像处理参数值
    qreal gaussianKSizeValue;
    qreal angleValue;
    qreal scaleValue;
    qreal shearValue;
    qreal translateValue;

    // 视图
    QGraphicsView *view;
    // 窗体
    QFrame *ctrlFrame;
    // 图元
    PixItem *pixItem;
};

#endif  // MAINWIDGET_H
