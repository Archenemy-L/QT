#include "myaction.h"
#include <QSplitter>
#include <QLabel>

MyAction::MyAction(QObject* parent):QWidgetAction(parent)
{
    lintEdit = new QLineEdit;       //用来发送回车信号
    //QLineEdit::returnPressed回车信号
    connect(lintEdit,&QLineEdit::returnPressed,this,&MyAction::sendText);
}

QWidget *MyAction::createWidget(QWidget *parent)
{
    //判断parent是否继承至QMenu类或QToolBar类
    //如果是则创建父部件的子部件并放回子部件
    if(parent->inherits("QMenu")||parent->inherits("QToolBar"))
    {
        //分割部件类
        QSplitter *splitter = new QSplitter(parent);
        QLabel *label = new QLabel("插入文本:");
        splitter->addWidget(label);
        splitter->addWidget(lintEdit);
        return splitter;
    }
    return 0;
}

void MyAction::sendText()
{
    emit getText(lintEdit->text()); //发送获取文本信号
    lintEdit->clear();  //清空
}
