/********************************************************************************
** Form generated from reading UI file 'testlayout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTLAYOUT_H
#define UI_TESTLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestLayout
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *namelabel;
    QLabel *agelabel;
    QLabel *emilelabel;
    QLabel *label_4;
    QLabel *label_5;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *namelE;
    QLineEdit *agelE;
    QLineEdit *emilelE;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;

    void setupUi(QWidget *TestLayout)
    {
        if (TestLayout->objectName().isEmpty())
            TestLayout->setObjectName(QString::fromUtf8("TestLayout"));
        TestLayout->resize(800, 600);
        layoutWidget = new QWidget(TestLayout);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(190, 170, 252, 133));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        namelabel = new QLabel(layoutWidget);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));

        verticalLayout->addWidget(namelabel);

        agelabel = new QLabel(layoutWidget);
        agelabel->setObjectName(QString::fromUtf8("agelabel"));

        verticalLayout->addWidget(agelabel);

        emilelabel = new QLabel(layoutWidget);
        emilelabel->setObjectName(QString::fromUtf8("emilelabel"));

        verticalLayout->addWidget(emilelabel);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        namelE = new QLineEdit(layoutWidget);
        namelE->setObjectName(QString::fromUtf8("namelE"));

        verticalLayout_2->addWidget(namelE);

        agelE = new QLineEdit(layoutWidget);
        agelE->setObjectName(QString::fromUtf8("agelE"));

        verticalLayout_2->addWidget(agelE);

        emilelE = new QLineEdit(layoutWidget);
        emilelE->setObjectName(QString::fromUtf8("emilelE"));

        verticalLayout_2->addWidget(emilelE);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        verticalLayout_2->addWidget(lineEdit_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout->addWidget(radioButton_2);

        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);


        verticalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);

#if QT_CONFIG(shortcut)
        namelabel->setBuddy(namelE);
        agelabel->setBuddy(agelE);
        emilelabel->setBuddy(emilelE);
#endif // QT_CONFIG(shortcut)

        retranslateUi(TestLayout);

        QMetaObject::connectSlotsByName(TestLayout);
    } // setupUi

    void retranslateUi(QWidget *TestLayout)
    {
        TestLayout->setWindowTitle(QCoreApplication::translate("TestLayout", "TestLayout", nullptr));
        namelabel->setText(QCoreApplication::translate("TestLayout", "\345\247\223\345\220\215\357\274\232(&N)", nullptr));
        agelabel->setText(QCoreApplication::translate("TestLayout", "\345\271\264\351\276\204\357\274\232(&A)", nullptr));
        emilelabel->setText(QCoreApplication::translate("TestLayout", "\351\202\256\347\256\261\357\274\232(&E)", nullptr));
        label_4->setText(QCoreApplication::translate("TestLayout", "\351\227\250\347\211\214\345\217\267\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("TestLayout", "\346\200\247\345\210\253\357\274\232", nullptr));
        radioButton_2->setText(QCoreApplication::translate("TestLayout", "\345\245\263", nullptr));
        radioButton->setText(QCoreApplication::translate("TestLayout", "\347\224\267", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestLayout: public Ui_TestLayout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTLAYOUT_H
