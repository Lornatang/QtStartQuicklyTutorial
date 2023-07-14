#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QPainter>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
    class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog {
    Q_OBJECT

  public:
    Dialog(QWidget* parent = nullptr);
    ~Dialog();

  private slots:
    void zoomIn();

  private:
    Ui::Dialog* ui;

    QPixmap pix;
    QPoint lastPoint;
    QPoint endPoint;

    qreal scale;
    QPushButton* button;

    QPixmap tempPix;  //辅助画布
    bool isDrawing;   //标志是否正在绘图

  protected:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
};

#endif  // DIALOG_H
