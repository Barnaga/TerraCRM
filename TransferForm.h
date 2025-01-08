#pragma once

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include<QDateTime>
#include<QMessageBox>

#include "ui_TransferForm.h"

class TransferForm : public QDialog
{
	Q_OBJECT

public:
	TransferForm(QWidget *parent = nullptr, const QString& company_id="");
	~TransferForm();
	TransferForm(TransferForm& r) = delete;
	TransferForm(TransferForm&& r) = delete;
	TransferForm& operator=(const TransferForm& r) = delete;
	TransferForm& operator=(const TransferForm&& r) = delete;
private slots: 
	void addData();
	void changeCurrentIndex(int);
private:
	std::unique_ptr<Ui::TransferFormClass> ui;
	std::unique_ptr<QWidget> parent;
	std::unique_ptr<QSqlTableModel> model;
	std::unique_ptr<QMessageBox> msgBox;
	std::unique_ptr<QSqlQuery> query;
	QSqlQueryModel* qModel;
	QString company_id;
	void createModel();
	void createView();
	void createConnections();
	void getData(const QString&, const int&, QComboBox*, QComboBox* secondary=nullptr);
	void updateAccount();
	void checkQuery(const int&, const int&, const int&, const int&, const int&);
	void updateQuery(const int&, const int&);
};
