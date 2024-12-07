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
	explicit ProjectWidget(QWidget *parent = nullptr, QStringList data={}, QSqlRelationalTableModel* model= nullptr, const QModelIndex& index={});
	ProjectWidget(ProjectWidget& r) = delete;
	ProjectWidget(ProjectWidget&& r) = delete;
	ProjectWidget& operator=(const ProjectWidget& r) = delete;
	ProjectWidget& operator=(const ProjectWidget&& r) = delete;
	~ProjectWidget();
private slots:
	void updateStatus();
	void addDebit();
	void saveIndex(int);
	void completeProject();
private:
	Ui::ProjectWidgetClass* ui;
	QSqlRelationalTableModel* model;
	QSqlQuery* query;
	QStringList data;
	const QModelIndex index;
	int tempIndex;
	int currentIndex;
	void createConnections();
	void getClient();
	void getStatus();
	void createView();
	void isDeadline();
	void addCash(int);
	QString getPaymentAccount();
	QString getResponsible();
};
