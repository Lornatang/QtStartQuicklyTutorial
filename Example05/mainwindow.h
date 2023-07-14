#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCloseEvent>
#include <QDialog>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QPushButton>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class QLineEdit;
    class QDialog;
    class QLabel;
}  // namespace Ui
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    void newFile();                          // 新建操作
    bool maybeSave();                        // 判断是否需要保存
    bool save();                             // 保存操作
    bool saveAs();                           // 另存为操作
    bool saveFile(const QString& fileName);  // 保存文件

    bool loadFile(const QString& fileName);  // 加载文件

  private slots:
    // 信号槽相关
    void on_action_New_triggered();
    void on_action_Open_triggered();
    void on_action_Save_triggered();
    void on_action_SaveAs_triggered();
    void on_action_Close_triggered();
    void on_action_Exit_triggered();
    void on_action_Undo_triggered();
    void on_action_Cut_triggered();
    void on_action_Copy_triggered();
    void on_action_Paste_triggered();
    void on_action_Find_triggered();

    void showFindText();

  private:
    Ui::MainWindow* ui;

    QLineEdit* findLineEdit;
    QDialog* findDlg;
    QLabel* statusLabel;

    // 为真表示文件没有保存过，为假表示文件已经被保存过了
    bool isUntitled;
    // 保存当前文件的路径
    QString curFile;

  protected:
    void closeEvent(QCloseEvent* event);  // 关闭事件
};

#endif  // MAINWINDOW_H
