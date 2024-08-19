#include "Task.h"

Task::Task(QWidget *parent, QVector<QString> data)
	: QDialog(parent), data(data)
{
	ui.setupUi(this);
	this->setModal(true);
	ui.nameTaskLbl->setText(data[1]);
	ui.dealLbl->setText(data[11]);
	ui.dateBegin->setText(data[8]);
	ui.deadLine->setText(data[9]);
	ui.priority->setText(data[7]);
	ui.creator->setText(data[3]);
	ui.executor->setText(data[4]);
	ui.completedDate->setText(data[10]);
	ui.id->setText(data[0]);
	ui.create->setText(data[5]);
	ui.edit->setText(data[6]);
	ui.com->setText(data[11]);
	id = data[0];
	getStatus();
	isDeadline();
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

bool Task::isDeadline() {
	auto begin = QDate::fromString(data[8], "yyyy-MM-dd");
	auto end = QDate::fromString(data[9], "yyyy-MM-dd");
	if (begin == end or begin < end) {

		QLabel* warning = new  QLabel(this);
		warning->setText("Задача просрочена");
		auto layout = new QVBoxLayout();
		layout->addWidget(warning);
		ui.dateLayout->addLayout(layout);
		ui.dateBegin->hide();
		ui.deadLine->hide();
		ui.dateBeginLbl->hide();
		ui.deadLineLbl->hide();
		return true;
	}
	else {
		return false;
	}

}