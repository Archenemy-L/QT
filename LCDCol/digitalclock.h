#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H
#include <QLCDNumber>

class DigitalClock : public QLCDNumber
{
    Q_OBJECT
public:
    DigitalClock(QWidget* parent = 0);
protected:
    void mousePressEvent(QMouseEvent* event);  //鼠标按下事件重写
    void mouseMoveEvent(QMouseEvent* event);   //鼠标移动事件重写
private slots:
    void showTime();        //显示当前时间
private:
    QPoint m_dragPosition;  //鼠标点相对左上角偏移值
    bool m_showColon;       //“:”显示

};

#endif // DIGITALCLOCK_H
