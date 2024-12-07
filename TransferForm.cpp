#include "TransferForm.h"

TransferForm::TransferForm(QWidget* parent, const QString& company_id)
	: QDialog(parent), ui(new Ui::TransferFormClass), model(new QSqlTableModel), company_id(company_id)
{
	ui->setupUi(this);
	query = new QSqlQuery;
	createModel();
	createView();
	createConnections();

}
void TransferForm::createView()
{
	ui->date->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));
	getData("accounts", 2, ui->fromAccountBox, ui->toAccountBox);
	getData("users", 5, ui->responsibleBox);
	getData("\"articleEvent\"", 1, ui->stateBox);
	msgBox = new QMessageBox;
}
void TransferForm::createConnections()
{
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
	if (table.compare("\"articleEvent\"")==0) {
		query->prepare("SELECT * FROM " + table);
	}
	else {
		query->prepare("SELECT * FROM " + table + " where company_id=:company_id");
		query->bindValue(":company_id", company_id);
	}
	query->exec();
	auto qModel = new QSqlQueryModel;
	qModel->setQuery(*query);
	main->setModel(qModel);
	main->setModelColumn(column);
	if (secondary != nullptr) {
		secondary->setModel(qModel);
		secondary->setModelColumn(column);
		secondary->setCurrentIndex(main->currentIndex() + 1);
	}
}
void TransferForm::updateAccount()
{	
	auto currentBalance = ui->cash->text().toInt();
	auto fromId = ui->fromAccountBox->model()->index(ui->fromAccountBox->currentIndex(), 0).data().toInt();
	auto toId = ui->toAccountBox->model()->index(ui->toAccountBox->currentIndex(), 0).data().toInt();
	auto fromCash = ui->fromAccountBox->model()->index(ui->fromAccountBox->currentIndex(), 3).data().toInt();
	auto toCash = ui->toAccountBox->model()->index(ui->toAccountBox->currentIndex(), 3).data().toInt();
	updateQuery(fromCash, toCash, currentBalance, fromId, toId);
}
void TransferForm::updateQuery(const int& fromCash, const int& toCash, const int& currentBalance, const int& fromId, const int& toId)
{
	int changeCash, changePayment;
	if (currentBalance < 0) {
		msgBox->setText("Введено отрицательное число");
		msgBox->exec();
	}
	else if (currentBalance > fromCash) {
		msgBox->setText("Не хватает средств для трансфера");
		msgBox->exec();
	}
	else if (currentBalance > 0 and currentBalance<= fromCash) {
		changeCash = fromCash - currentBalance;
		changePayment = toCash + currentBalance;
		changeQuery(changeCash, fromId);
		changeQuery(changePayment, toId);
	}		
}
void TransferForm::changeQuery(const int& changeCash, const int& id)
{
	query->prepare("UPDATE accounts SET balance=:balance where id=:id");
	query->bindValue(":balance", changeCash);
	query->bindValue(":id", id);
	query->exec();
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
	model->submitAll();
	model->select();
	updateAccount();
}

void TransferForm::changeCurrentIndex(int index)
{
	ui->fromAccountBox->currentIndex() == 1?
		ui->toAccountBox->setCurrentIndex(index - 1):
		ui->toAccountBox->setCurrentIndex(index + 1);
}
