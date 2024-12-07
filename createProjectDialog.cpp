#include "createProjectDialog.h"

createProjectDialog::createProjectDialog(QWidget* parent, QSqlRelationalTableModel* model, QString id)
	: QDialog(parent), ui(new Ui::createProjectDialogClass),
	model(model), id(id), query(new QSqlQuery)
{
	ui->setupUi(this);
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(create()));
}
void createProjectDialog::create(){
	const auto& row = model->rowCount();
	const auto& name = ui->name->text();
	const auto& status = "Не активен";
	const auto& deadline = ui->deadline->text();
	createClient();
	if (model->insertRow(row)) {
		model->setData(model->index(row, 1), name);
		model->setData(model->index(row, 2), status);
		model->setData(model->index(row, 3), "Подготовка");
		model->setData(model->index(row, 4), QDate::currentDate().toString());
		model->setData(model->index(row, 5), ui->receiptEdit->text());
		model->setData(model->index(row, 8), id);
		model->setData(model->index(row, 9), deadline);
		model->setData(model->index(row, 11), client);
		model->setData(model->index(row, 12), model->index(row - 1, 12).data().toString());
	}
	model->submitAll();
	model->select();
	getContactID(row);
}
void createProjectDialog::createClient()
{
	query->prepare("SELECT * FROM contacts WHERE name=:name and phone=:phone and email=:email");
	query->bindValue(":name", ui->clientEdit->text());
	query->bindValue(":phone", ui->phoneEdit->text());
	query->bindValue(":email", ui->emailEdit->text());
	qDebug() << query->lastError();
	if (query->exec() and query->first()) {
		client = query->value(0).toString();
	}
	else {
		query->prepare("INSERT INTO contacts(name,phone,email) VALUES (:name,:phone,:email)");
		query->bindValue(":name", ui->clientEdit->text());
		query->bindValue(":phone", ui->phoneEdit->text());
		query->bindValue(":email", ui->emailEdit->text());
		query->exec();
	}
}
void createProjectDialog::getContactID(const int& row) {
		query->prepare("INSERT INTO \"executorsProjects\" (executor, project) VALUES(:contact, :project)");
		query->bindValue(":contact", id);
		query->bindValue(":project", model->index(row, 0).data().toString());
		query->exec();
}
createProjectDialog::~createProjectDialog()
{}
