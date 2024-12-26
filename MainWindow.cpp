#include "MainWindow.h"
#include "LoginWindow.h"
#include "CRMWindow.h"
#include "TaskWindow.h"
#include "ProjectWindow.h"
#include "FinanceWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass), isLogin(false)
{
    ui->setupUi(this);
    auto database = "QPSQL";
    auto host = "localhost";
    auto name = "TerraCRM";
    auto user = "postgres";
    auto password = "1234";
    connectDatabase(database, host, name, user, password);
    ui->dateLbl->setText("Сегодня " + QDateTime::currentDateTime().toString("dd.MM.yyyy"));
    if (!isLogin) setLoginInterface();
    else this->activateWindow();
}

void MainWindow::connectDatabase(QString database, QString host, QString name, QString user, QString password)
{
    db = QSqlDatabase::addDatabase(database);
    db.setHostName(host);
    db.setDatabaseName(name);
    db.setUserName(user);
    db.setPassword(password);
    db.open();
}

MainWindow::~MainWindow()
{
}
void MainWindow::setLoginInterface(){
    setCentralWidget(new LoginWindow(this));
}
void MainWindow::setCRMInterface() {
    setCentralWidget(new CRMWindow(this));
}
void MainWindow::setTasksInterface() {
    setCentralWidget(new TaskWindow(this));
}
void MainWindow::setProjectsInterface() {
    setCentralWidget(new ProjectWindow(this));
}
void MainWindow::setFinanceInterface() {
    setCentralWidget(new FinanceWindow(this));
}

void MainWindow::openCRM() {
    setCRMInterface();
}
void MainWindow::openTasks() {
    setTasksInterface();
}
void MainWindow::openProjects() {
    setProjectsInterface();
}
void MainWindow::openFinance() {
    setFinanceInterface();
}

void MainWindow::outApp(){
    this->close();
}

QStringList MainWindow::getUser()
{
    query = new QSqlQuery;
    query->prepare("SELECT name, surname, login, id, role, company_id FROM users WHERE login= :login");
    query->bindValue(":login", login);
    if (query->exec() && query->first()) 
        return QStringList{
        query->value(0).toString(),
        query->value(1).toString(),
        login,
        query->value(3).toString(),
        query->value(4).toString(),
        query->value(5).toString()};
    return QStringList{ "","","","","",""};
}

void MainWindow::createMenu()
{
    toolbar = new QToolBar;
    addToolBar(Qt::LeftToolBarArea, toolbar);
    crmBtn = new QAction("CRM", this);
    tasksBtn = new QAction("Задачи", this);
    projectBtn = new QAction("Проекты", this);
    financeBtn = new QAction("Финансы", this);
    outBtn = new QAction("Выход", this);
    toolbar->addAction(crmBtn);
    toolbar->addAction(tasksBtn);
    toolbar->addAction(projectBtn);
    toolbar->addAction(financeBtn);
    toolbar->addAction(outBtn);
    toolbar->setStyleSheet("background:rgb(255,253,253); spacing: 10px; color:rgb(55, 107, 113);");
    connect(tasksBtn, SIGNAL(triggered()), this, SLOT(openTasks()));
    connect(crmBtn, SIGNAL(triggered()), this, SLOT(openCRM()));
    connect(projectBtn, SIGNAL(triggered()), this, SLOT(openProjects()));
    connect(financeBtn, SIGNAL(triggered()), this, SLOT(openFinance()));
    connect(outBtn, SIGNAL(triggered()), this, SLOT(outApp()));
}

