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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *dateLbl;
    QHBoxLayout *horizontalLayout_3;
    QLabel *nameLbl;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *createTaskBtn;
    QVBoxLayout *tasksLayout;
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
".QPushButton {\n"
"	background-color: rgb(255, 253, 253);\n"
"	border-radius: 5px;\n"
"	padding: 10px 10px;\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
".QPushButton:hover {\n"
"	color: rgb(45, 97, 100);\n"
"	border: 1px  solid rgb(55, 107, 113);\n"
"	cursor: pointer;\n"
"}\n"
".QLineEdit {\n"
"	padding: 5px;\n"
"	border-radius:5px;\n"
"\n"
"}\n"
".QWidget {\n"
"	background-color: rgb(255,253,253);\n"
"	padding: 10px 10px;\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
".QTableView {\n"
"    color: rgb(55, 107, 113);\n"
"    gridline-color: rgb(55, 107, 113);\n"
"    border-color: rgb(55, 107, 113);\n"
"    font: 10px;\n"
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
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        dateLbl = new QLabel(TaskWindowClass);
        dateLbl->setObjectName("dateLbl");
        dateLbl->setStyleSheet(QString::fromUtf8("	color: rgb(55, 107, 113);"));

        horizontalLayout_2->addWidget(dateLbl);


        horizontalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        nameLbl = new QLabel(TaskWindowClass);
        nameLbl->setObjectName("nameLbl");
        nameLbl->setStyleSheet(QString::fromUtf8("	color: rgb(55, 107, 113);"));

        horizontalLayout_3->addWidget(nameLbl);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        createTaskBtn = new QPushButton(TaskWindowClass);
        createTaskBtn->setObjectName("createTaskBtn");

        horizontalLayout_3->addWidget(createTaskBtn);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);


        verticalLayout_7->addLayout(verticalLayout_6);

        tasksLayout = new QVBoxLayout();
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
        dateLbl->setText(QCoreApplication::translate("TaskWindowClass", "4 \320\262\321\202", nullptr));
        nameLbl->setText(QCoreApplication::translate("TaskWindowClass", "\320\227\320\260\320\264\320\260\321\207\320\270", nullptr));
        createTaskBtn->setText(QCoreApplication::translate("TaskWindowClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 +", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TaskWindowClass: public Ui_TaskWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKWINDOW_H
