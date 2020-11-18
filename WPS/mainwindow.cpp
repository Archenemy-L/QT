#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMdiSubWindow>
#include <QCloseEvent>
#include <QFileDialog>
#include <QColorDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initMainWindow();   //初始化字号列表
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainWindow()
{
    setWindowTitle("我的WPS");
    //初始化字号列表项
    QFontDatabase fontdb;   //字体数据库类
    foreach(int fontsize,fontdb.standardSizes())
    {
        ui->sizeComboBox->addItem(QString::number(fontsize));   //添加下拉框选项
    }

    QFont defFont;      //当前应用程序默认的字体
    QString sFontSize;
    int defFontSize;    //当前应用程序默认字体的字号
    int defFontindex;   //当前字号在组合框中的索引位置

    defFont = QApplication::font();     //获取当前应用程序字体
    defFontSize = defFont.pointSize();  //字号
    sFontSize = QString::number(defFontSize);
    defFontindex = ui->sizeComboBox->findText(sFontSize);   //查找索引位置

    ui->sizeComboBox->setCurrentIndex(defFontindex);        //设置当前字体列表项默认值

    //设置多文档滚动条
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);   //设置窗口水平滚动条
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);     //垂直滚动条 Qt::ScrollBarAsNeeded需要时出现不需要则隐藏

    //刷新菜单项
    refreshMenus();
    connect(ui->mdiArea,&QMdiArea::subWindowActivated,this,&MainWindow::refreshMenus);           //&QMdiArea::subWindowActivated活动子窗口

    //更新菜单项
    addSubWndListMenu();
    connect(ui->menu_W,&QMenu::aboutToShow,this,&MainWindow::addSubWndListMenu);

    //创建信号映射器
    m_WndMapper = new QSignalMapper(this);
    connect(m_WndMapper,SIGNAL(mapped(QWidget*)),this,SLOT(SetActiveSubWindow(QWidget*)));

    //添加对齐分组，保证互斥性
    QActionGroup *alignGroup = new QActionGroup(this);
    alignGroup->addAction(ui->leftAlignAction);
    alignGroup->addAction(ui->centerAlignAction);
    alignGroup->addAction(ui->rightAlignAction);
    alignGroup->addAction(ui->justifyAlignAction);

}

void MainWindow::docNew()
{
    ChildWnd *childwnd = new ChildWnd;
    ui->mdiArea->addSubWindow(childwnd);    //添加子窗口部件
    connect(childwnd,SIGNAL(copyAvailable(bool)),ui->cutAction,SLOT(setEnabled(bool)));     //剪切信号
    connect(childwnd,SIGNAL(copyAvailable(bool)),ui->copyAction,SLOT(setEnabled(bool)));    //复制信号

    childwnd->newDoc();
    childwnd->show();
    formatEnabled();
}

void MainWindow::docOpen()
{
    QString docName = QFileDialog::getOpenFileName(this,"打开文档","","文本文件(*.txt);;HTML文件(*.html *.htm);;所有文件(*.*)");
    if(!docName.isEmpty())
    {
        QMdiSubWindow *existWnd =  findChildWnd(docName);
        if(existWnd)
        {
            ui->mdiArea->setActiveSubWindow(existWnd);
            return;
        }
        ChildWnd *childWnd = new ChildWnd;
        ui->mdiArea->addSubWindow(childWnd);

        //复制和剪切信号启用
        connect(childWnd,SIGNAL(copyAvailable(bool)),ui->copyAction,SLOT(setEnabled(bool)));
        connect(childWnd,SIGNAL(copyAvailable(bool)),ui->cutAction,SLOT(setEnabled(bool)));

        if(childWnd->loadDoc(docName))
        {
            statusBar()->showMessage("文档已打开",3000); //状态栏设置
            childWnd->show();
            formatEnabled();    //刷新格式
        }
        else
        {
            childWnd->close();
        }
    }

}

