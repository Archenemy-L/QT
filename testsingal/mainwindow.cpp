#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //信号和槽方法参数列表都只需要写类型,信号和槽可以一对多也可以多对一
    connect(this,SIGNAL(Welcome(QString &)),this,SLOT(Welcometest(QString &)));
    //一对多
    connect(this,SIGNAL(Welcome(QString &)),this,SLOT(Welcometest1(QString &)));
    //多对一
    m_ret = connect(this,SIGNAL(Welcome1(QString &)),this,SLOT(Welcometest1(QString &)));
    //信号发送信号
    //connect(this,SIGNAL(Welcome1(QString &)),this,SLOT(Welcome(QString &)));
//    connect(this,&MainWindow::Welcome,this,&MainWindow::Welcometest);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cbtn_clicked()
{
    QString str = "欢迎！";
    //emit 发送信号Welcome
    emit Welcome(str);

    emit Welcome1(str);
}

void MainWindow::Welcometest(QString &str)
{
    QMessageBox::information(this,"提示",str);
}

void MainWindow::Welcometest1(QString &str)
{
    qDebug() << str;
}

void MainWindow::on_wbtn_clicked()
{
    QString str = "我干！";
    //emit 发送信号Welcome
    emit Welcome(str);
}

void MainWindow::on_pushButton_clicked()
{
    //断开信号和槽
    //disconnect(this,SIGNAL(Welcome1(QString &)),this,SLOT(Welcometest1(QString &)));
    disconnect(m_ret);
    qDebug() << "已断开一个信号和一个槽连接";
}

void MainWindow::on_pushButton_2_clicked()
{
    //断开一个信号连接的所有槽
    disconnect(this,SIGNAL(Welcome(QString &)),0,0);
    qDebug() << "已断开一个信号连接的所有槽连接";
}

void MainWindow::on_pushButton_3_clicked()
{
    disconnect(this,0,this,0);
    //disconnect(this,0,0,0);断开this所有相关的槽相应
    qDebug() << "已断开this发射的所有信号与this对象的所有槽连接";
}
