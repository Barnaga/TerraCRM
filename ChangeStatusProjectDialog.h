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
	explicit ChangeStatusProjectDialog(QWidget* parent = nullptr, QSqlTableModel* model = nullptr, const QModelIndex& index = {});
	~ChangeStatusProjectDialog();
private slots:
	void updateStatus();
private:
	Ui::ChangeStatusProjectDialogClass* ui;
	QSqlTableModel* model;
	const QModelIndex index;
	QString currentDate;
};
