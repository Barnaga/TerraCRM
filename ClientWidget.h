#pragma once

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QAbstractItemModel>
#include "ui_ClientWidget.h"

class ClientWidget : public QWidget
{
	Q_OBJECT

public:
	ClientWidget(QStringList data={});
	~ClientWidget();

private:
	Ui::ClientWidgetClass* ui;
	QStringList data;
	void createProjects(QString table, QTableView* view);
};
