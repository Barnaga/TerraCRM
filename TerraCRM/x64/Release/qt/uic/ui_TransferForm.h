/********************************************************************************
** Form generated from reading UI file 'TransferForm.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERFORM_H
#define UI_TRANSFERFORM_H

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

class Ui_TransferFormClass
{
public:
    QPushButton *saveBtn;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *responsibleLayout;
    QLabel *responsibleLbl;
    QComboBox *responsibleBox;
    QVBoxLayout *cashLayout;
    QLabel *cashLbl;
    QLineEdit *cash;
    QVBoxLayout *fromAccountLayout;
    QLabel *fromAccountLbl;
    QComboBox *fromAccountBox;
    QVBoxLayout *toAccountLayout;
    QLabel *toAccountLbl;
    QComboBox *toAccountBox;
    QVBoxLayout *dateLayout;
    QLabel *dateLbl;
    QLineEdit *date;
    QVBoxLayout *stateLayout;
    QLabel *stateLbl;
    QComboBox *stateBox;
    QPushButton *cancelBtn;

    void setupUi(QDialog *TransferFormClass)
    {
        if (TransferFormClass->objectName().isEmpty())
            TransferFormClass->setObjectName("TransferFormClass");
        TransferFormClass->resize(961, 570);
        saveBtn = new QPushButton(TransferFormClass);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(70, 360, 75, 24));
        label = new QLabel(TransferFormClass);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 61, 16));
        layoutWidget = new QWidget(TransferFormClass);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 60, 911, 125));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        responsibleLayout = new QVBoxLayout();
        responsibleLayout->setSpacing(6);
        responsibleLayout->setObjectName("responsibleLayout");
        responsibleLbl = new QLabel(layoutWidget);
        responsibleLbl->setObjectName("responsibleLbl");

        responsibleLayout->addWidget(responsibleLbl);

        responsibleBox = new QComboBox(layoutWidget);
        responsibleBox->setObjectName("responsibleBox");

        responsibleLayout->addWidget(responsibleBox);


        gridLayout->addLayout(responsibleLayout, 1, 1, 1, 1);

        cashLayout = new QVBoxLayout();
        cashLayout->setSpacing(6);
        cashLayout->setObjectName("cashLayout");
        cashLbl = new QLabel(layoutWidget);
        cashLbl->setObjectName("cashLbl");

        cashLayout->addWidget(cashLbl);

        cash = new QLineEdit(layoutWidget);
        cash->setObjectName("cash");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cash->sizePolicy().hasHeightForWidth());
        cash->setSizePolicy(sizePolicy);

        cashLayout->addWidget(cash);


        gridLayout->addLayout(cashLayout, 0, 0, 1, 1);

        fromAccountLayout = new QVBoxLayout();
        fromAccountLayout->setSpacing(6);
        fromAccountLayout->setObjectName("fromAccountLayout");
        fromAccountLbl = new QLabel(layoutWidget);
        fromAccountLbl->setObjectName("fromAccountLbl");

        fromAccountLayout->addWidget(fromAccountLbl);

        fromAccountBox = new QComboBox(layoutWidget);
        fromAccountBox->setObjectName("fromAccountBox");

        fromAccountLayout->addWidget(fromAccountBox);


        gridLayout->addLayout(fromAccountLayout, 0, 1, 1, 1);

        toAccountLayout = new QVBoxLayout();
        toAccountLayout->setSpacing(6);
        toAccountLayout->setObjectName("toAccountLayout");
        toAccountLbl = new QLabel(layoutWidget);
        toAccountLbl->setObjectName("toAccountLbl");

        toAccountLayout->addWidget(toAccountLbl);

        toAccountBox = new QComboBox(layoutWidget);
        toAccountBox->setObjectName("toAccountBox");

        toAccountLayout->addWidget(toAccountBox);


        gridLayout->addLayout(toAccountLayout, 0, 2, 1, 2);

        dateLayout = new QVBoxLayout();
        dateLayout->setSpacing(6);
        dateLayout->setObjectName("dateLayout");
        dateLbl = new QLabel(layoutWidget);
        dateLbl->setObjectName("dateLbl");

        dateLayout->addWidget(dateLbl);

        date = new QLineEdit(layoutWidget);
        date->setObjectName("date");
        sizePolicy.setHeightForWidth(date->sizePolicy().hasHeightForWidth());
        date->setSizePolicy(sizePolicy);

        dateLayout->addWidget(date);


        gridLayout->addLayout(dateLayout, 1, 0, 1, 1);

        stateLayout = new QVBoxLayout();
        stateLayout->setSpacing(6);
        stateLayout->setObjectName("stateLayout");
        stateLbl = new QLabel(layoutWidget);
        stateLbl->setObjectName("stateLbl");

        stateLayout->addWidget(stateLbl);

        stateBox = new QComboBox(layoutWidget);
        stateBox->setObjectName("stateBox");

        stateLayout->addWidget(stateBox);


        gridLayout->addLayout(stateLayout, 1, 2, 1, 2);

        cancelBtn = new QPushButton(TransferFormClass);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setGeometry(QRect(170, 360, 75, 24));

        retranslateUi(TransferFormClass);

        QMetaObject::connectSlotsByName(TransferFormClass);
    } // setupUi

    void retranslateUi(QDialog *TransferFormClass)
    {
        TransferFormClass->setWindowTitle(QCoreApplication::translate("TransferFormClass", "TransferForm", nullptr));
        saveBtn->setText(QCoreApplication::translate("TransferFormClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("TransferFormClass", "\320\242\321\200\320\260\320\275\321\201\321\204\320\265\321\200", nullptr));
        responsibleLbl->setText(QCoreApplication::translate("TransferFormClass", "\320\236\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        cashLbl->setText(QCoreApplication::translate("TransferFormClass", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        fromAccountLbl->setText(QCoreApplication::translate("TransferFormClass", "\320\241\320\276 \321\201\321\207\320\265\321\202\320\260", nullptr));
        toAccountLbl->setText(QCoreApplication::translate("TransferFormClass", "\320\235\320\260 \321\201\321\207\320\265\321\202", nullptr));
        dateLbl->setText(QCoreApplication::translate("TransferFormClass", "\320\224\320\260\321\202\320\260 \320\276\320\277\320\273\320\260\321\202\321\213", nullptr));
        stateLbl->setText(QCoreApplication::translate("TransferFormClass", "\320\241\321\202\320\260\321\202\321\203\321\201 \320\277\321\200\320\276\320\262\320\265\320\264\320\265\320\275\320\270\321\217", nullptr));
        cancelBtn->setText(QCoreApplication::translate("TransferFormClass", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransferFormClass: public Ui_TransferFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERFORM_H
