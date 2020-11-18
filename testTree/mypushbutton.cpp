#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent):QPushButton(parent)
{
    qDebug() << "MyPushButton构造调用" << this;
}

MyPushButton::~MyPushButton()
{
    qDebug() << "MyPushButton析构调用" << this;
}
