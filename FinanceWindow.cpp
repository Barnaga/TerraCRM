#include "FinanceWindow.h"

FinanceWindow::FinanceWindow(MainWindow* parent)
	: ui(std::make_unique<Ui::FinanceWindowClass>()), parent(dynamic_cast<MainWindow*>(parent)),
	model(std::make_unique<QSqlRelationalTableModel>()), view(std::make_unique <QTableView>())
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
}

FinanceWindow::~FinanceWindow()
{}
void FinanceWindow::createModel() {
	company_id = parent->getUser()[5];
	model->setTable("finance");
	model->setHeaderData(1, Qt::Horizontal, "Дата");
	model->setHeaderData(2, Qt::Horizontal, "Сумма");
	model->setHeaderData(3, Qt::Horizontal, "Плательщик");
	model->setHeaderData(4, Qt::Horizontal, "Получатель");
	model->setHeaderData(5, Qt::Horizontal, "Связи");
	model->setHeaderData(6, Qt::Horizontal, "Ответственный");
	model->setHeaderData(10, Qt::Horizontal, "Статья учета");
	model->setRelation(model->fieldIndex("payer"), QSqlRelation("companies", "id", "name"));
	model->setRelation(model->fieldIndex("recipient"), QSqlRelation("companies", "id", "name"));
	model->setRelation(model->fieldIndex("communication"), QSqlRelation("project", "id", "name"));
	model->setRelation(model->fieldIndex("responsible"), QSqlRelation("users", "id", "name"));
	model->setRelation(model->fieldIndex("category"), QSqlRelation("categories", "id", "name"));
	model->setRelation(model->fieldIndex("account"), QSqlRelation("accounts", "id", "name"));
	model->setRelation(model->fieldIndex("state"), QSqlRelation("\"articleEvent\"", "id", "article"));
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->setFilter(QString("payer =\'%1\' or recipient =\'%1\' ").arg(company_id));
	model->select();
}
void FinanceWindow::createView() {
	view->setEditTriggers(QAbstractItemView::NoEditTriggers); 
	view->setItemDelegateForColumn(1, new DateDelegate());
	view->setModel(model.get());
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(7, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	view->setColumnHidden(11, true);
	ui->financeLayout->addWidget(view.get());
}
void FinanceWindow::createConnections() {
	connect(ui->receiptBTn, SIGNAL(clicked()), this, SLOT(addProfitAmount()));
	connect(ui->spendingBTn, SIGNAL(clicked()), this, SLOT(addLossAmount()));
	connect(ui->transferBtn, SIGNAL(clicked()), this, SLOT(addTransfer()));
}

void FinanceWindow::addProfitAmount()
{
	qDebug() << company_id;
	auto profitForm = new FinanceForm(this, "Поступление", model.get(), "", company_id);
	profitForm->show();
}
void FinanceWindow::addLossAmount()
{
	auto lossForm = new FinanceForm(this, "Расход", model.get(), "-", company_id);
	lossForm->show();
}
void FinanceWindow::addTransfer()
{
	auto transferForm = new TransferForm(this, company_id);
	transferForm->show();
}
