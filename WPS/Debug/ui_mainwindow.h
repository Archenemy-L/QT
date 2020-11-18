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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *saveAction;
    QAction *saveAsAction;
    QAction *printAction;
    QAction *printPreviewAction;
    QAction *exitAction;
    QAction *undoAction;
    QAction *redoAction;
    QAction *cutAction;
    QAction *copyAction;
    QAction *pasteAction;
    QAction *colorAction;
    QAction *boldAction;
    QAction *italicAction;
    QAction *underlinAction;
    QAction *leftAlignAction;
    QAction *centerAlignAction;
    QAction *rightAlignAction;
    QAction *justifyAlignAction;
    QAction *closeAction;
    QAction *closeAllAction;
    QAction *titleAction;
    QAction *cascadeAction;
    QAction *nextAction;
    QAction *previousAction;
    QAction *aboutAction;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QMdiArea *mdiArea;
    QMenuBar *menubar;
    QMenu *menu_F;
    QMenu *menu_E;
    QMenu *menu;
    QMenu *menu_D;
    QMenu *menu_2;
    QMenu *menu_W;
    QMenu *menu_H;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(730, 624);
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QString::fromUtf8("newAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newAction->setIcon(icon);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        openAction->setIcon(icon1);
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        saveAction->setIcon(icon2);
        saveAsAction = new QAction(MainWindow);
        saveAsAction->setObjectName(QString::fromUtf8("saveAsAction"));
        printAction = new QAction(MainWindow);
        printAction->setObjectName(QString::fromUtf8("printAction"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/print.png"), QSize(), QIcon::Normal, QIcon::Off);
        printAction->setIcon(icon3);
        printPreviewAction = new QAction(MainWindow);
        printPreviewAction->setObjectName(QString::fromUtf8("printPreviewAction"));
        exitAction = new QAction(MainWindow);
        exitAction->setObjectName(QString::fromUtf8("exitAction"));
        undoAction = new QAction(MainWindow);
        undoAction->setObjectName(QString::fromUtf8("undoAction"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        undoAction->setIcon(icon4);
        redoAction = new QAction(MainWindow);
        redoAction->setObjectName(QString::fromUtf8("redoAction"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        redoAction->setIcon(icon5);
        cutAction = new QAction(MainWindow);
        cutAction->setObjectName(QString::fromUtf8("cutAction"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        cutAction->setIcon(icon6);
        copyAction = new QAction(MainWindow);
        copyAction->setObjectName(QString::fromUtf8("copyAction"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        copyAction->setIcon(icon7);
        pasteAction = new QAction(MainWindow);
        pasteAction->setObjectName(QString::fromUtf8("pasteAction"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        pasteAction->setIcon(icon8);
        colorAction = new QAction(MainWindow);
        colorAction->setObjectName(QString::fromUtf8("colorAction"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/color.ico"), QSize(), QIcon::Normal, QIcon::Off);
        colorAction->setIcon(icon9);
        boldAction = new QAction(MainWindow);
        boldAction->setObjectName(QString::fromUtf8("boldAction"));
        boldAction->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        boldAction->setIcon(icon10);
        italicAction = new QAction(MainWindow);
        italicAction->setObjectName(QString::fromUtf8("italicAction"));
        italicAction->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        italicAction->setIcon(icon11);
        underlinAction = new QAction(MainWindow);
        underlinAction->setObjectName(QString::fromUtf8("underlinAction"));
        underlinAction->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/under.png"), QSize(), QIcon::Normal, QIcon::Off);
        underlinAction->setIcon(icon12);
        leftAlignAction = new QAction(MainWindow);
        leftAlignAction->setObjectName(QString::fromUtf8("leftAlignAction"));
        leftAlignAction->setCheckable(false);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/left.png"), QSize(), QIcon::Normal, QIcon::Off);
        leftAlignAction->setIcon(icon13);
        centerAlignAction = new QAction(MainWindow);
        centerAlignAction->setObjectName(QString::fromUtf8("centerAlignAction"));
        centerAlignAction->setCheckable(false);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/center.png"), QSize(), QIcon::Normal, QIcon::Off);
        centerAlignAction->setIcon(icon14);
        rightAlignAction = new QAction(MainWindow);
        rightAlignAction->setObjectName(QString::fromUtf8("rightAlignAction"));
        rightAlignAction->setCheckable(false);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/right.png"), QSize(), QIcon::Normal, QIcon::Off);
        rightAlignAction->setIcon(icon15);
        justifyAlignAction = new QAction(MainWindow);
        justifyAlignAction->setObjectName(QString::fromUtf8("justifyAlignAction"));
        justifyAlignAction->setCheckable(false);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/images/justify.png"), QSize(), QIcon::Normal, QIcon::Off);
        justifyAlignAction->setIcon(icon16);
        closeAction = new QAction(MainWindow);
        closeAction->setObjectName(QString::fromUtf8("closeAction"));
        closeAllAction = new QAction(MainWindow);
        closeAllAction->setObjectName(QString::fromUtf8("closeAllAction"));
        titleAction = new QAction(MainWindow);
        titleAction->setObjectName(QString::fromUtf8("titleAction"));
        cascadeAction = new QAction(MainWindow);
        cascadeAction->setObjectName(QString::fromUtf8("cascadeAction"));
        nextAction = new QAction(MainWindow);
        nextAction->setObjectName(QString::fromUtf8("nextAction"));
        previousAction = new QAction(MainWindow);
        previousAction->setObjectName(QString::fromUtf8("previousAction"));
        aboutAction = new QAction(MainWindow);
        aboutAction->setObjectName(QString::fromUtf8("aboutAction"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        fontComboBox = new QFontComboBox(centralwidget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout->addWidget(fontComboBox, 0, 1, 1, 1);

        sizeComboBox = new QComboBox(centralwidget);
        sizeComboBox->setObjectName(QString::fromUtf8("sizeComboBox"));

        gridLayout->addWidget(sizeComboBox, 0, 2, 1, 1);

        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(mdiArea->sizePolicy().hasHeightForWidth());
        mdiArea->setSizePolicy(sizePolicy);
        mdiArea->setAutoFillBackground(false);

        gridLayout->addWidget(mdiArea, 1, 0, 1, 3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 730, 26));
        menu_F = new QMenu(menubar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_E = new QMenu(menubar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_D = new QMenu(menu);
        menu_D->setObjectName(QString::fromUtf8("menu_D"));
        menu_2 = new QMenu(menu);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_W = new QMenu(menubar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        menu_H = new QMenu(menubar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

        menubar->addAction(menu_F->menuAction());
        menubar->addAction(menu_E->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_W->menuAction());
        menubar->addAction(menu_H->menuAction());
        menu_F->addAction(newAction);
        menu_F->addAction(openAction);
        menu_F->addAction(saveAction);
        menu_F->addAction(saveAsAction);
        menu_F->addAction(printAction);
        menu_F->addAction(printPreviewAction);
        menu_F->addAction(exitAction);
        menu_E->addAction(undoAction);
        menu_E->addAction(redoAction);
        menu_E->addAction(cutAction);
        menu_E->addAction(copyAction);
        menu_E->addAction(pasteAction);
        menu->addAction(menu_D->menuAction());
        menu->addAction(menu_2->menuAction());
        menu->addAction(colorAction);
        menu_D->addAction(boldAction);
        menu_D->addAction(italicAction);
        menu_D->addAction(underlinAction);
        menu_2->addAction(leftAlignAction);
        menu_2->addAction(centerAlignAction);
        menu_2->addAction(rightAlignAction);
        menu_2->addAction(justifyAlignAction);
        menu_W->addAction(closeAction);
        menu_W->addAction(closeAllAction);
        menu_W->addAction(titleAction);
        menu_W->addAction(cascadeAction);
        menu_W->addAction(nextAction);
        menu_W->addAction(previousAction);
        menu_H->addAction(aboutAction);
        toolBar->addAction(newAction);
        toolBar->addAction(openAction);
        toolBar->addAction(saveAction);
        toolBar->addAction(printAction);
        toolBar_2->addAction(undoAction);
        toolBar_2->addAction(redoAction);
        toolBar_2->addAction(cutAction);
        toolBar_2->addAction(copyAction);
        toolBar_2->addAction(pasteAction);
        toolBar_3->addAction(colorAction);
        toolBar_3->addAction(boldAction);
        toolBar_3->addAction(italicAction);
        toolBar_3->addAction(underlinAction);
        toolBar_3->addSeparator();
        toolBar_3->addAction(leftAlignAction);
        toolBar_3->addAction(centerAlignAction);
        toolBar_3->addAction(rightAlignAction);
        toolBar_3->addAction(justifyAlignAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        newAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272(N)", nullptr));
#if QT_CONFIG(statustip)
        newAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\344\270\200\344\270\252\346\226\260\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        newAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        openAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200(O)", nullptr));
#if QT_CONFIG(statustip)
        openAction->setStatusTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\200\344\270\252\345\267\262\345\255\230\345\234\250\347\232\204\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        openAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAction->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230(S)", nullptr));
#if QT_CONFIG(statustip)
        saveAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\345\275\223\345\211\215\346\226\207\346\241\243\345\255\230\347\233\230", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        saveAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        saveAsAction->setText(QCoreApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272(A)...", nullptr));
#if QT_CONFIG(statustip)
        saveAsAction->setStatusTip(QCoreApplication::translate("MainWindow", "\344\273\245\344\270\200\344\270\252\346\226\260\345\220\215\345\255\227\344\277\235\345\255\230\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
        printAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260(P)...", nullptr));
#if QT_CONFIG(statustip)
        printAction->setStatusTip(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\350\276\223\345\207\272\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        printAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        printPreviewAction->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\215\260\351\242\204\350\247\210...", nullptr));
#if QT_CONFIG(statustip)
        printPreviewAction->setStatusTip(QCoreApplication::translate("MainWindow", "\351\242\204\350\247\210\346\211\223\345\215\260\346\225\210\346\236\234", nullptr));
#endif // QT_CONFIG(statustip)
        exitAction->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(statustip)
        exitAction->setStatusTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\345\272\224\347\224\250\347\250\213\345\272\217", nullptr));
#endif // QT_CONFIG(statustip)
        undoAction->setText(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200(U)", nullptr));
#if QT_CONFIG(statustip)
        undoAction->setStatusTip(QCoreApplication::translate("MainWindow", "\346\222\244\351\224\200\345\275\223\345\211\215\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        undoAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        redoAction->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\201\232(R)", nullptr));
#if QT_CONFIG(statustip)
        redoAction->setStatusTip(QCoreApplication::translate("MainWindow", "\346\201\242\345\244\215\344\271\213\345\211\215\347\232\204\346\223\215\344\275\234", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        redoAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Y", nullptr));
#endif // QT_CONFIG(shortcut)
        cutAction->setText(QCoreApplication::translate("MainWindow", "\345\211\252\350\264\264(T)", nullptr));
#if QT_CONFIG(statustip)
        cutAction->setStatusTip(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\346\241\243\344\270\255\350\243\201\345\211\252\346\211\200\351\200\211\347\232\204\345\206\205\345\256\271\357\274\214\345\271\266\346\224\276\345\205\245\345\211\252\345\210\207\346\235\277", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        cutAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        copyAction->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266(C)", nullptr));
#if QT_CONFIG(statustip)
        copyAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266\346\211\200\351\200\211\345\206\205\345\256\271\357\274\214\345\271\266\346\224\276\345\205\245\345\211\252\345\210\207\346\235\277", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        copyAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        pasteAction->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264(P)", nullptr));
#if QT_CONFIG(statustip)
        pasteAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\345\211\252\345\210\207\346\235\277\345\206\205\345\256\271\347\262\230\350\264\264\345\210\260\346\226\207\346\241\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        pasteAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        colorAction->setText(QCoreApplication::translate("MainWindow", "\351\242\234\350\211\262(C)...", nullptr));
#if QT_CONFIG(statustip)
        colorAction->setStatusTip(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\211\200\351\200\211\346\226\207\345\255\227\351\242\234\350\211\262", nullptr));
#endif // QT_CONFIG(statustip)
        boldAction->setText(QCoreApplication::translate("MainWindow", "\345\212\240\347\262\227(B)", nullptr));
#if QT_CONFIG(statustip)
        boldAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\212\240\347\262\227", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        boldAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+B", nullptr));
#endif // QT_CONFIG(shortcut)
        italicAction->setText(QCoreApplication::translate("MainWindow", "\345\200\276\346\226\234(I)", nullptr));
#if QT_CONFIG(statustip)
        italicAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\200\276\346\226\234", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        italicAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        underlinAction->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277(U)", nullptr));
#if QT_CONFIG(statustip)
        underlinAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\212\240\344\270\212\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        underlinAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+U", nullptr));
#endif // QT_CONFIG(shortcut)
        leftAlignAction->setText(QCoreApplication::translate("MainWindow", "\345\267\246\345\257\271\351\275\220(L)", nullptr));
#if QT_CONFIG(statustip)
        leftAlignAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\267\246\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        leftAlignAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        centerAlignAction->setText(QCoreApplication::translate("MainWindow", "\345\261\205\344\270\255(C)", nullptr));
#if QT_CONFIG(statustip)
        centerAlignAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\261\205\344\270\255", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        centerAlignAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        rightAlignAction->setText(QCoreApplication::translate("MainWindow", "\345\217\263\345\257\271\351\275\220(R)", nullptr));
#if QT_CONFIG(statustip)
        rightAlignAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\217\263\345\257\271\351\275\220", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        rightAlignAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        justifyAlignAction->setText(QCoreApplication::translate("MainWindow", "\344\270\244\347\253\257\345\257\271\351\275\220(J)", nullptr));
#if QT_CONFIG(statustip)
        justifyAlignAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\260\206\346\211\200\351\200\211\346\226\207\345\255\227\345\267\246\345\217\263\344\270\244\347\253\257\345\257\271\351\275\220\357\274\214\345\271\266\346\240\271\346\215\256\351\234\200\350\246\201\350\260\203\346\225\264\351\227\264\350\267\235", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        justifyAlignAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+J", nullptr));
#endif // QT_CONFIG(shortcut)
        closeAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255(O)", nullptr));
#if QT_CONFIG(statustip)
        closeAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\264\273\345\212\250\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        closeAllAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211(A)", nullptr));
#if QT_CONFIG(statustip)
        closeAllAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\211\200\346\234\211\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        titleAction->setText(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272(T)", nullptr));
#if QT_CONFIG(statustip)
        titleAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\271\263\351\223\272\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        cascadeAction->setText(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240(C)", nullptr));
#if QT_CONFIG(statustip)
        cascadeAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\261\202\345\217\240\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
        nextAction->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252(X)", nullptr));
#if QT_CONFIG(statustip)
        nextAction->setStatusTip(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\204\246\347\202\271\345\210\260\344\270\213\344\270\200\344\270\252\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        nextAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        previousAction->setText(QCoreApplication::translate("MainWindow", "\345\211\215\344\270\200\344\270\252(V)", nullptr));
#if QT_CONFIG(statustip)
        previousAction->setStatusTip(QCoreApplication::translate("MainWindow", "\347\247\273\345\212\250\347\204\246\347\202\271\345\210\260\344\270\212\344\270\200\344\270\252\345\255\220\347\252\227\345\217\243", nullptr));
#endif // QT_CONFIG(statustip)
#if QT_CONFIG(shortcut)
        previousAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+Tab", nullptr));
#endif // QT_CONFIG(shortcut)
        aboutAction->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216(A)", nullptr));
#if QT_CONFIG(statustip)
        aboutAction->setStatusTip(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216WSP...", nullptr));
#endif // QT_CONFIG(statustip)
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\346\240\207\345\207\206", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\217)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\227\213)", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(\342\226\240)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(1.2.3.)", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(a.b.c.)", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(A.B.C.)", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(i.ii.iii.)", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "\351\241\271\347\233\256\347\254\246\345\217\267(I.II.III.)", nullptr));

        menu_F->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", nullptr));
        menu_E->setTitle(QCoreApplication::translate("MainWindow", "\347\274\226\350\276\221(&E)", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\240\274\345\274\217(&O)", nullptr));
        menu_D->setTitle(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223(&D)", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\256\265\350\220\275", nullptr));
        menu_W->setTitle(QCoreApplication::translate("MainWindow", "\347\252\227\344\275\223(&W)", nullptr));
        menu_H->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
        toolBar_2->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_2", nullptr));
        toolBar_3->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar_3", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
