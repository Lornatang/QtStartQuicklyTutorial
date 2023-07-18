#include <QCoreApplication>
#include <QtXml>

int main(int argc, char* argv[]) {
    QCoreApplication a(argc, argv);

    // 新建QDomDocument类对象，它代表一个XML文档
    QDomDocument doc;
    // 建立指向“my.xml”文件的QFile对象
    QFile file("../SQL05/resources/xml/my.xml");
    // 以只读方式打开
    if (!file.open(QIODevice::ReadOnly))
        return 0;
    // 将文件内容读到doc中
    if (!doc.setContent(&file)) {
        file.close();
        return 0;
    }
    // 关闭文件
    file.close();
    // 获得doc的第一个节点，即XML说明
    QDomNode firstNode = doc.firstChild();
    // 输出XML说明
    qDebug() << firstNode.nodeName() << firstNode.nodeValue();

    QDomElement docElem = doc.documentElement();  //返回根元素
    QDomNode n = docElem.firstChild();            //返回根节点的第一个子节点
    //如果节点不为空
    while (!n.isNull()) {
        if (n.isElement())  //如果节点是元素
        {
            QDomElement e = n.toElement();
            qDebug() << qPrintable(e.tagName()) << qPrintable(e.attribute("id"));
            // 获得元素e的所有子节点的列表
            QDomNodeList list = e.childNodes();
            // 遍历该列表
            for (int i = 0; i < list.count(); i++) {
                QDomNode node = list.at(i);
                if (node.isElement())
                    qDebug() << "   " << qPrintable(node.toElement().tagName()) << qPrintable(node.toElement().text());
            }
        }
    }

    return a.exec();
}
