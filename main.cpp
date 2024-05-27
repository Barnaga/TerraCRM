#pragma once
#include "MainWindow.h"
#include "LoginWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //LoginWindow lW;
    MainWindow mW;
    mW.showMaximized();
    return a.exec();
}
