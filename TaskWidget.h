#pragma once

#include <QDialog>
#include "ui_TaskWidget.h"

class TaskWidget : public QDialog
{
	Q_OBJECT

public:
	TaskWidget(QWidget *parent = nullptr);
	~TaskWidget();

private:
	Ui::TaskWidgetClass* ui;
};
