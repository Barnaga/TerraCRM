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
	void openProject(const QModelIndex&);
	void createProject();
private:
	std::unique_ptr<Ui::ProjectWindowClass> ui;
	MainWindow* parent;
	std::unique_ptr<QTableView> view;
	std::unique_ptr<QSqlRelationalTableModel> model;
	std::unique_ptr<ProjectWidget> project;
	std::unique_ptr<createProjectDialog> createProjectWindow;
	QStringList data;
	void createModel();
	void createView();
	void createConnections();
};