void MainWindow::docSave()
{
    if(activateChidWnd() && activateChidWnd()->saveDoc())
    {
        statusBar()->showMessage("保存成功",3000);
    }
}

void MainWindow::docSaveAs()
{
    if(activateChidWnd() && activateChidWnd()->saveAsDoc())
    {
        statusBar()->showMessage("保存成功",3000);
    }
}

void MainWindow::docPrint()
{
    QPrinter pter(QPrinter::HighResolution);    //像素为打印机的像素
    QPrintDialog *ddlg = new QPrintDialog(&pter,this);
    if(activateChidWnd())
    {
        ddlg->setOption(QAbstractPrintDialog::PrintSelection);  //打印窗口，用户选择
    }
    ddlg->setWindowTitle("打印文档");

    ChildWnd* childWnd = activateChidWnd();
    if(ddlg->exec() == QDialog::Accepted)   //QDialog::Accepted运行后用户选择接收
    {
        childWnd->print(&pter);     //进行打印
    }
    delete  ddlg;
}

void MainWindow::docPreview()
{
    QPrinter pter;
    QPrintPreviewDialog preview(&pter,this);
    connect(&preview,SIGNAL(paintRequested(QPrinter*)),this,SLOT(printPreview(QPrinter*)));
    preview.exec();
}

void MainWindow::docUndo()
{
    if(activateChidWnd())
        activateChidWnd()->undo();
}

void MainWindow::docRedo()
{
    if(activateChidWnd())
        activateChidWnd()->redo();
}

void MainWindow::docCut()
{
    if(activateChidWnd())
        activateChidWnd()->cut();
}

void MainWindow::docCopy()
{
    if(activateChidWnd())
        activateChidWnd()->copy();
}

void MainWindow::docPaste()
{
    if(activateChidWnd())
        activateChidWnd()->paste();
}

void MainWindow::textBold()
{
    QTextCharFormat fmt;
    fmt.setFontWeight(ui->boldAction->isChecked() ? QFont::Bold : QFont::Normal);   //加粗
    if(activateChidWnd())
    {
        activateChidWnd()->setFormatOnSelectedWord(fmt);    //设置选中文字
    }
}

void MainWindow::textItalic()
{
    QTextCharFormat fmt;
    fmt.setFontItalic(ui->italicAction->isChecked());     //倾斜
    if(activateChidWnd())
    {
        activateChidWnd()->setFormatOnSelectedWord(fmt);    //设置选中文字
    }
}

void MainWindow::textUnderline()
{
    QTextCharFormat fmt;
    fmt.setFontUnderline(ui->underlinAction->isChecked());  //下划线
    if(activateChidWnd())
    {
        activateChidWnd()->setFormatOnSelectedWord(fmt);    //设置选中文字
    }
}

void MainWindow::textFamily(const QString &fmly)
{
    QTextCharFormat fmt;
    fmt.setFontFamily(fmly);
    if(activateChidWnd())
    {
        activateChidWnd()->setFormatOnSelectedWord(fmt);
    }
}

void MainWindow::textSize(const QString &ps)
{
    qreal pointSize = ps.toFloat();     ///qreal = double类型
    if(ps.toFloat() > 0)
    {
        QTextCharFormat fmt;
        fmt.setFontPointSize(pointSize);    //设置字号
        if(activateChidWnd())
        {
            activateChidWnd()->setFormatOnSelectedWord(fmt);
        }
    }
}

void MainWindow::textColor()
{
    if(activateChidWnd())
    {
        QColor color = QColorDialog::getColor(activateChidWnd()->textColor(),this);
        //判断是否合法
        if(!color.isValid()) return;

        QTextCharFormat fmt; //文本格式类
        fmt.setForeground(color);
        activateChidWnd()->setFormatOnSelectedWord(fmt);
        //填充用户所选颜色
        QPixmap pix(16,16);
        pix.fill(color);
        ui->colorAction->setIcon(pix);
    }
}

void MainWindow::paraStyle(int nStyle)
{
    if(activateChidWnd())
    {
        activateChidWnd()->setPareSyle(nStyle);
    }
}

