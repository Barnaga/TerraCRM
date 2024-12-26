#include "ProjectWidget.h"


ProjectWidget::ProjectWidget(QWidget* parent, QStringList data, QSqlRelationalTableModel* model, const QModelIndex& index)
	: QDialog(parent), ui(new Ui::ProjectWidgetClass),
	model(model), query(new QSqlQuery), data(data), index(index)
{
	ui->setupUi(this);
	createView();
	getClient();
	getStatus();
	createConnections();
	isDeadline();
	currentIndex = ui->stageBox->currentIndex();
	
}
void ProjectWidget::isDeadline()
{
	if (data[4] < data[9]) {
		model->setData(model->index(index.row(), 2), "Просрочен");
	}
}
void ProjectWidget::createView()
{
	this->setModal(true);
	auto time = data[4] + " - " + data[9];
	ui->dealLbl->setText(data[1]);
	ui->date->setText(time);
	ui->costLbl->setText(data[5]);
	ui->expense->setText(data[6]);
	ui->manager->setText(data[8]);
}
void ProjectWidget::createConnections() {
	connect(ui->stageBox, SIGNAL(currentIndexChanged(int)), this, SLOT(saveIndex(int)));
	connect(ui->doneBtn, SIGNAL(clicked()), this, SLOT(completeProject()));
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(updateStatus()));
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(addDebit()));
}
void ProjectWidget::getClient()
{
	if (query->prepare("SELECT * FROM contacts WHERE \"id\" = :id")) {
		query->bindValue(":id", data[11]);
		if (query->exec()) {
			while (query->next()) {
				ui->nameCompanyLbl->setText(query->value(1).toString());
				ui->numberLbl->setText(query->value(2).toString());
				ui->emailLbl->setText(query->value(3).toString());
			}
		}
	}
}
void ProjectWidget::saveIndex(int changeIndex) {
	tempIndex = changeIndex;
}
void ProjectWidget::updateStatus() {
	if (currentIndex == tempIndex) return;
	else if (currentIndex < tempIndex) {
		model->setData(model->index(index.row(), 3), ui->stageBox->currentText());
	}
	else {
		auto* msg = new QMessageBox;
		msg->setText("Обратно нельзя");
		msg->exec();
	}
}
void ProjectWidget::addDebit() {
	if (ui->debitEdit->text().isEmpty()) return;
	else if (model->index(index.row(), 6).data().toInt() != 0) {
		auto temp = model->index(index.row(), 6).data().toInt() + ui->debitEdit->text().toInt();
		model->setData(model->index(index.row(), 6), temp);
		addCash(ui->debitEdit->text().toInt());
	}
	else {
		model->setData(model->index(index.row(), 6), ui->debitEdit->text());
		addCash(ui->debitEdit->text().toInt());
	}
}
void ProjectWidget::addCash(int cash)
{
	auto responsible = getResponsible().toInt();
	auto payment = getPaymentAccount().toInt();
	query->prepare("INSERT INTO finance(date, cash, payer, recipient, communication, responsible, category, account, note, state, company_id) VALUES(:date, :cash, :payer, :recipient, :communication, :responsible, :category, :account, NULL, :state, :company_id)");
	query->bindValue(":date", QDateTime::currentDateTime().toString("dd-MM-yyyy"));
	query->bindValue(":cash", -cash);
	query->bindValue(":payer", data[11].toInt());
	query->bindValue(":recipient", data[12].toInt());
	query->bindValue(":communication", data[0].toInt());
	query->bindValue(":responsible", responsible);
	query->bindValue(":category", 5);
	query->bindValue(":account", payment);
	query->bindValue(":state", 1);
	query->bindValue(":company_id", data[12].toInt());
	query->exec();
}
QString ProjectWidget::getPaymentAccount()
{
	query->prepare("SELECT id FROM accounts WHERE company_id = :id and name = \'Расчетный счет\'");
	query->bindValue(":id", data[12]);
	query->exec();
	query->first();
	return query->value(0).toString();
}
QString ProjectWidget::getResponsible()
{
	query->prepare("SELECT id FROM users WHERE company_id = :id and name = :name");
	query->bindValue(":id", data[12]);
	query->bindValue(":name", data[8]);
	query->exec();
	query->first();
	return query->value(0).toString();
}
void ProjectWidget::getStatus()
{
	if (data[3] =="Подготовка") 
		ui->stageBox->setCurrentIndex(0);
	else if (data[3] == "Проектирование") 
		ui->stageBox->setCurrentIndex(1);
	else if (data[3] == "Разработка") 
		ui->stageBox->setCurrentIndex(2);
	else if (data[3] == "Коррекция") 
		ui->stageBox->setCurrentIndex(3);
	else ui->stageBox->setCurrentIndex(4);
}
ProjectWidget::~ProjectWidget()
{
	delete ui;
}

void ProjectWidget::completeProject()
{
	ChangeStatusProjectDialog* dialog = new ChangeStatusProjectDialog(this, model, index);
	dialog->show();
}


