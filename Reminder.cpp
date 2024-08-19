#include "Reminder.h"

Reminder::Reminder(QWidget *parent, QString task_id)
	: QDialog(parent), task_id(task_id)
{
	ui.setupUi(this);
	connect(ui.dateBox, SIGNAL(activated(int)), this, SLOT(changed(int)));
	connect(ui.applyBtn, SIGNAL(clicked()), this, SLOT(validDate()));
}
void Reminder::changed(int index) {
	if (ui.dateBox->currentIndex() == 1) {
		ui.timeBox->setEnabled(false);
		ui.lineEdit->setPlaceholderText("01.01.2000");
		update();
	}
	else {
		ui.timeBox->setEnabled(true);
		ui.lineEdit->setPlaceholderText("");
		update();
	}
}

void Reminder::validDate() {
	std::regex rx{ R"((0[1-9]|[12][0-9]|3[01])[- /.](0[1-9]|1[012])[- /.](19|20)\d\d)" };
	auto date = ui.lineEdit->text();
	QSqlQuery query;
	auto parent = this->parent();
	if (std::regex_match(date.toStdString(), rx)) {
		query.prepare("INSERT INTO reminders (task_id, employee, time) VALUES ( :task_id, employee, time)");
		query.bindValue(":task_id", task_id);
		query.bindValue("employee", ui.empBox->currentText());
		query.bindValue("time", date);
		query.exec();
		qDebug() << query.exec();
	}
	else if (std::regex_match(date.toStdString(), std::regex("[0-9]{2}"))) {
		qDebug() << "true";
	}
	else {
		qDebug() << "false";
	}
	
	
}
Reminder::~Reminder()
{}

