#pragma once

#include <QDialog>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
#include <QSqlError>
#include "ui_ProjectWidget.h"
#include "ChangeStatusProjectDialog.h"

class ProjectWidget : public QDialog
{
	Q_OBJECT

public:
	ProjectWidget(QWidget *parent = nullptr, QVector<QString> data={}, QSqlRelationalTableModel* model=nullptr, QModelIndex index={});
	~ProjectWidget();
private slots:
	void updateStatus();
	void saveIndex(int);
	void completeProject();
private:
	Ui::ProjectWidgetClass ui;
	QSqlTableModel* model;
	QVector<QString> data;
	QModelIndex index;
	QSqlQuery query;
	QString id;
	int temp;
	int currentIndex;
	void getClient();
	void getStatus();
};
