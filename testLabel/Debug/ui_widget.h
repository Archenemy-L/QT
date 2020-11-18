/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *txtLabel;
    QLabel *numLabel;
    QLabel *picLabel;
    QLabel *gifLabel;
    QLabel *label;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        txtLabel = new QLabel(Widget);
        txtLabel->setObjectName(QString::fromUtf8("txtLabel"));
        txtLabel->setGeometry(QRect(110, 50, 101, 71));
        txtLabel->setFrameShape(QFrame::NoFrame);
        txtLabel->setFrameShadow(QFrame::Plain);
        txtLabel->setWordWrap(true);
        numLabel = new QLabel(Widget);
        numLabel->setObjectName(QString::fromUtf8("numLabel"));
        numLabel->setGeometry(QRect(110, 150, 131, 31));
        picLabel = new QLabel(Widget);
        picLabel->setObjectName(QString::fromUtf8("picLabel"));
        picLabel->setGeometry(QRect(40, 350, 181, 191));
        picLabel->setScaledContents(false);
        picLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        picLabel->setMargin(0);
        gifLabel = new QLabel(Widget);
        gifLabel->setObjectName(QString::fromUtf8("gifLabel"));
        gifLabel->setGeometry(QRect(250, 350, 171, 181));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 80, 111, 16));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(540, 70, 93, 28));
        pushButton->setCheckable(true);
        pushButton->setChecked(false);
        pushButton->setFlat(false);
        radioButton = new QRadioButton(Widget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(540, 120, 115, 19));
        radioButton->setChecked(false);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 120, 111, 16));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 210, 51, 51));
        QIcon icon;
        icon.addFile(QString::fromUtf8("1.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_2->setCheckable(false);
        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 210, 81, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/qq.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(16, 16));
        pushButton_3->setCheckable(false);
        pushButton_3->setChecked(false);
        pushButton_3->setFlat(true);
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(400, 170, 121, 91));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 20, 91, 19));
        radioButton_2->setCheckable(true);
        radioButton_2->setChecked(false);
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 40, 91, 19));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 60, 91, 19));
        groupBox_2 = new QGroupBox(Widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(580, 170, 121, 91));
        checkBox_1 = new QCheckBox(groupBox_2);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setGeometry(QRect(10, 20, 91, 19));
        checkBox_2 = new QCheckBox(groupBox_2);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(10, 40, 91, 19));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 60, 91, 19));
        checkBox_3->setTristate(true);
#if QT_CONFIG(shortcut)
        label->setBuddy(pushButton);
        label_2->setBuddy(radioButton);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        txtLabel->setText(QCoreApplication::translate("Widget", "\346\226\207\346\234\254", nullptr));
        numLabel->setText(QCoreApplication::translate("Widget", "\346\225\260\345\255\227", nullptr));
        picLabel->setText(QCoreApplication::translate("Widget", "\345\233\276\347\211\207", nullptr));
        gifLabel->setText(QCoreApplication::translate("Widget", "\345\212\250\345\233\276", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\214\211\351\222\256\345\277\253\346\215\267\351\224\256(&p)", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        radioButton->setText(QCoreApplication::translate("Widget", "RadioButton", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "&RadioButton", nullptr));
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Widget", "\346\200\247\345\210\253", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Widget", "\347\224\267", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Widget", "\345\245\263", nullptr));
        radioButton_4->setText(QCoreApplication::translate("Widget", "\347\247\201\345\257\206", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Widget", "\347\210\261\345\245\275", nullptr));
        checkBox_1->setText(QCoreApplication::translate("Widget", "\347\210\254\345\261\261", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\350\267\221\346\255\245", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\347\257\256\347\220\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
