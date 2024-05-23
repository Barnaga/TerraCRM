#pragma once

#include <QMainWindow>
#include <QDebug>
#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = nullptr);
		
	~LoginWindow();
private slots:
	void on_loginBtn_clicked();
private:
	Ui::LoginWindowClass ui;
};
