#pragma once

#include <QWidget>
#include "ui_FinanceWindow.h"

class FinanceWindow : public QWidget
{
	Q_OBJECT

public:
	FinanceWindow(QWidget *parent = nullptr);
	~FinanceWindow();

private:
	Ui::FinanceWindowClass ui;
};
