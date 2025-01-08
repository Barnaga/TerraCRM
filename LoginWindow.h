#pragma once

#include <QMainWindow>
#include "MainWindow.h"
#include "ui_LoginWindow.h"
class LoginWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit LoginWindow(QMainWindow* parent = nullptr);
	LoginWindow(LoginWindow& r) = delete;
	LoginWindow(LoginWindow&& r) = delete;
	LoginWindow& operator=(const LoginWindow& r) = delete;
	LoginWindow& operator=(const LoginWindow&& r) = delete;
	~LoginWindow();

private slots:
	void loginUser();
	void registerUser();
private:
	std::unique_ptr<Ui::LoginWindowClass> ui;
	MainWindow* parent;
	std::unique_ptr <QSqlQuery> query;
	int counter;
	QString login;
	QString password;
	QString role;
	QString name;
	QString surname;
	QString company;
	QString phone;
	QStringList compareLoginNPhone();
	const QString getHashedPassword(const QString&);
	bool isValid(const QString&, const QString&);
	bool isValid(const QString&, const QString&, const QString&, const QString&, const QString&);
	bool isValidLogin();
	bool isValidPassword(const QString&, const QString&);
	bool registerValid();
	void openMainWindow();
	void createConnections();
};