void MainWindow::formatEnabled()
{
    ui->boldAction->setEnabled(true);
    ui->italicAction->setEnabled(true);
    ui->underlinAction->setEnabled(true);
    ui->leftAlignAction->setEnabled(true);
    ui->centerAlignAction->setEnabled(true);
    ui->rightAlignAction->setEnabled(true);
    ui->justifyAlignAction->setEnabled(true);
    ui->colorAction->setEnabled(true);

}

ChildWnd *MainWindow::activateChidWnd()
{
    QMdiSubWindow* actWnd = ui->mdiArea->activeSubWindow();     //保存当前活动子窗口
    if(actWnd)
    {
        return qobject_cast<ChildWnd*>(actWnd->widget());
    }
    else
    {
        return 0;
    }
}

QMdiSubWindow *MainWindow::findChildWnd(const QString &docName)
{
    QString strFile = QFileInfo(docName).canonicalFilePath();   //返回标准文件路径
    foreach(QMdiSubWindow* subWnd,ui->mdiArea->subWindowList())
    {
        ChildWnd* childWnd = qobject_cast<ChildWnd*>(subWnd->widget());
        if(childWnd->m_CurDocPath == strFile)
        {
            return subWnd;
        }
    }
    return 0;
}

void MainWindow::refreshMenus()
{
    bool hasChild = false;
    hasChild = (activateChidWnd() != 0);

    ui->saveAction->setEnabled(hasChild);
    ui->saveAsAction->setEnabled(hasChild);
    ui->printAction->setEnabled(hasChild);
    ui->printPreviewAction->setEnabled(hasChild);
    ui->pasteAction->setEnabled(hasChild);
    ui->closeAction->setEnabled(hasChild);
    ui->closeAllAction->setEnabled(hasChild);
    ui->titleAction->setEnabled(hasChild);
    ui->cascadeAction->setEnabled(hasChild);
    ui->nextAction->setEnabled(hasChild);
    ui->previousAction->setEnabled(hasChild);

    //文本打开且有内容选中
    bool hasSelect = ( activateChidWnd() && activateChidWnd()->textCursor().hasSelection());     //textCursor()判断光标信息，hasSelection()判断光标是否有文本选中
    ui->cutAction->setEnabled(hasSelect);
    ui->copyAction->setEnabled(hasSelect);
    ui->boldAction->setEnabled(hasSelect);
    ui->italicAction->setEnabled(hasSelect);
    ui->underlinAction->setEnabled(hasSelect);
    ui->leftAlignAction->setEnabled(hasSelect);
    ui->centerAlignAction->setEnabled(hasSelect);
    ui->rightAlignAction->setEnabled(hasSelect);
    ui->justifyAlignAction->setEnabled(hasSelect);
    ui->colorAction->setEnabled(hasSelect);
}

void MainWindow::addSubWndListMenu()
{
    ui->menu_W->clear();        //每次调用清空菜单栏
    //重新添加菜单栏
    ui->menu_W->addAction(ui->closeAction);
    ui->menu_W->addAction(ui->closeAllAction);
    ui->menu_W->addSeparator(); //添加分割线
    ui->menu_W->addAction(ui->titleAction);
    ui->menu_W->addAction(ui->cascadeAction);
    ui->menu_W->addSeparator();
    ui->menu_W->addAction(ui->nextAction);
    ui->menu_W->addAction(ui->previousAction);

    QList<QMdiSubWindow*> wnds = ui->mdiArea->subWindowList();      //保存所有子窗口的链表
    if(!wnds.isEmpty())
    {
        ui->menu_W->addSeparator(); //添加分隔线
    }
    for(int i = 0 ; i < wnds.size() ; ++i)
    {
        ChildWnd* chileWnd = qobject_cast<ChildWnd*>(wnds.at(i)->widget()); //转换成ChildWnd*类型
        QString menuitem_text;
        menuitem_text = QString("%1 %2").arg(i+1).arg(chileWnd->getCurDocName());

        QAction *menuitem_act = ui->menu_W->addAction(menuitem_text);   //添加菜单项
        menuitem_act->setCheckable(true);               //设置可勾选
        menuitem_act->setChecked(chileWnd == activateChidWnd());    //判断是否为当前活动窗口

        //点击时发送map信号
        connect(menuitem_act,SIGNAL(triggered(bool)),m_WndMapper,SLOT(map()));
        //设置发送信号的对象，以及接收的窗体
        m_WndMapper->setMapping(menuitem_act,wnds.at(i));
    }
    formatEnabled();    //更新格式
}

