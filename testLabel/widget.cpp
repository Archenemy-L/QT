#include "widget.h"
#include "ui_widget.h"
#include <QMovie>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->txtLabel->setText("Label文本显示，这是一段文本。。。。。");
    ui->numLabel->setNum(3.141596);

    ui->picLabel->setPixmap(QPixmap("1.jpg"));

    QMovie * movie = new QMovie("cat.gif");
    ui->gifLabel->setMovie(movie);
    //设置填充
    ui->gifLabel->setScaledContents(true);
    movie->start();

    ui->checkBox_2->setChecked(true);

    qDebug()<<"多选按钮篮球选中状态："<<ui->checkBox_3->isChecked();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_toggled(bool checked)
{
    qDebug()<<"按钮选中状态："<<checked;
}

void Widget::on_radioButton_2_toggled(bool checked)
{
    qDebug()<<"单选按钮（男）选中状态："<<checked;
}

void Widget::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked)
    {
        qDebug() <<"没打篮球";
    }
    else if(arg1 == Qt::PartiallyChecked)
    {
        qDebug() <<"打了部分篮球";
    }
    else
    {
        qDebug() <<"打了篮球";
    }
}
