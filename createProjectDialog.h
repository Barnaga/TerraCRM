#pragma once

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_createProjectDialog.h"
#include <MainWindow.h>

class createProjectDialog : public QDialog
{
	Q_OBJECT

public:
	explicit createProjectDialog(QWidget* parent = nullptr, QSqlRelationalTableModel* model = nullptr, QString id = "");
	~createProjectDialog();
private slots:
	void create();
	void createClient();
private:
	QString id;
	std::unique_ptr<Ui::createProjectDialogClass> ui;
	QSqlRelationalTableModel* model;
	void getContactID(const int& row);
	QString client;
	std::unique_ptr<QSqlQuery> query;
};
