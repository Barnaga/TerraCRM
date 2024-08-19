#include "FormTask.h"

FormTask::FormTask(QWidget* parent, QSqlRelationalTableModel* model, int id)
	: QDialog(parent), ui(new Ui::FormTaskClass), model(model), id(id)
{
	ui->setupUi(this);
	ui->warningLbl->hide();
	createDataComboBox();
	connect(ui->projectBox, SIGNAL(activated(int)), this, SLOT(getProjects(int)));
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(accept()));
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
	const auto& project = query.value(idProject);
	const auto& row = model->rowCount();
	
	if (!name.isEmpty() and model->insertRow(row)) {
		model->setData(model->index(row, 1), name);
		model->setData(model->index(row, 2), status);
		model->setData(model->index(row, 3), creator);
		model->setData(model->index(row, 4), creator);
		model->setData(model->index(row, 5), date);
		model->setData(model->index(row, 7), priority);
		model->setData(model->index(row, 8), date);
		model->setData(model->index(row, 9), deadline);
		model->setData(model->index(row, 11), project);
	/*	for (auto i = 0; i < model->columnCount(); ++i) {
			qDebug() << model->index(row, i).data().toString();
		}*/
	}	
	else ui->warningLbl->setEnabled(true);
}
FormTask::~FormTask()
{}
void FormTask::createDataComboBox() {
	query.prepare("SELECT * FROM project");
	query.exec();
	QSqlQueryModel* model = new QSqlQueryModel(this);
	model->setQuery(query);
	ui->projectBox->setModel(model);
	ui->projectBox->setModelColumn(1);
}
void FormTask::getProjects(int index)
{
	idProject = query.record().indexOf("id");
}
