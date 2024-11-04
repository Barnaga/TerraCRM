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
	void createContactBox(int id);
private:
	QString id;
	Ui::createProjectDialogClass ui;
	QSqlRelationalTableModel* model;
	void getContactID(const int& row);
	QSqlQuery query;
	void createComponyBox();
};
