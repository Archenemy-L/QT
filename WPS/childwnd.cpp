#include "childwnd.h"
#include <QFileInfo>
#include <QFileDialog>
#include <QTextDocumentWriter>
#include <QMessageBox>
#include <QTextList>
#include <QTextBlockFormat>
#include <QTextListFormat>

ChildWnd::ChildWnd()
{
    //子窗口关闭时销毁该类的实例对象
    setAttribute(Qt::WA_DeleteOnClose);

    m_bSaved = false;

}

void ChildWnd::newDoc()
{
    static int wndSeqNum = 1;
    m_CurDocPath = QString("WPS 文档 %1").arg(wndSeqNum++);

    //设置窗口标题，文档改动后名称后加"*"号标识
    setWindowTitle(m_CurDocPath+"[*]"+" - MyWPS");
    connect(document(),SIGNAL(contentsChanged()),this,SLOT(docBeModified()));   //contentsChanged()是否被修改信号
}

QString ChildWnd::getCurDocName()
{
    return QFileInfo(m_CurDocPath).fileName();
}

bool ChildWnd::loadDoc(const QString &docName)
{
    if(!docName.isEmpty())
    {
        QFile file(docName);
        if(!file.exists())  //判断文件是否存在
        {
            return false;
        }
        if(!file.open(QFile::ReadOnly)) //判断文档是否打开成功
        {
            return false;
        }
        QByteArray text = file.readAll();
        if(Qt::mightBeRichText(text))   //判断是否为富文本
        {
            setHtml(text);  //直接显示文本
        }
        else
        {
            setPlainText(text); //设置成纯文本格式
        }
        setCurDoc(docName); //设置文档
        connect(document(),SIGNAL(contentsChanged()),this,SLOT(docBeModified()));
        return true;
    }
    return false;
}

void ChildWnd::setCurDoc(const QString &docName)
{
    m_CurDocPath = QFileInfo(docName).canonicalFilePath();  //canonicalFilePath()返回标准名称路径，去除标点
    m_bSaved = true;    //文档已被保存
    document()->setModified(false); //设置修改状态为未改动
    setWindowModified(false);       //窗口不显示改动标识
    setWindowTitle(getCurDocName()+"[*]");    //设置子窗口标题

}

bool ChildWnd::saveDoc()
{
    if(m_bSaved) return saveDocOpt(m_CurDocPath);
    else return saveAsDoc();
}

bool ChildWnd::saveAsDoc()
{
    QString docName = QFileDialog::getSaveFileName(this,"另存为",m_CurDocPath,"HTML文档(*.html *.htm);;所有文件(*.*)");
    if(docName.isEmpty()) return false;
    else return saveDocOpt(docName);
}

bool ChildWnd::saveDocOpt(QString docName)
{
    if(!(docName.endsWith(".htm",Qt::CaseInsensitive)||docName.endsWith(".html",Qt::CaseInsensitive)))
    {
        docName += ".html";
    }
    QTextDocumentWriter writer(docName);    //文档写入类
    bool isSuccess = writer.write(this->document());
    if(isSuccess)   setCurDoc(docName);
    return isSuccess;
}

void ChildWnd::setFormatOnSelectedWord(const QTextCharFormat &fmt)
{
    QTextCursor tcursor = textCursor();     //文本光标类
    if(!tcursor.hasSelection())  //判断是否选中文本
    {
        tcursor.select(QTextCursor::WordUnderCursor);//选中光标区域字符串
    }
    tcursor.mergeCharFormat(fmt);   //设置文本格式
    mergeCurrentCharFormat(fmt);
}

void ChildWnd::setAlignOfDocumentText(int aligntype)
{
    if(aligntype == 1)
    {
        setAlignment(Qt::AlignLeft|Qt::AlignAbsolute);  //AlignAbsolute绝对的
    }
    else if (aligntype == 2)
    {
        setAlignment(Qt::AlignRight|Qt::AlignAbsolute);
    }
    else if (aligntype == 3)
    {
        setAlignment(Qt::AlignCenter);
    }
    else if (aligntype == 4)
    {
        setAlignment(Qt::AlignJustify);
    }
}

void ChildWnd::setPareSyle(int pStyle)
{
    QTextCursor tcursor = textCursor(); //光标信息

    QTextListFormat::Style sname;
    if(pStyle != 0)
    {
        switch (pStyle)
        {
        case 1:
            sname = QTextListFormat::ListDisc;//黑实心圆
            break;
        case 2:
            sname = QTextListFormat::ListCircle;//空心圆
            break;
        case 3:
            sname = QTextListFormat::ListSquare;//方形
            break;
        case 4:
            sname = QTextListFormat::ListDecimal;//十进制整数
            break;
        case 5:
            sname = QTextListFormat::ListLowerAlpha;//小写字母
            break;
        case 6:
            sname = QTextListFormat::ListUpperAlpha;//大写字母
            break;
        case 7:
            sname = QTextListFormat::ListLowerRoman;//小写罗马数字
            break;
        case 8:
            sname = QTextListFormat::ListUpperRoman;//大写罗马数字
            break;
        default:
            sname = QTextListFormat::ListDisc;
            break;
        }
        tcursor.beginEditBlock();   //编辑开始
        QTextBlockFormat tBlockFmt = tcursor.blockFormat(); //返回光标所在文本块格式
        QTextListFormat tListFmt;
        if(tcursor.currentList())
        {
            tListFmt = tcursor.currentList()->format();
        }
        else
        {
            tListFmt.setIndent(tBlockFmt.indent() + 1);
            tBlockFmt.setIndent(0);
            tcursor.setBlockFormat(tBlockFmt);
        }

        tListFmt.setStyle(sname);
        tcursor.createList(tListFmt);
        tcursor.endEditBlock();
    }
    else
    {
        QTextBlockFormat tbFmt;
        tbFmt.setObjectIndex(-1);
        tcursor.mergeBlockFormat(tbFmt);
    }

}

void ChildWnd::closeEvent(QCloseEvent *event)
{
    if(promptSave())
        event->accept();
    else
        event->ignore();
}

bool ChildWnd::promptSave()
{
    if(!document()->isModified())    //判断文件是否修改
    {
        return true;
    }
    QMessageBox::StandardButton result;     //保存按钮的值
    result = QMessageBox::warning(this,QString("提示！"),
                                  QString("文档%1已修改，是否需要保存？").arg(getCurDocName()),
                                  QMessageBox::Yes|QMessageBox::Discard|QMessageBox::No);
    if(result == QMessageBox::Yes)
    {
        return saveDoc();
    }
    else if (result == QMessageBox::No) {
        return false;
    }
    return true;
}

void ChildWnd::docBeModified()
{
    setWindowModified(document()->isModified());
}
