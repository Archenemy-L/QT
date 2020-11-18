#include "testlayout.h"
#include "ui_testlayout.h"

TestLayout::TestLayout(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TestLayout)
{
    ui->setupUi(this);
}

TestLayout::~TestLayout()
{
    delete ui;
}

