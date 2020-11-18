#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QDebug>
#include "spinboxdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建标准项目模型
    QStandardItemModel *model = new QStandardItemModel(7,4,this);
    for(int row = 0;row < 7; ++row)
    {
        for(int column = 0;column < 4; ++column)
        {
            QStandardItem *item = new QStandardItem(QString("%1").arg(row*4));
            //设置数据项
            model->setItem(row,column,item);
        }
    }
    m_tableView = new QTableView;
    m_tableView->setModel(model);
    setCentralWidget(m_tableView);  //设置主窗口的中心部件

    //获取视图选择模式
    QItemSelectionModel *selectModel = m_tableView->selectionModel();

    QModelIndex topLeft;    //左上角模型索引
    QModelIndex bottomRight;//右下角模型索引
    topLeft = model->index(1,1);
    bottomRight = model->index(5,2);

    //创建模型选择
    QItemSelection selection(topLeft,bottomRight);
    //以选择的方式选择项目
    selectModel->select(selection,QItemSelectionModel::Select);

    //添加动作(动作文本,响应者,槽方法)
    ui->menubar->addAction(QString("当前项目"),this,&MainWindow::getCurrentItemData);
    ui->menubar->addAction(QString("切换选择"),this,&MainWindow::toggleSection);

    //关联选择模型的选择改变、当前项改变的信号
    connect(selectModel,&QItemSelectionModel::selectionChanged,this,&MainWindow::updataSelection);
    connect(selectModel,&QItemSelectionModel::currentChanged,this,&MainWindow::changeCurrent);

    m_tableView2 = new QTableView;
    m_tableView2->setWindowTitle("tableView2");
    m_tableView2->resize(400,300);
    m_tableView2->setModel(model);
    m_tableView2->setSelectionModel(selectModel);
    m_tableView2->show();

    //自定义委托实现编辑器效果
    SpinBoxDelegate *delegate = new SpinBoxDelegate(this);
    m_tableView->setItemDelegate(delegate);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_tableView2;
}

void MainWindow::getCurrentItemData()
{
    qDebug() << QString("当前项目数据：")
             << m_tableView->selectionModel()->currentIndex().data().toString();
}

void MainWindow::toggleSection()
{
    //左上角模型索引
    QModelIndex topLeft = m_tableView->model()->index(0,0,QModelIndex());
    //右下角模型索引
    QModelIndex bottomRight = m_tableView->model()->index
                              (m_tableView->model()->rowCount(QModelIndex()) - 1,
                               m_tableView->model()->columnCount(QModelIndex())-1);
    //项选择
    QItemSelection curSelection(topLeft,bottomRight);
    m_tableView->selectionModel()->select(curSelection,QItemSelectionModel::Toggle);
}

void MainWindow::updataSelection(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndex index;
    //indexes()返回所有选择项的索引
    QModelIndexList list = selected.indexes();

    //给现在选择的项目填充数据
    foreach(index,list)
    {
        QString text = QString("%1,%2").arg(index.row()).arg(index.column());
        m_tableView->model()->setData(index,text);
    }
    //清空上一次选择的内容
    list = deselected.indexes();
    foreach(index,list)
    {
        m_tableView->model()->setData(index,"");
    }

}

void MainWindow::changeCurrent(const QModelIndex &current, const QModelIndex &previous)
{
    qDebug() << QString("从(%1,%2)到(%3,%4)")
                    .arg(previous.row()).arg(previous.column())
                    .arg(current.row()).arg(current.column());

}

