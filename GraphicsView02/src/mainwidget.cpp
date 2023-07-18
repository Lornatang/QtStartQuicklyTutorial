#include "mainwidget.h"

#include <math.h>

#include <QGroupBox>
#include <QHBoxLayout>
#include <QSlider>
#include <QVBoxLayout>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent) {
    // 是否加入了图像处理，默认是否的
    isIsp = false;
    // 在构造函数中初始化图像处理的预设参数值
    gaussianKSizeValue = 0;
    angleValue = 0.f;
    scaleValue = 0.f;
    shearValue = 5.f;
    translateValue = 50.f;

    // 限定新建QGraphicsScene对象的显示区域
    QGraphicsScene *scene = new QGraphicsScene;
    scene->setSceneRect(-500, -500, 1000, 1000);
    // 这里图像是在本地存好的，应该可以从外部传入图像
    // TODO: 将从本地加载图像功能修改为从外部传入图像
    QPixmap *pixmap = new QPixmap("../GraphicsView02/resources/beacon_images/beacon_logo.png");

    pixItem = new PixItem(pixmap);
    // 场景中加入图元
    scene->addItem(pixItem);
    // 设置图元默认坐标
    pixItem->setPos(0, 0);

    // 新建一个视图对象
    view = new QGraphicsView;
    // 将视图对象与场景相连
    view->setScene(scene);
    // 设置视图的最小尺寸为（600,600）
    view->setMinimumSize(600, 600);

    // 新建控制，调节亮度对比度的东西
    ctrlFrame = new QFrame;

    // 新建主窗体右侧的控制面板区
    createControlFrame();

    // 主窗口布局
    QHBoxLayout *mainLayout = new QHBoxLayout;
    // 表示控件与窗体的左右边距
    mainLayout->setMargin(10);
    // 表示各个控件之间的上下间距
    mainLayout->setSpacing(20);
    // 布局中加入视图组件
    mainLayout->addWidget(view);
    // 布局中加入控制组件
    mainLayout->addWidget(ctrlFrame);
    // 设置主窗体
    setLayout(mainLayout);
    // 设置主窗体的标题
    setWindowTitle("Image Single Process App");
}

