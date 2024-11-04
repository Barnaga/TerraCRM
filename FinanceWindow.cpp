#include "FinanceWindow.h"

FinanceWindow::FinanceWindow(MainWindow *parent)
	: ui(new Ui::FinanceWindowClass), parent(dynamic_cast<MainWindow*>(parent)), model(new QSqlRelationalTableModel), view(new QTableView)
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
	getAccount();
}

FinanceWindow::~FinanceWindow()
{}
void FinanceWindow::createModel() {

	model->setTable("finance");
	model->setHeaderData(1, Qt::Horizontal, "Дата");
	model->setHeaderData(2, Qt::Horizontal, "Сумма");
	model->setHeaderData(3, Qt::Horizontal, "Контрагент");
	model->setHeaderData(4, Qt::Horizontal, "Организация");
	model->setHeaderData(5, Qt::Horizontal, "Статья учета");
	model->setHeaderData(6, Qt::Horizontal, "Связи");
	model->setHeaderData(7, Qt::Horizontal, "Ответственный");
	model->setRelation(model->fieldIndex("payer"), QSqlRelation("counterpars", "id", "name"));
	model->setRelation(model->fieldIndex("recipient"), QSqlRelation("counterpars", "id", "name"));
	model->setRelation(model->fieldIndex("communication"), QSqlRelation("project", "id", "name"));
	model->setRelation(model->fieldIndex("responsible"), QSqlRelation("users", "id", "name"));
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->select();
}
void FinanceWindow::createView() {
	view->setEditTriggers(QAbstractItemView::NoEditTriggers); 
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	view->setColumnHidden(10, true);
	ui->financeLayout->addWidget(view);

}
void FinanceWindow::createConnections() {
	connect(ui->receiptBTn, SIGNAL(clicked()), this, SLOT(addProfitAccount()));
	connect(ui->spendingBTn, SIGNAL(clicked()), this, SLOT(addLossAccount()));
	connect(ui->transferBtn, SIGNAL(clicked()), this, SLOT(addTransfer()));
}

void FinanceWindow::getAccount()
{
	auto profit = 0;
	auto loss = 0;
	for (int i = 0; i < model->rowCount(); ++i) {
		if (model->index(i, 2).data().toInt() < 0) 
			profit += model->index(i, 2).data().toInt();
		else
			loss -= model->index(i, 2).data().toInt();
	}
	ui->countLbl->setText(QString::number(profit-loss));
}

void FinanceWindow::addProfitAccount()
{
	auto profitForm = new FinanceForm(this, "Поступление", model);
	profitForm->show();
}
void FinanceWindow::addLossAccount()
{
	auto lossForm = new FinanceForm(this, "Расход", model, "-");
	lossForm->show();
}
void FinanceWindow::addTransfer()
{
	auto transferForm = new TransferForm(this);
	transferForm->show();
}
