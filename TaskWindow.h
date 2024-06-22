#pragma once

#include <QMainWindow>

#include "MainWindow.h"
#include "TaskWidget.h"
#include "ui_TaskWindow.h"

enum class StatusTask
{
	All = 0,
	Do = 1,
	Work = 2,
	Done = 3,
	Completed = 4
};
class TaskWindow : public QWidget
{
	Q_OBJECT

public:
	TaskWindow(QMainWindow *parent = nullptr);
	~TaskWindow();

private:
	Ui::TaskWindowClass* ui;
	MainWindow* parent;

	QStringList taskData;
	QStringListModel* taskDataModel;
	QVector<TaskWidget*> tasksWidget;
	QString getCountTask(StatusTask status);
	QList<QStringList> getTaskData();
	void printCountStatusTask();
	void createTaskWidget();
};
