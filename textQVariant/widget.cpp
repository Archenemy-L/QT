#include "widget.h"
#include <QVariant>     //共用体
#include <QDebug>
#include <QTimer>
#include <QApplication>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QVariant vNum(100);
    qDebug() << vNum.toInt();

    QVariant vPI(3.1415f);
    qDebug() << vPI.toFloat();

    QVariant vStr("Hello");
    qDebug() << vStr.toString();

    QVariant vb(true);
    qDebug() << vb.toBool();

    QColor c = QColor(Qt::red);
    QVariant vC(c);
    qDebug() << vC.type();
    qDebug() << vC.value<QColor>();

    QVariant vss = vStr;
    qDebug() << vss.canConvert(QVariant::Int);      //canConvert()只是判断数据是否有转换的能力
    qDebug() << vss.toString();
    //转换成功的条件：有转换能力，数据类型匹配
    qDebug() << vss.convert(QVariant::Int);         //convert()转换类型，转换失败会清空数据
    qDebug() << vss.toString();


    QTimer::singleShot(0,qApp,SLOT(quit()));
}

Widget::~Widget()
{
}

