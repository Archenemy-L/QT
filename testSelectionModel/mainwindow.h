#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QItemSelection>
#include <QModelIndex>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void getCurrentItemData();      //当前选择
    void toggleSection();           //切换选择
    //更新选择
    void updataSelection(const QItemSelection &selected,const QItemSelection &deselected);

    //改变当前模型索引
    void changeCurrent(const QModelIndex &current,const QModelIndex &previous);

private:
    Ui::MainWindow *ui;
    QTableView *m_tableView;
    QTableView *m_tableView2;

};
#endif // MAINWINDOW_H
