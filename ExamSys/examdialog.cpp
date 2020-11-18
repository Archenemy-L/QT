#include "examdialog.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QPushButton>
#include <QButtonGroup>

ExamDialog::ExamDialog(QWidget* parent):QDialog(parent)
{
    //设置字体大小类
    QFont font;
    font.setPointSize(12);
    //设置当前窗口字体大小
    setFont(font);
    //设置窗体背景颜色
    setPalette(QPalette(QColor(209,215,255)));

    setWindowTitle("考试已用时：0分0秒");
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    resize(800,900);

    initTimer();
    initLayout();
    if(!initTextEdit())
    {
        QMessageBox::information(this,"提示","初始化题库数据文件失败！");
        QTimer::singleShot(0,qApp,SLOT(quit()));
    }
    initButtons();
    show();
}

void ExamDialog::initTimer()
{
    m_timeGo = 0;
    m_timer = new QTimer(this);     //指定父窗口
    m_timer->setInterval(1000);     //设置时间间隔
    m_timer->start();               //开始
    //信号和槽
    connect(m_timer,SIGNAL(timeout()),this,SLOT(freshTime()));
}

void ExamDialog::initLayout()
{
    //    m_layout = new QGridLayout();//BUG：布局大小不正确
    m_layout = new QGridLayout(this);//this指针初始化布局，意味着将当前窗口作为布局的“父部件”，当前布局成为窗口的主布局，可以自适应窗口
    m_layout->setSpacing(10);       //设置控件间的间距
    m_layout->setMargin(10);        //设置窗体和控件的间距
}

bool ExamDialog::initTextEdit()
{
    QString strLine;        //保存文件中读取到的一行数据
    QStringList strList;    //保存读取到的答案行
    //    QString fileName("E:/QT_Projects/ExamSys/exam.txt");   //文件名
    //尽量避免使用磁盘绝对路径，可以到项目中设置运行路径为当前项目路径（使用宏）
    QString fileName("exam.txt");   //文件名
    QFile file(fileName);
    QTextStream stream(&file);
    stream.setCodec("UTF-8");   //设置编码

    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        m_textEdit = new QTextEdit(this);
        m_textEdit->setReadOnly(true);  //设为只读

        QString strText;    //用于保存显示到文本编辑器的数据
        int nLines = 0;     //记录读取行数
        while(!stream.atEnd())
        {
            //过滤首行
            if(nLines==0)
            {
                stream.readLine();
                nLines++;
                continue;
            }
            //过滤答案行
            if((nLines>=6 && nLines<=6*9 && (nLines%6==0)) || (nLines==6*9+4))
            {
                strLine = stream.readLine();
                //提取答案用链表接收
                strList = strLine.split(" ");
                //把答案保存到链表
                m_answerList.append(strList.at(1));
                strText += "\n";
                nLines++;
                continue;
            }
            strText += stream.readLine();
            strText += "\n";
            nLines++;
        }
        m_textEdit->setText(strText);
        //添加控件到布局管理器，控件名称、位置，所占行列
        m_layout->addWidget(m_textEdit,0,0,1,10);
        file.close();
        return true;
    }
    else
    {
        return false;
    }

}

