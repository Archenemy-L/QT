#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //菜单
    QMenu *editMenu = ui->menubar->addMenu("编辑(&E)");

    QAction *action_copy = editMenu->addAction(QIcon("copy.png"),QString("复制(&C)"));    //添加动作
    action_copy->setShortcut(QKeySequence("Ctrl + C")); //添加快捷键

    ui->toolBar->addAction(action_copy);    //动作添加到工具栏

    //动作分组
    QActionGroup *group = new QActionGroup(this);
    QAction *action_L = group->addAction("左对齐(&L)");
    QAction *action_R = group->addAction("右对齐(&R)");
    QAction *action_C = group->addAction("居中对齐(&C)");
    QAction *action_J = group->addAction("两端对齐(&J)");

    //设置可选
    action_L->setCheckable(true);
    action_R->setCheckable(true);
    action_C->setCheckable(true);
    action_J->setCheckable(true);

    //添加分割线
    editMenu->addSeparator();
    //添加动作
    editMenu->addAction(action_L);
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);
    editMenu->addAction(action_J);

    //工具栏按钮类
    QToolButton *toolBtn = new QToolButton(this);
    toolBtn->setText("颜色");

    QMenu *colorMenu = new QMenu(this);
    colorMenu->addAction("红色");
    colorMenu->addAction("绿色");
    //向工具栏按钮添加菜单
    toolBtn->setMenu(colorMenu);
    toolBtn->setPopupMode(QToolButton::MenuButtonPopup);    //设置弹出式菜单

    //添加部件到工具栏
    ui->toolBar->addWidget(toolBtn);

    QSpinBox *spinBox = new QSpinBox(this);
    ui->toolBar->addWidget(spinBox);

    //状态栏显示临时信息
    ui->statusbar->showMessage("欢迎使用",3000);

    QLabel *tag = new QLabel("www.baidu.com");
    //添加永久性部件
    ui->statusbar->addPermanentWidget(tag);

}

MainWindow::~MainWindow()
{
    delete ui;
}

