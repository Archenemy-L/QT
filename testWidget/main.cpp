#include <QApplication>
#include <QWidget>
#include <QDebug>

int main(int argc,char* argv[])
{
    QApplication app(argc,argv);

    QWidget widget;
    widget.setWindowTitle("widget窗口");
//    widget.setWindowState(Qt::WindowMaximized); //Qt::WindowMaximized设置窗口最大化
    //设置窗口大小
//    widget.resize(QSize(500,500));
    widget.resize(500,500);
    //设置窗口位置
//    widget.move(QPoint(0,0));
    widget.move(0,0);
    qDebug()<< " x:" << widget.x() << " y:" << widget.y() << " width:" << widget.width() << " height:" << widget.height() << " geometry:" << widget.geometry();
    widget.show();

    QWidget widget1(0,Qt::FramelessWindowHint | Qt::Dialog);
    widget1.setWindowTitle("widget无边框窗口");
    widget1.show();

    return app.exec();
}
