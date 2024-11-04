#pragma once

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include "ui_FinanceForm.h"

class FinanceForm : public QDialog
{
	Q_OBJECT

public:
	FinanceForm(QWidget *parent = nullptr, const QString& lbl="", QSqlRelationalTableModel* model= nullptr, QString sign="");
	~FinanceForm();
	FinanceForm(FinanceForm& r) = delete;
	FinanceForm(FinanceForm&& r) = delete;
	FinanceForm& operator=(const FinanceForm& r) = delete;
	FinanceForm& operator=(const FinanceForm&& r) = delete;
private slots:
	void addData();
private:
	Ui::FinanceFormClass* ui;
	QSqlRelationalTableModel* model;
	const QString& lbl;
	QSqlQuery query;
	QString sign;
	void getData(const QString&, const int&, QComboBox*);


};
