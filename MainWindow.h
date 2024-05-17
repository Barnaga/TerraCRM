#pragma once

#include <QtWidgets/QMainWindow>
#include <QDebug>
#include <pqxx/pqxx>
#include <string>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindowClass ui;
};