void ExamDialog::initButtons()
{
    QStringList strList={"A","B","C","D"};
    for(int i=0;i<10;i++)
    {
        //题目标签
        m_titleLables[i] = new QLabel(this);
        m_titleLables[i]->setText("第"+QString::number(i+1)+"题");
        m_layout->addWidget(m_titleLables[i],1,i,1,1);
        //判断题
        if(i == 9)
        {
            m_radioA = new QRadioButton(this);
            m_radioB = new QRadioButton(this);

            m_radioA->setText("正确");
            m_radioB->setText("错误");

            //设置布局
            m_layout->addWidget(m_radioA,2,9,1,1);
            m_layout->addWidget(m_radioB,3,9,1,1);
            //添加分组
            m_btnGroups[8] = new QButtonGroup(this);
            m_btnGroups[8]->addButton(m_radioA);
            m_btnGroups[8]->addButton(m_radioB);
            break;
        }
        if(i < 8)
        {
            m_btnGroups[i] = new QButtonGroup(this);
        }
        //选择题
        for(int j=0 ; j<4; j++)
        {
            //多选题
            if(i == 8)
            {
                m_checkBtns[j] = new QCheckBox(this);
                m_checkBtns[j]->setText(strList.at(j));
                m_layout->addWidget(m_checkBtns[j],2+j,8,1,1);
            }
            else
            {
                //单选题
                m_radioBtns[4*i+j]=new QRadioButton(this);
                m_radioBtns[4*i+j]->setText(strList.at(j));
                m_layout->addWidget(m_radioBtns[4*i+j],2+j,i,1,1);
                //向分组添加选项
                m_btnGroups[i]->addButton(m_radioBtns[4*i+j]);
            }
        }
    }
    QPushButton *submitBtn =new QPushButton(this);
    submitBtn->setText("提交");
    submitBtn->setFixedSize(100,35);
    connect(submitBtn,SIGNAL(clicked(bool)),this,SLOT(getScore()));
    m_layout->addWidget(submitBtn,6,9);
}

bool ExamDialog::hasNoSelect()
{
    //单选判断是否选择
    int radioSelects = 0;
    for(int i = 0 ;i < 8; i++)
    {
        if(m_btnGroups[i]->checkedButton())
        {
            radioSelects++;
        }
    }
    if(radioSelects != 8)
    {
        return true;
    }
    //多选判断
    int checkSelects = 0;
    for(int j = 0; j < 4; j++)
    {
        if(m_checkBtns[j]->isChecked())
        {
            checkSelects++;
        }
    }
    if(checkSelects == 0 || checkSelects == 1)
    {
        return true;
    }
    if(!m_radioA->isChecked() && !m_radioB->isChecked())
    {
        return true;
    }
    return false;
}

//刷新考试用时
void ExamDialog::freshTime()
{
    m_timeGo++;
    //计算分钟，转成QString类型
    QString min = QString::number(m_timeGo/60);
    QString sec = QString::number(m_timeGo%60);
    setWindowTitle("考试已用时："+min+"分"+sec+"秒");

}

void ExamDialog::getScore()
{
    if(hasNoSelect())
    {
        QMessageBox::information(this,"提示","您有未完成的题目，请完成考试！");
        return;
    }

    int scores = 0;
    for(int i = 0 ; i < 10 ; i++)
    {
        //单选题计分
        if(i < 8)
        {
            if(m_btnGroups[i]->checkedButton()->text() == m_answerList.at(i))
            {
                scores += 10;
            }
        }
        //多项选择题计分
        if(i == 8)
        {
            QString answer = m_answerList.at(i);
            bool hasA = false;
            bool hasB = false;
            bool hasC = false;
            bool hasD = false;

            if(answer.contains("A")) hasA = true;
            if(answer.contains("B")) hasB = true;
            if(answer.contains("C")) hasC = true;
            if(answer.contains("D")) hasD = true;

            bool checkA = m_checkBtns[0]->checkState();
            bool checkB = m_checkBtns[1]->checkState();
            bool checkC = m_checkBtns[2]->checkState();
            bool checkD = m_checkBtns[3]->checkState();

            if(hasA!=checkA || hasB!=checkB || hasC!=checkC || hasD!=checkD)
            {
                continue;
            }
            scores += 10;
        }
        //判断题计分
        if(i == 9)
        {
            if(m_btnGroups[8]->checkedButton()->text() == m_answerList.at(i))
            {
                scores += 10;
            }
        }
    }
    int res = QMessageBox::information(this,"提示","您的得分为："+QString::number(scores)+"分，是否需要重新考试？",QMessageBox::Yes | QMessageBox::No);
    if(res == QMessageBox::Yes)
    {
        return;
    }
    else
    {
        close();
    }
}
