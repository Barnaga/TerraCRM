/********************************************************************************
** Form generated from reading UI file 'Task.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASK_H
#define UI_TASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TaskClass
{
public:
    QComboBox *statusBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *nameTaskLbl;
    QLabel *dealLbl;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_12;
    QLabel *comLbl;
    QLabel *com;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *dateLayout;
    QHBoxLayout *dateBeginLayout;
    QLabel *dateBeginLbl;
    QLabel *dateBegin;
    QHBoxLayout *dateEndLayout;
    QLabel *deadLineLbl;
    QLabel *deadLine;
    QHBoxLayout *horizontalLayout_17;
    QLabel *priorityLbl;
    QLabel *priority;
    QHBoxLayout *horizontalLayout_22;
    QLabel *createLbl;
    QLabel *create;
    QHBoxLayout *horizontalLayout_18;
    QLabel *creatorLbl;
    QLabel *creator;
    QHBoxLayout *horizontalLayout_21;
    QLabel *idLbl;
    QLabel *id;
    QHBoxLayout *horizontalLayout_20;
    QLabel *completedDateLbl;
    QLabel *completedDate;
    QHBoxLayout *horizontalLayout_19;
    QLabel *executorLbl;
    QLabel *executor;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *warningLayout;
    QLabel *warning;

    void setupUi(QDialog *TaskClass)
    {
        if (TaskClass->objectName().isEmpty())
            TaskClass->setObjectName("TaskClass");
        TaskClass->resize(615, 356);
        TaskClass->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	padding:3px;\n"
"}\n"
"TaskClass {\n"
"	background-color: rgb(240, 240, 240);\n"
"}\n"
"QWidget {\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
""));
        statusBox = new QComboBox(TaskClass);
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->addItem(QString());
        statusBox->setObjectName("statusBox");
        statusBox->setGeometry(QRect(20, 80, 91, 22));
        layoutWidget = new QWidget(TaskClass);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 10, 391, 60));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        nameTaskLbl = new QLabel(layoutWidget);
        nameTaskLbl->setObjectName("nameTaskLbl");
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameTaskLbl->sizePolicy().hasHeightForWidth());
        nameTaskLbl->setSizePolicy(sizePolicy);
        nameTaskLbl->setMinimumSize(QSize(100, 0));
        QFont font;
        nameTaskLbl->setFont(font);
        nameTaskLbl->setFrameShape(QFrame::Shape::NoFrame);
        nameTaskLbl->setTextFormat(Qt::TextFormat::PlainText);
        nameTaskLbl->setWordWrap(false);
        nameTaskLbl->setMargin(0);
        nameTaskLbl->setIndent(-1);

        verticalLayout->addWidget(nameTaskLbl);

        dealLbl = new QLabel(layoutWidget);
        dealLbl->setObjectName("dealLbl");
        dealLbl->setWordWrap(true);
        dealLbl->setMargin(0);

        verticalLayout->addWidget(dealLbl);

        layoutWidget1 = new QWidget(TaskClass);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(20, 120, 391, 101));
        verticalLayout_12 = new QVBoxLayout(layoutWidget1);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        comLbl = new QLabel(layoutWidget1);
        comLbl->setObjectName("comLbl");
        QFont font1;
        font1.setPointSize(10);
        comLbl->setFont(font1);

        verticalLayout_12->addWidget(comLbl);

        com = new QLabel(layoutWidget1);
        com->setObjectName("com");
        com->setWordWrap(true);

        verticalLayout_12->addWidget(com);

        layoutWidget2 = new QWidget(TaskClass);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(431, 12, 173, 331));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        dateLayout = new QVBoxLayout();
        dateLayout->setSpacing(6);
        dateLayout->setObjectName("dateLayout");
        dateBeginLayout = new QHBoxLayout();
        dateBeginLayout->setSpacing(6);
        dateBeginLayout->setObjectName("dateBeginLayout");
        dateBeginLbl = new QLabel(layoutWidget2);
        dateBeginLbl->setObjectName("dateBeginLbl");

        dateBeginLayout->addWidget(dateBeginLbl);

        dateBegin = new QLabel(layoutWidget2);
        dateBegin->setObjectName("dateBegin");

        dateBeginLayout->addWidget(dateBegin);


        dateLayout->addLayout(dateBeginLayout);

        dateEndLayout = new QHBoxLayout();
        dateEndLayout->setSpacing(6);
        dateEndLayout->setObjectName("dateEndLayout");
        deadLineLbl = new QLabel(layoutWidget2);
        deadLineLbl->setObjectName("deadLineLbl");

        dateEndLayout->addWidget(deadLineLbl);

        deadLine = new QLabel(layoutWidget2);
        deadLine->setObjectName("deadLine");

        dateEndLayout->addWidget(deadLine);


        dateLayout->addLayout(dateEndLayout);


        verticalLayout_3->addLayout(dateLayout);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        priorityLbl = new QLabel(layoutWidget2);
        priorityLbl->setObjectName("priorityLbl");

        horizontalLayout_17->addWidget(priorityLbl);

        priority = new QLabel(layoutWidget2);
        priority->setObjectName("priority");

        horizontalLayout_17->addWidget(priority);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        createLbl = new QLabel(layoutWidget2);
        createLbl->setObjectName("createLbl");

        horizontalLayout_22->addWidget(createLbl);

        create = new QLabel(layoutWidget2);
        create->setObjectName("create");

        horizontalLayout_22->addWidget(create);


        verticalLayout_3->addLayout(horizontalLayout_22);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        creatorLbl = new QLabel(layoutWidget2);
        creatorLbl->setObjectName("creatorLbl");

        horizontalLayout_18->addWidget(creatorLbl);

        creator = new QLabel(layoutWidget2);
        creator->setObjectName("creator");

        horizontalLayout_18->addWidget(creator);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        idLbl = new QLabel(layoutWidget2);
        idLbl->setObjectName("idLbl");

        horizontalLayout_21->addWidget(idLbl);

        id = new QLabel(layoutWidget2);
        id->setObjectName("id");

        horizontalLayout_21->addWidget(id);


        verticalLayout_3->addLayout(horizontalLayout_21);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        completedDateLbl = new QLabel(layoutWidget2);
        completedDateLbl->setObjectName("completedDateLbl");

        horizontalLayout_20->addWidget(completedDateLbl);

        completedDate = new QLabel(layoutWidget2);
        completedDate->setObjectName("completedDate");

        horizontalLayout_20->addWidget(completedDate);


        verticalLayout_3->addLayout(horizontalLayout_20);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        executorLbl = new QLabel(layoutWidget2);
        executorLbl->setObjectName("executorLbl");

        horizontalLayout_19->addWidget(executorLbl);

        executor = new QLabel(layoutWidget2);
        executor->setObjectName("executor");

        horizontalLayout_19->addWidget(executor);


        verticalLayout_3->addLayout(horizontalLayout_19);

        verticalLayoutWidget = new QWidget(TaskClass);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 240, 391, 80));
        warningLayout = new QVBoxLayout(verticalLayoutWidget);
        warningLayout->setSpacing(6);
        warningLayout->setContentsMargins(11, 11, 11, 11);
        warningLayout->setObjectName("warningLayout");
        warningLayout->setContentsMargins(0, 0, 0, 0);
        warning = new QLabel(verticalLayoutWidget);
        warning->setObjectName("warning");

        warningLayout->addWidget(warning);


        retranslateUi(TaskClass);

        QMetaObject::connectSlotsByName(TaskClass);
    } // setupUi

    void retranslateUi(QDialog *TaskClass)
    {
        TaskClass->setWindowTitle(QCoreApplication::translate("TaskClass", "Task", nullptr));
        statusBox->setItemText(0, QCoreApplication::translate("TaskClass", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214", nullptr));
        statusBox->setItemText(1, QCoreApplication::translate("TaskClass", "\320\222 \321\200\320\260\320\261\320\276\321\202\320\265", nullptr));
        statusBox->setItemText(2, QCoreApplication::translate("TaskClass", "\320\241\320\264\320\265\320\273\320\260\320\275\320\276", nullptr));
        statusBox->setItemText(3, QCoreApplication::translate("TaskClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\276", nullptr));

        nameTaskLbl->setText(QString());
        dealLbl->setText(QString());
        comLbl->setText(QCoreApplication::translate("TaskClass", "\320\241\320\262\321\217\320\267\320\270", nullptr));
        com->setText(QString());
        dateBeginLbl->setText(QCoreApplication::translate("TaskClass", "\320\224\320\260\321\202\320\260 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
        dateBegin->setText(QCoreApplication::translate("TaskClass", "TextLabel", nullptr));
        deadLineLbl->setText(QCoreApplication::translate("TaskClass", "\320\232\321\200\320\260\320\271\320\275\320\270\320\271 \321\201\321\200\320\276\320\272", nullptr));
        deadLine->setText(QCoreApplication::translate("TaskClass", "TextLabel", nullptr));
        priorityLbl->setText(QCoreApplication::translate("TaskClass", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202", nullptr));
        priority->setText(QCoreApplication::translate("TaskClass", "TextLabel", nullptr));
        createLbl->setText(QCoreApplication::translate("TaskClass", "\320\241\320\276\320\267\320\264\320\260\320\275\320\276", nullptr));
        create->setText(QCoreApplication::translate("TaskClass", "TextLabel", nullptr));
        creatorLbl->setText(QCoreApplication::translate("TaskClass", "\320\237\320\276\321\201\321\202\320\260\320\275\320\276\320\262\321\211\320\270\320\272", nullptr));
        creator->setText(QCoreApplication::translate("TaskClass", "TextLabel", nullptr));
        idLbl->setText(QCoreApplication::translate("TaskClass", "ID \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        id->setText(QString());
        completedDateLbl->setText(QCoreApplication::translate("TaskClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\276", nullptr));
        completedDate->setText(QString());
        executorLbl->setText(QCoreApplication::translate("TaskClass", "\320\236\321\202\320\262\320\265\321\202\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271", nullptr));
        executor->setText(QCoreApplication::translate("TaskClass", "TextLabel", nullptr));
        warning->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TaskClass: public Ui_TaskClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASK_H
