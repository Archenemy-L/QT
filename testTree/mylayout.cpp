#include "mylayout.h"
#include <QtDebug>

MyLayout::MyLayout(QWidget *parent):QGridLayout(parent)
{
    qDebug() << "MyLayout构造调用" << this;
}

MyLayout::~MyLayout()
{
    qDebug() << "MyLayout析造调用" << this;
}
