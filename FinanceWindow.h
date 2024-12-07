#pragma once
#include <QWidget>
#include <QSqlRecord>
#include <QSqlField>
#include <MainWindow.h>
#include <FinanceForm.h>
#include <TransferForm.h>
#include "ui_FinanceWindow.h"

class FinanceWindow : public QWidget
{
	Q_OBJECT
public:
	explicit FinanceWindow(MainWindow* parent = nullptr);
	~FinanceWindow();
	FinanceWindow(FinanceWindow& r) = delete;
	FinanceWindow(FinanceWindow&& r) = delete;
	FinanceWindow& operator=(const FinanceWindow& r) = delete;
	FinanceWindow& operator=(const FinanceWindow&& r) = delete;

private slots:
	void addProfitAmount();
	void addLossAmount();
	void addTransfer();

private:
	Ui::FinanceWindowClass* ui;
	MainWindow* parent;
	QSqlRelationalTableModel* model;
	QTableView* view;
	QString company_id;
	void createModel();
	void createView();
	void createConnections();

};
