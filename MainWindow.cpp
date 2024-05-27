#include "MainWindow.h"
#include "LoginWindow.h"

#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);
    pool = std::make_shared<DbPool>(5);
    setLoginInterface();
}




MainWindow::~MainWindow()
{}

void MainWindow::setLoginInterface()
{
    setCentralWidget(new LoginWindow(this));
    
}
