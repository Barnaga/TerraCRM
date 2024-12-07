/********************************************************************************
** Form generated from reading UI file 'ChangeStatusProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESTATUSPROJECTDIALOG_H
#define UI_CHANGESTATUSPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ChangeStatusProjectDialogClass
{
public:
    QLabel *nameLbl;
    QLabel *dateLbl;
    QLabel *date;
    QTextEdit *desc;
    QCheckBox *checkArchiveTask;
    QPushButton *saveBtn;
    QComboBox *statusBox;

    void setupUi(QDialog *ChangeStatusProjectDialogClass)
    {
        if (ChangeStatusProjectDialogClass->objectName().isEmpty())
            ChangeStatusProjectDialogClass->setObjectName("ChangeStatusProjectDialogClass");
        ChangeStatusProjectDialogClass->resize(600, 291);
        ChangeStatusProjectDialogClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"color:rgb(55, 107, 113);\n"
"}"));
        nameLbl = new QLabel(ChangeStatusProjectDialogClass);
        nameLbl->setObjectName("nameLbl");
        nameLbl->setGeometry(QRect(10, 10, 581, 16));
        dateLbl = new QLabel(ChangeStatusProjectDialogClass);
        dateLbl->setObjectName("dateLbl");
        dateLbl->setGeometry(QRect(10, 80, 371, 16));
        date = new QLabel(ChangeStatusProjectDialogClass);
        date->setObjectName("date");
        date->setGeometry(QRect(10, 100, 221, 16));
        desc = new QTextEdit(ChangeStatusProjectDialogClass);
        desc->setObjectName("desc");
        desc->setGeometry(QRect(0, 130, 581, 71));
        checkArchiveTask = new QCheckBox(ChangeStatusProjectDialogClass);
        checkArchiveTask->setObjectName("checkArchiveTask");
        checkArchiveTask->setGeometry(QRect(10, 210, 161, 20));
        saveBtn = new QPushButton(ChangeStatusProjectDialogClass);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(10, 250, 75, 24));
        statusBox = new QComboBox(ChangeStatusProjectDialogClass);
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->setObjectName("statusBox");
        statusBox->setGeometry(QRect(20, 40, 561, 22));

        retranslateUi(ChangeStatusProjectDialogClass);

        QMetaObject::connectSlotsByName(ChangeStatusProjectDialogClass);
    } // setupUi

    void retranslateUi(QDialog *ChangeStatusProjectDialogClass)
    {
        ChangeStatusProjectDialogClass->setWindowTitle(QCoreApplication::translate("ChangeStatusProjectDialogClass", "ChangeStatusProjectDialog", nullptr));
        nameLbl->setText(QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\201\321\202\320\260\321\202\321\203\321\201\320\260 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        dateLbl->setText(QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\224\320\260\321\202\320\260 \320\260\321\205\320\270\320\262\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        date->setText(QCoreApplication::translate("ChangeStatusProjectDialogClass", "TextLabel", nullptr));
        checkArchiveTask->setText(QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\220\321\200\321\205\320\270\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        saveBtn->setText(QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        statusBox->setItemText(0, QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\227\320\260\320\272\321\200\321\213\321\202 \321\203\321\201\320\277\320\265\321\210\320\275\320\276", nullptr));
        statusBox->setItemText(1, QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\237\321\200\320\276\320\262\320\260\320\273\320\265\320\275", nullptr));
        statusBox->setItemText(2, QCoreApplication::translate("ChangeStatusProjectDialogClass", "\320\237\321\200\320\270\320\276\321\201\321\202\320\260\320\275\320\276\320\262\320\273\320\265\320\275", nullptr));

    } // retranslateUi

};

namespace Ui {
    class ChangeStatusProjectDialogClass: public Ui_ChangeStatusProjectDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESTATUSPROJECTDIALOG_H
