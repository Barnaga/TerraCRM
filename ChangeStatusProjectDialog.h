#pragma once

#include <QDialog>
#include <QDate>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include "ui_ChangeStatusProjectDialog.h"

class ChangeStatusProjectDialog : public QDialog
{
	Q_OBJECT

public:
	ChangeStatusProjectDialog(QWidget *parent = nullptr, QSqlTableModel* model= nullptr, QModelIndex index={});
	~ChangeStatusProjectDialog();
private slots:
	void updateStatus();
private:
	Ui::ChangeStatusProjectDialogClass ui;
	QSqlTableModel* model;
	QModelIndex index;
	QString currentDate;
};
