#pragma once

#include <QtWidgets>
#include <QDebug>
#include "db_pool.h"

#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    shared_ptr<DbPool> pool = nullptr;
    Ui::MainWindowClass* ui;
    ~MainWindow();

    bool isLogin;

    void createMenu();
private slots:  
    void on_crmBtn_triggered();
    void on_tasksBtn_triggered();
private:
    void setLoginInterface();
    void setCRMInterface();
    void setTasksInterface();
    

    
};
