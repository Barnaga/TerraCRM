#pragma once
#include "MainWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mW;
    mW.setWindowTitle("TerraCRM");
    mW.showMaximized();
    return a.exec();
}
