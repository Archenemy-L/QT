/********************************************************************************
** Form generated from reading UI file 'templedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEMPLEDIALOG_H
#define UI_TEMPLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_TempleDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TempleDialog)
    {
        if (TempleDialog->objectName().isEmpty())
            TempleDialog->setObjectName(QString::fromUtf8("TempleDialog"));
        TempleDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(TempleDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(TempleDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TempleDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TempleDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TempleDialog);
    } // setupUi

    void retranslateUi(QDialog *TempleDialog)
    {
        TempleDialog->setWindowTitle(QCoreApplication::translate("TempleDialog", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TempleDialog: public Ui_TempleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEMPLEDIALOG_H
