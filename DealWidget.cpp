#include "DealWidget.h"
DealWidget::DealWidget(QWidget* parent, QSqlTableModel* model, QList<QString> data, const QModelIndex& index)
	: ui(new Ui::DealWidgetClass),QDialog(parent), model(model), data(data), index(index), query(new QSqlQuery)
{
	auto timeDeal = data[3] + " - " + data[4];
	ui->setupUi(this);
	ui->dealLbl->setText(data[1]);
	ui->sum->setText(data[2]);
	ui->timeDeal->setText(timeDeal);
	ui->sourceDeal->setText(data[6]);
	ui->responsible->setText(data[7]);
	ui->nameCompanyLbl->setText(data[9]);
	ui->nameConnectionLbl->setText(data[8]);
	getClient();
	getAgent(id);
	getStatus();
	currentIndex = ui->statusComboBox->currentIndex();
	connect(ui->statusComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(updateStatus(int)));

}
DealWidget::~DealWidget()
{
	delete ui;
}
void DealWidget::getClient()
{
	if (query->prepare("SELECT * FROM counterpars WHERE name=:name")) {
		query->bindValue(":name", data[9]);
		if (query->exec()) {
			while (query->next()) {
				id = query->value(0).toString();
				ui->numberLbl->setText(query->value(2).toString());
				ui->emailLbl->setText(query->value(3).toString());
			}
		}
	}
}
void DealWidget::getAgent(QString id)
{
	if (query->prepare("SELECT * FROM contacts WHERE \"companyID\" = :companyID")) {
		query->bindValue(":companyID", id);
		if (query->exec()) {	
			while (query->next()) {
				ui->nameLblC->setText(query->value(1).toString());
				ui->numberLblC->setText(query->value(2).toString());
				ui->emailLblC->setText(query->value(3).toString());
			}
		}
	}
}
void DealWidget::getStatus()
{
	if (data[5]=="Новая заявка") {
		ui->statusComboBox->setCurrentIndex(0);
	}
	else if (data[5]=="Переговоры") {
		ui->statusComboBox->setCurrentIndex(1);
	}
	else if (data[5]=="Принятие решения") {
		ui->statusComboBox->setCurrentIndex(2);
	}
	else if (data[5]=="Согласование договора") {
		ui->statusComboBox->setCurrentIndex(3);
	}
	else
	{
		ui->statusComboBox->setCurrentIndex(4);
	}

}
void DealWidget::updateStatus(int temp) {
	if (currentIndex == temp) return;
	else if (temp == 4) {
		model->setData(model->index(index.row(), 5), ui->statusComboBox->currentText());
		model->setData(model->index(index.row(), 10), QDate::currentDate().toString());
	}
	else if (currentIndex < temp)
	{
		model->setData(index, ui->statusComboBox->currentText());
	}
	else {
		auto* msg=new QMessageBox;
		msg->setText("Обратно нельзя");
		msg->exec();
	}
}
