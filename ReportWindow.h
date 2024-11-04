#pragma once

#include <QWidget>
#include "ui_ReportWindow.h"

class ReportWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ReportWindow(QWidget *parent = nullptr);
	~ReportWindow();

private:
	Ui::ReportWindowClass ui;
};
