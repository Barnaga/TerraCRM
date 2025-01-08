#pragma once

#include <QWidget>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QTableView>
#include "ui_CompanyWidget.h"

class CompanyWidget : public QWidget
{
	Q_OBJECT

public:
	CompanyWidget( QStringList data = {});
	~CompanyWidget();

private:
	std::unique_ptr<Ui::CompanyWidgetClass> ui;
	QStringList data;
	void createProjects(QString table, QString field, QTableView* view);
};
