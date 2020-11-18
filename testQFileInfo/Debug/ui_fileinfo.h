/********************************************************************************
** Form generated from reading UI file 'fileinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEINFO_H
#define UI_FILEINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileInfo
{
public:
    QLabel *label_6;
    QPushButton *browseFileBtn;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *isDirCheckBox;
    QCheckBox *isFileCheckBox;
    QCheckBox *isSymLinkCheckBox;
    QCheckBox *isHiddenCheckBox;
    QCheckBox *isReadableCheckBox;
    QCheckBox *isWritableCheckBox;
    QCheckBox *isExecutableCheckBox;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLineEdit *fileNameLineEdit;
    QLineEdit *fileSizeLineEdit;
    QLineEdit *fileCreateLineEdit;
    QLineEdit *fileModifyLineEdit;
    QLineEdit *fileReadLineEdit;
    QWidget *widget2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *FileInfo)
    {
        if (FileInfo->objectName().isEmpty())
            FileInfo->setObjectName(QString::fromUtf8("FileInfo"));
        FileInfo->resize(664, 436);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        FileInfo->setFont(font);
        label_6 = new QLabel(FileInfo);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(40, 340, 72, 15));
        browseFileBtn = new QPushButton(FileInfo);
        browseFileBtn->setObjectName(QString::fromUtf8("browseFileBtn"));
        browseFileBtn->setGeometry(QRect(590, 50, 51, 28));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        browseFileBtn->setFont(font1);
        widget = new QWidget(FileInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 370, 561, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        isDirCheckBox = new QCheckBox(widget);
        isDirCheckBox->setObjectName(QString::fromUtf8("isDirCheckBox"));

        horizontalLayout->addWidget(isDirCheckBox);

        isFileCheckBox = new QCheckBox(widget);
        isFileCheckBox->setObjectName(QString::fromUtf8("isFileCheckBox"));

        horizontalLayout->addWidget(isFileCheckBox);

        isSymLinkCheckBox = new QCheckBox(widget);
        isSymLinkCheckBox->setObjectName(QString::fromUtf8("isSymLinkCheckBox"));

        horizontalLayout->addWidget(isSymLinkCheckBox);

        isHiddenCheckBox = new QCheckBox(widget);
        isHiddenCheckBox->setObjectName(QString::fromUtf8("isHiddenCheckBox"));

        horizontalLayout->addWidget(isHiddenCheckBox);

        isReadableCheckBox = new QCheckBox(widget);
        isReadableCheckBox->setObjectName(QString::fromUtf8("isReadableCheckBox"));

        horizontalLayout->addWidget(isReadableCheckBox);

        isWritableCheckBox = new QCheckBox(widget);
        isWritableCheckBox->setObjectName(QString::fromUtf8("isWritableCheckBox"));

        horizontalLayout->addWidget(isWritableCheckBox);

        isExecutableCheckBox = new QCheckBox(widget);
        isExecutableCheckBox->setObjectName(QString::fromUtf8("isExecutableCheckBox"));

        horizontalLayout->addWidget(isExecutableCheckBox);

        widget1 = new QWidget(FileInfo);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(160, 30, 421, 271));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        fileNameLineEdit = new QLineEdit(widget1);
        fileNameLineEdit->setObjectName(QString::fromUtf8("fileNameLineEdit"));

        verticalLayout->addWidget(fileNameLineEdit);

        fileSizeLineEdit = new QLineEdit(widget1);
        fileSizeLineEdit->setObjectName(QString::fromUtf8("fileSizeLineEdit"));

        verticalLayout->addWidget(fileSizeLineEdit);

        fileCreateLineEdit = new QLineEdit(widget1);
        fileCreateLineEdit->setObjectName(QString::fromUtf8("fileCreateLineEdit"));

        verticalLayout->addWidget(fileCreateLineEdit);

        fileModifyLineEdit = new QLineEdit(widget1);
        fileModifyLineEdit->setObjectName(QString::fromUtf8("fileModifyLineEdit"));

        verticalLayout->addWidget(fileModifyLineEdit);

        fileReadLineEdit = new QLineEdit(widget1);
        fileReadLineEdit->setObjectName(QString::fromUtf8("fileReadLineEdit"));

        verticalLayout->addWidget(fileReadLineEdit);

        widget2 = new QWidget(FileInfo);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setGeometry(QRect(30, 40, 135, 251));
        verticalLayout_2 = new QVBoxLayout(widget2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        label_3 = new QLabel(widget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        label_4 = new QLabel(widget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(widget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_2->addWidget(label_5);


        retranslateUi(FileInfo);

        QMetaObject::connectSlotsByName(FileInfo);
    } // setupUi

    void retranslateUi(QWidget *FileInfo)
    {
        FileInfo->setWindowTitle(QCoreApplication::translate("FileInfo", "\346\226\207\344\273\266\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("FileInfo", "\345\261\236\346\200\247\357\274\232", nullptr));
        browseFileBtn->setText(QCoreApplication::translate("FileInfo", "...", nullptr));
        isDirCheckBox->setText(QCoreApplication::translate("FileInfo", "\347\233\256\345\275\225", nullptr));
        isFileCheckBox->setText(QCoreApplication::translate("FileInfo", "\346\226\207\344\273\266", nullptr));
        isSymLinkCheckBox->setText(QCoreApplication::translate("FileInfo", "\347\254\246\345\217\267\350\277\236\346\216\245", nullptr));
        isHiddenCheckBox->setText(QCoreApplication::translate("FileInfo", "\351\232\220\350\227\217", nullptr));
        isReadableCheckBox->setText(QCoreApplication::translate("FileInfo", "\350\257\273", nullptr));
        isWritableCheckBox->setText(QCoreApplication::translate("FileInfo", "\345\206\231", nullptr));
        isExecutableCheckBox->setText(QCoreApplication::translate("FileInfo", "\346\211\247\350\241\214", nullptr));
        label->setText(QCoreApplication::translate("FileInfo", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("FileInfo", "\345\244\247\345\260\217\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FileInfo", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("FileInfo", "\346\234\200\345\220\216\344\277\256\346\224\271\346\227\266\351\227\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("FileInfo", "\346\234\200\345\220\216\350\256\277\351\227\256\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileInfo: public Ui_FileInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEINFO_H
