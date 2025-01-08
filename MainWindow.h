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
    std::unique_ptr<Ui::MainWindowClass> ui;
    std::unique_ptr<QSqlQuery> query;
    QSqlDatabase db; 
    std::unique_ptr<QToolBar> toolbar;
    std::unique_ptr<QAction> crmBtn;
    std::unique_ptr<QAction> tasksBtn;
    std::unique_ptr<QAction> projectBtn;
    std::unique_ptr<QAction> financeBtn;
    std::unique_ptr<QAction> outBtn;
    void connectDatabase(QString, QString, QString, QString, QString);
    void setLoginInterface();
    void setCRMInterface();
    void setTasksInterface();
    void setProjectsInterface();
    void setFinanceInterface();  
};
