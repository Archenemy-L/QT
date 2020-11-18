#include "widget.h"
#include "ui_widget.h"
#include "QDebug"
#include "mypropertyclass.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    MyPropertyClass *mypC = new MyPropertyClass;
    connect(mypC,SIGNAL(maskChanged(QString)),this,SLOT(maskChanged(QString)));
    mypC->setMask("1200");
    qDebug() << mypC->mask();

    QObject* obj = mypC;
    //通过obj进行属性读取
    qDebug() << obj->property("mask").toString();
    //通过obj设置属性
    obj->setProperty("mask","5000");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::maskChanged(QString str)
{
    qDebug() << "新的属性已改成"<<str;
}

