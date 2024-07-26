#pragma once

#include <QDialog>
#include "ui_FormTask.h"

class FormTask : public QDialog
{
	Q_OBJECT

public:
	FormTask(QWidget *parent = nullptr, bool isCreate=true);
	~FormTask();
	QLineEdit* nameTask;
	QPushButton* okBtn;
	QPushButton* cancelBtn;
	QLabel* warningLbl;
	void createTask();
private:
	Ui::FormTaskClass* ui;
};
