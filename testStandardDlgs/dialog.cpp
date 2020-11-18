#include "dialog.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle("标准对话框示例");

    m_fileBtn = new QPushButton("文件标准对话框");
    m_fileLineEdit = new QLineEdit;

    m_colorBtn = new QPushButton("颜色标准对话框");
    m_colorFrame = new QFrame;
    m_colorFrame->setFrameStyle(QFrame::Box);       //设置边框样式
    m_colorFrame->setAutoFillBackground(true);      //设置可否填充背景

    m_fontBtn = new QPushButton("字体标准对话框");
    m_fontLineEdit = new QLineEdit("喂，你好呀！");

    m_inputBtn = new QPushButton("标准输入对话框");

    m_msgBtn = new QPushButton("标准消息对话框");

    m_customBtn = new QPushButton("自定义消息框");
    m_customLabel = new QLabel;
    m_customLabel->setFrameStyle(QFrame::Panel|QFrame::Sunken);

    m_mainLayout = new QGridLayout(this);
    m_mainLayout->addWidget(m_fileBtn,0,0);
    m_mainLayout->addWidget(m_fileLineEdit,0,1);
    m_mainLayout->addWidget(m_colorBtn,1,0);
    m_mainLayout->addWidget(m_colorFrame,1,1);
    m_mainLayout->addWidget(m_fontBtn,2,0);
    m_mainLayout->addWidget(m_fontLineEdit,2,1);
    m_mainLayout->addWidget(m_inputBtn,3,0,1,2);
    m_mainLayout->addWidget(m_msgBtn,4,0,1,2);
    m_mainLayout->addWidget(m_customBtn,5,0);
    m_mainLayout->addWidget(m_customLabel,5,1);


    connect(m_fileBtn,&QPushButton::clicked,this,&Dialog::ShowFileDlg);
    connect(m_colorBtn,&QPushButton::clicked,this,&Dialog::ShowColorDlg);
    connect(m_fontBtn,&QPushButton::clicked,this,&Dialog::ShowFontDlg);
    connect(m_inputBtn,&QPushButton::clicked,this,&Dialog::ShowInputDlg);
    connect(m_msgBtn,&QPushButton::clicked,this,&Dialog::ShowMsgDlg);
    connect(m_customBtn,&QPushButton::clicked,this,&Dialog::ShowCustomDlg);
}

Dialog::~Dialog()
{
}

void Dialog::ShowFileDlg()
{   //(窗口,标题,文件路径,过滤)
    QString sPath = QFileDialog::getOpenFileName(this,"标准文件对话框",".","C++ files(*.cpp);;C files(*.c);;Header files(*.h)");
    m_fileLineEdit->setText(sPath);
}

void Dialog::ShowColorDlg()
{
    QColor color = QColorDialog::getColor(Qt::yellow);
    if(color.isValid())
    {
        //setPalette设置颜色填充
        m_colorFrame->setPalette(QPalette(color));
    }
}

void Dialog::ShowFontDlg()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok);
    if(ok)
    {
        m_fontLineEdit->setFont(font);
    }
}

void Dialog::ShowInputDlg()
{
    m_inputDlg = new InputDlg(this);
    m_inputDlg->show();
}

void Dialog::ShowMsgDlg()
{
    m_msgBoxDlg = new MsgBoxDlg(this);
    m_msgBoxDlg->show();
}

void Dialog::ShowCustomDlg()
{
    m_customLabel->setText("自定义消息框");
    QMessageBox customMsgBox;
    customMsgBox.setWindowTitle("自定义消息框");
    QPushButton* yes = customMsgBox.addButton("是的",QMessageBox::ActionRole);
    QPushButton* no = customMsgBox.addButton("不是",QMessageBox::ActionRole);
    QPushButton* cancel = customMsgBox.addButton(QMessageBox::Cancel);
    customMsgBox.setIconPixmap(QPixmap("1.ico"));
    customMsgBox.setText("淦！");
    customMsgBox.exec();
    if(customMsgBox.clickedButton() == yes)
    {
        m_customLabel->setText("选择了yes");
    }
    else if(customMsgBox.clickedButton() == no)
    {
         m_customLabel->setText("选择了no");
    }
    else if(customMsgBox.clickedButton() == cancel)
    {
        m_customLabel->setText("选择了cancel");
    }
}












