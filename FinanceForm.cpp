#include "FinanceForm.h"

FinanceForm::FinanceForm(QWidget* parent, const QString& lbl, QSqlRelationalTableModel* model, const QString& sign, const QString& company_id)
	: QDialog(parent), ui(std::make_unique<Ui::FinanceFormClass>()),
	model(model), lbl(lbl), sign(sign), company_id(company_id.toInt())
{
	ui->setupUi(this);
	query = std::make_unique<QSqlQuery>();
	msgBox = std::make_unique <QMessageBox>();
	createView(lbl);
	createConnections();
}

void FinanceForm::createConnections()
{
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(addData()));
	connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
	connect(ui->payerBox, SIGNAL(currentIndexChanged(int)), this, SLOT(getDataSecondary()));
	connect(ui->recipientBox, SIGNAL(currentIndexChanged(int)), this, SLOT(getDataSecondary()));
}

void FinanceForm::createView(const QString& lbl)
{
	ui->warningLbl->hide();
	ui->name->setText(lbl);
	ui->date->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));
	getData("companies", 1, ui->recipientBox, ui->communicationBox);
	getData("users", 5, ui->responsibleBox);
	getData("categories", 1, ui->categoryBox);
	getData("accounts", 2, ui->orgAccountBox);
	getData("\"articleEvent\"", 1, ui->stateBox);
	getData("companies", 1, ui->payerBox);
}

FinanceForm::~FinanceForm()
{}

void FinanceForm::addData()
{
	auto currentMoney = ui->orgAccountBox->model()->index(ui->orgAccountBox->currentIndex(), 3).data().toInt();
	const auto& row = model->rowCount();
	auto cash = ui->cash->text().toInt();
	if (model->insertRow(row) and model!=nullptr) {
		if (cash > currentMoney) {
			msgBox->setText("Не хватает средств");
			msgBox->exec();
		}
		else {
			if (sign == "-") 
				cash = -ui->cash->text().toInt();	
			else cash = ui->cash->text().toInt();
			const auto& date = QDateTime::currentDateTime().toString("yyyy-MM-dd");			
			const auto& state = ui->stateBox->model()->index(ui->stateBox->currentIndex(), 0).data().toInt();
			const auto& payer = ui->payerBox->model()->index(ui->payerBox->currentIndex(), 0).data().toInt();
			const auto& recipient = ui->recipientBox->model()->index(ui->recipientBox->currentIndex(), 0).data().toInt();
			const auto& account = ui->orgAccountBox->model()->index(ui->orgAccountBox->currentIndex(), 0).data().toInt();
			const auto& responsible = ui->responsibleBox->model()->index(ui->responsibleBox->currentIndex(), 0).data().toInt();
			const auto& category = ui->categoryBox->model()->index(ui->categoryBox->currentIndex(), 0).data().toInt();
			const auto& note = ui->note->text();
			const auto& communication = ui->communicationBox->model()->index(ui->communicationBox->currentIndex(), 0).data().toInt();
			model->setData(model->index(row, 1), date);
			model->setData(model->index(row, 2), cash);
			model->setData(model->index(row, 3), payer);
			model->setData(model->index(row, 4), recipient);
			model->setData(model->index(row, 5), communication);
			model->setData(model->index(row, 6), responsible);
			model->setData(model->index(row, 7), note);
			model->setData(model->index(row, 8), category);
			model->setData(model->index(row, 9), account);
			model->setData(model->index(row, 10), state);
			model->setData(model->index(row, 11), company_id);
		}
	}
	else ui->warningLbl->setEnabled(true);
	if (model->submit()and model->select()) {
		updateAccount(cash);
	}
	else return;
}
void FinanceForm::updateAccount(const int& cash)
{
	auto fromCash = ui->orgAccountBox->model()->index(ui->orgAccountBox->currentIndex(), 3).data().toInt();
	auto changeCash = fromCash + cash;
	updateQuery(changeCash, ui->orgAccountBox->model()->index(ui->orgAccountBox->currentIndex(), 0).data().toInt());
}
void FinanceForm::updateQuery(const int& changeCash, const int& account)
{
	query->prepare("UPDATE accounts SET balance=:balance where id=:id");
	query->bindValue(":balance", changeCash);
	query->bindValue(":id", account);
	query->exec();
}
void FinanceForm::getData(const QString& table, const int& column, QComboBox* main, QComboBox* secondary)
{
	query->prepare("SELECT * FROM " + table);
	if (query->exec()) {	
		auto qModel = new QSqlQueryModel;
		qModel->setQuery(*query);
		main->setModel(qModel);
		main->setModelColumn(column);
		if (secondary != nullptr)
			getDataSecondary();
		else return;
	}
}

void FinanceForm::getDataSecondary()
{
	int	id = ui->recipientBox->model()->index(ui->recipientBox->currentIndex(), 0).data().toInt();
	query->prepare("SELECT * FROM project where company_id = :id");
	query->bindValue(":id", id);
	query->exec();
	auto qModel = new QSqlQueryModel;
	qModel->setQuery(*query);
	ui->communicationBox->setModel(qModel);
	ui->communicationBox->setModelColumn(1);
}

