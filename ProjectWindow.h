#pragma once


#include "MainWindow.h"
#include "ProjectWidget.h"
#include "createProjectDialog.h"
#include <QSqlRelationalTableModel>
#include "ui_ProjectWindow.h"

class ProjectWindow : public QWidget
{
	Q_OBJECT

public:
	explicit ProjectWindow(MainWindow* parent = nullptr);
	~ProjectWindow();
private slots:
	void openProject(const QModelIndex index);
	void createProject();
private:
	Ui::ProjectWindowClass* ui;

	MainWindow* parent;
	QTableView* view;
	QSqlRelationalTableModel* model;
	ProjectWidget* project;
	void createModel();
	void createView();
	void createConnections();
};
