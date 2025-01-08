#include "MainWindow.h"
#include "LoginWindow.h"
#include "CRMWindow.h"
#include "TaskWindow.h"
#include "ProjectWindow.h"
#include "FinanceWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindowClass>()), isLogin(false)
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
    query = std::make_unique<QSqlQuery>();
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
    toolbar = std::make_unique<QToolBar>();
    addToolBar(Qt::LeftToolBarArea, toolbar.get());
    crmBtn = std::make_unique<QAction>("CRM", this);
    tasksBtn = std::make_unique<QAction>("Задачи", this);
    projectBtn = std::make_unique<QAction>("Проекты", this);
    financeBtn = std::make_unique<QAction>("Финансы", this);
    outBtn = std::make_unique<QAction>("Выход", this);
    toolbar->addAction(crmBtn.get());
    toolbar->addAction(tasksBtn.get());
    toolbar->addAction(projectBtn.get());
    toolbar->addAction(financeBtn.get());
    toolbar->addAction(outBtn.get());
    toolbar->setStyleSheet("background:rgb(255,253,253); spacing: 10px; color:rgb(55, 107, 113);");
    connect(tasksBtn.get(), SIGNAL(triggered()), this, SLOT(openTasks()));
    connect(crmBtn.get(), SIGNAL(triggered()), this, SLOT(openCRM()));
    connect(projectBtn.get(), SIGNAL(triggered()), this, SLOT(openProjects()));
    connect(financeBtn.get(), SIGNAL(triggered()), this, SLOT(openFinance()));
    connect(outBtn.get(), SIGNAL(triggered()), this, SLOT(outApp()));
}