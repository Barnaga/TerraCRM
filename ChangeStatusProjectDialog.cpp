#include "ChangeStatusProjectDialog.h"

ChangeStatusProjectDialog::ChangeStatusProjectDialog(QWidget *parent, QSqlTableModel* model, QModelIndex index)
	: QDialog(parent), model(model), index(index)
{
	ui.setupUi(this);
	currentDate = QDate::currentDate().toString("dd.MM.yyyy");
	ui.date->setText(currentDate);
	connect(ui.saveBtn, SIGNAL(clicked()), this, SLOT(updateStatus()));
}


void ChangeStatusProjectDialog::updateStatus() {
	model->setData(model->index(index.row(), 2), ui.statusBox->currentText());
	model->setData(model->index(index.row(), 12), currentDate);

	if (ui.checkArchiveTask->isChecked()) {
		QSqlQuery query;
		query.prepare("Update tasks SET \"statusTask\" =\'Архивировано\' where project=:id");
		query.bindValue(":id", model->index(index.row(), 0).data().toString());
		query.exec();
	}
}

ChangeStatusProjectDialog::~ChangeStatusProjectDialog()
{}
