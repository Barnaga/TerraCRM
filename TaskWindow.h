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
	void openTask(const QModelIndex&);
private:
	std::unique_ptr<Ui::TaskWindowClass> ui;
	MainWindow* parent;
	std::shared_ptr<QSqlRelationalTableModel> model;
	std::unique_ptr<FormTask> formTask;
	std::unique_ptr<Task> task;
	std::unique_ptr<QTableView> view;
	QStringList user;
	QStringList data;
	void createModel();
	void createConnections();
	void createView();
};
