#include "LoginWindow.h"
#include <iostream>


LoginWindow::LoginWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	pool = std::make_shared<DbPool>(5);
	
	
}

void LoginWindow::on_loginBtn_clicked() {
	QString login = ui.loginEdit->text();
	QString password = ui.passwordEdit->text();
	bool check = ui.rememberMe->isChecked();
	qDebug() << login <<" "<<password << " "<< check;
	result res = pool->runQuery("SELECT * FROM users");
	/*for (auto const &row:res) {
		for (auto const& field : row) qDebug() << field.c_str() << '\t';
		
	}*/
}
LoginWindow::~LoginWindow()
{}
