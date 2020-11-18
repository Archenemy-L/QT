#include <QCoreApplication>
#include <QDebug>
#include <QLinkedList>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QList<int> list;
    //添加元素
    list << 10 << 9 << 8;
    list.prepend(11);       //头插
    list.append(7);         //尾插
    list.insert(5,6);       //指定位置插入
    qDebug() << list;

    //查找元素
    qDebug() << "第0个元素：" << list.at(0);     //at查找
    qDebug() << "第1个元素：" << list[1];        //下标查找
    qDebug() << "是否包含8：" << list.contains(8);   //是否包含
    qDebug() << "当前链表元素个数：" << list.size();

    //修改元素
    list.replace(5,66);     //修改指定下标位置的值
    list[0] = 0;            //通过下标修改
    qDebug() << list;

    //删除元素
    list.removeFirst(); //删除第一个元素
    list.removeLast();  //删除最后一个元素
    list.removeAt(1);   //删除指定位置元素
    list.removeOne(10); //删除指定值的所有元素
    qDebug() << list;

    //清空元素
    list.clear();
    qDebug() << "清空链表后：" << list;


    //Java风格迭代器使用, QMutableListIterator 读写迭代器
    QList<int> montList;
    QMutableListIterator<int> it_mrw(montList);
    for(int i = 0 ;i <= 12 ; i++)
    {
        it_mrw.insert(i);
    }
    qDebug() << "初始化后数据反向遍历：";       //toBack()让迭代器指向最后一个元素 Previous()前一个元素
    for(it_mrw.toBack();it_mrw.hasPrevious();)
    {
        qDebug() << it_mrw.previous();
    }
    qDebug() << "初始化后数据正向遍历：";
    for(it_mrw.toFront();it_mrw.hasNext();)
    {
        qDebug() << it_mrw.next();
    }

    for(it_mrw.toFront();it_mrw.hasNext();)
    {
        int month = it_mrw.next();
        if(month == 0)
        {
            it_mrw.remove();
        }
        if(month == 12)
        {
            it_mrw.setValue(13);
        }
    }
    qDebug() << "删除0修改12后数据正向遍历：";
    for(it_mrw.toFront();it_mrw.hasNext();)
    {
        qDebug() << it_mrw.next();
    }

    //Java只读迭代器
    QListIterator<int> it_mr(montList);
    qDebug() << "只读迭代器反向遍历：";
    for(it_mr.toBack();it_mr.hasPrevious();)
    {
        qDebug() << it_mr.previous();
    }
    qDebug() << "只读迭代器正向遍历：";
    for(it_mr.toFront();it_mr.hasNext();)
    {
        qDebug() << it_mr.next();
    }



    //STL风格迭代器
    QList<int> numList;
    numList << 11 << 22 << 33 << 44 << 55;

    //STL读写迭代器
    QList<int>::iterator it_numRW;
    qDebug() << "STL读写迭代器遍历：";
    for(it_numRW = numList.begin();it_numRW != numList.end(); ++it_numRW)
    {
        *it_numRW = *it_numRW * 10;
        qDebug() << *it_numRW;
    }
    //只读迭代器
    qDebug() << "STL只读迭代器遍历：";
    QList<int>::const_iterator it_numR;
    for(it_numR = numList.constBegin();it_numR != numList.constEnd(); ++it_numR)
    {
        qDebug() << *it_numR;
    }


    //QLinkedList类，和QList相比不能通过索引访问元素
    QLinkedList<QString> weekList;
    for(int j = 1 ; j < 8 ; ++j)
    {
        weekList << QString("%1%2").arg("星期").arg(j);
    }
    //Java风格只读迭代器
    qDebug() << "QLinkedList Java风格只读迭代器遍历";
    QLinkedListIterator<QString> it_wr(weekList);
    for(it_wr.toFront();it_wr.hasNext();)
    {
        qDebug() << it_wr.next();
    }
    qDebug() << "QLinkedList Java风格读写迭代器遍历";
    QMutableLinkedListIterator<QString> it_wrw(weekList);
    for(it_wrw.toFront();it_wrw.hasNext();)
    {
        QString day = it_wrw.next();
        if(day == "星期3")
        {
            //赋值
            it_wrw.setValue("星期三");
        }
        if(day == "星期7")
        {
            //删除
            it_wrw.remove();
            //插入
            it_wrw.insert("星期天");
        }
    }
    for(it_wrw.toFront();it_wrw.hasNext();)
    {
        qDebug() << it_wrw.next();
    }



    return a.exec();
}
















