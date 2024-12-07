/********************************************************************************
** Form generated from reading UI file 'createProjectDialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEPROJECTDIALOG_H
#define UI_CREATEPROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_createProjectDialogClass
{
public:
    QLabel *label;
    QLabel *nameLbl;
    QLineEdit *name;
    QDateEdit *deadline;
    QLabel *deadlineLbl;
    QComboBox *contact;
    QLabel *contactLbl;
    QPushButton *saveBtn;
    QComboBox *company;
    QLabel *companyLbl;

    void setupUi(QDialog *createProjectDialogClass)
    {
        if (createProjectDialogClass->objectName().isEmpty())
            createProjectDialogClass->setObjectName("createProjectDialogClass");
        createProjectDialogClass->resize(600, 229);
        createProjectDialogClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"color:rgb(55, 107, 113);\n"
"}"));
        label = new QLabel(createProjectDialogClass);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 481, 16));
        nameLbl = new QLabel(createProjectDialogClass);
        nameLbl->setObjectName("nameLbl");
        nameLbl->setGeometry(QRect(20, 40, 111, 16));
        name = new QLineEdit(createProjectDialogClass);
        name->setObjectName("name");
        name->setGeometry(QRect(130, 40, 451, 21));
        deadline = new QDateEdit(createProjectDialogClass);
        deadline->setObjectName("deadline");
        deadline->setGeometry(QRect(130, 70, 110, 22));
        deadlineLbl = new QLabel(createProjectDialogClass);
        deadlineLbl->setObjectName("deadlineLbl");
        deadlineLbl->setGeometry(QRect(20, 70, 111, 16));
        contact = new QComboBox(createProjectDialogClass);
        contact->setObjectName("contact");
        contact->setGeometry(QRect(140, 140, 211, 22));
        contactLbl = new QLabel(createProjectDialogClass);
        contactLbl->setObjectName("contactLbl");
        contactLbl->setGeometry(QRect(20, 140, 111, 16));
        saveBtn = new QPushButton(createProjectDialogClass);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(20, 180, 75, 24));
        company = new QComboBox(createProjectDialogClass);
        company->setObjectName("company");
        company->setGeometry(QRect(140, 100, 211, 22));
        companyLbl = new QLabel(createProjectDialogClass);
        companyLbl->setObjectName("companyLbl");
        companyLbl->setGeometry(QRect(20, 100, 111, 16));

        retranslateUi(createProjectDialogClass);

        QMetaObject::connectSlotsByName(createProjectDialogClass);
    } // setupUi

    void retranslateUi(QDialog *createProjectDialogClass)
    {
        createProjectDialogClass->setWindowTitle(QCoreApplication::translate("createProjectDialogClass", "createProjectDialog", nullptr));
        label->setText(QCoreApplication::translate("createProjectDialogClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\277\321\200\320\276\320\265\320\272\321\202", nullptr));
        nameLbl->setText(QCoreApplication::translate("createProjectDialogClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        deadlineLbl->setText(QCoreApplication::translate("createProjectDialogClass", "\320\232\321\200\320\260\320\271\320\275\320\270\320\271 \321\201\321\200\320\276\320\272", nullptr));
        contactLbl->setText(QCoreApplication::translate("createProjectDialogClass", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        saveBtn->setText(QCoreApplication::translate("createProjectDialogClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        companyLbl->setText(QCoreApplication::translate("createProjectDialogClass", "\320\232\320\276\320\274\320\277\320\260\320\275\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createProjectDialogClass: public Ui_createProjectDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEPROJECTDIALOG_H
