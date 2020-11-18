#include <QCoreApplication>
#include <QMap>
#include <QHash>    //存储数据无序，比map快
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,QString> infoMap;
    //根据key值排序数据
    infoMap.insert("张杰","166cm");
    infoMap.insert("王祖蓝","162cm");
    infoMap["小王"] = "172cm";

    //通过key寻找value
    qDebug() << infoMap["小王"];
    qDebug() << infoMap.value("王祖蓝");

    //通过value找key
    qDebug() << infoMap.key("166cm");

    //Java风格迭代器
    qDebug() << "Java只读迭代器遍历：";
    QMapIterator<QString,QString> it_r(infoMap);
    for(it_r.toFront();it_r.hasNext();)
    {
        it_r.next();
        qDebug() << it_r.key() << ":" << it_r.value();
    }
    qDebug() << "Java读写迭代器遍历：";
    QMutableMapIterator<QString,QString> it_rw(infoMap);
    if(it_rw.findNext("162cm"))
    {
        it_rw.setValue("175cm");
    }
    for(it_rw.toFront();it_rw.hasNext();)
    {
        it_rw.next();
        if(it_rw.key() == "张杰")
        {
            it_rw.setValue("170");
        }
        qDebug() << it_rw.key() << ":" << it_rw.value();
    }


    QMap<QString,QString> wMap;
    wMap.insert("spring","15℃");
    wMap.insert("summer","35℃");
    wMap.insert("autum","23℃");
    wMap.insert("winter","0℃");

    //STL风格只读迭代器
    qDebug() << "STL风格只读迭代器：";
    QMap<QString,QString>::const_iterator i_r;
    for(i_r = wMap.constBegin();i_r != wMap.constEnd(); ++i_r)
    {
        qDebug() << i_r.key() <<i_r.value();
    }
    //STL风格读写迭代器
    qDebug() << "STL风格读写迭代器：";
    QMap<QString,QString>::iterator i_rw;
    i_rw = wMap.find("spring");
    if(i_rw != wMap.end())
    {
        i_rw.value() = "16℃";
    }
    for(i_rw = wMap.begin();i_rw != wMap.end(); ++i_rw)
    {
        qDebug() << i_rw.key() <<i_rw.value();
    }

    QMultiMap<QString,QString> wMap1;
    wMap1.insert("spring","15℃");
    wMap1.insert("summer","35℃");
    wMap1.insert("summer","37℃");
    wMap1.insert("summer","39℃");
    wMap1.insert("autum","23℃");
    wMap1.insert("winter","0℃");
    wMap1.insert("winter","-10℃");
    wMap1.insert("winter","5℃");

    qDebug() << "初始化后：" << wMap1;

    wMap1.remove("winter","-10℃");
    qDebug() << "删除10℃的winter后：" << wMap1;
    qDebug() << "winter：" << wMap1.values("winter");

    //Java只读
    QMapIterator<QString,QString> i_r1(wMap1);
    qDebug() << "Java只读迭代器遍历：";
    for(i_r1.toFront();i_r1.hasNext();)
    {
        i_r1.next();
        qDebug() << i_r1.key() << i_r1.value();
    }


    //QHash类，每次遍历的顺序都不一样
    QHash<int,QString> moneyHash;
    moneyHash.insert(1,"一块钱");
    moneyHash.insert(10,"十块钱");
    moneyHash.insert(20,"二十块钱");
    moneyHash[50] = "五十块钱";
    moneyHash[100] = "一百块钱";
    moneyHash.insertMulti(100,"毛爷爷");
//    moneyHash[100] = "毛爷爷";   一个键多个值不能这样插入

    //Java
    QHashIterator<int,QString> it_mr(moneyHash);

    qDebug() << endl << "只读正遍历人民币：";
    for(it_mr.toFront();it_mr.hasNext();)
    {
        it_mr.next();
        qDebug() << it_mr.key() << it_mr.value();
    }

    QMutableHashIterator<int,QString> it_mrw(moneyHash);
    if( it_mrw.findNext("毛爷爷") )
    {
        it_mrw.setValue("长城");
    }
    qDebug() << endl << "修改数据后：";
    for(it_mrw.toFront();it_mrw.hasNext();)
    {
        it_mrw.next();
        qDebug() << it_mrw.key() << it_mrw.value();
    }

    return a.exec();
}














