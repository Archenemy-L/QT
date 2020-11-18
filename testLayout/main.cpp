#include "testlayout.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QFormLayout>
#include <QPushButton>
#include <QSpacerItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestLayout w;
    w.setWindowTitle("设计模式实现：");
    w.show();

    QWidget qw;
    qw.setWindowTitle("代码实现：");
    QLabel *namelabel = new QLabel("姓名：(&N)");
    QLabel *agelabel = new QLabel("年龄：(&A)");
    QLabel *emlabel = new QLabel("邮箱：(&E)");
    QLabel *label4 = new QLabel("门牌号码：");
    QLabel *label5 = new QLabel("性别：");

    QRadioButton *rb1 = new QRadioButton;
    QRadioButton *rb2 = new QRadioButton;
    rb1->setText("男");
    rb2->setText("女");
    //水平布局
    QHBoxLayout *qhb = new QHBoxLayout;
    qhb->addWidget(rb1);
    qhb->addWidget(rb2);

    QLineEdit *nameEdit = new QLineEdit;
    QLineEdit *ageEdit = new QLineEdit;
    QLineEdit *emEdit = new QLineEdit;
    QLineEdit *Edit4 = new QLineEdit;

    namelabel->setBuddy(nameEdit);
    agelabel->setBuddy(ageEdit);
    emlabel->setBuddy(emEdit);


    //常用于表单布局
    QFormLayout *left = new QFormLayout;
    left->addRow(namelabel,nameEdit);
    left->addRow(agelabel,ageEdit);
    left->addRow(emlabel,emEdit);
    left->addRow(label4,Edit4);
    left->addRow(label5,qhb);

    QPushButton * okbtn = new QPushButton("确定");

    //空格控件
    QSpacerItem *qsp = new QSpacerItem(10,10);

    //垂直布局
    QVBoxLayout *qvb = new QVBoxLayout(&qw);
    qvb->addLayout(left);
    //添加空隙对象
    qvb->addItem(qsp);
    qvb->addWidget(okbtn,0,Qt::AlignRight);
    qvb->setMargin(10);//设置布局和窗体间隙
    qvb->setSpacing(10);//控件间的空隙

    qw.setLayout(qvb);


    qw.show();

    return a.exec();
}
