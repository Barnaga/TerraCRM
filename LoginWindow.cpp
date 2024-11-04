#include "LoginWindow.h"

LoginWindow::LoginWindow(QMainWindow* parent)
	: ui(new Ui::LoginWindowClass), parent(dynamic_cast<MainWindow*>(parent))
{
	ui->setupUi(this);
	connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(loginUser()));
	connect(ui->registerBtn, SIGNAL(clicked()), this, SLOT(registerUser()));
}
void LoginWindow::loginUser() {
	LoginWindow::login = ui->loginEdit->text();
	LoginWindow::password = ui->passwordEdit->text();
	parent->login = login;
	if (isValidPassword(login, password))
	{
		openMainWindow();
		parent->isLogin = true;
	}
	else 
		ui->errorLbl->setText("Don't correct login or password");
}
void LoginWindow::registerUser() {
	LoginWindow::login = ui->loginEdit_2->text();
	LoginWindow::password = ui->passwordEdit_2->text();
	LoginWindow::role = ui->comboBox->currentText();
	LoginWindow::name = ui->nameEdit->text();
	LoginWindow::surname = ui->surnameEdit->text();
	if (registerValid()) 
		openMainWindow();
	else 
		QMessageBox::critical(this, tr("Error"), tr("The username or password is not entered correctly"));	
}
bool LoginWindow::registerValid()
{
	if (isValid(login, password, role, name, surname)) {
		query.prepare("INSERT INTO public.users (hashedpassword, login, salt, role, name, surname) VALUES ( crypt(:password, gen_salt('md5')), :login,  gen_salt('md5'), :role, :name, :surname)");
		query.bindValue(":password", password);
		query.bindValue(":login", login);
		query.bindValue(":role", role);
		query.bindValue(":name", name);
		query.bindValue(":surname", surname);
		query.exec();
		return true;
	}
	else
		QMessageBox::critical(this, tr("Error"), tr("The username or password is not entered correctly"));
	return false;
}
const QString LoginWindow::getHashedPassword(const QString& l_login)
{
	if (isValidLogin()) {
		query.prepare("SELECT hashedPassword  FROM users where login=:login");
		query.bindValue(":login", l_login);
		query.exec();
		query.first();
		auto hashedPassword = query.value(0).toString();
		return hashedPassword;
	}
	else return "";
}
bool LoginWindow::isValidLogin()  {
	if (isValid(login, password)) return false;
	else {
		query.prepare("SELECT login FROM users where login =:login");
		query.bindValue(":login", login);
		if (!query.exec() && !query.first()) return false;
		else return true;
	}				
}
bool LoginWindow::isValid(const QString& l_login, const QString& l_password)
{
	if (l_login.isEmpty() and l_password.isEmpty())
		return true;
	return false;
}
bool LoginWindow::isValid(const QString& l_login, const QString& l_password, const QString& l_role, const QString& l_name, const QString& l_surname)
{
	if (l_login.isEmpty() and l_password.isEmpty() and l_role.isEmpty() and l_name.isEmpty() and l_surname.isEmpty())
		return false;
	return true;
}
bool LoginWindow::isValidPassword(const QString& l_login, const QString& l_password)
{
	const auto hashedPassword = getHashedPassword(l_login);
	if (hashedPassword.isEmpty()) return false;
	else {
		query.prepare("SELECT (hashedPassword =crypt(:password, :hashedPassword)) AS password_match FROM users WHERE login =:login");
		query.bindValue(":password", l_password);
		query.bindValue(":hashedPassword", hashedPassword);
		query.bindValue(":login", l_login);
		query.exec();
		query.first();
		if (query.value(0).toString() == "true") return true;
		return false;
	}
}
void LoginWindow::openMainWindow()
{
	this->close();
	parent->ui->setupUi(parent);
	parent->createMenu();
	parent->showMaximized();
}
LoginWindow::~LoginWindow()
{
	delete ui;
}


