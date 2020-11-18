#include "logindialog.h"
#include <examdialog.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog logDialog;
    int rec = logDialog.exec();
    if(rec == QDialog::Accepted)
    {
        ExamDialog *examDialog;
        examDialog = new ExamDialog;
    }
    else
    {
        return 0;
    }
    return a.exec();
}
