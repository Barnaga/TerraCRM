#pragma once

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QMessageBox>
#include "ui_FinanceForm.h"

class FinanceForm : public QDialog
{
	Q_OBJECT

public:
	FinanceForm(QWidget *parent = nullptr, const QString& lbl="", QSqlRelationalTableModel* model= nullptr, const QString& sign="", const QString& company_id="");
	~FinanceForm();
	FinanceForm(FinanceForm& r) = delete;
	FinanceForm(FinanceForm&& r) = delete;
	FinanceForm& operator=(const FinanceForm& r) = delete;
	FinanceForm& operator=(const FinanceForm&& r) = delete;
private slots:
	void addData();
	void getDataSecondary();
private:
	std::unique_ptr<Ui::FinanceFormClass> ui;
	QSqlRelationalTableModel* model;
	std::unique_ptr < QSqlQuery> query;
	std::unique_ptr < QMessageBox> msgBox;
	const QString& lbl;
	int company_id;
	QString sign;
	void createConnections();
	void createView(const QString&);
	void getData(const QString&, const int&, QComboBox*, QComboBox* secondary = nullptr);
	void updateAccount(const int&);
	void updateQuery(const int&, const int&);
};
