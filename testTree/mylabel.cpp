#include "mylabel.h"
#include <QDebug>

MyLabel::MyLabel(QWidget *parent):QLabel(parent)
{
    qDebug()<<"MyLabel构造调用！" << this;
}
MyLabel::~MyLabel()
{
    qDebug()<<"MyLabel析构调用！" << this;
}
