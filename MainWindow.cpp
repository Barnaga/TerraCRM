#include "MainWindow.h"
#include "LoginWindow.h"
#include "CRMWindow.h"
#include "TaskWindow.h"

#include <QToolbar>
#include <QAction>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    
    db= QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setDatabaseName("TerraCRM");
    db.setUserName("postgres");
    db.setPassword("1234");
    auto ok = db.open();
    isLogin = false;
    if(isLogin) createMenu();
    else   setLoginInterface();
}

MainWindow::~MainWindow()
{
}

void MainWindow::setLoginInterface()
{
    setCentralWidget(new LoginWindow(this));
}
void MainWindow::on_crmBtn_triggered() {
    setCRMInterface();
}
void MainWindow::setCRMInterface() {
  setCentralWidget(new CRMWindow(this));
}
void MainWindow::on_tasksBtn_triggered() {
    setTasksInterface();
}
void MainWindow::setTasksInterface() {
    setCentralWidget(new TaskWindow(this));
}

void MainWindow::createMenu()
{
    toolbar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolbar);
    crmBtn = new QAction(tr("CRM"), this);
    tasksBtn = new QAction("Tasks", this);
    projectBtn = new QAction(tr("Project"), this);
    financeBtn = new QAction("Finance", this);
    teamBtn = new QAction("Team", this);
    reportBtn = new QAction("Report", this);
    toolbar->addAction(crmBtn);
    toolbar->addAction(tasksBtn);
    toolbar->addAction(projectBtn);
    toolbar->addAction(financeBtn);
    toolbar->addAction(teamBtn);
    toolbar->addAction(reportBtn);
    toolbar->setStyleSheet("background:rgb(255,253,253); spacing: 10px; color:rgb(55, 107, 113);");
    connect(tasksBtn, SIGNAL(triggered()), this, SLOT(on_tasksBtn_triggered()));
    connect(crmBtn, SIGNAL(triggered()), this, SLOT(on_crmBtn_triggered()));
}

