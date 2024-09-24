#pragma once
#include <QSqlTableModel>
#include <QDialog>
#include "ui_DealWidget.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QDate>
class DealWidget : public QDialog
{
	Q_OBJECT

public:
	DealWidget(QWidget* parent = nullptr, QSqlTableModel* model = nullptr, QVector<QString> data = {}, QModelIndex index={});
	~DealWidget();
private slots:
	void updateStatus(int temp);
private:
	Ui::DealWidgetClass ui;

	QSqlTableModel* model;
	QVector<QString> data;
	QString id;
	int idProject;
	int currentIndex;
	QModelIndex index;
	QSqlQuery query;
	void getClient();
	void getAgent(QString id);
	void getStatus();
	
};
