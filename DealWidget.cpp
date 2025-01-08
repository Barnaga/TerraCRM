#include "DealWidget.h"
DealWidget::DealWidget(QWidget* parent, QSqlTableModel* model, QStringList data, const QModelIndex& index)
	: ui(std::make_unique<Ui::DealWidgetClass>()),QDialog(parent), model(model), data(data), index(index)
{
	auto timeDeal = data[3] + " - " + data[4];
	ui->setupUi(this);
	ui->dealLbl->setText(data[1]);
	ui->sum->setText(data[2]);
	ui->timeDeal->setText(timeDeal);
	ui->sourceDeal->setText(data[6]);
	ui->responsible->setText(data[7]);
	getClient();
	getStatus();
	currentIndex = ui->statusComboBox->currentIndex();
	connect(ui->statusComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateStatus(int)));
}
DealWidget::~DealWidget()
{
}
void DealWidget::getClient()
{
	auto query = std::make_unique<QSqlQuery>();
	if (query->prepare("SELECT * FROM contacts WHERE id=:id")) {
		query->bindValue(":id", data[8]);
		if (query->exec()) {
			while (query->next()) {
				id = query->value(0).toString();
				ui->client->setText(query->value(1).toString());
				ui->number->setText(query->value(2).toString());
				ui->email->setText(query->value(3).toString());
			}
		}
	}
}
void DealWidget::getStatus()
{
	if (data[5] == "Новая заявка")
		ui->statusComboBox->setCurrentIndex(0);
	else if (data[5] == "Переговоры")
		ui->statusComboBox->setCurrentIndex(1);
	else if (data[5] == "Принятие решения")
		ui->statusComboBox->setCurrentIndex(2);
	else if (data[5] == "Согласование договора")
		ui->statusComboBox->setCurrentIndex(3);
	else
		ui->statusComboBox->setCurrentIndex(4);
}
void DealWidget::updateStatus(int temp) {
	if (currentIndex == temp) return;
	else if (temp == 4) {
		model->setData(model->index(index.row(), 5), ui->statusComboBox->currentText());
		model->setData(model->index(index.row(), 9), QDate::currentDate().toString());
	}
	else if (currentIndex < temp)
		model->setData(model->index(index.row(), 5), ui->statusComboBox->currentText());
	else {
		auto msg=std::make_unique<QMessageBox>();
		msg->setText("Обратно нельзя");
		msg->exec();
	}
}
