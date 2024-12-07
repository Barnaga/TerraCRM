/********************************************************************************
** Form generated from reading UI file 'DealWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEALWIDGET_H
#define UI_DEALWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DealWidgetClass
{
public:
    QLabel *dealLbl;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *sumLayout;
    QLabel *sumLbl;
    QLabel *sum;
    QVBoxLayout *timeDealLayout;
    QLabel *timeDealLbl;
    QLabel *timeDeal;
    QVBoxLayout *sourceDealLayout;
    QLabel *sourceDealLbl;
    QLabel *sourceDeal;
    QVBoxLayout *responsibleLayout;
    QLabel *responsibleLbl;
    QLabel *responsible;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *statusSaleLbl;
    QComboBox *statusComboBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *client;
    QLabel *clientLbl;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *numberLbl;
    QLabel *number;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *emailLbl;
    QLabel *email;
    QPushButton *phoneCallBtn;
    QPushButton *smsBtn;

    void setupUi(QDialog *DealWidgetClass)
    {
        if (DealWidgetClass->objectName().isEmpty())
            DealWidgetClass->setObjectName("DealWidgetClass");
        DealWidgetClass->resize(513, 227);
        DealWidgetClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"color:rgb(55, 107, 113);\n"
"}"));
        dealLbl = new QLabel(DealWidgetClass);
        dealLbl->setObjectName("dealLbl");
        dealLbl->setGeometry(QRect(9, 9, 49, 16));
        layoutWidget_4 = new QWidget(DealWidgetClass);
        layoutWidget_4->setObjectName("layoutWidget_4");
        layoutWidget_4->setGeometry(QRect(9, 96, 331, 42));
        horizontalLayout = new QHBoxLayout(layoutWidget_4);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        sumLayout = new QVBoxLayout();
        sumLayout->setSpacing(6);
        sumLayout->setObjectName("sumLayout");
        sumLbl = new QLabel(layoutWidget_4);
        sumLbl->setObjectName("sumLbl");

        sumLayout->addWidget(sumLbl);

        sum = new QLabel(layoutWidget_4);
        sum->setObjectName("sum");

        sumLayout->addWidget(sum);


        horizontalLayout->addLayout(sumLayout);

        timeDealLayout = new QVBoxLayout();
        timeDealLayout->setSpacing(6);
        timeDealLayout->setObjectName("timeDealLayout");
        timeDealLbl = new QLabel(layoutWidget_4);
        timeDealLbl->setObjectName("timeDealLbl");

        timeDealLayout->addWidget(timeDealLbl);

        timeDeal = new QLabel(layoutWidget_4);
        timeDeal->setObjectName("timeDeal");

        timeDealLayout->addWidget(timeDeal);


        horizontalLayout->addLayout(timeDealLayout);

        sourceDealLayout = new QVBoxLayout();
        sourceDealLayout->setSpacing(6);
        sourceDealLayout->setObjectName("sourceDealLayout");
        sourceDealLbl = new QLabel(layoutWidget_4);
        sourceDealLbl->setObjectName("sourceDealLbl");

        sourceDealLayout->addWidget(sourceDealLbl);

        sourceDeal = new QLabel(layoutWidget_4);
        sourceDeal->setObjectName("sourceDeal");

        sourceDealLayout->addWidget(sourceDeal);


        horizontalLayout->addLayout(sourceDealLayout);

        responsibleLayout = new QVBoxLayout();
        responsibleLayout->setSpacing(6);
        responsibleLayout->setObjectName("responsibleLayout");
        responsibleLbl = new QLabel(layoutWidget_4);
        responsibleLbl->setObjectName("responsibleLbl");

        responsibleLayout->addWidget(responsibleLbl);

        responsible = new QLabel(layoutWidget_4);
        responsible->setObjectName("responsible");

        responsibleLayout->addWidget(responsible);


        horizontalLayout->addLayout(responsibleLayout);

        layoutWidget = new QWidget(DealWidgetClass);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(9, 67, 233, 23));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        statusSaleLbl = new QLabel(layoutWidget);
        statusSaleLbl->setObjectName("statusSaleLbl");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(statusSaleLbl->sizePolicy().hasHeightForWidth());
        statusSaleLbl->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(statusSaleLbl);

        statusComboBox = new QComboBox(layoutWidget);
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->addItem(QString());
        statusComboBox->setObjectName("statusComboBox");

        horizontalLayout_3->addWidget(statusComboBox);

        widget = new QWidget(DealWidgetClass);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(9, 144, 96, 18));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        client = new QLabel(widget);
        client->setObjectName("client");

        horizontalLayout_2->addWidget(client);

        clientLbl = new QLabel(widget);
        clientLbl->setObjectName("clientLbl");

        horizontalLayout_2->addWidget(clientLbl);

        widget1 = new QWidget(DealWidgetClass);
        widget1->setObjectName("widget1");
        widget1->setGeometry(QRect(9, 176, 95, 18));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        numberLbl = new QLabel(widget1);
        numberLbl->setObjectName("numberLbl");

        horizontalLayout_4->addWidget(numberLbl);

        number = new QLabel(widget1);
        number->setObjectName("number");

        horizontalLayout_4->addWidget(number);

        widget2 = new QWidget(DealWidgetClass);
        widget2->setObjectName("widget2");
        widget2->setGeometry(QRect(9, 200, 86, 18));
        horizontalLayout_5 = new QHBoxLayout(widget2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        emailLbl = new QLabel(widget2);
        emailLbl->setObjectName("emailLbl");

        horizontalLayout_5->addWidget(emailLbl);

        email = new QLabel(widget2);
        email->setObjectName("email");

        horizontalLayout_5->addWidget(email);

        phoneCallBtn = new QPushButton(DealWidgetClass);
        phoneCallBtn->setObjectName("phoneCallBtn");
        phoneCallBtn->setGeometry(QRect(112, 145, 75, 24));
        smsBtn = new QPushButton(DealWidgetClass);
        smsBtn->setObjectName("smsBtn");
        smsBtn->setGeometry(QRect(193, 145, 75, 24));

        retranslateUi(DealWidgetClass);

        QMetaObject::connectSlotsByName(DealWidgetClass);
    } // setupUi

    void retranslateUi(QDialog *DealWidgetClass)
    {
        DealWidgetClass->setWindowTitle(QCoreApplication::translate("DealWidgetClass", "DealWidget", nullptr));
        dealLbl->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        sumLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\241\321\203\320\274\320\274\320\260", nullptr));
        sum->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        timeDealLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\241\321\200\320\276\320\272\320\270 \321\201\320\264\320\265\320\273\320\272\320\270", nullptr));
        timeDeal->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        sourceDealLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\230\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\264\320\265\320\273\320\272\320\270", nullptr));
        sourceDeal->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        responsibleLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\236\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        responsible->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        statusSaleLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\255\321\202\320\260\320\277 \321\201\320\264\320\265\320\273\320\272\320\270:", nullptr));
        statusComboBox->setItemText(0, QCoreApplication::translate("DealWidgetClass", "\320\235\320\276\320\262\320\260\321\217 \320\267\320\260\321\217\320\262\320\272\320\260", nullptr));
        statusComboBox->setItemText(1, QCoreApplication::translate("DealWidgetClass", "\320\237\320\265\321\200\320\265\320\263\320\276\320\262\320\276\321\200\321\213", nullptr));
        statusComboBox->setItemText(2, QCoreApplication::translate("DealWidgetClass", "\320\237\321\200\320\270\320\275\321\217\321\202\320\270\320\265 \321\200\320\265\321\210\320\265\320\275\320\270\321\217", nullptr));
        statusComboBox->setItemText(3, QCoreApplication::translate("DealWidgetClass", "\320\241\320\276\320\263\320\273\320\260\321\201\320\276\320\262\320\260\320\275\320\270\320\265 \320\264\320\276\320\263\320\276\320\262\320\276\321\200\320\260", nullptr));
        statusComboBox->setItemText(4, QCoreApplication::translate("DealWidgetClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214 \321\201\320\264\320\265\320\273\320\272\321\203", nullptr));

        client->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        clientLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        numberLbl->setText(QCoreApplication::translate("DealWidgetClass", "\320\235\320\276\320\274\320\265\321\200", nullptr));
        number->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        emailLbl->setText(QCoreApplication::translate("DealWidgetClass", "email", nullptr));
        email->setText(QCoreApplication::translate("DealWidgetClass", "TextLabel", nullptr));
        phoneCallBtn->setText(QCoreApplication::translate("DealWidgetClass", "\320\227\320\262\320\276\320\275\320\276\320\272", nullptr));
        smsBtn->setText(QCoreApplication::translate("DealWidgetClass", "\321\201\320\274\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DealWidgetClass: public Ui_DealWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEALWIDGET_H
