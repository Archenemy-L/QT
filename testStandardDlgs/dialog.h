#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QFrame>
#include "inputdlg.h"
#include "msgboxdlg.h"

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void ShowFileDlg();
    void ShowColorDlg();
    void ShowFontDlg();
    void ShowInputDlg();
    void ShowMsgDlg();
    void ShowCustomDlg();


private:
    QPushButton* m_fileBtn;         //打开文件对话框
    QLineEdit* m_fileLineEdit;      //显示所选文件路径

    QPushButton* m_colorBtn;         //打开颜色对话框
    QFrame* m_colorFrame;            //显示所选颜色效果

    QPushButton* m_fontBtn;         //打开字体对话框
    QLineEdit* m_fontLineEdit;      //显示字体样式

    QPushButton* m_inputBtn;        //显示输入对话框
    InputDlg * m_inputDlg;          //输入对话框

    QPushButton* m_msgBtn;          //显示消息对话框
    MsgBoxDlg* m_msgBoxDlg;         //消息对话框

    QPushButton* m_customBtn;       //自定义消息框
    QLabel* m_customLabel;          //自定义显示

    QGridLayout* m_mainLayout;      //布局管理器
};
#endif // DIALOG_H


















