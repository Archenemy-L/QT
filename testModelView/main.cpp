#include <QApplication>
#include <QAbstractTableModel>  //模型基类
#include <QAbstractItemView>    //视图
#include <QItemSelectionModel>  //项目选择模型
#include <QDirModel>    //目录模型
#include <QTreeView>    //树视图
#include <QListView>    //列表视图
#include <QTableView>   //表格视图
#include <QSplitter>    //窗体分割

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    //创建目录模型
    QDirModel model;
    //创建视图 显示系统目录
    QTreeView tree;
    QListView list;
    QTableView table;
    //视图设置模型
    tree.setModel(&model);
    list.setModel(&model);
    table.setModel(&model);
    //设置视图对象的选择方式
    tree.setSelectionMode(QAbstractItemView::MultiSelection);   //MultiSelection多选
    list.setSelectionMode(tree.selectionMode());    //设为树的选择方式
    table.setSelectionMode(tree.selectionMode());

    //doublClicked(QModelIndex)双击事件信号，setRootIndex(QModelIndex)跟随操作
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&list,SLOT(setRootIndex(QModelIndex)));
    QObject::connect(&tree,SIGNAL(doubleClicked(QModelIndex)),&table,SLOT(setRootIndex(QModelIndex)));

    //设置分割
    QSplitter *splitter = new QSplitter;
    splitter->addWidget(&tree);
    splitter->addWidget(&list);
    splitter->addWidget(&table);
    splitter->setWindowTitle(QString("模型/视图"));
    splitter->show();



    return app.exec();
}
