#include "CRMWindow.h"
CRMWindow::CRMWindow(QMainWindow* parent) 
	: QWidget(parent), ui(new Ui::CRMWindowClass)
{
	ui->setupUi(this);
}

CRMWindow::~CRMWindow()
{}
