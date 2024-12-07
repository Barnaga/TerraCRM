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
#include <QtWidgets/QGridLayout>
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
    QGridLayout *gridLayout;
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
    QWidget *reg;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *regSurnameEdit;
    QLineEdit *regNameEdit;
    QLineEdit *regLoginEdit;
    QLineEdit *regPasswordEdit;
    QLineEdit *companyEdit;
    QComboBox *roleBox;
    QSpacerItem *verticalSpacer_4;
    QPushButton *registerBtn;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *LoginWindowClass)
    {
        if (LoginWindowClass->objectName().isEmpty())
            LoginWindowClass->setObjectName("LoginWindowClass");
        LoginWindowClass->resize(962, 618);
        LoginWindowClass->setStyleSheet(QString::fromUtf8(".QWidget {\n"
"		background-color: rgb(63, 129, 158);\n"
"}\n"
".QTabWidget::pane {\n"
"	color: rgb(255, 255, 253);\n"
"}\n"
"QTabBar::tab {\n"
"			color: rgb(55, 107, 113);\n"
"}\n"
".QTabWidget::tab-bar {\n"
"        left: 5px;\n"
"\n"
"}\n"
" .QLabel {\n"
"	font-size: 25px;\n"
"    color: rgb(255, 253, 253);\n"
"}\n"
" .QLabel#errorLlb{\n"
"	font-size: 20px;\n"
"}\n"
"\n"
".QPushButton {\n"
"	color: rgb(55, 107, 113);\n"
"	background-color: rgb(255, 253, 253);\n"
"	border-radius: 5px;\n"
"	padding: 10px 10px;\n"
"}\n"
"QComboBox {\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
".QLineEdit {\n"
"	padding: 5px;\n"
"	border-radius:5px;\n"
"	color: rgb(55, 107, 113);\n"
"}\n"
""));
        centralWidget = new QWidget(LoginWindowClass);
        centralWidget->setObjectName("centralWidget");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(0, 0));
        centralWidget->setMaximumSize(QSize(1920, 1080));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

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
        reg = new QWidget();
        reg->setObjectName("reg");
        sizePolicy2.setHeightForWidth(reg->sizePolicy().hasHeightForWidth());
        reg->setSizePolicy(sizePolicy2);
        reg->setMaximumSize(QSize(300, 300));
        layoutWidget1 = new QWidget(reg);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(35, 30, 222, 241));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        regSurnameEdit = new QLineEdit(layoutWidget1);
        regSurnameEdit->setObjectName("regSurnameEdit");
        sizePolicy4.setHeightForWidth(regSurnameEdit->sizePolicy().hasHeightForWidth());
        regSurnameEdit->setSizePolicy(sizePolicy4);
        regSurnameEdit->setMinimumSize(QSize(220, 0));
        regSurnameEdit->setMaximumSize(QSize(220, 16777215));

        verticalLayout_2->addWidget(regSurnameEdit);

        regNameEdit = new QLineEdit(layoutWidget1);
        regNameEdit->setObjectName("regNameEdit");
        sizePolicy4.setHeightForWidth(regNameEdit->sizePolicy().hasHeightForWidth());
        regNameEdit->setSizePolicy(sizePolicy4);
        regNameEdit->setMinimumSize(QSize(220, 0));
        regNameEdit->setMaximumSize(QSize(220, 16777215));

        verticalLayout_2->addWidget(regNameEdit);

        regLoginEdit = new QLineEdit(layoutWidget1);
        regLoginEdit->setObjectName("regLoginEdit");
        sizePolicy4.setHeightForWidth(regLoginEdit->sizePolicy().hasHeightForWidth());
        regLoginEdit->setSizePolicy(sizePolicy4);
        regLoginEdit->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(regLoginEdit);

        regPasswordEdit = new QLineEdit(layoutWidget1);
        regPasswordEdit->setObjectName("regPasswordEdit");
        sizePolicy4.setHeightForWidth(regPasswordEdit->sizePolicy().hasHeightForWidth());
        regPasswordEdit->setSizePolicy(sizePolicy4);
        regPasswordEdit->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(regPasswordEdit);

        companyEdit = new QLineEdit(layoutWidget1);
        companyEdit->setObjectName("companyEdit");

        verticalLayout_2->addWidget(companyEdit);

        roleBox = new QComboBox(layoutWidget1);
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->addItem(QString());
        roleBox->setObjectName("roleBox");
        sizePolicy3.setHeightForWidth(roleBox->sizePolicy().hasHeightForWidth());
        roleBox->setSizePolicy(sizePolicy3);
        roleBox->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(roleBox);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        registerBtn = new QPushButton(layoutWidget1);
        registerBtn->setObjectName("registerBtn");
        sizePolicy.setHeightForWidth(registerBtn->sizePolicy().hasHeightForWidth());
        registerBtn->setSizePolicy(sizePolicy);
        registerBtn->setMinimumSize(QSize(220, 0));

        verticalLayout_2->addWidget(registerBtn);

        tabWidget->addTab(reg, QString());

        verticalLayout_4->addWidget(tabWidget);


        gridLayout->addLayout(verticalLayout_4, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        LoginWindowClass->setCentralWidget(centralWidget);

        retranslateUi(LoginWindowClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(LoginWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindowClass)
    {
        LoginWindowClass->setWindowTitle(QCoreApplication::translate("LoginWindowClass", "LoginWindow", nullptr));
        nameCompany->setText(QCoreApplication::translate("LoginWindowClass", "TerraCRM", nullptr));
        loginEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\273\320\276\320\263\320\270\320\275", nullptr));
        passwordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        errorLbl->setText(QString());
        loginBtn->setText(QCoreApplication::translate("LoginWindowClass", "\320\222\320\276\320\271\321\202\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("LoginWindowClass", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        regSurnameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        regNameEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\230\320\274\321\217", nullptr));
        regLoginEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\273\320\276\320\263\320\270\320\275", nullptr));
        regPasswordEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        companyEdit->setPlaceholderText(QCoreApplication::translate("LoginWindowClass", "\320\272\320\276\320\274\320\277\320\260\320\275\320\270\321\217", nullptr));
        roleBox->setItemText(0, QCoreApplication::translate("LoginWindowClass", "\320\224\320\270\321\200\320\265\320\272\321\202\320\276\321\200", nullptr));
        roleBox->setItemText(1, QCoreApplication::translate("LoginWindowClass", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        roleBox->setItemText(2, QCoreApplication::translate("LoginWindowClass", "\320\237\321\200\320\276\320\264\320\260\320\262\320\265\321\206", nullptr));
        roleBox->setItemText(3, QCoreApplication::translate("LoginWindowClass", "\320\234\320\260\321\200\320\272\320\265\321\202\320\276\320\273\320\276\320\263", nullptr));
        roleBox->setItemText(4, QCoreApplication::translate("LoginWindowClass", "\320\235\320\265 \320\276\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275", nullptr));
        roleBox->setItemText(5, QCoreApplication::translate("LoginWindowClass", "\320\234\320\265\320\275\320\265\320\264\320\266\320\265\321\200", nullptr));

        registerBtn->setText(QCoreApplication::translate("LoginWindowClass", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(reg), QCoreApplication::translate("LoginWindowClass", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindowClass: public Ui_LoginWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
