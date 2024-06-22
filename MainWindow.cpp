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
    
    isLogin = false;
    pool = make_shared<DbPool>(5);
    if(isLogin){
        createMenu();
    } 
    else {
        setLoginInterface();

    }
 
}

MainWindow::~MainWindow()
{
}

void MainWindow::setLoginInterface()
{
    setCentralWidget(new LoginWindow(this));
}
void MainWindow::on_crmBtn_triggered() {
    qDebug() << "Clicked crm";
    setCRMInterface();
}
void MainWindow::setCRMInterface() {
  setCentralWidget(new CRMWindow(this));
}
void MainWindow::on_tasksBtn_triggered() {
    qDebug() << "Clicked tasks";
    setTasksInterface();
}
void MainWindow::setTasksInterface() {
    setCentralWidget(new TaskWindow(this));
}

void MainWindow::createMenu()
{
    QToolBar *menu = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, menu);
    QAction* crmBtn = new QAction(tr("CRM"), this);
    QAction* tasksBtn = new QAction("Tasks", this);
    QAction* projectBtn = new QAction(tr("Project"), this);
    QAction* financeBtn = new QAction("Finance", this);
    QAction* teamBtn = new QAction("Team", this);
    QAction* reportBtn = new QAction("Report", this);
    menu->addAction(crmBtn);
    menu->addAction(tasksBtn);
    menu->addAction(projectBtn);
    menu->addAction(financeBtn);
    menu->addAction(teamBtn);
    menu->addAction(reportBtn);
    connect(tasksBtn, SIGNAL(triggered()), this, SLOT(on_tasksBtn_triggered()));
    connect(crmBtn, SIGNAL(triggered()), this, SLOT(on_crmBtn_triggered()));
}
