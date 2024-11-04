#pragma once
#include <QSqlTableModel>
#include <QDialog>
#include "ui_DealWidget.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
class DealWidget : public QDialog
{
	Q_OBJECT

public:
	explicit DealWidget(QWidget* parent = nullptr, QSqlTableModel* model = nullptr, QList<QString> data = {}, const QModelIndex& index = {});
	~DealWidget();
private slots:
	void updateStatus(int);
private:
	Ui::DealWidgetClass ui;

	QSqlTableModel* model;
	const QModelIndex& index;
	QSqlQuery query;
	QList<QString> data;
	QString id;
	int idProject;
	int currentIndex;

	void getClient();
	void getAgent(QString id);
	void getStatus();
	
};
