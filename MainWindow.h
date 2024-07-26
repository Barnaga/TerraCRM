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


    bool isLogin;
    
    void createMenu();
private slots:  
    void on_crmBtn_triggered();
    void on_tasksBtn_triggered();
    
private:
    QToolBar* toolbar;
    QAction* crmBtn;
    QAction* tasksBtn;
    QAction* projectBtn;
    QAction* financeBtn;
    QAction* teamBtn;
    QAction* reportBtn;
    void setLoginInterface();
    void setCRMInterface();
    void setTasksInterface();
};
