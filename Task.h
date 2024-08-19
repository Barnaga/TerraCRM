#pragma once

#include <QDialog>
#include <QFileDialog>
#include "Reminder.h"
#include "ui_Task.h"

class Task : public QDialog
{
	Q_OBJECT

public:
	Task(QWidget *parent = nullptr, QVector<QString> data={});
	~Task();
private:
	Ui::TaskClass ui;
	QString id;
	QVector<QString> data;
	void getStatus();
	bool isDeadline();
};
