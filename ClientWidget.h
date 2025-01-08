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
	std::unique_ptr<Ui::ClientWidgetClass> ui;
	QStringList data;
	void createProjects(QString, QTableView*);
};
