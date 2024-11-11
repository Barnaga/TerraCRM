#pragma once

#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include<QDateTime>
#include "ui_TransferForm.h"

class TransferForm : public QDialog
{
	Q_OBJECT

public:
	TransferForm(QWidget *parent = nullptr);
	~TransferForm();
	TransferForm(TransferForm& r) = delete;
	TransferForm(TransferForm&& r) = delete;
	TransferForm& operator=(const TransferForm& r) = delete;
	TransferForm& operator=(const TransferForm&& r) = delete;
private slots: 
	void addData();
	void changeCurrentIndex(int);
private:
	Ui::TransferFormClass* ui;
	QSqlTableModel* model;
	QSqlQuery query;
	void createModel();
	void getData(const QString& table, const int& column, QComboBox* main, QComboBox* secondary=nullptr);
	void updateAccount();
	int getBalance(const int& id);
	void updateQuery(const int& cash, const int& balance, const int& id, bool flag);
};
