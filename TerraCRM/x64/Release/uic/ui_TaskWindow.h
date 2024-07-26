/********************************************************************************
** Form generated from reading UI file 'TaskWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKWINDOW_H
#define UI_TASKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskWindowClass
{
public:
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *nameLbl;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dateLbl;
    QPushButton *createEventBTn;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *createTaskBtn;
    QHBoxLayout *horizontalLayout;
    QWidget *doColumn;
    QVBoxLayout *verticalLayout;
    QLabel *doLbl;
    QLabel *countDoLbl;
    QWidget *workColumn;
    QVBoxLayout *verticalLayout_2;
    QLabel *workLbl;
    QLabel *countWorkLbl;
    QWidget *doneColumn;
    QVBoxLayout *verticalLayout_3;
    QLabel *doneLbl;
    QLabel *countDoneLbl;
    QWidget *completedColumn;
    QVBoxLayout *verticalLayout_4;
    QLabel *completeLbl;
    QLabel *countCompletedLbl;
    QGridLayout *tasksLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TaskWindowClass)
    {
        if (TaskWindowClass->objectName().isEmpty())
            TaskWindowClass->setObjectName("TaskWindowClass");
        TaskWindowClass->resize(890, 505);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TaskWindowClass->sizePolicy().hasHeightForWidth());
        TaskWindowClass->setSizePolicy(sizePolicy);
        TaskWindowClass->setStyleSheet(QString::fromUtf8("#centralwidget {\n"
"	background-color: rgb(63, 129, 158);\n"
"}\n"
".QPushButton, .QMenubar {\n"
"	background-color: rgb(255, 253, 253);\n"
"	border-radius: 5px;\n"
"	padding: 10px 10px;\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
".QPushButton:hover,  QMenubar:hover {\n"
"	color: rgb(45, 97, 100);\n"
"	border: 1px  solid rgb(55, 107, 113);\n"
"	cursor: pointer;\n"
"}\n"
".QLineEdit {\n"
"	padding: 5px;\n"
"	border-radius:5px;\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
".QWidget {\n"
"background-color: rgb(255,253,253);\n"
"padding: 10px 10px;\n"
"}"));
        verticalLayout_7 = new QVBoxLayout(TaskWindowClass);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(8, -1, -1, -1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        nameLbl = new QLabel(TaskWindowClass);
        nameLbl->setObjectName("nameLbl");

        horizontalLayout_4->addWidget(nameLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        dateLbl = new QLabel(TaskWindowClass);
        dateLbl->setObjectName("dateLbl");

        horizontalLayout_2->addWidget(dateLbl);

        createEventBTn = new QPushButton(TaskWindowClass);
        createEventBTn->setObjectName("createEventBTn");

        horizontalLayout_2->addWidget(createEventBTn);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        searchEdit = new QLineEdit(TaskWindowClass);
        searchEdit->setObjectName("searchEdit");

        horizontalLayout_3->addWidget(searchEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        createTaskBtn = new QPushButton(TaskWindowClass);
        createTaskBtn->setObjectName("createTaskBtn");

        horizontalLayout_3->addWidget(createTaskBtn);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        doColumn = new QWidget(TaskWindowClass);
        doColumn->setObjectName("doColumn");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doColumn->sizePolicy().hasHeightForWidth());
        doColumn->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(doColumn);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(9, -1, -1, -1);
        doLbl = new QLabel(doColumn);
        doLbl->setObjectName("doLbl");

        verticalLayout->addWidget(doLbl);

        countDoLbl = new QLabel(doColumn);
        countDoLbl->setObjectName("countDoLbl");

        verticalLayout->addWidget(countDoLbl);


        horizontalLayout->addWidget(doColumn);

        workColumn = new QWidget(TaskWindowClass);
        workColumn->setObjectName("workColumn");
        sizePolicy1.setHeightForWidth(workColumn->sizePolicy().hasHeightForWidth());
        workColumn->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(workColumn);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(9, -1, -1, -1);
        workLbl = new QLabel(workColumn);
        workLbl->setObjectName("workLbl");

        verticalLayout_2->addWidget(workLbl);

        countWorkLbl = new QLabel(workColumn);
        countWorkLbl->setObjectName("countWorkLbl");

        verticalLayout_2->addWidget(countWorkLbl);


        horizontalLayout->addWidget(workColumn);

        doneColumn = new QWidget(TaskWindowClass);
        doneColumn->setObjectName("doneColumn");
        sizePolicy1.setHeightForWidth(doneColumn->sizePolicy().hasHeightForWidth());
        doneColumn->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(doneColumn);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(9, -1, -1, -1);
        doneLbl = new QLabel(doneColumn);
        doneLbl->setObjectName("doneLbl");

        verticalLayout_3->addWidget(doneLbl);

        countDoneLbl = new QLabel(doneColumn);
        countDoneLbl->setObjectName("countDoneLbl");

        verticalLayout_3->addWidget(countDoneLbl);


        horizontalLayout->addWidget(doneColumn);

        completedColumn = new QWidget(TaskWindowClass);
        completedColumn->setObjectName("completedColumn");
        sizePolicy1.setHeightForWidth(completedColumn->sizePolicy().hasHeightForWidth());
        completedColumn->setSizePolicy(sizePolicy1);
        verticalLayout_4 = new QVBoxLayout(completedColumn);
        verticalLayout_4->setSpacing(10);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(9, -1, -1, -1);
        completeLbl = new QLabel(completedColumn);
        completeLbl->setObjectName("completeLbl");

        verticalLayout_4->addWidget(completeLbl);

        countCompletedLbl = new QLabel(completedColumn);
        countCompletedLbl->setObjectName("countCompletedLbl");

        verticalLayout_4->addWidget(countCompletedLbl);


        horizontalLayout->addWidget(completedColumn);


        verticalLayout_6->addLayout(horizontalLayout);


        verticalLayout_7->addLayout(verticalLayout_6);

        tasksLayout = new QGridLayout();
        tasksLayout->setSpacing(6);
        tasksLayout->setObjectName("tasksLayout");

        verticalLayout_7->addLayout(tasksLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);


        retranslateUi(TaskWindowClass);

        QMetaObject::connectSlotsByName(TaskWindowClass);
    } // setupUi

    void retranslateUi(QWidget *TaskWindowClass)
    {
        TaskWindowClass->setWindowTitle(QCoreApplication::translate("TaskWindowClass", "TaskWindow", nullptr));
        nameLbl->setText(QCoreApplication::translate("TaskWindowClass", "\320\227\320\260\320\264\320\260\321\207\320\270", nullptr));
        dateLbl->setText(QCoreApplication::translate("TaskWindowClass", "4 \320\262\321\202", nullptr));
        createEventBTn->setText(QCoreApplication::translate("TaskWindowClass", "\321\201\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\276\320\261\321\213\321\202\320\270\320\265", nullptr));
        searchEdit->setPlaceholderText(QCoreApplication::translate("TaskWindowClass", "\320\277\320\276\320\270\321\201\320\272", nullptr));
        createTaskBtn->setText(QCoreApplication::translate("TaskWindowClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 +", nullptr));
        doLbl->setText(QCoreApplication::translate("TaskWindowClass", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214", nullptr));
        countDoLbl->setText(QCoreApplication::translate("TaskWindowClass", "0", nullptr));
        workLbl->setText(QCoreApplication::translate("TaskWindowClass", "\320\222 \321\200\320\260\320\261\320\276\321\202\320\265", nullptr));
        countWorkLbl->setText(QCoreApplication::translate("TaskWindowClass", "0", nullptr));
        doneLbl->setText(QCoreApplication::translate("TaskWindowClass", "\320\241\320\264\320\265\320\273\320\260\320\275\320\276", nullptr));
        countDoneLbl->setText(QCoreApplication::translate("TaskWindowClass", "0", nullptr));
        completeLbl->setText(QCoreApplication::translate("TaskWindowClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\276", nullptr));
        countCompletedLbl->setText(QCoreApplication::translate("TaskWindowClass", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWindowClass: public Ui_TaskWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWINDOW_H
