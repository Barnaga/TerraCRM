/********************************************************************************
** Form generated from reading UI file 'FinanceWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINANCEWINDOW_H
#define UI_FINANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FinanceWindowClass
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *financeLbl;
    QSpacerItem *horizontalSpacer;
    QPushButton *spendingBTn;
    QPushButton *receiptBTn;
    QPushButton *transferBtn;
    QHBoxLayout *financeLayout;

    void setupUi(QWidget *FinanceWindowClass)
    {
        if (FinanceWindowClass->objectName().isEmpty())
            FinanceWindowClass->setObjectName("FinanceWindowClass");
        FinanceWindowClass->resize(909, 591);
        horizontalLayout_3 = new QHBoxLayout(FinanceWindowClass);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        financeLbl = new QLabel(FinanceWindowClass);
        financeLbl->setObjectName("financeLbl");

        horizontalLayout->addWidget(financeLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spendingBTn = new QPushButton(FinanceWindowClass);
        spendingBTn->setObjectName("spendingBTn");

        horizontalLayout->addWidget(spendingBTn);

        receiptBTn = new QPushButton(FinanceWindowClass);
        receiptBTn->setObjectName("receiptBTn");

        horizontalLayout->addWidget(receiptBTn);

        transferBtn = new QPushButton(FinanceWindowClass);
        transferBtn->setObjectName("transferBtn");

        horizontalLayout->addWidget(transferBtn);


        verticalLayout->addLayout(horizontalLayout);

        financeLayout = new QHBoxLayout();
        financeLayout->setSpacing(6);
        financeLayout->setObjectName("financeLayout");

        verticalLayout->addLayout(financeLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(FinanceWindowClass);

        QMetaObject::connectSlotsByName(FinanceWindowClass);
    } // setupUi

    void retranslateUi(QWidget *FinanceWindowClass)
    {
        FinanceWindowClass->setWindowTitle(QCoreApplication::translate("FinanceWindowClass", "FinanceWindow", nullptr));
        financeLbl->setText(QCoreApplication::translate("FinanceWindowClass", "\320\224\320\265\320\275\321\214\320\263\320\270", nullptr));
        spendingBTn->setText(QCoreApplication::translate("FinanceWindowClass", "\320\240\320\260\321\201\321\205\320\276\320\264", nullptr));
        receiptBTn->setText(QCoreApplication::translate("FinanceWindowClass", "\320\237\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\320\265", nullptr));
        transferBtn->setText(QCoreApplication::translate("FinanceWindowClass", "\320\242\321\200\320\260\320\275\321\201\321\204\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FinanceWindowClass: public Ui_FinanceWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINANCEWINDOW_H
