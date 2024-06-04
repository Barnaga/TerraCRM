#pragma once

#include <QMainWindow>
#include <MainWindow.h>
#include "ui_LoginWindow.h"

enum class Role { Leader, Manager, Marketer, Seller, Unknown};
class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit LoginWindow(QMainWindow *parent = nullptr);
	
	~LoginWindow();
private slots:
	void on_loginBtn_clicked();
	void on_registerBtn_clicked();

private:
	Ui::LoginWindowClass* ui;
	MainWindow* parent;
	string login;
	string password;
	string role;
	const string getHashedPassword(const string& login, const string& password) const;
	bool isValid(const string& login, const string& password) const;
	bool isValid(const string& login, const string& password, const string& role) const;
	bool isValidLogin() const;
	bool isValidPassword(const string& login, const string& password) const;
	void openMainWindow();
};
