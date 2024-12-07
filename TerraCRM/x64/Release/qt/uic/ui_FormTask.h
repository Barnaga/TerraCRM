/********************************************************************************
** Form generated from reading UI file 'FormTask.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTASK_H
#define UI_FORMTASK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FormTaskClass
{
public:
    QLineEdit *nameTaskEdit;
    QPushButton *saveBtn;
    QPushButton *cancelBtn;
    QLabel *warningLbl;
    QLabel *formLbl;
    QLabel *nameTask;
    QComboBox *priority;
    QLabel *priorityLbl;
    QPushButton *saveCreateBtn;
    QCalendarWidget *deadline;
    QLabel *deadlineLbl;
    QComboBox *projectBox;

    void setupUi(QDialog *FormTaskClass)
    {
        if (FormTaskClass->objectName().isEmpty())
            FormTaskClass->setObjectName("FormTaskClass");
        FormTaskClass->resize(838, 391);
        FormTaskClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
"QButton {\n"
" border: 1px solid rgb(55, 107, 113);\n"
"}"));
        nameTaskEdit = new QLineEdit(FormTaskClass);
        nameTaskEdit->setObjectName("nameTaskEdit");
        nameTaskEdit->setGeometry(QRect(30, 90, 411, 21));
        saveBtn = new QPushButton(FormTaskClass);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setGeometry(QRect(30, 330, 75, 24));
        cancelBtn = new QPushButton(FormTaskClass);
        cancelBtn->setObjectName("cancelBtn");
        cancelBtn->setGeometry(QRect(700, 330, 75, 24));
        warningLbl = new QLabel(FormTaskClass);
        warningLbl->setObjectName("warningLbl");
        warningLbl->setEnabled(true);
        warningLbl->setGeometry(QRect(180, 300, 231, 16));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(warningLbl->sizePolicy().hasHeightForWidth());
        warningLbl->setSizePolicy(sizePolicy);
        warningLbl->setTextFormat(Qt::TextFormat::AutoText);
        warningLbl->setAlignment(Qt::AlignmentFlag::AlignCenter);
        formLbl = new QLabel(FormTaskClass);
        formLbl->setObjectName("formLbl");
        formLbl->setGeometry(QRect(20, 20, 161, 31));
        QFont font;
        font.setPointSize(13);
        formLbl->setFont(font);
        nameTask = new QLabel(FormTaskClass);
        nameTask->setObjectName("nameTask");
        nameTask->setGeometry(QRect(30, 70, 71, 16));
        priority = new QComboBox(FormTaskClass);
        priority->addItem(QString());
        priority->addItem(QString());
        priority->addItem(QString());
        priority->setObjectName("priority");
        priority->setGeometry(QRect(450, 90, 68, 22));
        priorityLbl = new QLabel(FormTaskClass);
        priorityLbl->setObjectName("priorityLbl");
        priorityLbl->setGeometry(QRect(450, 70, 101, 16));
        saveCreateBtn = new QPushButton(FormTaskClass);
        saveCreateBtn->setObjectName("saveCreateBtn");
        saveCreateBtn->setGeometry(QRect(210, 330, 161, 24));
        deadline = new QCalendarWidget(FormTaskClass);
        deadline->setObjectName("deadline");
        deadline->setGeometry(QRect(540, 90, 256, 190));
        deadlineLbl = new QLabel(FormTaskClass);
        deadlineLbl->setObjectName("deadlineLbl");
        deadlineLbl->setGeometry(QRect(540, 70, 91, 16));
        projectBox = new QComboBox(FormTaskClass);
        projectBox->setObjectName("projectBox");
        projectBox->setGeometry(QRect(30, 130, 491, 22));

        retranslateUi(FormTaskClass);

        QMetaObject::connectSlotsByName(FormTaskClass);
    } // setupUi

    void retranslateUi(QDialog *FormTaskClass)
    {
        FormTaskClass->setWindowTitle(QCoreApplication::translate("FormTaskClass", "FormTask", nullptr));
        saveBtn->setText(QCoreApplication::translate("FormTaskClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        cancelBtn->setText(QCoreApplication::translate("FormTaskClass", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        warningLbl->setText(QCoreApplication::translate("FormTaskClass", "\320\222\321\213 \320\275\320\265 \320\262\320\262\320\265\320\273\320\270 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        formLbl->setText(QCoreApplication::translate("FormTaskClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\267\320\260\320\264\320\260\321\207\321\203", nullptr));
        nameTask->setText(QCoreApplication::translate("FormTaskClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        priority->setItemText(0, QCoreApplication::translate("FormTaskClass", "\320\235\320\270\320\267\320\272\320\270\320\271", nullptr));
        priority->setItemText(1, QCoreApplication::translate("FormTaskClass", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271", nullptr));
        priority->setItemText(2, QCoreApplication::translate("FormTaskClass", "\320\222\321\213\321\201\320\276\320\272\320\270\320\271", nullptr));

        priorityLbl->setText(QCoreApplication::translate("FormTaskClass", "\320\237\321\200\320\270\320\276\321\200\320\270\321\202\320\265\321\202", nullptr));
        saveCreateBtn->setText(QCoreApplication::translate("FormTaskClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270 \321\201\320\276\320\267\320\264\320\260\321\202\321\214 \320\265\321\211\320\265", nullptr));
        deadlineLbl->setText(QCoreApplication::translate("FormTaskClass", "\320\232\321\200\320\260\320\271\320\275\320\270\320\271 \321\201\321\200\320\276\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTaskClass: public Ui_FormTaskClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTASK_H
