#pragma once

#include <QtWidgets>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
   
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(const MainWindow& m) = delete;
    MainWindow(const MainWindow&& m) = delete;
    MainWindow& operator=(const MainWindow& r) = delete;
    MainWindow& operator=(const MainWindow&& r) = delete;  
    ~MainWindow();
    QStringList getUser(); 
    QString login;
    bool isLogin;
    void createMenu();
private slots:  
    void openCRM();
    void openTasks();
    void openProjects();
    void openFinance();
    void outApp();
private:
    Ui::MainWindowClass* ui;
    QSqlQuery* query;
    QSqlDatabase db; 
    QToolBar* toolbar;
    QAction* crmBtn;
    QAction* tasksBtn;
    QAction* projectBtn;
    QAction* financeBtn;
    QAction* outBtn;
    void connectDatabase();
    void setLoginInterface();
    void setCRMInterface();
    void setTasksInterface();
    void setProjectsInterface();
    void setFinanceInterface();  
};
