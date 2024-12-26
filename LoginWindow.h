#pragma once

#include <QMainWindow>
#include <MainWindow.h>
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
	Ui::LoginWindowClass* ui;
	MainWindow* parent;
	QSqlQuery* query;
	QString login;
	QString password;
	QString role;
	QString name;
	QString surname;
	QString company;
	QString phone;
	const QString getHashedPassword(const QString& login);
	bool isValid(const QString& login, const QString& password);
	bool isValid(const QString& login, const QString& password, const QString& role, const QString& name, const QString& surname);
	bool isValidLogin();
	bool isValidPassword(const QString& login, const QString& password);
	bool registerValid();
	void openMainWindow();
	void createConnections();
};
