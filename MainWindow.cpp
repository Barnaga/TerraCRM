#include "MainWindow.h"
#include "LoginWindow.h"
#include "CRMWindow.h"
#include <iostream>
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    pool = make_shared<DbPool>(5);
    setLoginInterface();  
}

MainWindow::~MainWindow()
{}

void MainWindow::setLoginInterface()
{
    setCentralWidget(new LoginWindow(this));
}

void MainWindow::setCRMInterface() {
    setCentralWidget(new CRMWindow(this));
}

void MainWindow::on_crmBtn_clicked() {
    setCRMInterface();
}