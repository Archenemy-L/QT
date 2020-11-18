#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //传入const char*类型
    QString str("老王");

    QChar ch[5] = {'h','e','l','l','o'};
    //Qchar类型传入
    QString s1(ch,5);

    qDebug() << s1;

    QString Qinum("11");
    QString Qfnum("3.14");

    //Qstring转数字
    int inum = Qinum.toInt();
    float fnum = Qfnum.toFloat();
    double dnum = 3.14;

    qDebug() << inum << fnum;

    QString Qdnum,num1,num2;
    //数字转Qstring
    Qdnum=QString::number(dnum);
    num1 = num1.number(inum);
    num2 = num2.setNum(fnum);

    qDebug() << Qdnum<<num1<<num2;

    //const char*转Qstring
    const char* hi ="hello word!";
    QString strHi(hi);
    qDebug() << strHi;

    //QString转QByteArray
    QString strTom = "Tom";
    QByteArray tomArr = strTom.toUtf8();
    const char* ctom = tomArr.data();
    qDebug() << ctom;

    //QString转QDataTime，得指定格式
    QString strTime = "1949-10-01 10:00:00";
    QDateTime dtTime = dtTime.fromString(strTime,"yyyy-MM-dd hh:mm:ss");
    qDebug() << dtTime;

    //QDataTime转QString，得指定格式
    QDateTime dtCurrent = QDateTime::currentDateTime();
    QString strCurrent = dtCurrent.toString("yyyy-MM-dd hh:mm:ss");
    qDebug() << strCurrent;



    //QString拼接
    QString s2 = "我的男神：";
    s2 = s2+"老金";
    s2 += "可惜";
    s2.append("是个");
    qDebug() << s2;

    //QString格式化
    QString s3,s4;
    s3.sprintf("%s%d%s","史前",400,"万年");
    s4.sprintf("%s%d%s%.1f%s","史前",400,"万年前有",0.5,"个人");
    qDebug() << s3;
    qDebug() << s4;

    QString s5;
    s5 = QString("%1%2%3").arg("史前").arg(400).arg("万年");
    qDebug() << s5;

    //at()  返回QChar类型
    QString s6 = "lione";
    qDebug() << s6.at(1);

    //插入字符
    QString s7 = "Love";
    QString s8 = " you";
    s7.insert(4,s8);
    qDebug() << s7;

    //prepend()在字符串起始位置插入
    QString s9 = "i ";
    s7.prepend(s9);
    qDebug() << s7;

    //replace()替换字符
    qDebug() << s7.replace(7,3,"her");

    //trimmed()去除字符串两端空格
    s7 = "    "+s7+"   ";
    qDebug() << s7.trimmed();

    //simplified()去除两端空格，中间空格以单个空格替代
    QString s10 = "   I   love you  too  ";
    qDebug() << s10.simplified();

    //查询字符 startsWith()、endsWith()、contains()
    QString s11 = "这是一段test字符串";
    qDebug() << s11.startsWith("s");
    qDebug() << s11.endsWith("串");
    //Qt::CaseInsensitive大小写不敏感，把In去掉为敏感
    qDebug() << s11.contains("Test",Qt::CaseInsensitive);
    //compare()结果为0表示相等
    qDebug() << QString::compare("test","Test",Qt::CaseInsensitive);

    //splist()分割字符串
    QString s12 = "2020/10/15";
    QStringList sList = s12.split("/");
    qDebug() << "字符串分割";
    foreach(QString ss ,sList)
    {
        qDebug() << ss;
    }


    //mid(n,m)截取字符串，从n开始截取m个字符
    QString s13 = "这是一段测试字符串";
    qDebug() << s13.mid(2,4);

    //NULL字符串与空字符串，默认构造为NULL，赋空字符串不为NULL
    qDebug() << QString().isNull();
    qDebug() << QString().isEmpty();
    qDebug() << QString("").isNull();
    qDebug() << QString("").isEmpty();


    qDebug() << "容器QStringList：";
    QStringList WeekList;
    WeekList << "星期一" << "星期二" << "星期三";
    WeekList << "星期四" << "星期五" << "星期六";
    WeekList.append("星期天");
    //遍历链表可以直接打印或者用for和foreach
    qDebug() << WeekList;
    qDebug() << "for 遍历：";
    for(int i = 0;i < WeekList.size(); i++)
    {
        qDebug() << WeekList.at(i);
    }
    qDebug() << "foreach 遍历：";
    foreach(QString s,WeekList)
    {
        qDebug() << s;
    }
    qDebug() << "STL迭代器遍历：";
    QStringList::iterator it = WeekList.begin();
    for( ;it != WeekList.end(); ++it)
    {
        qDebug() << *it;
    }
    qDebug() << "JAVA风格遍历：";
    QListIterator<QString> itr(WeekList);
    while(itr.hasNext())
    {
        qDebug() << itr.next();
    }

    //contains() 判断是否包含
    qDebug() << WeekList.contains("星期一");

    //insert() 插入元素
    WeekList.insert(0,"星期零");
    WeekList.insert(8,"星期八");
    qDebug() << WeekList;

    //删除头尾元素
//    WeekList.pop_back();删除尾元素
//    WeekList.pop_front();删除头元素
    WeekList.removeFirst();
    WeekList.removeLast();
    qDebug() << WeekList;

    //removerOne()删除指定元素
    WeekList.removeOne("星期一");
    qDebug() << WeekList;

     //removerAt()删除指定位置元素
    WeekList.removeAt(0);
    qDebug() << WeekList;

    //清空元素
    WeekList.clear();
    qDebug() << WeekList;




    return a.exec();
}



















