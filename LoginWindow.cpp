#include "LoginWindow.h"
#include <iostream>

LoginWindow::LoginWindow(QMainWindow* parent)
	: parent(dynamic_cast<MainWindow*>(parent)), ui(new Ui::LoginWindowClass)
{
	ui->setupUi(this);
}

void LoginWindow::on_loginBtn_clicked() {
	
		LoginWindow::login = ui->loginEdit->text().toStdString();
		LoginWindow::password = ui->passwordEdit->text().toStdString();
		result r = parent->pool->runQuery("Select role from users where login = '" + login + "'");
		LoginWindow::role = r[0][0].view();
		if (isValidPassword(login, password))
		{
			openMainWindow();
		}
		else
			ui->errorLbl->setText("Don't correct login or password");
	
	/*for (auto const &row : r) {
		for (auto const & field : row) {
			qDebug() << field.view();
		}
	}*/
}

void LoginWindow::on_registerBtn_clicked() {
	LoginWindow::login = ui->loginEdit_2->text().toStdString();
	LoginWindow::password = ui->passwordEdit_2->text().toStdString();
	LoginWindow::role = ui->comboBox->currentText().toStdString();
	
	if (isValidLogin()) {
		result reg = parent->pool->runQuery("INSERT INTO public.users (hashedpassword, login, salt, role) VALUES ( crypt('" + password + "', gen_salt('md5')), '"+login + "',  gen_salt('md5'), '"+role+"')");
		
		openMainWindow();
	}
	else 
		QMessageBox::critical(this, tr("Error"), tr("The username or password is not entered correctly"));
}
const string LoginWindow::getHashedPassword(const string login, const string password) const
{
	if (isValidLogin()) {
		result log = parent->pool->runQuery("SELECT hashedPassword  FROM users where login='" + login + "'");
		const string hashedPassword = (string)log[0][0].view();
		return hashedPassword;
	}
	else return "";
}
bool LoginWindow::isValidLogin() const  {
		result log = parent->pool->runQuery("SELECT login FROM users where login = '" + login + "'");
		if (isValid(login, password) and log[0][0].view() == "")
			return false;
		else 
			return true;		
}
bool LoginWindow::isValid(const string login, const string password) const
{
	if (login.empty() and password.empty())
		return false;
	return true;
}
bool LoginWindow::isValidPassword(const string login, const string password) const
{
	string hashedPassword = getHashedPassword(login, password);
	if (hashedPassword.size()==0) {
		return false;
	}
	else {
		result pass = parent->pool->runQuery("SELECT (hashedPassword =crypt('" + password + "', '"
			+ hashedPassword + "')) AS password_match FROM users WHERE login ='" + login + "'");
		if (pass[0][0].view() == "t")
			return true;
		return false;
	}

}
void LoginWindow::openMainWindow()
{
	this->close();
	parent->ui->setupUi(parent);
	parent->showMaximized();
}
LoginWindow::~LoginWindow()
{
	delete ui;
}


