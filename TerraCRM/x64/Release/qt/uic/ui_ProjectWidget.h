/********************************************************************************
** Form generated from reading UI file 'ProjectWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTWIDGET_H
#define UI_PROJECTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ProjectWidgetClass
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *header;
    QPushButton *doneBtn;
    QSpacerItem *horizontalSpacer;
    QLabel *dealLbl;
    QHBoxLayout *common;
    QVBoxLayout *plannedAdmissionLayout;
    QLabel *admissionLbl;
    QLabel *costLbl;
    QVBoxLayout *expenseLayout;
    QLabel *expenseLbl;
    QLabel *expense;
    QVBoxLayout *doneTaskLayout;
    QLabel *doneTaskLbl;
    QLabel *count;
    QVBoxLayout *dateProjectLayout;
    QLabel *dateProjectLbl;
    QLabel *date;
    QVBoxLayout *managerLayout;
    QLabel *MamagerProjectLbl;
    QLabel *manager;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *stageBox;
    QVBoxLayout *clientLayout;
    QLabel *clientLbl;
    QFormLayout *formLayout;
    QVBoxLayout *infoClient;
    QLabel *nameCompanyLbl;
    QLabel *numberLbl;
    QLabel *emailLbl;
    QHBoxLayout *btnLayout;
    QPushButton *phoneCallBtn;
    QPushButton *smsBtn;
    QTextEdit *descEdit;
    QPushButton *saveBtn;

    void setupUi(QDialog *ProjectWidgetClass)
    {
        if (ProjectWidgetClass->objectName().isEmpty())
            ProjectWidgetClass->setObjectName("ProjectWidgetClass");
        ProjectWidgetClass->resize(717, 553);
        ProjectWidgetClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"color:rgb(55, 107, 113);\n"
"}"));
        verticalLayout = new QVBoxLayout(ProjectWidgetClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        header = new QGridLayout();
        header->setSpacing(6);
        header->setObjectName("header");
        doneBtn = new QPushButton(ProjectWidgetClass);
        doneBtn->setObjectName("doneBtn");

        header->addWidget(doneBtn, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        header->addItem(horizontalSpacer, 0, 1, 1, 1);

        dealLbl = new QLabel(ProjectWidgetClass);
        dealLbl->setObjectName("dealLbl");

        header->addWidget(dealLbl, 0, 0, 1, 1);


        verticalLayout->addLayout(header);

        common = new QHBoxLayout();
        common->setSpacing(6);
        common->setObjectName("common");
        plannedAdmissionLayout = new QVBoxLayout();
        plannedAdmissionLayout->setSpacing(6);
        plannedAdmissionLayout->setObjectName("plannedAdmissionLayout");
        admissionLbl = new QLabel(ProjectWidgetClass);
        admissionLbl->setObjectName("admissionLbl");

        plannedAdmissionLayout->addWidget(admissionLbl);

        costLbl = new QLabel(ProjectWidgetClass);
        costLbl->setObjectName("costLbl");

        plannedAdmissionLayout->addWidget(costLbl);


        common->addLayout(plannedAdmissionLayout);

        expenseLayout = new QVBoxLayout();
        expenseLayout->setSpacing(6);
        expenseLayout->setObjectName("expenseLayout");
        expenseLbl = new QLabel(ProjectWidgetClass);
        expenseLbl->setObjectName("expenseLbl");

        expenseLayout->addWidget(expenseLbl);

        expense = new QLabel(ProjectWidgetClass);
        expense->setObjectName("expense");

        expenseLayout->addWidget(expense);


        common->addLayout(expenseLayout);

        doneTaskLayout = new QVBoxLayout();
        doneTaskLayout->setSpacing(6);
        doneTaskLayout->setObjectName("doneTaskLayout");
        doneTaskLbl = new QLabel(ProjectWidgetClass);
        doneTaskLbl->setObjectName("doneTaskLbl");

        doneTaskLayout->addWidget(doneTaskLbl);

        count = new QLabel(ProjectWidgetClass);
        count->setObjectName("count");

        doneTaskLayout->addWidget(count);


        common->addLayout(doneTaskLayout);

        dateProjectLayout = new QVBoxLayout();
        dateProjectLayout->setSpacing(6);
        dateProjectLayout->setObjectName("dateProjectLayout");
        dateProjectLbl = new QLabel(ProjectWidgetClass);
        dateProjectLbl->setObjectName("dateProjectLbl");

        dateProjectLayout->addWidget(dateProjectLbl);

        date = new QLabel(ProjectWidgetClass);
        date->setObjectName("date");

        dateProjectLayout->addWidget(date);


        common->addLayout(dateProjectLayout);

        managerLayout = new QVBoxLayout();
        managerLayout->setSpacing(6);
        managerLayout->setObjectName("managerLayout");
        MamagerProjectLbl = new QLabel(ProjectWidgetClass);
        MamagerProjectLbl->setObjectName("MamagerProjectLbl");

        managerLayout->addWidget(MamagerProjectLbl);

        manager = new QLabel(ProjectWidgetClass);
        manager->setObjectName("manager");

        managerLayout->addWidget(manager);


        common->addLayout(managerLayout);


        verticalLayout->addLayout(common);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(ProjectWidgetClass);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        stageBox = new QComboBox(ProjectWidgetClass);
        stageBox->addItem(QString());
        stageBox->addItem(QString());
        stageBox->addItem(QString());
        stageBox->addItem(QString());
        stageBox->addItem(QString());
        stageBox->setObjectName("stageBox");

        horizontalLayout->addWidget(stageBox);


        verticalLayout->addLayout(horizontalLayout);

        clientLayout = new QVBoxLayout();
        clientLayout->setSpacing(6);
        clientLayout->setObjectName("clientLayout");
        clientLbl = new QLabel(ProjectWidgetClass);
        clientLbl->setObjectName("clientLbl");

        clientLayout->addWidget(clientLbl);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName("formLayout");
        infoClient = new QVBoxLayout();
        infoClient->setSpacing(6);
        infoClient->setObjectName("infoClient");
        nameCompanyLbl = new QLabel(ProjectWidgetClass);
        nameCompanyLbl->setObjectName("nameCompanyLbl");

        infoClient->addWidget(nameCompanyLbl);

        numberLbl = new QLabel(ProjectWidgetClass);
        numberLbl->setObjectName("numberLbl");

        infoClient->addWidget(numberLbl);

        emailLbl = new QLabel(ProjectWidgetClass);
        emailLbl->setObjectName("emailLbl");

        infoClient->addWidget(emailLbl);


        formLayout->setLayout(0, QFormLayout::LabelRole, infoClient);

        btnLayout = new QHBoxLayout();
        btnLayout->setSpacing(6);
        btnLayout->setObjectName("btnLayout");
        phoneCallBtn = new QPushButton(ProjectWidgetClass);
        phoneCallBtn->setObjectName("phoneCallBtn");

        btnLayout->addWidget(phoneCallBtn);

        smsBtn = new QPushButton(ProjectWidgetClass);
        smsBtn->setObjectName("smsBtn");

        btnLayout->addWidget(smsBtn);


        formLayout->setLayout(0, QFormLayout::FieldRole, btnLayout);


        clientLayout->addLayout(formLayout);


        verticalLayout->addLayout(clientLayout);

        descEdit = new QTextEdit(ProjectWidgetClass);
        descEdit->setObjectName("descEdit");

        verticalLayout->addWidget(descEdit);

        saveBtn = new QPushButton(ProjectWidgetClass);
        saveBtn->setObjectName("saveBtn");

        verticalLayout->addWidget(saveBtn);


        retranslateUi(ProjectWidgetClass);

        QMetaObject::connectSlotsByName(ProjectWidgetClass);
    } // setupUi

    void retranslateUi(QDialog *ProjectWidgetClass)
    {
        ProjectWidgetClass->setWindowTitle(QCoreApplication::translate("ProjectWidgetClass", "ProjectWidget", nullptr));
        doneBtn->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        dealLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        admissionLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\237\320\273\320\260\320\275\320\276\320\262\321\213\320\265 \320\277\320\276\321\201\321\202\321\203\320\277\320\273\320\265\320\275\320\270\320\265", nullptr));
        costLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "TextLabel", nullptr));
        expenseLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\240\320\260\321\201\321\205\320\276\320\264\321\213", nullptr));
        expense->setText(QCoreApplication::translate("ProjectWidgetClass", "TextLabel", nullptr));
        doneTaskLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\227\320\260\320\264\320\260\321\207 \320\262\321\213\320\277\320\276\320\273\320\275\320\265\320\275\320\276", nullptr));
        count->setText(QCoreApplication::translate("ProjectWidgetClass", "TextLabel", nullptr));
        dateProjectLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\241\321\200\320\276\320\272\320\270 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        date->setText(QCoreApplication::translate("ProjectWidgetClass", "TextLabel", nullptr));
        MamagerProjectLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        manager->setText(QCoreApplication::translate("ProjectWidgetClass", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\242\320\265\320\272\321\203\321\211\320\270\320\271 \321\215\321\202\320\260\320\277 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", nullptr));
        stageBox->setItemText(0, QCoreApplication::translate("ProjectWidgetClass", "\320\237\320\276\320\264\320\263\320\276\321\202\320\276\320\262\320\272\320\260", nullptr));
        stageBox->setItemText(1, QCoreApplication::translate("ProjectWidgetClass", "\320\237\321\200\320\276\320\265\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        stageBox->setItemText(2, QCoreApplication::translate("ProjectWidgetClass", "\320\240\320\260\320\267\321\200\320\260\320\261\320\276\321\202\320\272\320\260", nullptr));
        stageBox->setItemText(3, QCoreApplication::translate("ProjectWidgetClass", "\320\232\320\276\321\200\321\200\320\265\320\272\321\206\320\270\321\217", nullptr));
        stageBox->setItemText(4, QCoreApplication::translate("ProjectWidgetClass", "\320\227\320\260\320\262\320\265\321\200\321\210\320\265\320\275\320\270\320\265", nullptr));

        clientLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        nameCompanyLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\272\320\276\320\274\320\277\320\260\320\275\320\270\320\270", nullptr));
        numberLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\235\320\276\320\274\320\265\321\200", nullptr));
        emailLbl->setText(QCoreApplication::translate("ProjectWidgetClass", "email", nullptr));
        phoneCallBtn->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\227\320\262\320\276\320\275\320\276\320\272", nullptr));
        smsBtn->setText(QCoreApplication::translate("ProjectWidgetClass", "\321\201\320\274\321\201", nullptr));
        saveBtn->setText(QCoreApplication::translate("ProjectWidgetClass", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectWidgetClass: public Ui_ProjectWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTWIDGET_H
