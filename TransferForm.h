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
	QWidget* parent;
	QSqlTableModel* model;
	QMessageBox* msgBox;
	QSqlQuery* query;
	void createModel();
	void createView();
	void createConnections();
	void getData(const QString& table, const int& column, QComboBox* main, QComboBox* secondary=nullptr);
	void updateAccount();
	void updateQuery(const int& fromCash, const int& toCash, const int& currentBalance, const int& fromId, const int& toId);
	void changeQuery(const int& changeCash, const int& id);
};
