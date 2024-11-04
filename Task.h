#pragma once

#include <QDialog>
#include <QFileDialog>
#include <QSqlQuery>
#include "ui_Task.h"
#include <QMessageBox>
#include <QSqlRelationalTableModel>
 class Task : public QDialog
{
	Q_OBJECT

public:
	explicit Task(QWidget* parent = nullptr, QVector<QString> data = {}, QSqlRelationalTableModel* model=nullptr, QModelIndex index={});
	~Task();
	Task(Task& r) = delete;
	Task(Task&& r) = delete;
	Task& operator=(const Task& r) = delete;
	Task& operator=(const Task&& r) = delete;
private slots:
	void updateStatus(int);
private:
	Ui::TaskClass ui;
	QString id; 
	QModelIndex index;
	 int currentIndex;
	QVector<QString> data;
	void getStatus();
	void isDeadline();
	QSqlQuery query;
	QSqlRelationalTableModel* model;
};
