#include "Task.h"

Task::Task(QWidget* parent, QStringList data, QSqlRelationalTableModel* model, const QModelIndex& index)
	: QDialog(parent), ui(std::make_unique<Ui::TaskClass>()),
	model(new QSqlRelationalTableModel), index(index), data(data)
{
	ui->setupUi(this);
	createView();
	getStatus();
	isDeadline();
	currentIndex = ui->statusBox->currentIndex();
	connect(ui->statusBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateStatus(int)));
}

void Task::createView()
{
	this->setModal(true);
	ui->nameTaskLbl->setText(data[1]);
	ui->dealLbl->setText(data[10]);
	ui->dateBegin->setText(data[7]);
	ui->deadLine->setText(data[8]);
	ui->priority->setText(data[6]);
	ui->creator->setText(data[3]);
	ui->executor->setText(data[4]);
	ui->completedDate->setText(data[9]);
	ui->id->setText(data[0]);
	ui->create->setText(data[5]);
	id = data[0];
}

Task::~Task()
{
}
void Task::getStatus()
{
	if (data[2] == "Сделать") 
		ui->statusBox->setCurrentIndex(0);
	else if (data[2] == "В работе") 
		ui->statusBox->setCurrentIndex(1);
	else if (data[2] == "Сделано") 
		ui->statusBox->setCurrentIndex(2);
	else ui->statusBox->setCurrentIndex(3);
}

void Task::isDeadline() {
	auto current = QDate::currentDate();
	auto end = QDate::fromString(data[8], "yyyy-MM-dd");
	if (ui->statusBox->currentIndex()==3) {
		ui->warning->setText("Задача выполнена");
	}
	else if (current >= end or current == end) {
		ui->warning->setText("Задача просрочена");
	}
}

void Task::updateStatus(int temp) {
	if (currentIndex == temp) return;
	else if (temp == 3) {
		model->setData(model->index(index.row(), 2), ui->statusBox->currentText());
		model->setData(model->index(index.row(), 9), QDate::currentDate().toString());
	}
	else if (currentIndex < temp) {
		model->setData(model->index(index.row(), 2), ui->statusBox->currentText());
	}

	else {
		auto msg = std::make_unique<QMessageBox>();
		msg->setText("Обратно нельзя");
		msg->exec();
	}
}