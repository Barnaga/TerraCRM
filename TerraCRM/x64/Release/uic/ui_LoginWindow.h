/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindowClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *nameCompany;
    QSpacerItem *verticalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_3;
    QLineEdit *loginEdit;
    QLineEdit *passwordEdit;
    QLabel *errorLbl;
    QPushButton *loginBtn;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLineEdit *loginEdit_2;
    QLineEdit *passwordEdit_2;
    QComboBox *comboBox;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *LoginWindowClass)
    {
        if (LoginWindowClass->objectName().isEmpty())
            LoginWindowClass->setObjectName("LoginWindowClass");
        LoginWindowClass->resize(962, 618);
        LoginWindowClass->setStyleSheet(QString::fromUtf8(".QWidget, .QTabWidget {\n"
"	background-color: rgb(63, 129, 158);\n"
"}\n"
".QTabWidget {\n"
"    color: rgb(255, 253, 253);\n"
"}\n"
" .QLabel {\n"
"	font-size: 25px;\n"
"    color: rgb(255, 253, 253);\n"
"}\n"
" .QLabel  #errorLlb{\n"
"	font-size: 12px;\n"
"\n"
"}\n"
"QCheckBox {\n"
" color: rgb(255, 253, 253);\n"
"}\n"
".QPushButton {\n"
"	color: rgb(55, 107, 113);\n"
"	background-color: rgb(255, 253, 253);\n"
"	border-radius: 5px;\n"
"	padding: 10px 10px;\n"
"\n"
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
"}"));
        centralWidget = new QWidget(LoginWindowClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(1920, 1080));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setSizeConstraint(QLayout::SizeConstraint::SetFixedSize);
        verticalSpacer = new QSpacerItem(20, 240, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer);

        nameCompany = new QLabel(centralWidget);
        nameCompany->setObjectName("nameCompany");
        sizePolicy.setHeightForWidth(nameCompany->sizePolicy().hasHeightForWidth());
        nameCompany->setSizePolicy(sizePolicy);
        nameCompany->setMinimumSize(QSize(0, 30));
        nameCompany->setMaximumSize(QSize(300, 30));
        nameCompany->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(nameCompany);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

        verticalLayout_4->addItem(verticalSpacer_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMinimumSize(QSize(300, 300));
        tabWidget->setMaximumSize(QSize(300, 300));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName("tab");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy2);
        tab->setMaximumSize(QSize(300, 300));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(20, 0, 252, 198));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(12);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        loginEdit = new QLineEdit(layoutWidget);
        loginEdit->setObjectName("loginEdit");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(loginEdit->sizePolicy().hasHeightForWidth());
        loginEdit->setSizePolicy(sizePolicy3);
        loginEdit->setMinimumSize(QSize(220, 0));

        verticalLayout->addWidget(loginEdit, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        passwordEdit = new QLineEdit(layoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(passwordEdit->sizePolicy().hasHeightForWidth());
        passwordEdit->setSizePolicy(sizePolicy4);
        passwordEdit->setMinimumSize(QSize(220, 0));

        verticalLayout->addWidget(passwordEdit, 0, Qt::AlignmentFlag::AlignHCenter);

        errorLbl = new QLabel(layoutWidget);
        errorLbl->setObjectName("errorLbl");
        errorLbl->setStyleSheet(QString::fromUtf8("font-size:12px"));

        verticalLayout->addWidget(errorLbl, 0, Qt::AlignmentFlag::AlignHCenter);

        loginBtn = new QPushButton(layoutWidget);
        loginBtn->setObjectName("loginBtn");
        sizePolicy.setHeightForWidth(loginBtn->sizePolicy().hasHeightForWidth());
        loginBtn->setSizePolicy(sizePolicy);
        loginBtn->setMinimumSize(QSize(220, 0));

        verticalLayout->addWidget(loginBtn, 0, Qt::AlignmentFlag::AlignHCenter);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        sizePolicy2.setHeightForWidth(tab_2->sizePolicy().hasHeightForWidth());
        tab_2->setSizePolicy(sizePolicy2);
        tab_2->setMaximumSize(QSize(300, 300));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 10, 271, 203));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(12);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        loginEdit_2 = new QLineEdit(layoutWidget1);
        loginEdit_2->setObjectName("loginEdit_2");
        sizePolicy3.setHeightForWidth(loginEdit_2->sizePolicy().hasHeightForWidth());
        loginEdit_2->setSizePolicy(sizePolicy3);
        loginEdit_2->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(loginEdit_2, 0, Qt::AlignmentFlag::AlignHCenter);

        passwordEdit_2 = new QLineEdit(layoutWidget1);
        passwordEdit_2->setObjectName("passwordEdit_2");
        sizePolicy4.setHeightForWidth(passwordEdit_2->sizePolicy().hasHeightForWidth());
        passwordEdit_2->setSizePolicy(sizePolicy4);
        passwordEdit_2->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(passwordEdit_2, 0, Qt::AlignmentFlag::AlignHCenter);

        comboBox = new QComboBox(layoutWidget1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        sizePolicy3.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy3);
        comboBox->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(comboBox, 0, Qt::AlignmentFlag::AlignHCenter);

        registerBtn = new QPushButton(layoutWidget1);
        registerBtn->setObjectName("registerBtn");
        sizePolicy.setHeightForWidth(registerBtn->sizePolicy().hasHeightForWidth());
        registerBtn->setSizePolicy(sizePolicy);
        registerBtn->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(registerBtn, 0, Qt::AlignmentFlag::AlignHCenter);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_4->addWidget(tabWidget, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LoginWindowClass->setCentralWidget(centralWidget);

        retranslateUi(LoginWindowClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindowClass)
    {
        LoginWindowClass->setWindowTitle(QCoreApplication::translate("LoginWindowClass", "LoginWindow", nullptr));
        nameCompany->setText(QCoreApplication::translate("LoginWindowClass", "TerraCRM", nullptr));
        loginEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "login", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "password", nullptr));
        errorLbl->setText(QString());
        loginBtn->setText(QCoreApplication::translate("LoginWindowClass", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginWindowClass", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        loginEdit_2->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "login", nullptr));
        passwordEdit_2->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "password", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("LoginWindowClass", "Leader", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("LoginWindowClass", "Administrator", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("LoginWindowClass", "Seller", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("LoginWindowClass", "Marketer", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("LoginWindowClass", "Unknown", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("LoginWindowClass", "Manager", nullptr));

        registerBtn->setText(QCoreApplication::translate("LoginWindowClass", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("LoginWindowClass", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindowClass: public Ui_LoginWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
