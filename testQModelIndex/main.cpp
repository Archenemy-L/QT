#include <QApplication>
#include <QTreeView>    //树视图
#include <QStandardItemModel>   //标准项目模型
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    //创建标准项模型
    QStandardItemModel model;

    //invisibleRootItem 返回标准项模型的根项，根项是不可见的
    QStandardItem *parentItem = model.invisibleRootItem();

    //创建标准项
    QStandardItem *item0 = new QStandardItem;
    item0->setText(QString("A"));

    //位图
    QPixmap pixmap0(50,50);
    pixmap0.fill(Qt::red);
    //设置图标
    item0->setIcon(pixmap0);
    //工具提示
    item0->setToolTip(QString("A项"));
    //添加行
    parentItem->appendRow(item0);
    //将item0做为父项的子项
    parentItem = item0;

    //创建item0的子项
    QStandardItem *item1 = new QStandardItem;
    item1->setText(QString("B"));
    QPixmap pixmap1(50,50);
    pixmap1.fill(Qt::blue);
    item1->setIcon(pixmap1);
    item1->setToolTip(QString("B项"));

    parentItem->appendRow(item1);

    QStandardItem *item2 = new QStandardItem;
    QPixmap pixmap2(50,50);
    pixmap2.fill(Qt::green);
    item2->setData("C",Qt::EditRole);   //设置数据，指定角色为EditRole编辑
    item2->setData("indexC",Qt::ToolTipRole);   //ToolTipRole工具提示
    item2->setData(QIcon(pixmap2),Qt::DecorationRole);  //DecorationRole渲染为图标

    parentItem->appendRow(item2);

    //在树视图中显示数据
    QTreeView view;
    view.setModel(&model);  //设置模型
    view.show();

    QModelIndex indexA = model.index(0,0,QModelIndex());
    //rowCount行计数
    qDebug() << "indexA row count:" << model.rowCount(indexA);

    QModelIndex indexB = model.index(0,0,indexA);
    //返回数据
    qDebug() << "indexB text:" << model.data(indexB,Qt::EditRole).toString();
    qDebug() << "indexB toolTip:" << model.data(indexB,Qt::ToolTipRole).toString();

    return app.exec();
}


