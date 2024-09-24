#include "Task.h"

Task::Task(QWidget* parent, QVector<QString> data, QSqlRelationalTableModel* model, QModelIndex index)
	: QDialog(parent), data(data), model(model), index(index)
{
	ui.setupUi(this);

	this->setModal(true);
	ui.nameTaskLbl->setText(data[1]);
	ui.dealLbl->setText(data[10]);
	ui.dateBegin->setText(data[7]);
	ui.deadLine->setText(data[8]);
	ui.priority->setText(data[6]);
	ui.creator->setText(data[3]);
	ui.executor->setText(data[4]);
	ui.completedDate->setText(data[9]);
	ui.id->setText(data[0]);
	ui.create->setText(data[5]);
	ui.com->setText(data[10]);
	id = data[0];
	getStatus();
	isDeadline();
	currentIndex = ui.statusBox->currentIndex();
	connect(ui.statusBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateStatus(int)));
}

Task::~Task()
{}
void Task::getStatus()
{
	if (data[2] == QString("Сделать")) {
		ui.statusBox->setCurrentIndex(0);
	}
	else if (data[2] == QString("В работе")) {
		ui.statusBox->setCurrentIndex(1);
	}
	else if (data[2] == QString("Сделано")) {
		ui.statusBox->setCurrentIndex(2);
	}
	else ui.statusBox->setCurrentIndex(3);
}

void Task::isDeadline() {
	auto current = QDate::currentDate();
	auto end = QDate::fromString(data[8], "yyyy-MM-dd");

	if (ui.statusBox->currentIndex()==3) {
		ui.warning->setText("Задача выполнена");
	}
	else if (current >= end or current == end) {
		ui.warning->setText("Задача просрочена");
	}
}

void Task::updateStatus(int temp) {
	if (currentIndex == temp) return;
	else if (temp == 3) {
		model->setData(model->index(index.row(), 2), ui.statusBox->currentText());
		model->setData(model->index(index.row(), 9), QDate::currentDate().toString());
	}
	else if(currentIndex < temp) {
		model->setData(index, ui.statusBox->currentText());
	}
	else {
		QMessageBox msg;
		msg.setText("Обратно нельзя");
		msg.exec();
	}
	
}