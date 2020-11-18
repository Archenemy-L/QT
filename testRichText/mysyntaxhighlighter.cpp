#include "mysyntaxhighlighter.h"

MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument* parent):QSyntaxHighlighter(parent)
{

}

void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat format;//字符格式
    format.setFontWeight(QFont::Bold);  //加粗
    format.setBackground(Qt::red);  //背景色
    format.setForeground(Qt::green);    //前景色

    QString patter = "\\bgood\\b";  //单词边界(\\b)
    QRegExp expression(patter);
    int index = text.indexOf(expression);   //匹配并且返回位置
    while(index >= 0)
    {
        int length = expression.matchedLength(); //返回匹配到的字符长度
        setFormat(index,length,format); //设置格式(开始位置,结束位置,格式)
        index = text.indexOf(expression,index + length);    //多次匹配
    }
}
