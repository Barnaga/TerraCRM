#include "FinanceWindow.h"

FinanceWindow::FinanceWindow(MainWindow* parent)
	: ui(new Ui::FinanceWindowClass), parent(dynamic_cast<MainWindow*>(parent)), model(new QSqlRelationalTableModel), view(new QTableView)
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
}

FinanceWindow::~FinanceWindow()
{}
void FinanceWindow::createModel() {
	model->setTable("finance");
	model->setHeaderData(1, Qt::Horizontal, "Дата");
	model->setHeaderData(2, Qt::Horizontal, "Сумма");
	model->setHeaderData(3, Qt::Horizontal, "Контрагент");
	model->setHeaderData(4, Qt::Horizontal, "Организация");
	model->setHeaderData(5, Qt::Horizontal, "Связи");
	model->setHeaderData(6, Qt::Horizontal, "Ответственный");
	model->setHeaderData(10, Qt::Horizontal, "Статья учета");
	model->setRelation(model->fieldIndex("payer"), QSqlRelation("counterpars", "id", "name"));
	model->setRelation(model->fieldIndex("recipient"), QSqlRelation("counterpars", "id", "name"));
	model->setRelation(model->fieldIndex("communication"), QSqlRelation("project", "id", "name"));
	model->setRelation(model->fieldIndex("responsible"), QSqlRelation("users", "id", "name"));
	model->setRelation(model->fieldIndex("category"), QSqlRelation("categories", "id", "name"));
	model->setRelation(model->fieldIndex("account"), QSqlRelation("accounts", "id", "name"));
	model->setRelation(model->fieldIndex("state"), QSqlRelation("\"articleEvent\"", "id", "article"));
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->select();
}
void FinanceWindow::createView() {
	view->setEditTriggers(QAbstractItemView::NoEditTriggers); 
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(7, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	ui->financeLayout->addWidget(view);
}
void FinanceWindow::createConnections() {
	connect(ui->receiptBTn, SIGNAL(clicked()), this, SLOT(addProfitAmount()));
	connect(ui->spendingBTn, SIGNAL(clicked()), this, SLOT(addLossAmount()));
	connect(ui->transferBtn, SIGNAL(clicked()), this, SLOT(addTransfer()));
}

void FinanceWindow::addProfitAmount()
{
	auto profitForm = new FinanceForm(this, "Поступление", model);
	profitForm->show();
}
void FinanceWindow::addLossAmount()
{
	auto lossForm = new FinanceForm(this, "Расход", model, "-");
	lossForm->show();
}
void FinanceWindow::addTransfer()
{
	auto transferForm = new TransferForm(this);
	transferForm->show();
}