void MainWindow::on_newAction_triggered()
{
    docNew();
}

void MainWindow::on_closeAction_triggered()
{
    ui->mdiArea->closeActiveSubWindow();    //关闭活动子窗口
}

void MainWindow::on_closeAllAction_triggered()
{
    ui->mdiArea->closeAllSubWindows();      //关闭所有窗口
}

void MainWindow::on_titleAction_triggered()
{
    ui->mdiArea->tileSubWindows();      //平铺
}

void MainWindow::on_cascadeAction_triggered()
{
    ui->mdiArea->cascadeSubWindows();   //层叠
}

void MainWindow::on_nextAction_triggered()
{
    ui->mdiArea->activateNextSubWindow();   //下一个
}

void MainWindow::on_previousAction_triggered()
{
    ui->mdiArea->activatePreviousSubWindow();   //前一个
}

void MainWindow::SetActiveSubWindow(QWidget *wnd)
{
    if(!wnd)
    {
        return;
    }
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow*>(wnd));     //设置活动窗口
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow()) //判断是否还有子窗口
    {
        event->ignore();    //忽略此事件
    }
    else
    {
        event->accept();    //接收
    }
}

void MainWindow::on_openAction_triggered()
{
    docOpen();
}

void MainWindow::on_saveAction_triggered()
{
    docSave();
}

void MainWindow::on_saveAsAction_triggered()
{
    docSaveAs();
}

void MainWindow::on_undoAction_triggered()
{
    docUndo();
}

void MainWindow::on_redoAction_triggered()
{
    docRedo();
}

void MainWindow::on_cutAction_triggered()
{
    docCut();
}

void MainWindow::on_copyAction_triggered()
{
    docCopy();
}

void MainWindow::on_pasteAction_triggered()
{
    docPaste();
}

void MainWindow::on_boldAction_triggered()
{
    textBold();
}

void MainWindow::on_italicAction_triggered()
{
    textItalic();
}

void MainWindow::on_underlinAction_triggered()
{
    textUnderline();
}

void MainWindow::on_fontComboBox_activated(const QString &arg1)
{
    textFamily(arg1);
}

void MainWindow::on_sizeComboBox_activated(const QString &arg1)
{
    textSize(arg1);
}

void MainWindow::on_leftAlignAction_triggered()
{
    if(activateChidWnd())
    {
        activateChidWnd()->setAlignOfDocumentText(1);
    }
}

void MainWindow::on_centerAlignAction_triggered()
{
    if(activateChidWnd())
    {
        activateChidWnd()->setAlignOfDocumentText(3);
    }
}

void MainWindow::on_rightAlignAction_triggered()
{
    if(activateChidWnd())
    {
        activateChidWnd()->setAlignOfDocumentText(2);
    }
}

void MainWindow::on_justifyAlignAction_triggered()
{
    if(activateChidWnd())
    {
        activateChidWnd()->setAlignOfDocumentText(4);
    }
}

void MainWindow::on_colorAction_triggered()
{
    textColor();
}

void MainWindow::on_comboBox_activated(int index)
{
    paraStyle(index);
}

void MainWindow::on_printAction_triggered()
{
    docPrint();
}

void MainWindow::printPreview(QPrinter *printer)
{
    activateChidWnd()->print(printer);
}

void MainWindow::on_printPreviewAction_triggered()
{
    docPreview();
}
