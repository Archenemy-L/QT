#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H
#include <QSyntaxHighlighter>

class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    MySyntaxHighlighter(QTextDocument* parent = 0);

protected:
    void highlightBlock(const QString& text); //重写高亮文本块函数

};

#endif // MYSYNTAXHIGHLIGHTER_H
