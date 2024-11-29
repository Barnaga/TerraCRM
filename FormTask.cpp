#include "FormTask.h"

FormTask::FormTask(QWidget* parent, QSqlRelationalTableModel* model, int id)
	: QDialog(parent), ui(new Ui::FormTaskClass), model(model), id(id), query(new QSqlQuery)
{
	ui->setupUi(this);
	ui->warningLbl->hide();
	createDataComboBox();
	createConnections();
}
void FormTask::createConnections()
{
	connect(ui->projectBox, SIGNAL(activated(int)), this, SLOT(getProjects()));
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(accept()));
	connect(ui->saveCreateBtn, SIGNAL(clicked()), this, SLOT(addData()));
	connect(this, SIGNAL(accepted()), this, SLOT(addData()));
	connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(reject()));
}
void FormTask::addData()
{
	const auto& name = ui->nameTaskEdit->text();
	const auto& status = "Сделать";
	const auto& creator = id;
	const auto& date = QDateTime::currentDateTime().toString("yyyy-MM-dd");
	const auto& priority = ui->priority->currentText();
	const auto& deadline = ui->deadline->selectedDate();
	const auto& project = query->value(idProject);
	const auto& row = model->rowCount();
	
	if (!name.isEmpty() and model->insertRow(row)) {
		model->setData(model->index(row, 1), name);
		model->setData(model->index(row, 2), status);
		model->setData(model->index(row, 3), creator);
		model->setData(model->index(row, 4), creator);
		model->setData(model->index(row, 5), date);
		model->setData(model->index(row, 6), priority);
		model->setData(model->index(row, 7), date);
		model->setData(model->index(row, 8), deadline);
		model->setData(model->index(row, 10), project);
	}
	else ui->warningLbl->setEnabled(true);

	model->submitAll();
	model->select();
}
FormTask::~FormTask()
{}
void FormTask::createDataComboBox() {
	query->prepare("SELECT * FROM project");
	query->exec();
	auto* qModel = new QSqlQueryModel;
	qModel->setQuery(*query);
	ui->projectBox->setModel(qModel);
	ui->projectBox->setModelColumn(1);
}
void FormTask::getProjects()
{
	idProject = query->record().indexOf("id");
}
