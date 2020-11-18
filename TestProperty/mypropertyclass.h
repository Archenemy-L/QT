#ifndef MYPROPERTYCLASS_H
#define MYPROPERTYCLASS_H

#include <QObject>

class MyPropertyClass : public QObject
{
    //使用信号和槽
    Q_OBJECT
    //使用动态属性
    Q_PROPERTY(QString mask READ mask WRITE setMask NOTIFY maskChanged)
public:
    explicit MyPropertyClass(QObject *parent = nullptr);
    QString mask()const;                    //读属性 READ
    void setMask(QString strMaskNum);       //写属性 WRITE setMask

signals:
    void maskChanged(QString str);          //属性改变时发送的信号 NOTIEY
private:
    QString m_mask; //保存属性的值
};

#endif // MYPROPERTYCLASS_H
