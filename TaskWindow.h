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
public slots:
	void onClickCreateTaskBtn();

	void openTask(const QModelIndex index);
private:
	Ui::TaskWindowClass* ui;

	MainWindow* parent;
	QSqlRelationalTableModel* model;
	FormTask* formTask;
	QTableView* view;
	void createModel();
	void createConnections();
	void createView();
	

	
};
