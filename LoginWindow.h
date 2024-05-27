#pragma once

#include <QMainWindow>
#include <MainWindow.h>
#include "ui_LoginWindow.h"


class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	explicit LoginWindow(QMainWindow *parent = nullptr);
	
	~LoginWindow();
private slots:
	void on_loginBtn_clicked();

private:
	Ui::LoginWindowClass* ui;
	MainWindow* parent;
	const string getHashedPassword(const string& login, const string& password) const;
	bool isValid(const string& login, const string& password) const;
	bool isValidPassword(const string& login, const string& password);
};
