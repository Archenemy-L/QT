/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *cbtn;
    QPushButton *wbtn;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cbtn = new QPushButton(centralwidget);
        cbtn->setObjectName(QString::fromUtf8("cbtn"));
        cbtn->setGeometry(QRect(190, 190, 93, 28));
        wbtn = new QPushButton(centralwidget);
        wbtn->setObjectName(QString::fromUtf8("wbtn"));
        wbtn->setGeometry(QRect(360, 190, 93, 28));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 290, 311, 28));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 330, 311, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(170, 370, 311, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        cbtn->setText(QCoreApplication::translate("MainWindow", "\345\215\225\345\207\273", nullptr));
        wbtn->setText(QCoreApplication::translate("MainWindow", "\346\210\221\345\271\262\357\274\201", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\344\270\200\344\270\252\344\277\241\345\217\267\345\222\214\344\270\200\344\270\252\346\247\275", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\344\270\200\344\270\252\344\277\241\345\217\267\345\222\214\346\211\200\346\234\211\347\233\270\345\272\224\345\256\203\347\232\204\346\247\275", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\346\214\207\345\256\232\345\257\271\350\261\241\347\232\204\346\211\200\346\234\211\344\277\241\345\217\267\345\222\214\346\214\207\345\256\232\345\257\271\350\261\241\347\232\204\346\211\200\346\234\211\346\247\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
