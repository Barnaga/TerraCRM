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

private:
    //Ui::MainWindowClass* ui;
    void setLoginInterface();
    
};
