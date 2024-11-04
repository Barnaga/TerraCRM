#pragma once

#include "MainWindow.h"
#include "StatusDelegate.h"
#include "ui_CRMWindow.h"
#include "DealWidget.h"
#include <QSqlRelationalTableModel>
enum class Deals {
	NewRequests,
	InitialNegolation,
	ApprovalDocuments,
	CompletionDeal
};

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
	QMainWindow* parent;
	QTableView* view;
	QSqlRelationalTableModel* model;
	QVector<QString> data;
	void createModel();
	void createView();
	
	
};
