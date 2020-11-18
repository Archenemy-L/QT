#ifndef CHILDWND_H
#define CHILDWND_H
#include <QCloseEvent>
#include <QTextEdit>

class ChildWnd : public QTextEdit
{
    Q_OBJECT
public:
    ChildWnd();
    QString m_CurDocPath;       //当前文档路径
    void newDoc();              //新建文档
    QString getCurDocName();    //文档路径中提取文档名
    bool loadDoc(const QString& docName);    //加载文档
    void setCurDoc(const QString& docName);  //设置当前文档
    bool saveDoc();     //保存文档
    bool saveAsDoc();   //另存为
    bool saveDocOpt(QString docName);   //实现保存文档
    void setFormatOnSelectedWord(const QTextCharFormat &fmt);       //设置字体
    void setAlignOfDocumentText(int aligntype);     //设置对齐方式
    void setPareSyle(int pStyle); //项目风隔

protected:
    void closeEvent(QCloseEvent *event);    //关闭事件

private:
    bool promptSave();  //尝试保存

private slots:
    void docBeModified();   //文档修改时，窗口标题栏加“*”

private:
    bool m_bSaved;      //文档是否保存
};

#endif // CHILDWND_H
