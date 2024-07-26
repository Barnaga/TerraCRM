#include "FormTask.h"

FormTask::FormTask(QWidget *parent, bool isCreate)
	: QDialog(parent), ui(new Ui::FormTaskClass)
{
	ui->setupUi(this);
	okBtn = ui->okBtn;
	cancelBtn = ui->cancelBtn;
	nameTask = ui->nameTaskEdit;
	warningLbl = ui->warningLbl;
	warningLbl->hide();
}

void FormTask::createTask() {
	ui->comboBox->hide();
	ui->creatorTaskEdit->hide();
	nameTask->clear();
}
FormTask::~FormTask()
{}
