#pragma once
#include "LoginWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginWindow lW;
    lW.showMaximized();
    return a.exec();
}
