#include "widget.h"

#include <QApplication>
#include <QtDebug>
#include "mylabel.h"
#include "mypushbutton.h"
#include "myradiobutton.h"
#include "mylayout.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;


    MyLabel *mylabel = new MyLabel(&w);
    MyPushButton *mypbtn = new MyPushButton(&w);
    MyRadioButton *myrdbtn = new MyRadioButton(&w);
    MyLayout *mylayout = new MyLayout(&w);

    MyLayout *sunlayout = new MyLayout(mylabel);
    MyPushButton *sunpbtn1 = new MyPushButton;
    MyPushButton *sunpbtn2 = new MyPushButton;
    MyPushButton *sunpbtn3 = new MyPushButton;
    sunpbtn1->setText("孙按钮1");
    sunpbtn2->setText("孙按钮2");
    sunpbtn3->setText("孙按钮3");
    sunlayout->addWidget(sunpbtn1);
    sunlayout->addWidget(sunpbtn2);
    sunlayout->addWidget(sunpbtn3);
    mylabel->setLayout(sunlayout);


    mylabel->setText("子标签");
    mypbtn->setText("子按钮");
    myrdbtn->setText("子单选");

    mylayout->addWidget(mylabel,0,0);
    mylayout->addWidget(mypbtn,1,0);
    mylayout->addWidget(myrdbtn,2,0);

    w.setLayout(mylayout);

    w.show();

    qDebug() << "w.children()";
    const QObjectList list = w.children();
    foreach(QObject *obj,list)
    {
        qDebug() << obj;
    }

    qDebug() << "mylabel->children()";
    const QObjectList listmylabel = mylabel->children();
    foreach(QObject *obj,listmylabel)
    {
        qDebug() << obj;
    }

    mylabel->deleteLater();


    return a.exec();
}





