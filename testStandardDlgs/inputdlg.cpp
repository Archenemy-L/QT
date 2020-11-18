#include "inputdlg.h"
#include <QInputDialog>

InputDlg::InputDlg(QWidget* parent):QDialog(parent)
{
    this->setWindowTitle("标准输入对话框示例");

    m_nameTitle = new QLabel("姓名：");
    m_sexTitle = new QLabel("性别：");
    m_ageTitle = new QLabel("年龄：");
    m_scoreTitle = new QLabel("分数：");

    m_nameLabel = new QLabel("热巴");
    m_sexLabel = new QLabel("女");
    m_ageLabel = new QLabel("27");
    m_scoreLabel = new QLabel("98.6");

    m_nameBtn = new QPushButton("修改姓名");
    m_sexBtn = new QPushButton("修改性别");
    m_ageBtn = new QPushButton("修改年龄");
    m_scoreBtn = new QPushButton("修改分数");

    m_mainLayout = new QGridLayout(this);
    m_mainLayout->addWidget(m_nameTitle,0,0);
    m_mainLayout->addWidget(m_nameLabel,0,1);
    m_mainLayout->addWidget(m_nameBtn,0,2);
    m_mainLayout->addWidget(m_sexTitle,1,0);
    m_mainLayout->addWidget(m_sexLabel,1,1);
    m_mainLayout->addWidget(m_sexBtn,1,2);
    m_mainLayout->addWidget(m_ageTitle,2,0);
    m_mainLayout->addWidget(m_ageLabel,2,1);
    m_mainLayout->addWidget(m_ageBtn,2,2);
    m_mainLayout->addWidget(m_scoreTitle,3,0);
    m_mainLayout->addWidget(m_scoreLabel,3,1);
    m_mainLayout->addWidget(m_scoreBtn,3,2);

    m_mainLayout->setSpacing(20);   //部件间的间距
    m_mainLayout->setMargin(10);    //部件与窗体间距

    connect(m_nameBtn,&QPushButton::clicked,this,&InputDlg::setName);
    connect(m_sexBtn,&QPushButton::clicked,this,&InputDlg::setSex);
    connect(m_ageBtn,&QPushButton::clicked,this,&InputDlg::setAge);
    connect(m_scoreBtn,&QPushButton::clicked,this,&InputDlg::setScore);

}

InputDlg::~InputDlg()
{

}

void InputDlg::setName()
{
    bool ok;
    QString sName = QInputDialog::getText(this,"getText文本框","请输入姓名：",QLineEdit::Normal,m_nameLabel->text(),&ok);  //QLineEdit::Normal窗口模式
    if(ok && !sName.isEmpty())
    {
        m_nameLabel->setText(sName);
    }
}

void InputDlg::setSex()
{
    QStringList sexList;
    sexList << "男" << "女" << "未知";
    bool ok;
    QString sSex = QInputDialog::getItem(this,"getItem选择框","请选择性别：",sexList,0,false,&ok); //getItem(父窗体,标题,文字,字符串链表,默认选中项,调用结果)
    if(ok && !sSex.isEmpty())
    {
       m_sexLabel->setText(sSex);
    }
}

void InputDlg::setAge()
{
    bool ok;
    int age = QInputDialog::getInt(this,"getInt整数框","请输入年龄：",m_ageLabel->text().toInt(),0,120,1,&ok); //getInt(父窗体,标题,文字,默认值,最小值,最大值,每次增长,调用结果)
    if(ok)
    {
        m_ageLabel->setText(QString::number(age));
    }
}

void InputDlg::setScore()
{
    bool ok;
    //getDouble(父窗体,标题,文字,默认值,最小值,最大值,精度,调用结果)
    double score = QInputDialog::getDouble(this,"getDouble双精度框","请输入分数：",m_scoreLabel->text().toDouble(),0,100,1,&ok);
    if(ok)
    {
        m_scoreLabel->setText(QString::number(score));
    }
}








