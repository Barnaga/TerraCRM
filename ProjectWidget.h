#pragma once

#include <QDialog>
#include "ui_ProjectWidget.h"

class ProjectWidget : public QDialog
{
	Q_OBJECT

public:
	ProjectWidget(QWidget *parent = nullptr);
	~ProjectWidget();

private:
	Ui::ProjectWidgetClass ui;
};
