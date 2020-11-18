#include "widget.h"
#include "ui_widget.h"
#include <QtDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    qDebug() << "widget构造！" << this;
}

Widget::~Widget()
{
    delete ui;
    qDebug() << "widget析构！" << this;
}

