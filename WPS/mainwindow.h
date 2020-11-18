#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "childwnd.h"
#include <QSignalMapper>    //信号映射器类
#include <QMdiSubWindow>
#include <QtPrintSupport/QPrinter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initMainWindow();      //初始化主窗口
    void docNew();              //新建文件`
    void docOpen();             //打开文档
    void docSave();             //保存文件
    void docSaveAs();           //另存为文件
    void docPrint();            //打印
    void docPreview();          //打印预览
    void docUndo();             //撤销
    void docRedo();             //重做
    void docCut();              //剪切
    void docCopy();             //复制
    void docPaste();            //粘贴
    void textBold();            //加粗
    void textItalic();          //倾斜
    void textUnderline();       //下划线
    void textFamily(const QString &fmly);   //字体
    void textSize(const QString &ps);       //字号
    void textColor();           //字体颜色
    void paraStyle(int nStyle); //项目符号

private slots:
    void on_newAction_triggered();      //新建点击信号和槽
    void refreshMenus();                //刷新菜单
    void addSubWndListMenu();           //更新菜单

    void on_closeAction_triggered();

    void on_closeAllAction_triggered();

    void on_titleAction_triggered();

    void on_cascadeAction_triggered();

    void on_nextAction_triggered();

    void on_previousAction_triggered();

    void SetActiveSubWindow(QWidget* wnd);  //点击菜单栏，设置活动窗口

    void on_openAction_triggered();

    void on_saveAction_triggered();

    void on_saveAsAction_triggered();

    void on_undoAction_triggered();

    void on_redoAction_triggered();

    void on_cutAction_triggered();

    void on_copyAction_triggered();

    void on_pasteAction_triggered();

    void on_boldAction_triggered();

    void on_italicAction_triggered();

    void on_underlinAction_triggered();

    void on_fontComboBox_activated(const QString &arg1);

    void on_sizeComboBox_activated(const QString &arg1);

    void on_leftAlignAction_triggered();

    void on_centerAlignAction_triggered();

    void on_rightAlignAction_triggered();

    void on_justifyAlignAction_triggered();

    void on_colorAction_triggered();

    void on_comboBox_activated(int index);

    void on_printAction_triggered();

    void printPreview(QPrinter *printer);

    void on_printPreviewAction_triggered();

protected:
    void closeEvent(QCloseEvent *event);  //关闭事件重写

private:
    void formatEnabled();           //开启控件
    ChildWnd* activateChidWnd();    //获取活动子窗口
    QMdiSubWindow* findChildWnd(const QString& docName);    //查找文件是否打开


private:
    Ui::MainWindow *ui;
    QSignalMapper* m_WndMapper;     //信号映射器
};
#endif // MAINWINDOW_H
