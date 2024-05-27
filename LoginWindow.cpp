#include "LoginWindow.h"
#include <iostream>


LoginWindow::LoginWindow(QMainWindow* parent)
	: parent(dynamic_cast<MainWindow*>(parent)), ui(new Ui::LoginWindowClass)
{
	ui->setupUi(this);
}

void LoginWindow::on_loginBtn_clicked() {
	const string& login = ui->loginEdit->text().toStdString();
	const string& password = ui->passwordEdit->text().toStdString();
	bool check = ui->rememberMe->isChecked();

	
	if (isValidPassword(login, password)) {
		this->close();
		parent->showMaximized();
	}
	else {
		QMessageBox::critical(this, tr("Error"), tr("The username or password is not entered correctly"));
	}

	//qDebug() << salt;
	//for (auto const &row : res) {
	//	for (auto const & field : row) {
	//		qDebug() << field.view();
	//	}
	//}
}

const string LoginWindow::getHashedPassword(const string& login, const string& password) const
{	
	
	if (isValid(login, password)) {
		result log = parent->pool->runQuery("SELECT hashedPassword  FROM users where login='" + login + "'");
		const string hashedPassword = (string)log[0][0].view();
		
		return hashedPassword;
	}
}

bool LoginWindow::isValid(const string& login, const string& password) const
{
	if (!login.empty() and !password.empty())
		return true;
	return false;
}
bool LoginWindow::isValidPassword(const string& login, const string& password)
{
	string hashedPassword = getHashedPassword(login, password);
	result pass = parent->pool->runQuery("SELECT (hashedPassword =crypt('" + password + "', '"
		+ hashedPassword + "')) AS password_match FROM users WHERE login ='" + login + "'");
	if (pass[0][0].view() == "t") {
		qDebug() << "Good";
		return true;
	}
	
	return false;
}

LoginWindow::~LoginWindow()
{
}


