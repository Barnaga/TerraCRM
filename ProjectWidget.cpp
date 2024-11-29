#include "ProjectWidget.h"

ProjectWidget::ProjectWidget(QWidget* parent, QStringList data, QSqlRelationalTableModel* model, const QModelIndex index)
	: QDialog(parent), ui(new Ui::ProjectWidgetClass),
	model(model), query(new QSqlQuery), data(data), index(index)
{
	ui->setupUi(this);
	createView();
	getClient();
	getStatus();
	createConnections();
	isDeadline();


	currentIndex = ui->stageBox->currentIndex();
}
void ProjectWidget::isDeadline()
{
	if (data[4] < data[11]) {
		model->setData(model->index(index.row(), 2), "Просрочен");
	}
}
void ProjectWidget::createView()
{
	this->setModal(true);
	auto time = data[4] + " - " + data[11];
	ui->dealLbl->setText(data[1]);
	ui->date->setText(time);
	ui->costLbl->setText(data[5]);
	ui->expense->setText(data[6]);
	ui->manager->setText(data[8]);
}
void ProjectWidget::createConnections() {
	connect(ui->stageBox, SIGNAL(currentIndexChanged(int)), this, SLOT(saveIndex(int)));
	connect(ui->doneBtn, SIGNAL(clicked()), this, SLOT(completeProject()));
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(updateStatus()));
}
void ProjectWidget::getClient()
{
	if (query->prepare("SELECT * FROM contacts WHERE \"id\" = :id")) {
		query->bindValue(":id", data[14]);
		if (query->exec()) {
			while (query->next()) {
				ui->nameCompanyLbl->setText(query->value(1).toString());
				ui->numberLbl->setText(query->value(2).toString());
				ui->emailLbl->setText(query->value(3).toString());
			}
		}
	}
}
void ProjectWidget::saveIndex(int changeIndex) {
	tempIndex = changeIndex;
}
void ProjectWidget::updateStatus() {

	if (currentIndex == tempIndex) return;
	else if (currentIndex < tempIndex) {
		model->setData(model->index(index.row(), 3), ui->stageBox->currentText());
	}
	else {
		auto* msg = new QMessageBox;
		msg->setText("Обратно нельзя");
		msg->exec();
	}
}
void ProjectWidget::getStatus()
{
	if (data[3] =="Подготовка") {
		ui->stageBox->setCurrentIndex(0);
	}
	else if (data[3] == "Проектирование") {
		ui->stageBox->setCurrentIndex(1);
	}
	else if (data[3] == "Разработка") {
		ui->stageBox->setCurrentIndex(2);
	}
	else if (data[3] == "Коррекция") {
		ui->stageBox->setCurrentIndex(3);
	}
	else {
		ui->stageBox->setCurrentIndex(4);
	}
}
ProjectWidget::~ProjectWidget()
{
}

void ProjectWidget::completeProject()
{
	ChangeStatusProjectDialog* dialog = new ChangeStatusProjectDialog(this, model, index);
	dialog->show();
}


