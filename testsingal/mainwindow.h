#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //信号定义，函数返回值都为空，无需实现也不能实现
signals:
    void Welcome(QString &str);
    void Welcome1(QString &str);

private slots:
    void on_cbtn_clicked();

    void Welcometest(QString &str); //槽函数参数数量得小于等于信号参数
    void Welcometest1(QString &str);

    void on_wbtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    //connect的返回值类型
    QMetaObject::Connection m_ret;
};
#endif // MAINWINDOW_H
