#pragma once
#include <QSqlTableModel>
#include <QDialog>
#include "ui_DealWidget.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
class DealWidget : public QDialog
{
	Q_OBJECT

public:
	explicit DealWidget(QWidget* parent = nullptr, QSqlTableModel* model=nullptr, QStringList data = {}, const QModelIndex& index = {});
	~DealWidget();
private slots:
	void updateStatus(int);
private:
	Ui::DealWidgetClass* ui;
	QSqlTableModel* model;
	const QModelIndex index;
	QStringList data;
	QString id;
	int idProject;
	int currentIndex;
	void getClient();
	void getStatus();	
};
