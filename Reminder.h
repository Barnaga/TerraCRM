#pragma once

#include <QDialog>
#include "ui_Reminder.h"
#include <QCalendarWidget>
#include <regex>
#include <QSqlQuery>

class Reminder : public QDialog
{
	Q_OBJECT
private slots:
	void changed(int index);
	void validDate();
public:
	Reminder(QWidget *parent = nullptr, QString id="");
	~Reminder();

private:
	Ui::ReminderClass ui;
	QString task_id;
};
