#include "fileinfo.h"
#include "ui_fileinfo.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>

FileInfo::FileInfo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileInfo)
{
    ui->setupUi(this);
}

FileInfo::~FileInfo()
{
    delete ui;
}

void FileInfo::getFileInfo(QString &fileName)
{
    QFileInfo info(fileName);
    qint64 size = info.size();  //文件大小
    QDateTime creatTime = info.created();       //创建时间
    QDateTime lastMTime = info.lastModified();  //最后修改时间
    QDateTime lastRTime = info.lastRead();      //最后访问时间

    //属性信息
    bool bIsDir = info.isDir();     //判断是否是目录
    bool bIsFile = info.isFile();   //判断是否文件
    bool bIsSymLink = info.isSymLink(); //是否链接
    bool bIsHidden = info.isHidden();   //是否隐藏
    bool bIsReadable = info.isReadable();   //是否可读
    bool bIsWritable = info.isWritable();   //是否可写
    bool bIsExcutable = info.isExecutable();//是否可执行

    ui->fileSizeLineEdit->setText(QString::number(size));
    ui->fileCreateLineEdit->setText(creatTime.toString());
    ui->fileModifyLineEdit->setText(lastMTime.toString());
    ui->fileReadLineEdit->setText(lastRTime.toString());

    ui->isDirCheckBox->setChecked(bIsDir);
    ui->isFileCheckBox->setChecked(bIsFile);
    ui->isSymLinkCheckBox->setChecked(bIsSymLink);
    ui->isHiddenCheckBox->setChecked(bIsHidden);
    ui->isReadableCheckBox->setChecked(bIsReadable);
    ui->isWritableCheckBox->setChecked(bIsWritable);
    ui->isExecutableCheckBox->setChecked(bIsExcutable);
}


void FileInfo::on_browseFileBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"打开文件",".","files(*)");    //getOpenFileName选择文件
    //QString path = QFileDialog::getExistingDirectory(this,"选择目录",".");            //getExistingDirectory选择目录，不能计算文件大小
    ui->fileNameLineEdit->setText(fileName);
    getFileInfo(fileName);

}
