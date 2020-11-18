#include <QCoreApplication>
#include <QFile>
#include <QDebug>
#include <QDate>
#include <QDataStream>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile binFile("info.bat");

    if( binFile.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        //写入二进制数据
        QDataStream out(&binFile);
        out << QString("世界你好！")
            << QDate::fromString("2000-10-15","yyyy-MM-dd")
            << (qint32)20;
        binFile.close();
    }
    else
    {
        qDebug() << binFile.errorString();
    }

    //读入二进制文件
    binFile.setFileName("info.bat");
    if( binFile.open(QIODevice::ReadOnly) )
    {
        QDataStream in(&binFile);
        QString str;
        QDate data;
        qint32 age;
        in >> str >> data >> age;       //读取文件数据类型必须和存入数据类型相同
        qDebug() << str << data << age;
        binFile.close();
    }


    return a.exec();
}