void MainWidget::createControlFrame() {
    // 高斯控制
    // 创建滑块控件
    QSlider *gaussianBlurSlider = new QSlider;
    // 进度条的方位，这里设置为水平
    gaussianBlurSlider->setOrientation(Qt::Horizontal);
    // 进度条范围值，自定义成0, 11
    gaussianBlurSlider->setRange(0, 11);
    // 将调整后的值传入进度条
    gaussianBlurSlider->setValue(gaussianKSizeValue);
    // 创建水平布局控件
    QHBoxLayout *gaussianBlurLayout = new QHBoxLayout;
    // 将水平布局控件加入高斯控制当中
    gaussianBlurLayout->addWidget(gaussianBlurSlider);
    QGroupBox *gaussianBlurGroup = new QGroupBox("GaussianBlur");
    // 总高斯控制布局加入高斯控件
    gaussianBlurGroup->setLayout(gaussianBlurLayout);

    // 旋转控制
    // 创建滑块控件
    QSlider *rotateSlider = new QSlider;
    // 进度条的方位，这里设置为水平
    rotateSlider->setOrientation(Qt::Horizontal);
    // 进度条范围值，自定义成-180,180就可以
    rotateSlider->setRange(-180, 180);
    // 将调整后的值传入进度条
    rotateSlider->setValue(angleValue);
    // 创建水平布局控件
    QHBoxLayout *rotateLayout = new QHBoxLayout;
    // 将水平布局控件加入旋转控制当中
    rotateLayout->addWidget(rotateSlider);
    QGroupBox *rotateGroup = new QGroupBox("Rotate");
    // 总旋转控制布局加入旋转控件
    rotateGroup->setLayout(rotateLayout);

    // 缩放控制
    // 创建滑块控件
    QSlider *scaleSlider = new QSlider;
    // 进度条的方位，这里设置为水平
    scaleSlider->setOrientation(Qt::Horizontal);
    // 进度条范围值，自定义设置成-2~2
    scaleSlider->setRange(-2, 2);
    // 将调整后的值传入进度条
    scaleSlider->setValue(scaleValue);
    // 创建水平布局控件
    QHBoxLayout *scaleLayout = new QHBoxLayout;
    // 将水平布局控件加入旋转控制当中
    scaleLayout->addWidget(scaleSlider);
    QGroupBox *scaleGroup = new QGroupBox("Scale");
    // 总缩放控制布局加入缩放控件
    scaleGroup->setLayout(scaleLayout);

    // 裂变控制
    QSlider *shearSlider = new QSlider;
    // 进度条的方位，这里设置为水平
    shearSlider->setOrientation(Qt::Horizontal);
    // 进度条范围值，自定义设置成0~10
    shearSlider->setRange(0, 10);
    // 将调整后的值传入进度条
    shearSlider->setValue(shearValue);
    // 创建水平布局控件
    QHBoxLayout *shearLayout = new QHBoxLayout;
    // 将水平布局控件加入裂变控制当中
    shearLayout->addWidget(shearSlider);
    QGroupBox *shearGroup = new QGroupBox("Shear");
    // 总裂变控制布局加入裂变控件
    shearGroup->setLayout(shearLayout);

    // 位移控制
    QSlider *translateSlider = new QSlider;
    // 进度条的方位，这里设置为水平
    translateSlider->setOrientation(Qt::Horizontal);
    // 进度条范围值，自定义设置成0~100
    translateSlider->setRange(0, 100);
    // 将调整后的值传入进度条
    translateSlider->setValue(translateValue);
    // 创建水平布局控件
    QHBoxLayout *translateLayout = new QHBoxLayout;
    // 将水平布局控件加入位移控制当中
    translateLayout->addWidget(translateSlider);
    QGroupBox *translateGroup = new QGroupBox("Translate");
    // 总裂变控制布局加入位移控件
    translateGroup->setLayout(translateLayout);

    // 将每个操作的信号槽都连接起来
    connect(gaussianBlurSlider, SIGNAL(valueChanged(int)), this, SLOT(slotGaussianBlur(int)));
    connect(rotateSlider, SIGNAL(valueChanged(int)), this, SLOT(slotRotate(int)));
    connect(scaleSlider, SIGNAL(valueChanged(int)), this, SLOT(slotScale(int)));
    connect(shearSlider, SIGNAL(valueChanged(int)), this, SLOT(slotShear(int)));
    connect(translateSlider, SIGNAL(valueChanged(int)), this, SLOT(slotTranslate(int)));

    // 控制面板布局
    QVBoxLayout *frameLayout = new QVBoxLayout;
    // 表示控件与窗体的左右边距
    frameLayout->setMargin(10);
    // 表示各个控件之间的上下间距
    frameLayout->setSpacing(20);
    // 在控制面版中加入所有控制按钮组
    frameLayout->addWidget(gaussianBlurGroup);
    frameLayout->addWidget(rotateGroup);
    frameLayout->addWidget(scaleGroup);
    frameLayout->addWidget(shearGroup);
    frameLayout->addWidget(translateGroup);
    // 设置控制帧的布局由控制面板定义
    ctrlFrame->setLayout(frameLayout);
}

void MainWidget::slotGaussianBlur(int kSizeValue) {
    if (kSizeValue != 0) {
        isIsp = true;
    } else {
        isIsp = false;
    }
    QGraphicsBlurEffect *blur = new QGraphicsBlurEffect(this);
    blur->setBlurRadius(kSizeValue);
    view->setGraphicsEffect(blur);
    gaussianKSizeValue = kSizeValue;
}

void MainWidget::slotRotate(int value) {
    if (isIsp) {
        slotGaussianBlur(gaussianKSizeValue);
    }
    view->rotate(value - angleValue);
    angleValue = value;
}

void MainWidget::slotScale(int value) {
    if (isIsp) {
        slotGaussianBlur(gaussianKSizeValue);
    }

    qreal scale_factor;

    if (value > scaleValue) {
        scale_factor = pow(1.1, (value - scaleValue));
    } else {
        scale_factor = pow(1 / 1.1, (scaleValue - value));
    }
    view->scale(scale_factor, scale_factor);
    scaleValue = value;
}

void MainWidget::slotShear(int value) {
    if (isIsp) {
        slotGaussianBlur(gaussianKSizeValue);
    }

    view->shear((value - shearValue) / 10.0, 0);
    shearValue = value;
}

void MainWidget::slotTranslate(int value) {
    if (isIsp) {
        slotGaussianBlur(gaussianKSizeValue);
    }

    view->translate(value - translateValue, value - translateValue);
    translateValue = value;
}

MainWidget::~MainWidget() {}
