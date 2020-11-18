#include <QApplication>
#include <QDebug>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    QListWidget listWidget;

    //添加项目
    new QListWidgetItem("太阳",&listWidget);

    QListWidgetItem *listWidgetItem = new QListWidgetItem;
    listWidgetItem->setText("月亮");

    QPixmap pixmap(50,50);
    pixmap.fill(Qt::blue);
    listWidgetItem->setIcon(QIcon(pixmap));
    listWidgetItem->setToolTip("行星");

    //部件插入项目
    listWidget.insertItem(1,listWidgetItem);
    //设置排序 DescendingOrder降序
    listWidget.sortItems(Qt::DescendingOrder);

    listWidget.show();

    QTreeWidget treeWidget;
    //设置列数
    treeWidget.setColumnCount(2);

    QStringList headers;
    headers << "名字" << "数量";
    //设置表头
    treeWidget.setHeaderLabels(headers);

    //添加项目
    QTreeWidgetItem *item1 = new QTreeWidgetItem(&treeWidget);
    item1->setText(0,"猫");
    QTreeWidgetItem *item11 = new QTreeWidgetItem(item1);
    item11->setText(0,"波斯猫");
    item11->setText(1,"布偶猫");
    //添加项目指定前一项为item1
    QTreeWidgetItem *item2 = new QTreeWidgetItem(&treeWidget,item1);
    item2->setText(0,"狗");

    treeWidget.show();

    //创建表格部件指定行列
    QTableWidget tableWidget(3,2);
    QTableWidgetItem *tableWidgetItem = new QTableWidgetItem("布偶猫");
    tableWidget.setItem(0,0,tableWidgetItem);

    //创建表格项目，作为表头
    QTableWidgetItem *headerV = new QTableWidgetItem("cat");
    //设置垂直表头
    tableWidget.setVerticalHeaderItem(0,headerV);
    QTableWidgetItem *headerH = new QTableWidgetItem("猫");
    //设置水平表头
    tableWidget.setHorizontalHeaderItem(0,headerH);
    tableWidget.show();



    return app.exec();
}


