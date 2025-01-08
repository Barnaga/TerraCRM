#include "LoginWindow.h"
#include <QTest>

LoginWindow::LoginWindow(QMainWindow* parent)
	: ui(std::make_unique<Ui::LoginWindowClass>()),
	parent(dynamic_cast<MainWindow*>(parent)),
	query(std::make_unique<QSqlQuery>())
{
	ui->setupUi(this);
	createConnections();
	counter = 0;
}
void LoginWindow::createConnections()
{
	connect(ui->loginBtn, SIGNAL(clicked()), this, SLOT(loginUser()));
	connect(ui->registerBtn, SIGNAL(clicked()), this, SLOT(registerUser()));
}
void LoginWindow::loginUser() {
	login = ui->emailEdit->text();
	password = ui->passwordEdit->text();
	parent->login = login;
	if (isValidPassword(login, password))
		openMainWindow();
	else if(counter>=3){
		ui->errorLbl->setText("Превышено количество попыток авторизации");
		ui->loginBtn->hide();
		QTimer::singleShot(180000, ui->loginBtn, SLOT(show()));
		counter = 0;
	}
	else {
		ui->errorLbl->setText("Неверный логин и пароль");
		++counter;
	}
}
void LoginWindow::registerUser() {
	login = ui->regEmailEdit->text();
	password = ui->regPasswordEdit->text();
	role = ui->roleBox->currentText();
	name = ui->regNameEdit->text();
	surname = ui->regSurnameEdit->text();
	phone = ui->phoneEdit->text();
	company = ui->companyEdit->text();
	if (registerValid()) 
		openMainWindow();
}
bool LoginWindow::registerValid()
{	
	query->prepare("SELECT id FROM companies WHERE name =:company");
	query->bindValue(":company", company);
	query->exec();
	query->first();
	QString company_id = query->value(0).toString();

	if (isValid(login, password, role, name, surname) and compareLoginNPhone().constFirst() =="" or compareLoginNPhone().constLast() =="") {
		query->prepare("INSERT INTO public.users (hashedpassword, login, salt, role, name, surname, phone, company_id) VALUES ( crypt(:password, gen_salt('md5')), :login,  gen_salt('md5'), :role, :name, :surname,:phone, :company_id)");
		query->bindValue(":password", password);
		query->bindValue(":login", login);
		query->bindValue(":role", role);
		query->bindValue(":name", name);
		query->bindValue(":surname", surname);
		query->bindValue(":phone", phone);
		query->bindValue(":company_id", company_id);
		if (query->exec()) 
			return true;
		return false;
	}
	else
		ui->errorLblReg->setText("Не все поля заполнены");
	return false;
}
QStringList LoginWindow::compareLoginNPhone()
{
	query->prepare("SELECT login, phone FROM users WHERE login=:login or phone=:phone");
	query->bindValue(":login", login);
	query->bindValue(":phone", phone);
	query->exec();
	if (query->first()) {
		return QStringList{ query->value(0).toString(), query->value(1).toString() };
	}
	else {
		return QStringList{ "",""};
	}
}
const QString LoginWindow::getHashedPassword(const QString& login)
{
	if (isValidLogin()) {
		query->prepare("SELECT hashedPassword  FROM users where login=:login");
		query->bindValue(":login", login);
		query->exec();
		query->first();
		return query->value(0).toString();
	}
	else return "";
}
bool LoginWindow::isValidLogin()  {
	if (isValid(login, password)) return false;
	else {
		query->prepare("SELECT login FROM users where login =:login");
		query->bindValue(":login", login);
		if (!query->exec() && !query->first()) return false;
		else return true;
	}				
}
bool LoginWindow::isValid(const QString& login, const QString& password)
{
	if (login.isEmpty() and password.isEmpty())
		return true;
	return false;
}
bool LoginWindow::isValid(const QString& login, const QString& password, const QString& role, const QString& name, const QString& surname)
{
	if (login.isEmpty() and password.isEmpty() and role.isEmpty() and name.isEmpty() and surname.isEmpty())
		return true;
	return false;
}
bool LoginWindow::isValidPassword(const QString& login, const QString& password)
{
	const auto& hashedPassword = getHashedPassword(login);
	if (hashedPassword.isEmpty()) return false;
	else {
		query->prepare("SELECT (hashedPassword =crypt(:password, :hashedPassword)) AS password_match FROM users WHERE login =:login");
		query->bindValue(":password", password);
		query->bindValue(":hashedPassword", hashedPassword);
		query->bindValue(":login", login);
		query->exec();
		query->first();
		if (query->value(0).toString() == "true") return true;
		return false;
	}
}
void LoginWindow::openMainWindow()
{
	this->close();
	parent->isLogin = true;
	parent->activateWindow();
	parent->createMenu();

	parent->showMaximized();
}
LoginWindow::~LoginWindow()
{
}


