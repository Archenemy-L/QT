#ifndef MSGBOXDLG_H
#define MSGBOXDLG_H
#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QMessageBox>


class MsgBoxDlg : public QDialog
{
    Q_OBJECT
public:
    MsgBoxDlg(QWidget* parent = 0);

private:
    QLabel* m_tipLabel;             //提示标签
    QPushButton* m_questionBtn;     //确认框
    QPushButton* m_informationBtn;  //信息提示
    QPushButton* m_warmingBtn;      //警告提示
    QPushButton* m_criticalBtn;     //错误提示
    QPushButton* m_aboutQtBtn;      //关于Qt
    QPushButton* m_aboutBtn;        //自定义关于对话框

    QGridLayout* m_mainlayout;      //布局管理器

private slots:
    void showQuestionMsgDlg();
    void showInformationMsgDlg();
    void showWarmingMsgDlg();
    void showCriticalMsgDlg();
    void showAboutMsgDlg();
    void showAboutQtMsgDlg();

};

#endif // MSGBOXDLG_H
