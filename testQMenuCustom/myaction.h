#ifndef MYACTION_H
#define MYACTION_H
#include <QWidgetAction>
#include <QLineEdit>

/*
    自定义菜单，需要继承自QWidgetAction类
    以及重写QWidget* createWidget(QWidget *parent)函数
*/

class MyAction : public QWidgetAction
{
    Q_OBJECT
public:
    MyAction(QObject* parent = 0);

protected:
    QWidget* createWidget(QWidget *parent);

signals:
    void getText(const QString& string);

private slots:
    void sendText();    //发送文本
private:
    QLineEdit* lintEdit;
};

#endif // MYACTION_H
