#include "mypropertyclass.h"

MyPropertyClass::MyPropertyClass(QObject *parent) : QObject(parent)
{

}

QString MyPropertyClass::mask() const
{
    return m_mask;
}

void MyPropertyClass::setMask(QString strMaskNum)
{
    //设置属性
    m_mask = strMaskNum;
    //发送信号
    emit maskChanged(strMaskNum);
}
