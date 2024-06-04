#pragma once

#include <QMainWindow>
#include "MainWindow.h"
#include "ui_CRMWindow.h"

class CRMWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit CRMWindow(QMainWindow *parent = nullptr);
	~CRMWindow();

private:
	Ui::CRMWindowClass* ui;
	QMainWindow* parent;
};
