#include "CRMWindow.h"
CRMWindow::CRMWindow(QWidget* parent) 
	: parent(dynamic_cast<MainWindow*>(parent)),
	ui(new Ui::CRMWindowClass),
	model(new QSqlTableModel)
{
	ui->setupUi(this);
	createModel();
	createView();
}
void CRMWindow::createModel() {
	model->setTable("deals");
	model->setHeaderData(0, Qt::Horizontal, "id");
	model->setHeaderData(1, Qt::Horizontal, "Название сделки");
	model->setHeaderData(2, Qt::Horizontal, "Компания");
	model->setHeaderData(3, Qt::Horizontal, "Стоимость");
	model->setHeaderData(4, Qt::Horizontal, "Начало");
	model->setHeaderData(5, Qt::Horizontal, "Конец");
	model->setHeaderData(6, Qt::Horizontal, "Статус");
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->select();
}

void CRMWindow::createView() {
	view = new QTableView(this);
	view->setItemDelegateForColumn(6, new StatusDelegate(view));
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	ui->crmLayout->addWidget(view);
}
CRMWindow::~CRMWindow()
{}
