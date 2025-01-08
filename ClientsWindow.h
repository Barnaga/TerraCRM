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
	std::unique_ptr<Ui::ClientsWindowClass> ui;
	std::unique_ptr<QSqlRelationalTableModel> client_model;
	std::unique_ptr<QTableView> client_view;
	void createClientModel();
	void createClientView();
	std::unique_ptr<QSqlRelationalTableModel> company_model;
	std::unique_ptr<QTableView> company_view;
	std::unique_ptr<ClientWidget> client_widget;
	std::unique_ptr<CompanyWidget> company_widget;
	void createCompanyModel();
	void createCompanyView();
};
