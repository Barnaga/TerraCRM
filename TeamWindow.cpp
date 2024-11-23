#include "TeamWindow.h"

TeamWindow::TeamWindow(MainWindow *parent)
	:  ui(new Ui::TeamWindowClass), parent(dynamic_cast<MainWindow*>(parent)),
	model(new QSqlTableModel), view(new QTableView)
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
}

TeamWindow::~TeamWindow()
{}

void TeamWindow::createModel()
{
	model->setTable("users");
	model->setHeaderData(4, Qt::Horizontal, "Роль");
	model->setHeaderData(5, Qt::Horizontal, "Имя");
	model->setHeaderData(6, Qt::Horizontal, "Фамилия");
	model->setHeaderData(7, Qt::Horizontal, "Email");
	model->setHeaderData(8, Qt::Horizontal, "Номер");
	model->select();
}

void TeamWindow::createView()
{
	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(1, true);
	view->setColumnHidden(2, true);
	view->setColumnHidden(3, true);
	ui->teamLayout->addWidget(view);
}

void TeamWindow::createConnections()
{
}
