#include "LoginWindow.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void LoginWindow::on_loginBtn_clicked() {
	
	qDebug() << "Click";
}
LoginWindow::~LoginWindow()
{}
