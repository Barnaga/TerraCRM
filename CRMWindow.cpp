#include "CRMWindow.h"
CRMWindow::CRMWindow(QWidget* parent) 
	: ui(new Ui::CRMWindowClass), parent(dynamic_cast<MainWindow*>(parent)),
	model(new QSqlRelationalTableModel), view(new QTableView)
{
	ui->setupUi(this);
	createModel();
	createView();
	connect(view, SIGNAL(clicked(const QModelIndex&)), this, SLOT(openDeal(const QModelIndex&)));
	ui->dateLbl->setText("Сегодня " + QDateTime::currentDateTime().toString("dd.MM.yyyy"));
}
void CRMWindow::createModel() {
	model->setTable("deals");
	model->setHeaderData(0, Qt::Horizontal, "id");
	model->setHeaderData(1, Qt::Horizontal, "Название сделки");
	model->setHeaderData(2, Qt::Horizontal, "Стоимость");
	model->setHeaderData(3, Qt::Horizontal, "Начало");
	model->setHeaderData(4, Qt::Horizontal, "Конец");
	model->setHeaderData(5, Qt::Horizontal, "Статус");
	model->setHeaderData(6, Qt::Horizontal, "Источник сделки");
	model->setHeaderData(7, Qt::Horizontal, "Ответственный");
	model->setRelation(model->fieldIndex("company"), QSqlRelation("companies", "id", "name"));
	model->setRelation(model->fieldIndex("responsible"), QSqlRelation("users", "id", "name"));
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->setFilter(QString("deals.company_id=\'%1\'").arg(parent->getUser()[5]));
	model->select();
}

void CRMWindow::createView() {
	view->setItemDelegateForColumn(5, new StatusDelegate(view));
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	view->setColumnHidden(10, true);
	ui->crmLayout->addWidget(view);
}
CRMWindow::~CRMWindow()
{
	delete ui;
	delete model;
	delete view;

}

void CRMWindow::openDeal(const QModelIndex& index) {
	QStringList data;
	for (auto i = 0; i < index.model()->columnCount(); ++i)
		data.append(index.model()->index(index.row(), i).data().toString());
	auto deal = new DealWidget(this, model, data, index);
	deal->show();
	data.clear();
}