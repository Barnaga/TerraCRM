/********************************************************************************
** Form generated from reading UI file 'CRMWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRMWINDOW_H
#define UI_CRMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRMWindowClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *dealsLbl;
    QSpacerItem *horizontalSpacer;
    QLabel *dateLbl;
    QVBoxLayout *crmLayout;

    void setupUi(QWidget *CRMWindowClass)
    {
        if (CRMWindowClass->objectName().isEmpty())
            CRMWindowClass->setObjectName("CRMWindowClass");
        CRMWindowClass->resize(978, 516);
        CRMWindowClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"color:rgb(55, 107, 113);\n"
"}"));
        verticalLayout = new QVBoxLayout(CRMWindowClass);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        dealsLbl = new QLabel(CRMWindowClass);
        dealsLbl->setObjectName("dealsLbl");
        dealsLbl->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(dealsLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dateLbl = new QLabel(CRMWindowClass);
        dateLbl->setObjectName("dateLbl");

        horizontalLayout->addWidget(dateLbl);


        verticalLayout->addLayout(horizontalLayout);

        crmLayout = new QVBoxLayout();
        crmLayout->setObjectName("crmLayout");

        verticalLayout->addLayout(crmLayout);


        retranslateUi(CRMWindowClass);

        QMetaObject::connectSlotsByName(CRMWindowClass);
    } // setupUi

    void retranslateUi(QWidget *CRMWindowClass)
    {
        CRMWindowClass->setWindowTitle(QCoreApplication::translate("CRMWindowClass", "Form", nullptr));
        dealsLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\241\320\264\320\265\320\273\320\272\320\270", nullptr));
        dateLbl->setText(QCoreApplication::translate("CRMWindowClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRMWindowClass: public Ui_CRMWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRMWINDOW_H
