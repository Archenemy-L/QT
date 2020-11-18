#include "digitalclock.h"
#include <QTimer>
#include <QTime>
#include <QMouseEvent>
#include <QMessageBox>

DigitalClock::DigitalClock(QWidget* parent):QLCDNumber(parent)
{
    //设置背景颜色
    QPalette p = palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);

    //无边框窗体风格
    setWindowFlag(Qt::FramelessWindowHint);

    //窗体透明度
    setWindowOpacity(0.5);

    //计时器类
    QTimer *timer = new QTimer(this);
    //每秒触发
    connect(timer,&QTimer::timeout,this,&DigitalClock::showTime);
    timer->start(1000); //启动并设置间隔时间

    showTime();
    //设置大小
    resize(150,60);
    m_showColon = true;
}

void DigitalClock::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)   //判断是否为鼠标左键单击
    {
        //获取鼠标偏移位置 鼠标坐标减去边框的左上角坐标
        //globalPos()鼠标相对屏幕左上角的位置信息 frameGeometry()边框几何信息
        m_dragPosition = event->globalPos()-frameGeometry().topLeft();
        event->accept();    //接收事件
    }
    if(event->button() == Qt::RightButton)
    {
        int res = QMessageBox::information(this,"提示","是否关闭时钟？",QMessageBox::Yes|QMessageBox::No);
        if(res == QMessageBox::Yes)
        {
            close();
        }
        else
        {
            return;
        }
    }
}

void DigitalClock::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
}

void DigitalClock::showTime()
{
    QTime time = QTime::currentTime();  //获取当前时间
    QString strTime = time.toString("hh:mm");  //转换成字符串类型
    if(m_showColon)
    {
        strTime[2] = ':';
    }else{
        strTime[2] = ' ';
    }
    //显示在窗体
    display(strTime);
    //取反
    m_showColon = !m_showColon;
}
