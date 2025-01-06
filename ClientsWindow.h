#pragma once

#include <QWidget>
#include <QSqlError>

#include <QSqlRelationalTableModel>
#include <QVBoxLayout>
#include <QTableView>
#include <QHeaderView>
#include "ui_ClientsWindow.h"
#include "ClientWidget.h"
#include "CompanyWidget.h"

class ClientsWindow : public QWidget
{
	Q_OBJECT

public:
	ClientsWindow(QWidget *parent = nullptr);
	~ClientsWindow();
private slots:
	void openClient(const QModelIndex&);
	void openCompany(const QModelIndex&);
private:
	Ui::ClientsWindowClass* ui;
	QSqlRelationalTableModel* client_model;
	QTableView* client_view;
	void createClientModel();
	void createClientView();
	QSqlRelationalTableModel* company_model;
	QTableView* company_view;
	void createCompanyModel();
	void createCompanyView();
};
