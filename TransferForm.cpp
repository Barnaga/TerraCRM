#include "TransferForm.h"

TransferForm::TransferForm(QWidget *parent)
	: QDialog(parent), ui(new Ui::TransferFormClass)
{
	ui->setupUi(this);
	ui->date->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy"));

}

TransferForm::~TransferForm()
{}
