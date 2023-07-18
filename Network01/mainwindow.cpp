#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    //    manager = new QNetworkAccessManager(this);
    //    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));
    //    // 使用了下面的代码来发送请求, 它返回一个QNetworkReply对象
    //    manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));

    manager = new QNetworkAccessManager(this);
    ui->progressBar->hide();
}

MainWindow::~MainWindow() { delete ui; }

// void MainWindow::replyFinished(QNetworkReply* reply) {
//    // 当下载数据结束时，就会执行replyFinished()函数
//    QTextCodec* codec = QTextCodec::codecForName("utf8");
//    // 为了能显示下载的网页中的中文，我们使用了QTextCodec 类对象，应用utf8编码。
//    // 使用reply->readAll()函数就可以将下载的所有数据读出。然后，我们在textBrowser中将数据显示出来。
//    QString all = codec->toUnicode(reply->readAll());
//    ui->textBrowser->setText(all);
//    // 当reply对象已经完成了它的功能时，我们需要将它释放
//    reply->deleteLater();
//}

void MainWindow::startRequest(QUrl url) {
    reply = manager->get(QNetworkRequest(url));
    connect(reply, SIGNAL(readyRead()), this, SLOT(httpReadyRead()));
    connect(reply, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(updateDataReadProgress(qint64, qint64)));
    connect(reply, SIGNAL(finished()), this, SLOT(httpFinished()));
}

void MainWindow::httpReadyRead() {
    if (file)
        file->write(reply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead, qint64 totalBytes) {
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

void MainWindow::httpFinished() {
    ui->progressBar->hide();
    file->flush();
    file->close();
    reply->deleteLater();
    reply = 0;
    delete file;
    file = 0;
}

void MainWindow::on_pushButton_clicked() {
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());
    if (fileName.isEmpty())
        fileName = "index.html";
    file = new QFile(fileName);
    if (!file->open(QIODevice::WriteOnly)) {
        qDebug() << "file open error";
        delete file;
        file = 0;
        return;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();
}
