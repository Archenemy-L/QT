#include "dialog.h"

#include <QApplication>
#include "templedialog.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Dialog w1;
//    w1.setWindowTitle("w1窗口");
//    //设置模态阻塞其他窗口
//    //w1.setWindowModality(Qt::ApplicationModal);
//    w1.show();

//    Dialog w2;
//    w2.setWindowTitle("w2窗口");
//    //设置模态阻塞其他窗口
//    //w2.setModal(true);
//    w2.show();

//    Dialog w3;
//    w3.setWindowTitle("w3窗口");
//    //进入循环阻塞其他窗口输入
//    //w3.exec();
//    w3.show();

    TempleDialog tDlg;
    int tmp = tDlg.exec();
    qDebug() << tmp;

    return a.exec();
}
