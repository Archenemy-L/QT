#include <QCoreApplication>
#include <QDebug>
#include <QVector>  //向量容器，插入数据比较麻烦，但是可以通过下标快速访问

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QVector<QString> vStarts;

    //添加元素
    vStarts << "鹿晗" << "张艺兴" ;
    vStarts.append("周杰伦");     //尾插
    vStarts.prepend("张杰");      //前插
    vStarts.insert(2,"章子怡");
    qDebug() << vStarts;

    //修改元素
    vStarts.replace(3,"迪丽热巴");
    qDebug() << vStarts;

    //删除元素
    vStarts.remove(0);
    qDebug() << vStarts;

    //下标访问元素
    qDebug() << vStarts[2];

    //判断是否有某一元素
    qDebug() << vStarts.contains("小鹿");

    //Java风格只读迭代器
    QVectorIterator<QString> it_sr(vStarts);
    for(it_sr.toFront();it_sr.hasNext();)
    {
        qDebug() << it_sr.next();
    }
    //Java风格读写迭代器
    qDebug() << "Java风格读写迭代器遍历：";
    QMutableVectorIterator<QString> it_srw(vStarts);
    for(it_srw.toFront();it_srw.hasNext();)
    {
        QString s = it_srw.next();
        if(!QString::compare(s,"鹿晗"))
        {
            it_srw.setValue("李晨");
        }
    }
    qDebug() << vStarts;

    //STL
    qDebug() << "STL风格遍历：";
    QVector<QString>::iterator it_rw;
    for(it_rw = vStarts.begin(); it_rw != vStarts.end(); ++it_rw)
    {
        qDebug() << *it_rw;
    }





    return a.exec();
}










