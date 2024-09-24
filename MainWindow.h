#pragma once

#include <QtWidgets>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    Ui::MainWindowClass* ui;
    ~MainWindow();
    QSqlDatabase db;
    QString login;
    bool isLogin;
    QList<QString> getUser();
    void createMenu();
private slots:  
    void openCRM();
    void openTasks();
    void openProjects();
    void openFinance();
    void openTeam();
    void openReport();
    void outApp();

private:
    QString name, surname,  role, id;
    QToolBar* toolbar;
    QAction* crmBtn;
    QAction* tasksBtn;
    QAction* projectBtn;
    QAction* financeBtn;
    QAction* teamBtn;
    QAction* reportBtn;
    QAction* outBtn;

    void connectDatabase();
    void setLoginInterface();
    void setCRMInterface();
    void setTasksInterface();
    void setProjectsInterface();
    void setFinanceInterface();
    void setTeamInterface();
    void setReportInterface();
    
};
