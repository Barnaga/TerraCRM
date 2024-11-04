#pragma once

#include <QDialog>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDate>
#include <QSqlError>
#include "ui_ProjectWidget.h"
#include "ChangeStatusProjectDialog.h"
#include "FormTask.h"
#include <MainWindow.h>

class ProjectWidget : public QDialog
{
	Q_OBJECT

public:
	ProjectWidget(QWidget *parent = nullptr, QList<QString> data={}, QSqlRelationalTableModel* model=nullptr, QModelIndex index={}, int id=-1);
	~ProjectWidget();
private slots:
	void updateStatus();
	void saveIndex(int);
	void completeProject();
private:

	Ui::ProjectWidgetClass ui;
	QSqlRelationalTableModel* model;
	QList<QString> data;
	QModelIndex index;
	QSqlQuery query;
	int id;
	int temp;
	int currentIndex;
	void createConnections();
	void getClient();
	void getStatus();
};
