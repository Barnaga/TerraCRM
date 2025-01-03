#pragma once

#include "MainWindow.h"
#include "StatusDelegate.h"
#include "ui_CRMWindow.h"
#include "DealWidget.h"
#include <QSqlRelationalTableModel>

class CRMWindow : public QWidget
{
	Q_OBJECT
public:
	explicit CRMWindow(QWidget*parent = nullptr);
	~CRMWindow();
	CRMWindow(CRMWindow& r) = delete;
	CRMWindow(CRMWindow&& r) = delete;
	CRMWindow& operator=(const CRMWindow& r) = delete;
	CRMWindow& operator=(const CRMWindow&& r) = delete;
private slots:
	void openDeal(const QModelIndex&);
private:
	Ui::CRMWindowClass* ui;
	MainWindow* parent;
	QTableView* view;
	QSqlRelationalTableModel* model;
	void createModel();
	void createView();
	
	
};
