#include "FinanceForm.h"

FinanceForm::FinanceForm(QWidget* parent, const QString& lbl, QSqlRelationalTableModel* model, const QString& sign)
	: QDialog(parent), ui(new Ui::FinanceFormClass), model(model), lbl(lbl), sign(sign)
{
	ui->setupUi(this);
	ui->warningLbl->hide();
	ui->name->setText(lbl);
	ui->date->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));
	getData("counterpars", 1, ui->payerBox);
	getData("users", 5, ui->responsibleBox);
	getData("project", 1, ui->communicationBox);
	getData("counterpars", 1, ui->recipientBox);
	getData("categories", 1, ui->categoryBox);
	getData("accounts", 2, ui->orgAccountBox);
	getData("\"articleEvent\"", 1, ui->stateBox);
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(addData()));
}

FinanceForm::~FinanceForm()
{}

void FinanceForm::addData()
{
	const auto& row = model->rowCount();
	int cash;
	if (model->insertRow(row)) {
		if (sign == "-") {
			cash = -ui->cash->text().toInt();
		}
		else cash = ui->cash->text().toInt();
		const auto& date = QDateTime::currentDateTime().toString("yyyy-MM-dd");
		const auto& account = ui->orgAccountBox->model()->index(ui->orgAccountBox->currentIndex(), 0).data().toInt();
		const auto& state = ui->stateBox->model()->index(ui->stateBox->currentIndex(), 0).data().toInt();
		const auto& payer = ui->payerBox->model()->index(ui->payerBox->currentIndex(), 0).data().toInt();
		const auto& recipient = ui->recipientBox->model()->index(ui->recipientBox->currentIndex(), 0).data().toInt();
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
	}
	else ui->warningLbl->setEnabled(true);

	model->submitAll();
	model->select();
}

void FinanceForm::getData(const QString& table, const int& column, QComboBox* box)
{
	query.prepare("SELECT * FROM " + table);
	if (query.exec()) {
		QSqlQueryModel* qModel = new QSqlQueryModel(this);
		qModel->setQuery(query);
		box->setModel(qModel);
		box->setModelColumn(column);
	}
}

