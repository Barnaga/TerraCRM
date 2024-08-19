#pragma once

#include <QMainWindow>
#include <MainWindow.h>
#include "ui_LoginWindow.h"
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
	QString login;
	QString password;
	QString role;
	QString name;
	QString surname;

	QSqlQuery query;
	const QString getHashedPassword(const QString& login, const QString& password);
	bool isValid(const QString& login, const QString& password);
	bool isValid(const QString& login, const QString& password, const QString& role, const QString& name, const QString& surname);
	bool isValidLogin();;
	bool isValidPassword(const QString& login, const QString& password);
	bool registerValid();

	void openMainWindow();

};
