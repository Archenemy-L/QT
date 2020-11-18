#include "myradiobutton.h"
#include <QDebug>


MyRadioButton::MyRadioButton(QWidget *parent):QRadioButton(parent)
{
    qDebug() << "MyRadioButton构造调用" << this;
}

MyRadioButton::~MyRadioButton()
{
    qDebug() << "MyRadioButton析构调用" << this;
}
