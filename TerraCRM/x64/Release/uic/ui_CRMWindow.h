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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CRMWindowClass
{
public:
    QFormLayout *formLayout;
    QLabel *dealsLbl;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout;
    QWidget *toDoWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *toDoTasksLbl;
    QLabel *toDoTasks;
    QSpacerItem *horizontalSpacer;
    QWidget *toWorksWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *toWorksTasksLbl;
    QLabel *toWorksTasks;
    QSpacerItem *horizontalSpacer_2;
    QWidget *toDoneWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *toDoneTasksLbl;
    QLabel *toDoneTasks;
    QSpacerItem *horizontalSpacer_3;
    QWidget *toCompleteWidget;
    QVBoxLayout *verticalLayout_5;
    QLabel *toCompleteTasksLbl;
    QLabel *toCompleteTasks;
    QWidget *toDoItem;
    QVBoxLayout *verticalLayout_6;
    QLabel *nameTasksLbl;
    QLabel *projectName;

    void setupUi(QWidget *CRMWindowClass)
    {
        if (CRMWindowClass->objectName().isEmpty())
            CRMWindowClass->setObjectName("CRMWindowClass");
        CRMWindowClass->resize(978, 516);
        formLayout = new QFormLayout(CRMWindowClass);
        formLayout->setObjectName("formLayout");
        dealsLbl = new QLabel(CRMWindowClass);
        dealsLbl->setObjectName("dealsLbl");
        dealsLbl->setMaximumSize(QSize(100, 30));

        formLayout->setWidget(0, QFormLayout::LabelRole, dealsLbl);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit = new QLineEdit(CRMWindowClass);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(lineEdit);

        comboBox = new QComboBox(CRMWindowClass);
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(CRMWindowClass);
        pushButton->setObjectName("pushButton");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButton);

        comboBox_2 = new QComboBox(CRMWindowClass);
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_2->addWidget(comboBox_2);


        formLayout->setLayout(1, QFormLayout::SpanningRole, horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        toDoWidget = new QWidget(CRMWindowClass);
        toDoWidget->setObjectName("toDoWidget");
        sizePolicy.setHeightForWidth(toDoWidget->sizePolicy().hasHeightForWidth());
        toDoWidget->setSizePolicy(sizePolicy);
        toDoWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255,253,253);\n"
"padding: 10px 10px;"));
        verticalLayout_4 = new QVBoxLayout(toDoWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        toDoTasksLbl = new QLabel(toDoWidget);
        toDoTasksLbl->setObjectName("toDoTasksLbl");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toDoTasksLbl->sizePolicy().hasHeightForWidth());
        toDoTasksLbl->setSizePolicy(sizePolicy1);
        toDoTasksLbl->setMinimumSize(QSize(150, 30));
        toDoTasksLbl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_4->addWidget(toDoTasksLbl);

        toDoTasks = new QLabel(toDoWidget);
        toDoTasks->setObjectName("toDoTasks");

        verticalLayout_4->addWidget(toDoTasks);


        horizontalLayout->addWidget(toDoWidget);

        horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toWorksWidget = new QWidget(CRMWindowClass);
        toWorksWidget->setObjectName("toWorksWidget");
        sizePolicy.setHeightForWidth(toWorksWidget->sizePolicy().hasHeightForWidth());
        toWorksWidget->setSizePolicy(sizePolicy);
        toWorksWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255,253,253);\n"
"padding: 10px 10px;"));
        verticalLayout_2 = new QVBoxLayout(toWorksWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        toWorksTasksLbl = new QLabel(toWorksWidget);
        toWorksTasksLbl->setObjectName("toWorksTasksLbl");
        sizePolicy1.setHeightForWidth(toWorksTasksLbl->sizePolicy().hasHeightForWidth());
        toWorksTasksLbl->setSizePolicy(sizePolicy1);
        toWorksTasksLbl->setMinimumSize(QSize(150, 30));
        toWorksTasksLbl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_2->addWidget(toWorksTasksLbl);

        toWorksTasks = new QLabel(toWorksWidget);
        toWorksTasks->setObjectName("toWorksTasks");

        verticalLayout_2->addWidget(toWorksTasks);


        horizontalLayout->addWidget(toWorksWidget);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        toDoneWidget = new QWidget(CRMWindowClass);
        toDoneWidget->setObjectName("toDoneWidget");
        sizePolicy.setHeightForWidth(toDoneWidget->sizePolicy().hasHeightForWidth());
        toDoneWidget->setSizePolicy(sizePolicy);
        toDoneWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255,253,253);\n"
