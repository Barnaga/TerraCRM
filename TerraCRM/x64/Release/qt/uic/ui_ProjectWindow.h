/********************************************************************************
** Form generated from reading UI file 'ProjectWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTWINDOW_H
#define UI_PROJECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectWindowClass
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *listProjectsLbl;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *dateLbl;
    QPushButton *createBtn;
    QVBoxLayout *projectsLayout;

    void setupUi(QWidget *ProjectWindowClass)
    {
        if (ProjectWindowClass->objectName().isEmpty())
            ProjectWindowClass->setObjectName("ProjectWindowClass");
        ProjectWindowClass->resize(959, 567);
        ProjectWindowClass->setStyleSheet(QString::fromUtf8("QWidget {\n"
"color: rgb(55, 107, 113);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(ProjectWindowClass);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        listProjectsLbl = new QLabel(ProjectWindowClass);
        listProjectsLbl->setObjectName("listProjectsLbl");

        horizontalLayout->addWidget(listProjectsLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName("verticalLayout");
        dateLbl = new QLabel(ProjectWindowClass);
        dateLbl->setObjectName("dateLbl");

        verticalLayout->addWidget(dateLbl);

        createBtn = new QPushButton(ProjectWindowClass);
        createBtn->setObjectName("createBtn");

        verticalLayout->addWidget(createBtn);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        projectsLayout = new QVBoxLayout();
        projectsLayout->setSpacing(6);
        projectsLayout->setObjectName("projectsLayout");

        verticalLayout_2->addLayout(projectsLayout);


        retranslateUi(ProjectWindowClass);

        QMetaObject::connectSlotsByName(ProjectWindowClass);
    } // setupUi

    void retranslateUi(QWidget *ProjectWindowClass)
    {
        ProjectWindowClass->setWindowTitle(QCoreApplication::translate("ProjectWindowClass", "ProjectWindow", nullptr));
        listProjectsLbl->setText(QCoreApplication::translate("ProjectWindowClass", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\277\321\200\320\276\320\265\320\272\321\202\320\276\320\262", nullptr));
        dateLbl->setText(QCoreApplication::translate("ProjectWindowClass", "TextLabel", nullptr));
        createBtn->setText(QCoreApplication::translate("ProjectWindowClass", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectWindowClass: public Ui_ProjectWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTWINDOW_H
