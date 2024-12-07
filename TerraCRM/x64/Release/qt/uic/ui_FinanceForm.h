/********************************************************************************
** Form generated from reading UI file 'FinanceForm.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCEFORM_H
#define UI_FINANCEFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinanceFormClass
{
public:
    QLabel *name;
    QPushButton *saveBtn;
    QPushButton *cancelBtn;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *payerLayout;
    QLabel *payerLbl;
    QComboBox *payerBox;
    QVBoxLayout *responsibleLayout;
    QLabel *responsibleLbl;
    QComboBox *responsibleBox;
    QVBoxLayout *categoryLayout;
    QLabel *categoryLbl;
    QComboBox *categoryBox;
    QVBoxLayout *recipientLayout;
    QLabel *recipientLbl;
    QComboBox *recipientBox;
    QVBoxLayout *orgAccount;
    QLabel *orgAccountLbl;
    QComboBox *orgAccountBox;
    QVBoxLayout *communicationLayout;
    QLabel *communicationLbl;
    QComboBox *communicationBox;
    QVBoxLayout *dateLayout;
    QLabel *dateLbl;
    QLineEdit *date;
    QVBoxLayout *cashLayout;
    QLabel *cashLbl;
    QLineEdit *cash;
    QVBoxLayout *noteLayout;
    QLabel *noteLbl;
    QLineEdit *note;
    QVBoxLayout *stateLayout;
    QLabel *stateLbl;
    QComboBox *stateBox;
    QLabel *warningLbl;

    void setupUi(QDialog *FinanceFormClass)
    {
        if (FinanceFormClass->objectName().isEmpty())
            FinanceFormClass->setObjectName("FinanceFormClass");
        FinanceFormClass->resize(954, 609);
        name = new QLabel(FinanceFormClass);
        name->setObjectName("name");
        name->setGeometry(QRect(40, 20, 231, 16));
        saveBtn = new QPushButton(FinanceFormClass);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(60, 350, 75, 24));
        cancelBtn = new QPushButton(FinanceFormClass);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setGeometry(QRect(160, 350, 75, 24));
        layoutWidget = new QWidget(FinanceFormClass);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(16, 50, 921, 137));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(9);
        gridLayout->setVerticalSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        payerLayout = new QVBoxLayout();
        payerLayout->setSpacing(6);
        payerLayout->setObjectName("payerLayout");
        payerLbl = new QLabel(layoutWidget);
        payerLbl->setObjectName("payerLbl");

        payerLayout->addWidget(payerLbl);

        payerBox = new QComboBox(layoutWidget);
        payerBox->setObjectName("payerBox");

        payerLayout->addWidget(payerBox);


        gridLayout->addLayout(payerLayout, 1, 1, 1, 1);

        responsibleLayout = new QVBoxLayout();
        responsibleLayout->setSpacing(6);
        responsibleLayout->setObjectName("responsibleLayout");
        responsibleLbl = new QLabel(layoutWidget);
        responsibleLbl->setObjectName("responsibleLbl");

        responsibleLayout->addWidget(responsibleLbl);

        responsibleBox = new QComboBox(layoutWidget);
        responsibleBox->setObjectName("responsibleBox");

        responsibleLayout->addWidget(responsibleBox);


        gridLayout->addLayout(responsibleLayout, 0, 2, 1, 1);

        categoryLayout = new QVBoxLayout();
        categoryLayout->setSpacing(6);
        categoryLayout->setObjectName("categoryLayout");
        categoryLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        categoryLbl = new QLabel(layoutWidget);
        categoryLbl->setObjectName("categoryLbl");

        categoryLayout->addWidget(categoryLbl);

        categoryBox = new QComboBox(layoutWidget);
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->addItem(QString());
        categoryBox->setObjectName("categoryBox");

        categoryLayout->addWidget(categoryBox);


        gridLayout->addLayout(categoryLayout, 2, 0, 1, 2);

        recipientLayout = new QVBoxLayout();
        recipientLayout->setSpacing(6);
        recipientLayout->setObjectName("recipientLayout");
        recipientLbl = new QLabel(layoutWidget);
        recipientLbl->setObjectName("recipientLbl");

        recipientLayout->addWidget(recipientLbl);

        recipientBox = new QComboBox(layoutWidget);
        recipientBox->setObjectName("recipientBox");

        recipientLayout->addWidget(recipientBox);


        gridLayout->addLayout(recipientLayout, 1, 0, 1, 1);

        orgAccount = new QVBoxLayout();
        orgAccount->setSpacing(6);
        orgAccount->setObjectName("orgAccount");
        orgAccountLbl = new QLabel(layoutWidget);
        orgAccountLbl->setObjectName("orgAccountLbl");

        orgAccount->addWidget(orgAccountLbl);

        orgAccountBox = new QComboBox(layoutWidget);
        orgAccountBox->addItem(QString());
        orgAccountBox->addItem(QString());
        orgAccountBox->setObjectName("orgAccountBox");

        orgAccount->addWidget(orgAccountBox);


        gridLayout->addLayout(orgAccount, 1, 2, 1, 1);

        communicationLayout = new QVBoxLayout();
        communicationLayout->setSpacing(6);
        communicationLayout->setObjectName("communicationLayout");
        communicationLbl = new QLabel(layoutWidget);
        communicationLbl->setObjectName("communicationLbl");

        communicationLayout->addWidget(communicationLbl);

        communicationBox = new QComboBox(layoutWidget);
        communicationBox->setObjectName("communicationBox");

        communicationLayout->addWidget(communicationBox);


        gridLayout->addLayout(communicationLayout, 1, 3, 1, 1);

        dateLayout = new QVBoxLayout();
        dateLayout->setSpacing(6);
        dateLayout->setObjectName("dateLayout");
        dateLbl = new QLabel(layoutWidget);
        dateLbl->setObjectName("dateLbl");

        dateLayout->addWidget(dateLbl);

        date = new QLineEdit(layoutWidget);
        date->setObjectName("date");

        dateLayout->addWidget(date);


        gridLayout->addLayout(dateLayout, 0, 1, 1, 1);

        cashLayout = new QVBoxLayout();
        cashLayout->setSpacing(6);
        cashLayout->setObjectName("cashLayout");
        cashLbl = new QLabel(layoutWidget);
        cashLbl->setObjectName("cashLbl");

        cashLayout->addWidget(cashLbl);

        cash = new QLineEdit(layoutWidget);
        cash->setObjectName("cash");

        cashLayout->addWidget(cash);


        gridLayout->addLayout(cashLayout, 0, 0, 1, 1);

        noteLayout = new QVBoxLayout();
        noteLayout->setSpacing(6);
        noteLayout->setObjectName("noteLayout");
        noteLayout->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        noteLbl = new QLabel(layoutWidget);
        noteLbl->setObjectName("noteLbl");

        noteLayout->addWidget(noteLbl);

        note = new QLineEdit(layoutWidget);
        note->setObjectName("note");

        noteLayout->addWidget(note);


        gridLayout->addLayout(noteLayout, 2, 2, 1, 2);

        stateLayout = new QVBoxLayout();
        stateLayout->setSpacing(6);
        stateLayout->setObjectName("stateLayout");
        stateLbl = new QLabel(layoutWidget);
        stateLbl->setObjectName("stateLbl");

        stateLayout->addWidget(stateLbl);

        stateBox = new QComboBox(layoutWidget);
        stateBox->addItem(QString());
        stateBox->addItem(QString());
        stateBox->addItem(QString());
        stateBox->addItem(QString());
        stateBox->setObjectName("stateBox");

        stateLayout->addWidget(stateBox);


        gridLayout->addLayout(stateLayout, 0, 3, 1, 1);

        warningLbl = new QLabel(FinanceFormClass);
        warningLbl->setObjectName("warningLbl");
        warningLbl->setEnabled(false);
        warningLbl->setGeometry(QRect(70, 300, 181, 16));

        retranslateUi(FinanceFormClass);

        QMetaObject::connectSlotsByName(FinanceFormClass);
    } // setupUi

    void retranslateUi(QDialog *FinanceFormClass)
    {
        FinanceFormClass->setWindowTitle(QCoreApplication::translate("FinanceFormClass", "FinanceForm", nullptr));
        name->setText(QString());
        saveBtn->setText(QCoreApplication::translate("FinanceFormClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cancelBtn->setText(QCoreApplication::translate("FinanceFormClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        payerLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\237\320\273\320\260\321\202\320\265\320\273\321\214\321\211\320\270\320\272", nullptr));
        responsibleLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\236\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        categoryLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\232\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", nullptr));
        categoryBox->setItemText(0, QCoreApplication::translate("FinanceFormClass", "\320\235\320\265\321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\275\321\213\320\265", nullptr));
        categoryBox->setItemText(1, QCoreApplication::translate("FinanceFormClass", "\320\237\321\200\320\276\320\264\320\260\320\266\320\260 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        categoryBox->setItemText(2, QCoreApplication::translate("FinanceFormClass", "\320\236\320\272\320\260\320\267\320\260\320\275\320\270\320\265 \321\203\321\201\320\273\321\203\320\263", nullptr));
        categoryBox->setItemText(3, QCoreApplication::translate("FinanceFormClass", "\320\237\320\276\320\273\321\203\321\207\320\265\320\275\320\270\320\265 \320\272\321\200\320\265\320\264\320\270\321\202\320\260", nullptr));
        categoryBox->setItemText(4, QCoreApplication::translate("FinanceFormClass", "\320\237\321\200\320\276\321\206\320\265\320\275\321\202\321\213 \320\272 \320\277\320\276\320\273\321\203\321\207\320\265\320\275\320\270\321\216", nullptr));
        categoryBox->setItemText(5, QCoreApplication::translate("FinanceFormClass", "\320\237\321\200\320\276\321\207\320\270\320\271 \320\264\320\276\321\205\320\276\320\264", nullptr));
        categoryBox->setItemText(6, QCoreApplication::translate("FinanceFormClass", "\320\237\320\265\321\200\320\265\320\262\320\276\320\264 \320\274\320\265\320\266\320\264\321\203 \321\201\321\207\320\265\321\202\320\260\320\274\320\270", nullptr));
        categoryBox->setItemText(7, QCoreApplication::translate("FinanceFormClass", "\320\235\320\265\321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\275\320\260\321\217 \321\201\321\203\320\274\320\274\320\260", nullptr));

        recipientLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\237\320\276\320\273\321\203\321\207\320\260\321\202\320\265\320\273\321\214", nullptr));
        orgAccountLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\241\321\207\320\265\321\202 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270", nullptr));
        orgAccountBox->setItemText(0, QCoreApplication::translate("FinanceFormClass", "\320\235\320\260\320\273\320\270\321\207\320\275\321\213\320\265", nullptr));
        orgAccountBox->setItemText(1, QCoreApplication::translate("FinanceFormClass", "\320\240\320\260\321\201\321\207\320\265\321\202\320\275\321\213\320\271 \321\201\321\207\320\265\321\202", nullptr));

        communicationLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\241\320\262\321\217\320\267\321\214", nullptr));
        dateLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\224\320\260\321\202\320\260 \320\276\320\277\320\273\320\260\321\202\321\213", nullptr));
        cashLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        noteLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\237\321\200\320\270\320\274\320\265\321\207\320\260\320\275\320\270\320\265", nullptr));
        stateLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\217", nullptr));
        stateBox->setItemText(0, QCoreApplication::translate("FinanceFormClass", "\320\224\320\224\320\241 \320\270 \320\237\320\270\320\243", nullptr));
        stateBox->setItemText(1, QCoreApplication::translate("FinanceFormClass", "\320\224\320\224\320\241", nullptr));
        stateBox->setItemText(2, QCoreApplication::translate("FinanceFormClass", "\320\237\320\270\320\243", nullptr));
        stateBox->setItemText(3, QCoreApplication::translate("FinanceFormClass", "\320\235\320\265 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275", nullptr));

        warningLbl->setText(QCoreApplication::translate("FinanceFormClass", "\320\237\321\200\320\276\320\262\320\265\321\200\321\214\321\202\320\265 \320\272\320\276\321\200\321\200\320\265\320\272\321\202\320\275\320\276\321\201\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinanceFormClass: public Ui_FinanceFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCEFORM_H
