#pragma once

#include <QWidget>
#include "MainWindow.h"
#include "ui_TeamWindow.h"

class TeamWindow : public QWidget
{
	Q_OBJECT

public:
	explicit TeamWindow(MainWindow *parent = nullptr);
	~TeamWindow();
	TeamWindow(TeamWindow& r) = delete;
	TeamWindow(TeamWindow&& r) = delete;
	TeamWindow& operator=(const TeamWindow& r) = delete;
	TeamWindow& operator=(const TeamWindow&& r) = delete;

private:
	Ui::TeamWindowClass* ui;
	MainWindow* parent;
	QSqlTableModel* model;
	QTableView* view;
	void createModel();
	void createView();
	void createConnections();
};
