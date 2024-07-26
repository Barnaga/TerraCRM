#pragma once

#include "MainWindow.h"
#include "StatusDelegate.h"
#include "ui_CRMWindow.h"
class CRMWindow : public QWidget
{
	Q_OBJECT
public:
	explicit CRMWindow(QWidget*parent = nullptr);
	~CRMWindow();

private:
	Ui::CRMWindowClass* ui;
	QMainWindow* parent;
	QTableView* view;
	QSqlTableModel* model;
	void createModel();
	void createView();
	
};
