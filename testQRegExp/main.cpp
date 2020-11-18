#include <QCoreApplication>
#include <QDebug>
#include <QRegularExpression>   //Qt5新的正则表达式类名

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QRegExp reg("a");
    qDebug() << "匹配字符本身："
             << reg.exactMatch("abc")
             << reg.exactMatch("a")
             << endl;

    QRegExp reg0("(\\d*\\D{2})");   //任意数字(\\d*)两个非数字(\\D{2})
    qDebug() << "匹配数字："
             << reg0.exactMatch("180cm")
             << reg0.exactMatch("170m")
             << reg0.exactMatch("72in");

    QRegExp rx("*.txt");
    rx.setPatternSyntax(QRegExp::Wildcard); //支持通配符
    qDebug() << "通配符匹配："
             << rx.exactMatch("loney.txt")
             << rx.exactMatch("bi.exe")
             << endl;

    //匹配单词的边界
    QRegExp reg1;
    //设置匹配模式
    reg1.setPattern("\\b(hello|Hello)\\b");             //前后需要有单词边界，像 hello 或 Hello
    qDebug() << "匹配多个单词："
             << reg1.indexIn("helloEveryone!")          //indexIn()匹配单个单词返回首字母位置
             << reg1.indexIn("Hmm hello everyone!")
             << reg1.indexIn("Hi girls! Hello boys!")
             << endl;

    //捕获匹配到的文本
    //非捕获括号语法：由 “(?:” 开始 由 “)” 结束
    QRegExp regHeight("(\\d+)(?:\\s*)(cm|inch)");       //(\\d+)任意数字 (?:\\s*)不捕获任意空格 (cm|inch)cm或inch
    int res = regHeight.indexIn("YaoMing 226 cm");
    if(res > -1)
    {
        qDebug() << "文本捕获："
                 << "cap(0)：" << regHeight.cap(0)        //cap(0)捕获匹配到的所有文本
                 << "cap(1)：" << regHeight.cap(1)       //cap(1)捕获匹配到的第一个字符
                 << "cap(2)：" << regHeight.cap(2)
                 << endl;
    }

    //断言(?!E)不紧跟E才匹配
    QRegExp reg2;
    reg2.setPattern("面(?!包)");
    QString str = "面没了，吃面包也好，吃面也好。";
    str.replace(reg2,"鸡腿");
    qDebug() << str << endl;

    //QT5引进了新的类
    QRegularExpression regExp("hello");

    qDebug() << "QRegularExpression 匹配字符："
             << regExp.match("hello word!");

    regExp.setPattern("[A-Z]{3,8}");
    regExp.setPatternOptions(QRegularExpression::CaseInsensitiveOption);    //设置匹配模式大小写不敏感
    qDebug() << "大小写不敏感匹配："
             << regExp.match("abc");

    QRegularExpression reData("^(\\d\\d)/(\\d\\d)/(\\d\\d\\d\\d)$");
    QRegularExpressionMatch match0 = reData.match("01/10/1949");
    if( match0.hasMatch())
    {
        QString strMatch = match0.captured(0);  //captured()捕获文本
        QString day = match0.captured(1);
        QString month = match0.captured(2);
        QString year = match0.captured(3);
        qDebug() << "QRegularExpression 捕获文本："
                 << strMatch << endl
                 << year << "年"
                 << month << "月"
                 << day << "日"
                 << endl;
    }

    QString sPattern;
    sPattern = "^(Jan|Feb|Mar|Apr|May) \\d\\d \\d\\d\\d\\d$";
    QRegularExpression reData1(sPattern);
    QString ss("Apr 01");
    QRegularExpressionMatch match2;
    match2 = reData1.match(ss,0,QRegularExpression::PartialPreferFirstMatch);   //(匹配字符串,偏移量,部分匹配)
    bool bHasMatched = match2.hasMatch();       //完全匹配
    bool bPartial = match2.hasPartialMatch();   //部分匹配
    qDebug() << bHasMatched << bPartial << endl;





    return a.exec();
}





















