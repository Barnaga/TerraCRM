#include "TransferForm.h"

TransferForm::TransferForm(QWidget* parent)
	: QDialog(parent), ui(new Ui::TransferFormClass), model(new QSqlTableModel)
{
	ui->setupUi(this);
	ui->date->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));
	createModel();
	getData("accounts", 2, ui->fromAccountBox, ui->toAccountBox);
	getData("users", 5, ui->responsibleBox);
	//getData("accounts", 2, ui->toAccountBox);
	getData("\"articleEvent\"", 1, ui->stateBox);
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(addData()));
	connect(ui->fromAccountBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeCurrentIndex(int)));
}
void TransferForm::createModel() {
	model->setTable("transfers");
	model->setHeaderData(1, Qt::Horizontal, "Дата");
	model->setHeaderData(2, Qt::Horizontal, "Сумма");
	model->setHeaderData(3, Qt::Horizontal, "Ответственный");
	model->setHeaderData(4, Qt::Horizontal, "Откуда");
	model->setHeaderData(5, Qt::Horizontal, "Куда");
	model->setHeaderData(6, Qt::Horizontal, "Статья");
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->select();
	
}
TransferForm::~TransferForm()
{}

void TransferForm::getData(const QString& table, const int& column, QComboBox* main, QComboBox* secondary)
{
	query.prepare("SELECT * FROM " + table);
	if (query.exec()) {
		QSqlQueryModel* qModel = new QSqlQueryModel(this);
		qModel->setQuery(query);
		main->setModel(qModel);
		main->setModelColumn(column);
		if (secondary != nullptr) {
			secondary->setModel(qModel);
			secondary->setModelColumn(column);
			secondary->setCurrentIndex(main->currentIndex() + 1);
		}
	}
}
void TransferForm::updateAccount()
{	
	auto balance = ui->cash->text().toInt();
	auto toid = ui->toAccountBox->model()->index(ui->toAccountBox->currentIndex(), 0).data().toInt(); 
	auto fromid = ui->fromAccountBox->model()->index(ui->fromAccountBox->currentIndex(), 0).data().toInt();
	auto cash=getBalance(fromid);
	auto payment= getBalance(toid);
	updateQuery(balance, cash, fromid, true);
	updateQuery(balance, payment, toid, false);

}
int TransferForm::getBalance(const int& id)
{
	QSqlQuery q;
	q.prepare("Select balance from accounts where id=:id");
	q.bindValue(":id", id);
	q.exec();
	q.first();
	return q.value(0).toInt();
}
void TransferForm::updateQuery(const int& balance, const int& cash, const int& id, bool flag)
{
	int sum;
	if (flag) {
		sum = cash - balance;
	}
	else sum= cash + balance;
	QSqlQuery query;
	query.prepare("UPDATE accounts SET balance=:balance where id=:id");
	query.bindValue(":balance", sum);
	query.bindValue(":id", id);
	query.exec();
}
void TransferForm::addData()
{
	const auto& row = model->rowCount();
	if (model->insertRow(row)) {
		const int& cash = ui->cash->text().toInt();
		const auto& date = QDateTime::currentDateTime().toString("yyyy-MM-dd");
		const auto& fromAccount = ui->fromAccountBox->model()->index(ui->fromAccountBox->currentIndex(), 0).data().toInt();
		const auto& state = ui->stateBox->model()->index(ui->stateBox->currentIndex(), 0).data().toInt();
		const auto& toAccount = ui->toAccountBox->model()->index(ui->toAccountBox->currentIndex(), 0).data().toInt();
		const auto& responsible = ui->responsibleBox->model()->index(ui->responsibleBox->currentIndex(), 0).data().toInt();

		model->setData(model->index(row, 1), date);
		model->setData(model->index(row, 2), cash);	
		model->setData(model->index(row, 3), responsible);
		model->setData(model->index(row, 4), fromAccount);
		model->setData(model->index(row, 5), toAccount);
		model->setData(model->index(row, 6), state);
	
	}
	//for (auto i = 0; i < model->rowCount(); ++i) {
	//	qDebug() << model->index(row, i).data();
	//}
	model->submitAll();
	model->select();
	updateAccount();
	qDebug() << model->lastError();
}

void TransferForm::changeCurrentIndex(int index)
{
	ui->fromAccountBox->currentIndex() == 1?
		ui->toAccountBox->setCurrentIndex(index - 1):
		ui->toAccountBox->setCurrentIndex(index + 1);
}
