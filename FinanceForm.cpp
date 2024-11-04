#include "FinanceForm.h"

FinanceForm::FinanceForm(QWidget *parent, const QString& lbl, QSqlRelationalTableModel* model, QString sign)
	: QDialog(parent), ui(new Ui::FinanceFormClass), model(model), lbl(lbl), sign(sign)
{
	ui->setupUi(this);
	ui->name->setText(lbl);
	ui->date->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));
	getData("counterpars", 1, ui->payerBox);
	getData("users", 5, ui->responsibleBox);
	getData("project", 1, ui->communicationBox);
	getData("counterpars", 1, ui->recipientBox);
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(this, SIGNAL(accepted()), this, SLOT(addData()));
}

FinanceForm::~FinanceForm()
{
	delete ui;
}

void FinanceForm::addData()
{
	const QString& cash = sign+ui->cash->text();

	const auto& date = ui->date->text();
	const auto& account = ui->orgAccountBox->model()->index(ui->orgAccountBox->currentIndex(), 0).data().toString();
	const auto& state = ui->stateBox->currentText();
	const auto& payer = ui->payerBox->model()->index(ui->payerBox->currentIndex(), 0).data().toString();
	const auto& recipient = ui->recipientBox->model()->index(ui->recipientBox->currentIndex(), 0).data().toString();
	const auto& responsible = ui->responsibleBox->model()->index(ui->responsibleBox->currentIndex(), 0).data().toString();
	const auto& category = ui->categoryBox->currentText();
	const auto& note = ui->note->text();
	const auto& communication = ui->communicationBox->model()->index(ui->communicationBox->currentIndex(), 0).data().toString();
	const auto& row = model->rowCount();
	if (model->insertRow(row)) {
		model->setData(model->index(row, 1), date);
			
		model->setData(model->index(row, 2), cash);
		model->setData(model->index(row, 3), payer);
		model->setData(model->index(row, 4), recipient);
		model->setData(model->index(row, 5), category);
		model->setData(model->index(row, 6), communication);
		model->setData(model->index(row, 7), responsible);
		model->setData(model->index(row, 8), note);
		model->setData(model->index(row, 9), state);
		model->setData(model->index(row, 10), account);
	}
	else ui->warningLbl->setEnabled(true);
	qDebug() << model->index(row, 2).data();
	/*
	for (int i = 0; i < 11; ++i) {
		qDebug() << model->index(row, i).data();
	}*/
	//model->submitAll();
	//model->select();
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

