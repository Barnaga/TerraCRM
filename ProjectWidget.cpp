#include "ProjectWidget.h"

ProjectWidget::ProjectWidget(QWidget* parent, QList<QString> data, QSqlRelationalTableModel* model, QModelIndex index, int id)
	: QDialog(parent), model(model), data(data), index(index), id(id)
{
	ui.setupUi(this);
	auto time = data[4] + " - " + data[11];
	ui.dealLbl->setText(data[1]);
	ui.date->setText(time);
	ui.costLbl->setText(data[5]);
	ui.expense->setText(data[6]);
	ui.manager->setText(data[8]);
	if (data[4] < data[11]) {
		model->setData(model->index(index.row(), 2), "Просрочен");
	}
	createConnections();
	getClient();
	getStatus();
	currentIndex = ui.stageBox->currentIndex();
	
}
void ProjectWidget::createConnections() {
	connect(ui.stageBox, SIGNAL(currentIndexChanged(int)), this, SLOT(saveIndex(int)));
	connect(ui.doneBtn, SIGNAL(clicked()), this, SLOT(completeProject()));
	connect(ui.saveBtn, SIGNAL(clicked()), this, SLOT(updateStatus()));
}
void ProjectWidget::getClient()
{
	if (query.prepare("SELECT * FROM contacts WHERE \"id\" = :id")) {
		query.bindValue(":id", data[14]);
		if (query.exec()) {
			while (query.next()) {
				ui.nameCompanyLbl->setText(query.value(1).toString());
				ui.numberLbl->setText(query.value(2).toString());
				ui.emailLbl->setText(query.value(3).toString());
			}
		}
	}

	else {
		qDebug() << query.lastError() << " error";
	}
}
void ProjectWidget::saveIndex(int index) {
	temp = index;
}
void ProjectWidget::updateStatus() {
	if (currentIndex == temp) return;
	else if (currentIndex < temp) {
		model->setData(model->index(index.row(), 3), ui.stageBox->currentText());
	}
	else {
		QMessageBox msg;
		msg.setText("Обратно нельзя");
		msg.exec();
	}
}
void ProjectWidget::getStatus()
{
	if (data[3] == QString("Подготовка")) {
		ui.stageBox->setCurrentIndex(0);
	}
	else if (data[3] == QString("Проектирование")) {
		ui.stageBox->setCurrentIndex(1);
	}
	else if (data[3] == QString("Разработка")) {
		ui.stageBox->setCurrentIndex(2);
	}
	else if (data[3] == QString("Коррекция")) {
		ui.stageBox->setCurrentIndex(3);
	}
	else {
		ui.stageBox->setCurrentIndex(4);
	}
}
ProjectWidget::~ProjectWidget()
{}

void ProjectWidget::completeProject()
{
	ChangeStatusProjectDialog* dialog = new ChangeStatusProjectDialog(this, model, index);
	dialog->show();
}


