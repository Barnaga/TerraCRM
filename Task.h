#pragma once

#include <QDialog>
#include <QFileDialog>
#include <QSqlQuery>
#include <QSqlError>
#include "ui_Task.h"
#include <QMessageBox>
#include <QSqlRelationalTableModel>
 class Task : public QDialog
{
	Q_OBJECT

public:
	explicit Task(QWidget* parent = nullptr, QStringList data = {}, QSqlRelationalTableModel* model = nullptr, const QModelIndex& index = {});
	~Task();
	Task(Task& r) = delete;
	Task(Task&& r) = delete;
	Task& operator=(const Task& r) = delete;
	Task& operator=(const Task&& r) = delete;
private slots:
	void updateStatus(int);
private:
	Ui::TaskClass* ui;
	QSqlRelationalTableModel* model;
	const QModelIndex index;
	QString id;
	int currentIndex;
	QStringList data;
	void getStatus();
	void isDeadline();
	void createView();
 };
