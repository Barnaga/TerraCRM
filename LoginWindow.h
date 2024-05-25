#pragma once

#include <QMainWindow>
#include <QDebug>

#include "db_pool.h"
#include "ui_LoginWindow.h"

class LoginWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit LoginWindow(QWidget *parent = nullptr);
	shared_ptr<DbPool> pool = nullptr;
	~LoginWindow();
private slots:
	void on_loginBtn_clicked();
private:
	Ui::LoginWindowClass ui;
};
