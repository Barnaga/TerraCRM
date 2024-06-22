#pragma once

#include <QMainWindow>
#include "ui_CRMWindow.h"

class CRMWindow : public QWidget
{
	Q_OBJECT

public:
	explicit CRMWindow(QMainWindow *parent = nullptr);
	~CRMWindow();

private:
	Ui::CRMWindowClass* ui;
	QMainWindow* parent;
};