"padding: 10px 10px;"));
        verticalLayout_3 = new QVBoxLayout(toDoneWidget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        toDoneTasksLbl = new QLabel(toDoneWidget);
        toDoneTasksLbl->setObjectName("toDoneTasksLbl");
        sizePolicy1.setHeightForWidth(toDoneTasksLbl->sizePolicy().hasHeightForWidth());
        toDoneTasksLbl->setSizePolicy(sizePolicy1);
        toDoneTasksLbl->setMinimumSize(QSize(150, 30));
        toDoneTasksLbl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_3->addWidget(toDoneTasksLbl);

        toDoneTasks = new QLabel(toDoneWidget);
        toDoneTasks->setObjectName("toDoneTasks");

        verticalLayout_3->addWidget(toDoneTasks);


        horizontalLayout->addWidget(toDoneWidget);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toCompleteWidget = new QWidget(CRMWindowClass);
        toCompleteWidget->setObjectName("toCompleteWidget");
        sizePolicy.setHeightForWidth(toCompleteWidget->sizePolicy().hasHeightForWidth());
        toCompleteWidget->setSizePolicy(sizePolicy);
        toCompleteWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255,253,253);\n"
"padding: 10px 10px;"));
        verticalLayout_5 = new QVBoxLayout(toCompleteWidget);
        verticalLayout_5->setObjectName("verticalLayout_5");
        toCompleteTasksLbl = new QLabel(toCompleteWidget);
        toCompleteTasksLbl->setObjectName("toCompleteTasksLbl");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toCompleteTasksLbl->sizePolicy().hasHeightForWidth());
        toCompleteTasksLbl->setSizePolicy(sizePolicy2);
        toCompleteTasksLbl->setMinimumSize(QSize(150, 30));
        toCompleteTasksLbl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_5->addWidget(toCompleteTasksLbl);

        toCompleteTasks = new QLabel(toCompleteWidget);
        toCompleteTasks->setObjectName("toCompleteTasks");

        verticalLayout_5->addWidget(toCompleteTasks);


        horizontalLayout->addWidget(toCompleteWidget);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout);

        toDoItem = new QWidget(CRMWindowClass);
        toDoItem->setObjectName("toDoItem");
        sizePolicy.setHeightForWidth(toDoItem->sizePolicy().hasHeightForWidth());
        toDoItem->setSizePolicy(sizePolicy);
        toDoItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255,253,253);\n"
"padding: 10px 10px;"));
        verticalLayout_6 = new QVBoxLayout(toDoItem);
        verticalLayout_6->setObjectName("verticalLayout_6");
        nameTasksLbl = new QLabel(toDoItem);
        nameTasksLbl->setObjectName("nameTasksLbl");
        sizePolicy1.setHeightForWidth(nameTasksLbl->sizePolicy().hasHeightForWidth());
        nameTasksLbl->setSizePolicy(sizePolicy1);
        nameTasksLbl->setMinimumSize(QSize(150, 30));
        nameTasksLbl->setStyleSheet(QString::fromUtf8(""));

        verticalLayout_6->addWidget(nameTasksLbl);

        projectName = new QLabel(toDoItem);
        projectName->setObjectName("projectName");
        projectName->setWordWrap(true);

        verticalLayout_6->addWidget(projectName);


        formLayout->setWidget(3, QFormLayout::FieldRole, toDoItem);


        retranslateUi(CRMWindowClass);

        QMetaObject::connectSlotsByName(CRMWindowClass);
    } // setupUi

    void retranslateUi(QWidget *CRMWindowClass)
    {
        CRMWindowClass->setWindowTitle(QCoreApplication::translate("CRMWindowClass", "Form", nullptr));
        dealsLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\241\320\264\320\265\320\273\320\272\320\270", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("CRMWindowClass", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("CRMWindowClass", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));

        pushButton->setText(QCoreApplication::translate("CRMWindowClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("CRMWindowClass", "\320\237\320\276 \321\201\321\202\320\260\321\202\321\203\321\201\321\203", nullptr));

        toDoTasksLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214", nullptr));
        toDoTasks->setText(QCoreApplication::translate("CRMWindowClass", "0 \320\227\320\260\320\264\320\260\321\207", nullptr));
        toWorksTasksLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\222 \321\200\320\260\320\261\320\276\321\202\320\265", nullptr));
        toWorksTasks->setText(QCoreApplication::translate("CRMWindowClass", "0 \320\227\320\260\320\264\320\260\321\207", nullptr));
        toDoneTasksLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\241\320\264\320\265\320\273\320\260\320\275\320\276", nullptr));
        toDoneTasks->setText(QCoreApplication::translate("CRMWindowClass", "0 \320\227\320\260\320\264\320\260\321\207", nullptr));
        toCompleteTasksLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\276", nullptr));
        toCompleteTasks->setText(QCoreApplication::translate("CRMWindowClass", "0 \320\227\320\260\320\264\320\260\321\207", nullptr));
        nameTasksLbl->setText(QCoreApplication::translate("CRMWindowClass", "\320\222\320\273\320\276\320\266\320\270\321\202\321\214 \320\270\320\275\321\201\321\202\321\200\321\203\320\272\321\206\320\270\320\270", nullptr));
        projectName->setText(QCoreApplication::translate("CRMWindowClass", " \320\237\321\200\320\276\320\265\320\272\321\202: \320\227\320\260\320\272\320\260\320\267 \320\275\320\260 \320\277\320\260\321\200\321\202\320\270\321\216 \320\270\320\263\321\200\321\203\321\210\320\265\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CRMWindowClass: public Ui_CRMWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRMWINDOW_H
