#pragma once
#include "MainWindow.h"
#include "RateDelegate.h"
#include "FormTask.h"
#include "ui_TaskWindow.h"


class TaskWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TaskWindow(QMainWindow *parent = nullptr);
	~TaskWindow();
public slots:
	void onClickCreateTaskBtn();
	void addData();
	void slotCustomMenuRequested(QPoint pos);
private:
	Ui::TaskWindowClass* ui;
	MainWindow* parent;
	QSqlTableModel* model;
	FormTask* formTask;
	QTableView *view;
	void createModel();
	void createConnections();
	void createView();
	
};
