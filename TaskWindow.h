#pragma once
#include "MainWindow.h"
#include "RateDelegate.h"
#include "FormTask.h"
#include "ui_TaskWindow.h"
#include "Task.h"
#include <QSqlRelationalTableModel>
#include <QSqlRelationalDelegate>


class TaskWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TaskWindow(MainWindow *parent = nullptr);
	~TaskWindow();
	TaskWindow(TaskWindow& r) = delete;
	TaskWindow(TaskWindow&& r) = delete;
	TaskWindow& operator=(const TaskWindow& r) = delete;
	TaskWindow& operator=(const TaskWindow&& r) = delete;
public slots:
	void createTaskBtn();

	void openTask(const QModelIndex index);
private:
	Ui::TaskWindowClass* ui;

	MainWindow* parent;
	QSqlRelationalTableModel* model;
	FormTask* formTask;
	QTableView* view;
	QList<QString> user;
	Task* task;
	QList<QString> data;
	void createModel();
	void createConnections();
	void createView();
	

	
};
