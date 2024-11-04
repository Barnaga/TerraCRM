#include <QToolbar>
#include <QAction>
#include "MainWindow.h"
#include "LoginWindow.h"
#include "CRMWindow.h"
#include "TaskWindow.h"
#include "ProjectWindow.h"
#include "FinanceWindow.h"
#include "TeamWindow.h"
#include "ReportWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    connectDatabase();
  
    isLogin = false;
    ui->dateLbl->setText("Сегодня " + QDateTime::currentDateTime().toString("dd.MM.yyyy"));
    if (!isLogin)
        setLoginInterface();
    else
        new MainWindow(this);
}
void MainWindow::connectDatabase()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("TerraCRM");
    db.setUserName("postgres");
    db.setPassword("1234");
    db.open();
}
MainWindow::~MainWindow()
{
}
void MainWindow::setLoginInterface(){
    setCentralWidget(new LoginWindow(this));
}
void MainWindow::openCRM() {
    setCRMInterface();
}
void MainWindow::setCRMInterface() {
  setCentralWidget(new CRMWindow(this));
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
void MainWindow::openTeam() {
    setTeamInterface();
}
void MainWindow::openReport() {
    setReportInterface();
}
void MainWindow::outApp(){
    this->close();
}
void MainWindow::setTasksInterface() {
    setCentralWidget(new TaskWindow(this));
}
void MainWindow::setProjectsInterface(){
    setCentralWidget(new ProjectWindow(this));
}
void MainWindow::setFinanceInterface(){
    setCentralWidget(new FinanceWindow(this));
}
void MainWindow::setTeamInterface(){
    setCentralWidget(new TeamWindow(this));
}
void MainWindow::setReportInterface(){
    setCentralWidget(new ReportWindow(this));
}
QList<QString> MainWindow::getUser()
{
    QSqlQuery query;
    query.prepare("SELECT name, surname, login, id, role FROM users WHERE login= :login");
    query.bindValue(":login", login);
    if (query.exec() && query.first()) {
        name = query.value(0).toString();
        surname = query.value(1).toString();
        login = login;
        id = query.value(3).toString();
        role = query.value(4).toString();
        return QList<QString>{name, surname, login, id, role};
    }
    return QList<QString>{"","","","",""};
}

void MainWindow::createMenu()
{
    toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    crmBtn = new QAction(tr("CRM"), this);
    tasksBtn = new QAction("Задачи", this);
    projectBtn = new QAction(tr("Проекты"), this);
    financeBtn = new QAction("Финансы", this);
    teamBtn = new QAction("Команда", this);
    reportBtn = new QAction("Отчеты", this);
    outBtn = new QAction("Выход", this);
    toolbar->addAction(crmBtn);
    toolbar->addAction(tasksBtn);
    toolbar->addAction(projectBtn);
    toolbar->addAction(financeBtn);
    toolbar->addAction(teamBtn);
    toolbar->addAction(reportBtn);
    toolbar->addAction(outBtn);
    toolbar->setStyleSheet("background:rgb(255,253,253); spacing: 10px; color:rgb(55, 107, 113);");
    connect(tasksBtn, SIGNAL(triggered()), this, SLOT(openTasks()));
    connect(crmBtn, SIGNAL(triggered()), this, SLOT(openCRM()));
    connect(projectBtn, SIGNAL(triggered()), this, SLOT(openProjects()));
    connect(financeBtn, SIGNAL(triggered()), this, SLOT(openFinance()));
    connect(teamBtn, SIGNAL(triggered()), this, SLOT(openTeam()));
    connect(reportBtn, SIGNAL(triggered()), this, SLOT(openReport()));
    connect(outBtn, SIGNAL(triggered()), this, SLOT(outApp()));
}

