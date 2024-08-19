#pragma once

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlRecord>
#include "ui_FormTask.h"
#include <QSqlError>

class FormTask : public QDialog
{
	Q_OBJECT

public:
	FormTask(QWidget *parent = nullptr, QSqlRelationalTableModel* model= nullptr, int id =-1);
	~FormTask();
private slots:
	void addData();
	void getProjects(int index);
private:
	Ui::FormTaskClass* ui;
	QSqlRelationalTableModel* model;
	
	QSqlQuery query;
	void createDataComboBox();
	int id;
	int idProject;
};
