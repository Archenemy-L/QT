#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>
#include <QFileDialog>
#include <QImageReader>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //获取文档对象
    QTextDocument *document = ui->textEdit->document();

    //获取根框架
    QTextFrame *rootFrame = document->rootFrame();

    //文本框架格式
    QTextFrameFormat format;
    format.setBorderBrush(Qt::red); //设置边框颜色
    format.setBorder(3);    //设置边框宽度

    rootFrame->setFrameFormat(format);  //文档框架设置格式

    //设置文本边框风格
    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);   //设置背景颜色
    frameFormat.setMargin(10);  //设置边距
    frameFormat.setPadding(5);  //设置填衬，文本和边框距离
    frameFormat.setBorder(2);   //设置边框宽度
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_DotDash);//设置边框风格

    QTextCursor cursor = ui->textEdit->textCursor();    //获取光标
    cursor.insertFrame(frameFormat);    //插入边框风格

    QAction *action_textFrame = new QAction("框架",this);
    connect(action_textFrame,&QAction::triggered,this,&MainWindow::showTextFrame);
    ui->toolBar->addAction(action_textFrame);

    QAction *action_textBlock = new QAction("文本块",this);
    connect(action_textBlock,&QAction::triggered,this,&MainWindow::showTextBlock);
    ui->toolBar->addAction(action_textBlock);

    QAction *action_textFont = new QAction("字体",this);
    action_textFont->setCheckable(true);
    connect(action_textFont,&QAction::triggered,this,&MainWindow::setTextFont);
    ui->toolBar->addAction(action_textFont);

    QAction *action_textTable = new QAction("表格",this);
    connect(action_textTable,&QAction::triggered,this,&MainWindow::insertTable);
    ui->toolBar->addAction(action_textTable);

    QAction *action_textList = new QAction("列表",this);
    connect(action_textList,&QAction::triggered,this,&MainWindow::insertList);
    ui->toolBar->addAction(action_textList);

    QAction *action_textImage = new QAction("图片",this);
    connect(action_textImage,&QAction::triggered,this,&MainWindow::insertImage);
    ui->toolBar->addAction(action_textImage);

    //语法高亮
    m_sLighter = new MySyntaxHighlighter(ui->textEdit->document());

    QAction *action_Find = new QAction("查找",this);
    connect(action_Find,&QAction::triggered,this,&MainWindow::textFind);
    ui->toolBar->addAction(action_Find);

    m_findDialog = new QDialog(this);
    m_lineEdit = new QLineEdit(m_findDialog);

    QPushButton *btn = new QPushButton(m_findDialog);
    btn->setText("查找下一个");
    connect(btn,&QPushButton::clicked,this,&MainWindow::textNext);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(m_lineEdit);
    layout->addWidget(btn);
    m_findDialog->setLayout(layout);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextFrame()
{
    //获取文档对象
    QTextDocument *document = ui->textEdit->document();

    //获取根框架
    QTextFrame *frame = document->rootFrame();

    QTextFrame::iterator it;
    for(it = frame->begin();it != frame->end(); ++it)
    {
        //获取当前框架指针
        QTextFrame *childFrame = it.currentFrame();

        //获取当前文本块   每次换行就相当于生成一个新的文本块
        QTextBlock childBlock = it.currentBlock();
        if(childFrame)
        {
            qDebug() << "frame" ;
        }
        else if(childBlock.isValid())
        {
            qDebug() << "block:" << childBlock.text();
        }
    }


}

void MainWindow::showTextBlock()
{
    QTextDocument *document = ui->textEdit->document();

    QTextBlock block = document->firstBlock();  //获取第一个文本块
    for(int i = 0;i < document->blockCount(); ++i)
    {
        //打印输出当前文本信息
        qDebug() << QString("文本块:%1,文本块首行行号为:%2,长度为:%3,内容:%4")
                        .arg(i).arg(block.firstLineNumber())
                        .arg(block.length()).arg(block.text());
        block = block.next();
    }

}

void MainWindow::setTextFont(bool checked)
{
    if(checked)
    {
        QTextCursor cursor = ui->textEdit->textCursor();
        //设置文本块格式
        QTextBlockFormat blockFormat;
        blockFormat.setAlignment(Qt::AlignCenter);
        cursor.insertBlock(blockFormat);

        //字符格式
        QTextCharFormat charFormat;
        //背景色以及前景色(前景色=字符颜色)
        charFormat.setBackground(Qt::blue);
        charFormat.setForeground(Qt::yellow);
        //字体样式
        charFormat.setFont(QFont(QString("宋体"),12,QFont::Bold,true));
        //字体下线
        charFormat.setFontUnderline(true);
        //设置光标位置字符格式
        cursor.setCharFormat(charFormat);
        cursor.insertText("淦");


    }
}

void MainWindow::insertTable()
{
    QTextCursor cursor = ui->textEdit->textCursor();    //获取文本光标
    QTextTableFormat format;    //表格格式类
    format.setCellSpacing(2);   //外边距
    format.setCellPadding(10);  //内边距
    cursor.insertTable(3,3,format); //插入表格

}

void MainWindow::insertList()
{
    QTextListFormat format; //列表格式类
    format.setStyle(QTextListFormat::ListDecimal);  //设置列表样式
    ui->textEdit->textCursor().insertList(format);  //当前光标位置插入列表
}

void MainWindow::insertImage()
{
    QString filepath = QFileDialog::getOpenFileName(this,"选择图片",".","JPEG(*.jpg *.jpeg);;PNG(*.png);;GIF(*.gif)");
    QUrl url(QString("file://%1").arg(filepath));

    QImage image = QImageReader(filepath).read();   //读取图片

    QTextDocument* document = ui->textEdit->document();
    //添加资源(资源类型,路径,类型)
    document->addResource(QTextDocument::ImageResource,url,QVariant(image));

    //获取文档光标
    QTextCursor cursor = ui->textEdit->textCursor();
    //图片格式类
    QTextImageFormat imgFormat;
    imgFormat.setWidth(image.width());
    imgFormat.setHeight(image.height());
    imgFormat.setName(url.toString());
    //光标处插入图片
    cursor.insertImage(imgFormat);

}

void MainWindow::textFind()
{
    m_findDialog->show();
}

void MainWindow::textNext()
{
    QString strFind = m_lineEdit->text();
    //QTextDocument::FindBackward从后向前查找
    bool isFind = ui->textEdit->find(strFind,QTextDocument::FindBackward);
    if(isFind)
    {
        qDebug() << QString("行号：%1，列号：%2")
                        .arg(ui->textEdit->textCursor().blockNumber())
                        .arg(ui->textEdit->textCursor().columnNumber());
    }
}

