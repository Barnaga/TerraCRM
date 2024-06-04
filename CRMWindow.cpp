#include "CRMWindow.h"
CRMWindow::CRMWindow(QMainWindow *parent) : parent(dynamic_cast<MainWindow*>(parent)), ui(new Ui::CRMWindowClass)
{
	ui->setupUi(this);
}

CRMWindow::~CRMWindow()
{}
