#pragma once

#include "MainWindow.h"
#include "StatusDelegate.h"
#include "ui_CRMWindow.h"
#include "DealWidget.h"
#include "ClientsWindow.h"
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
	void openClients();
private:
	std::unique_ptr<Ui::CRMWindowClass> ui;
	MainWindow* parent;
	std::unique_ptr<QTableView> view;
	std::unique_ptr<QSqlRelationalTableModel> model;
	std::unique_ptr<DealWidget> deal;
	std::unique_ptr<ClientsWindow> clients;
	void createModel();
	void createView();
	void createConnections();
	
	
};
