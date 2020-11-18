#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //设置标签填充
    ui->imgLabel->setScaledContents(true);
    //设置当前窗口和imglabel标签窗口宽高一致
    this->resize(ui->imgLabel->width(),ui->imgLabel->height());
    //固定窗口宽高
    setFixedSize(width(),height());
    //设置窗口标题
    this->setWindowTitle("驾校科目一考试登入");
    //设置窗口为对话框风格，并且只需要一个关闭按钮
    this->setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}


void LoginDialog::on_loginBtn_clicked()
{
    //正则验证邮箱地址 用户名@域名
    //元字符解释：^表示规则字符串的开始 $表示规则字符串的结束
    //+表示匹配次数>=一次 *表示任意匹配次数(可为0次)  {n,m}表示匹配次数最少n次最多m次
    //QRegExp正则表达式类
    QRegExp rx("^[A-Za-z0-9]+([_\.][A-Za-z0-9]+)*@([A-Za-z0-9\-]+\.)+[A-Za-z]{2,6}$");
    //匹配正则表达式
    bool res = rx.exactMatch(ui->accountEdit->text());
    if(!res)
    {
        QMessageBox::information(this,"提示","非法邮箱地址，请重新输入！");
        //清除输入框
        ui->accountEdit->clear();
        ui->codeEdit->clear();
        //聚焦
        ui->accountEdit->setFocus();
        return;
    }
    else
    {
        QString filename;       //读取文件路径
        QString strAccInput;    //保存输入的用户名
        QString strCode;        //保存输入的密码
        QString strLine;        //保存每一行读取的字符串
        QStringList strList;    //字符串链表

        filename="account.txt";
        strAccInput = ui->accountEdit->text();
        strCode = ui->codeEdit->text();

        QFile file(filename);
        //文件流
        QTextStream stream(&file);
        //ReadOnly只读，Text文本类型
        if(file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            while(!stream.atEnd())
            {
                //操作文件流读取一行
                strLine = stream.readLine();
                //以分隔符","分隔QString类型的数据,保存在字符串链表中
                strList=strLine.split(",");
                if(strAccInput==strList.at(0))
                {
                    if(strCode==strList.at(1))
                    {
                        QMessageBox::information(this,"提示","科目一考试系统登入成功！");
                        file.close();
                        //返回用户接收
                        done(Accepted);
                        return;
                    }
                    else
                    {
                        QMessageBox::information(this,"提示","密码输入错误！");
                        //清除密码输入框
                        ui->codeEdit->clear();
                        //聚焦
                        ui->codeEdit->setFocus();
                        file.close();
                    }
                }
                else
                {

                }
            }
            QMessageBox::information(this,"提示","您输入的账号错误，请重新输入！");
            //清除输入框
            ui->accountEdit->clear();
            ui->codeEdit->clear();
            //聚焦
            ui->accountEdit->setFocus();
            file.close();
            return;
        }
        else
        {
            QMessageBox::information(this,"提示","读取账号数据文件失败");
            return;
        }

    }
}




void LoginDialog::on_cencelBtn_clicked()
{
    //返回用户拒绝
    done(Rejected);
}
