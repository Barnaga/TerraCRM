#include "MainWindow.h"
#include "LoginWindow.h"
#include <iostream>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    //ui->setupUi(this);
    pool = make_shared<DbPool>(5);
    setLoginInterface();  
}

MainWindow::~MainWindow()
{}

void MainWindow::setLoginInterface()
{
    setCentralWidget(new LoginWindow(this));
}
