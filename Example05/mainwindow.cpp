#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // 初始化文件为未保存状态
    isUntitled = true;
    // 初始化文件名为"新建文本.txt"
    curFile = tr("新建文本.txt");
    // 初始化窗口标题为文件名
    setWindowTitle(curFile);

    findDlg = new QDialog(this);
    findDlg->setWindowTitle(tr("查找"));
    findLineEdit = new QLineEdit(findDlg);
    QPushButton* btn = new QPushButton(tr("查找下一个"), findDlg);
    QVBoxLayout* layout = new QVBoxLayout(findDlg);
    layout->addWidget(findLineEdit);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(showFindText()));

    statusLabel = new QLabel;
    statusLabel->setMinimumSize(150, 20);          // 设置标签最小大小
    statusLabel->setFrameShape(QFrame::WinPanel);  // 设置标签形状
    statusLabel->setFrameShadow(QFrame::Sunken);   // 设置标签阴影
    ui->statusBar->addWidget(statusLabel);
    statusLabel->setText(tr("欢迎访问Qt爱好者社区！"));

    QLabel* permanent = new QLabel(this);
    permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
    permanent->setText(tr("<a href=\"http://www.github.com\">github.com</a>"));
    permanent->setTextFormat(Qt::RichText);
    permanent->setOpenExternalLinks(true);
    ui->statusBar->addPermanentWidget(permanent);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::newFile() {
    if (maybeSave()) {
        isUntitled = true;
        curFile = tr("新建文本.txt");
        setWindowTitle(curFile);
        ui->textEdit->clear();
        ui->textEdit->setVisible(true);
    }
}

bool MainWindow::maybeSave() {
    // 如果文档被修改了
    if (ui->textEdit->document()->isModified()) {
        // 自定义一个警告对话框
        QMessageBox box;
        QPushButton* yesBtn = box.addButton(tr("是(&Y)"), QMessageBox::YesRole);
        QPushButton* cancelBtn = box.addButton(tr("取消"), QMessageBox::RejectRole);

        box.setWindowTitle(tr("警告"));
        box.setIcon(QMessageBox::Warning);
        box.setText(curFile + tr(" 尚未保存，是否保存？"));
        box.addButton(tr("否(&N)"), QMessageBox::NoRole);
        box.exec();

        if (box.clickedButton() == yesBtn) {
            return save();
        } else if (box.clickedButton() == cancelBtn) {
            return false;
        }
    }

    // 如果文档没有被更改，则直接返回true
    return true;
}

bool MainWindow::save() {
    if (isUntitled) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool MainWindow::saveAs() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("另存为"), curFile);

    if (fileName.isEmpty()) {
        return false;
    }

    return saveFile(fileName);
}

bool MainWindow::saveFile(const QString& fileName) {
    QFile file(fileName);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QString warning_msg = "无法写入文件 %1：/n %2";
        // %1和%2分别对应后面arg两个参数，/n起换行的作用
        QMessageBox::warning(this, tr("多文档编辑器"), warning_msg.arg(fileName, file.errorString()));
        return false;
    }
    QTextStream out(&file);
    // 鼠标指针变为等待状态
    QApplication::setOverrideCursor(Qt::WaitCursor);
    out << ui->textEdit->toPlainText();
    // 鼠标指针恢复原来的状态
    QApplication::restoreOverrideCursor();
    isUntitled = false;
    // 获得文件的标准路径
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

bool MainWindow::loadFile(const QString& fileName) {
    QFile file(fileName);  // 新建QFile对象
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QString warning_msg = "无法读取文件 %1：/n %2";
        QMessageBox::warning(this, tr("多文档编辑器"), warning_msg.arg(fileName, file.errorString()));
        return false;  // 只读方式打开文件，出错则提示，并返回false
    }
    QTextStream in(&file);  // 新建文本流对象
    QApplication::setOverrideCursor(Qt::WaitCursor);
    // 读取文件的全部文本内容，并添加到编辑器中
    ui->textEdit->setPlainText(in.readAll());
    QApplication::restoreOverrideCursor();

    // 设置当前文件
    curFile = QFileInfo(fileName).canonicalFilePath();
    setWindowTitle(curFile);
    return true;
}

void MainWindow::on_action_New_triggered() { newFile(); }
void MainWindow::on_action_Open_triggered() {
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);

        // 如果文件名不为空，则加载文件
        if (!fileName.isEmpty()) {
            loadFile(fileName);
            ui->textEdit->setVisible(true);
        }
    }
}
void MainWindow::on_action_Save_triggered() { save(); }
void MainWindow::on_action_SaveAs_triggered() { saveAs(); }
// 关闭动作
void MainWindow::on_action_Close_triggered() {
    if (maybeSave()) {
        ui->textEdit->setVisible(false);
    }
}
// 退出动作
void MainWindow::on_action_Exit_triggered() {
    // 先执行关闭操作，再退出程序
    // qApp是指向应用程序的全局指针
    on_action_Close_triggered();
    qApp->quit();
}
// 撤销动作
void MainWindow::on_action_Undo_triggered() { ui->textEdit->undo(); }
// 剪切动作
void MainWindow::on_action_Cut_triggered() { ui->textEdit->cut(); }
// 复制动作
void MainWindow::on_action_Copy_triggered() { ui->textEdit->copy(); }
// 粘贴动作
void MainWindow::on_action_Paste_triggered() { ui->textEdit->paste(); }
// 查找动作
void MainWindow::on_action_Find_triggered() { findDlg->show(); }
void MainWindow::closeEvent(QCloseEvent* event) {
    // 如果maybeSave()函数返回true，则关闭程序
    if (maybeSave()) {
        event->accept();
    } else {  // 否则忽略该事件
        event->ignore();
    }
}

void MainWindow::showFindText() {
    QString str = findLineEdit->text();
    if (!ui->textEdit->find(str, QTextDocument::FindBackward)) {
        QString warning_msg = "找不到%1";
        QMessageBox::warning(this, tr("查找"), warning_msg.arg(str));
    }
}
