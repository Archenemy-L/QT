#include "msgboxdlg.h"

MsgBoxDlg::MsgBoxDlg(QWidget* parent):QDialog(parent)
{
    setWindowTitle("标准信息对话框示例");
    //构造
    m_tipLabel = new QLabel("请选择一种消息框");
    m_questionBtn = new QPushButton("问题消息框");
    m_informationBtn = new QPushButton("信息提示框");
    m_warmingBtn = new QPushButton("警告消息框");
    m_criticalBtn = new QPushButton("错误消息框");
    m_aboutBtn = new QPushButton("关于消息框");
    m_aboutQtBtn = new QPushButton("关于Qt消息框");
    //布局
    m_mainlayout = new QGridLayout(this);
    m_mainlayout->addWidget(m_tipLabel,0,0,1,2);
    m_mainlayout->addWidget(m_questionBtn,1,0);
    m_mainlayout->addWidget(m_informationBtn,1,1);
    m_mainlayout->addWidget(m_warmingBtn,2,0);
    m_mainlayout->addWidget(m_criticalBtn,2,1);
    m_mainlayout->addWidget(m_aboutBtn,3,0);
    m_mainlayout->addWidget(m_aboutQtBtn,3,1);

    //信号和槽连接
    connect(m_questionBtn,&QPushButton::clicked,this,&MsgBoxDlg::showQuestionMsgDlg);
    connect(m_informationBtn,&QPushButton::clicked,this,&MsgBoxDlg::showInformationMsgDlg);
    connect(m_warmingBtn,&QPushButton::clicked,this,&MsgBoxDlg::showWarmingMsgDlg);
    connect(m_criticalBtn,&QPushButton::clicked,this,&MsgBoxDlg::showCriticalMsgDlg);
    connect(m_aboutBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutMsgDlg);
    connect(m_aboutQtBtn,&QPushButton::clicked,this,&MsgBoxDlg::showAboutQtMsgDlg);
}

void MsgBoxDlg::showQuestionMsgDlg()
{
    m_tipLabel->setText("问题消息框");
    //questiong(父窗口,标题,文本,选择按钮样式,默认按钮)
    int res = QMessageBox::question(this,"问题消息框","是否确认？",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);

    switch (res) {
    case QMessageBox::Ok:
        m_tipLabel->setText("问题消息框-确定");
        break;
    case QMessageBox::Cancel:
        m_tipLabel->setText("问题消息框-取消");
        break;
    default:
        break;
    }
}

void MsgBoxDlg::showInformationMsgDlg()
{
    m_tipLabel->setText("信息消息框");
    QMessageBox::information(this,"信息消息框","是否确认？");
}

void MsgBoxDlg::showWarmingMsgDlg()
{
    m_tipLabel->setText("警告消息框");
    int res = QMessageBox::warning(this,"警告消息框","您有一个为保存文件，是否保存？",
                                   QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel,
                                   QMessageBox::Save);
    switch (res) {
    case QMessageBox::Save:
        m_tipLabel->setText("警告消息框-保存");
        break;
    case QMessageBox::Discard:
        m_tipLabel->setText("警告消息框-忽视");
        break;
    case QMessageBox::Cancel:
        m_tipLabel->setText("警告消息框-取消");
        break;
    default:
        break;
    }
}

void MsgBoxDlg::showCriticalMsgDlg()
{
    m_tipLabel->setText("错误消息框");
    QMessageBox::critical(this,"错误消息框","发生一个错误！");
}

void MsgBoxDlg::showAboutMsgDlg()
{
    m_tipLabel->setText("关于消息框");
    QMessageBox::about(this,"关于消息框","这是一条关于信息");
}

void MsgBoxDlg::showAboutQtMsgDlg()
{
    m_tipLabel->setText("Qt关于消息框");
    QMessageBox::aboutQt(this,"关于Qt消息框");
}




















