#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile file("hello.txt");
    //读取文件
    if(file.open(QIODevice::ReadOnly))      //QIODevice::ReadOnly只读
    {
        char buffer[100];

        //返回-1读取失败，读取成功返回读取的字节数
        qint32 n = file.readLine(buffer,sizeof (buffer));      //readLine(存储的变量,读取的长度) 读取数据
        if(n != -1)
        {
            qDebug() << "读取到的字节数为：" << n;
            qDebug() << "读取到数据：" << buffer;
            file.close();
        }
    }
    else
    {
        qDebug() << file.errorString();     //打印文件打开失败原因
    }


    //写文件
    double dPI = 3.1415926;
    int age = 13;
    QFile dataFile;
    dataFile.setFileName("data.txt");
    if( dataFile.open(QFile::WriteOnly | QFile::Truncate) )     //QFile::Truncate清空覆盖
    {
        QTextStream out(&dataFile);     //文件流
        out.setRealNumberPrecision(3);  //设置整数精度
        out.setFieldWidth(10);          //宽度位数
        out.setFieldAlignment(QTextStream::AlignRight);  //设置对齐方式
        out << QString("PI:")
//            << qSetRealNumberPrecision(3)       //设置整数精度位数，默认为6位存入3.14159
//            << qSetFieldWidth(10)               //设置之后存储的所有字段宽度，存入的数据宽度不够会自动用空格补充
//            << dPI
//            << left                             //左对齐，默认右对齐
            << dPI
            << bin                                //二进制方式写入
            << uppercasebase                      //设置进制为大写显示
            << showbase                           //显示进制前缀
            << age;
    }



    return a.exec();
}

































