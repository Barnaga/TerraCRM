#pragma once

#include <QDialog>
#include<QDateTime>
#include "ui_TransferForm.h"

class TransferForm : public QDialog
{
	Q_OBJECT

public:
	TransferForm(QWidget *parent = nullptr);
	~TransferForm();
	TransferForm(TransferForm& r) = delete;
	TransferForm(TransferForm&& r) = delete;
	TransferForm& operator=(const TransferForm& r) = delete;
	TransferForm& operator=(const TransferForm&& r) = delete;

private:
	Ui::TransferFormClass* ui;
};
