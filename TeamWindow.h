#pragma once

#include <QWidget>
#include "ui_TeamWindow.h"

class TeamWindow : public QWidget
{
	Q_OBJECT

public:
	TeamWindow(QWidget *parent = nullptr);
	~TeamWindow();

private:
	Ui::TeamWindowClass ui;
};