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
	explicit FormTask(QWidget* parent = nullptr, QSqlRelationalTableModel* model = nullptr, int id = -1);
	
	~FormTask();
	FormTask(FormTask& r) = delete;
	FormTask(FormTask&& r) = delete;
	FormTask& operator=(const FormTask& r) = delete;
	FormTask& operator=(const FormTask&& r) = delete;
private slots:
	void addData();
	void getProjects();
private:
	std::unique_ptr<Ui::FormTaskClass> ui;
	QSqlTableModel* model;
	std::unique_ptr<QSqlQuery> query;
	void createDataComboBox();
	void createConnections();
	int id;
	int idProject;
};
