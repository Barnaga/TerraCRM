#include "LoginWindow.h"
#include "CRMWindow.h"

LoginWindow::LoginWindow(QMainWindow* parent)
	: ui(new Ui::LoginWindowClass),
	parent(dynamic_cast<MainWindow*>(parent)),
	query(new QSqlQuery)
{
	ui->setupUi(this);
	
	createConnections();
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
	else 
		ui->errorLbl->setText("Don't correct login or password");
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
	else 
		QMessageBox::critical(this, tr("Error"), tr("Ошибка"));
}
bool LoginWindow::registerValid()
{	
	QString company_id = "";
	query->prepare("SELECT id FROM companies WHERE name =:company");
	query->bindValue(":company", company);

	qDebug() << query->exec();
	qDebug() << query->lastError();
	while (query->next()) {
		company_id = query->value(0).toString();
	}
	if (isValid(login, password, role, name, surname)) {
		query->prepare("INSERT INTO public.users (hashedpassword, login, salt, role, name, surname, phone, company_id) VALUES ( crypt(:password, gen_salt('md5')), :login,  gen_salt('md5'), :role, :name, :surname,:phone, :company_id)");
		query->bindValue(":password", password);
		query->bindValue(":login", login);
		query->bindValue(":role", role);
		query->bindValue(":name", name);
		query->bindValue(":surname", surname);
		query->bindValue(":phone", phone);
		query->bindValue(":company_id", company_id);
		
		if (query->exec()) {
			return true;
		}
		qDebug() << query->exec();
		qDebug() << query->lastError();
		return false;
	}
	else
		QMessageBox::critical(this, tr("Error"), tr("Не все поля заполнены"));
	return false;
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
		return false;
	return true;
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


