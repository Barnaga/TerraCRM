/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *tasksAction;
    QAction *CRMAction;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *mainLbl;
    QSpacerItem *horizontalSpacer;
    QLabel *dateLbl;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName("MainWindowClass");
        MainWindowClass->resize(1920, 1080);
        MainWindowClass->setMaximumSize(QSize(1920, 1080));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tahoma")});
        font.setBold(false);
        font.setItalic(false);
        MainWindowClass->setFont(font);
        MainWindowClass->setAutoFillBackground(true);
        MainWindowClass->setStyleSheet(QString::fromUtf8("* {\n"
"	font: Tahoma;\n"
"	font-size: 12px;\n"
"}\n"
"#centralwidget {\n"
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
"	color: rgb(55, 107, 113);\n"
"}\n"
".QTableView QTableCornerButton::section {\n"
"	background-color: rgb(71,153,176);\n"
"}\n"
".QHeaderView::section {\n"
"    background-color: rgb(71,153,176);\n"
"    color: white;\n"
"    height: 35px;\n"
"    font: 14px;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: rgb(188, 224, 235);\n"
"}\n"
".QScrollBar::handle:vertical {\n"
"    background: rgb(71, 153, 176);\n"
" }\n"
".QScrollBar:horizontal {\n"
"    background: rgb(188, 224, 235);\n"
"}\n"
".QScrollBar::handle:horizontal {\n"
"    background: rgb(71, 15"
                        "3, 176);\n"
" }\n"
""));
        MainWindowClass->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonFollowStyle);
        MainWindowClass->setTabShape(QTabWidget::TabShape::Triangular);
        tasksAction = new QAction(MainWindowClass);
        tasksAction->setObjectName("tasksAction");
        tasksAction->setMenuRole(QAction::MenuRole::NoRole);
        CRMAction = new QAction(MainWindowClass);
        CRMAction->setObjectName("CRMAction");
        CRMAction->setMenuRole(QAction::MenuRole::NoRole);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMaximumSize(QSize(1820, 1080));
        centralWidget->setFont(font);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        mainLbl = new QLabel(centralWidget);
        mainLbl->setObjectName("mainLbl");

        horizontalLayout->addWidget(mainLbl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dateLbl = new QLabel(centralWidget);
        dateLbl->setObjectName("dateLbl");

        horizontalLayout->addWidget(dateLbl);

        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QCoreApplication::translate("MainWindowClass", "MainWindow", nullptr));
        tasksAction->setText(QCoreApplication::translate("MainWindowClass", "\320\227\320\260\320\264\320\260\321\207\320\270", nullptr));
        CRMAction->setText(QCoreApplication::translate("MainWindowClass", "CRM", nullptr));
        mainLbl->setText(QCoreApplication::translate("MainWindowClass", "\320\223\320\273\320\260\320\262\320\275\320\260\321\217", nullptr));
        dateLbl->setText(QCoreApplication::translate("MainWindowClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
