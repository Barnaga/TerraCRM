#include "createProjectDialog.h"

createProjectDialog::createProjectDialog(QWidget* parent, QSqlRelationalTableModel* model, QString id)
	: QDialog(parent), ui(new Ui::createProjectDialogClass), model(model), id(id), query(std::make_unique<QSqlQuery>())
{
	ui->setupUi(this);
	createComponyBox();
	connect(ui->saveBtn, SIGNAL(clicked()), this, SLOT(create()));
	connect(ui->company, SIGNAL(currentIndexChanged(int)), this, SLOT(createContactBox(int)));
	connect(ui->company, SIGNAL(currentIndexChanged(int)), this, SLOT(createContactBox(int)));
}
void createProjectDialog::create(){
	const auto& row = model->rowCount();
	const auto& name = ui->name->text();
	const auto& status = "Не активен";
	const auto& deadline = ui->deadline->text();
	const auto& company = ui->company->model()->index(ui->company->currentIndex(), 0).data().toString();
	if (model->insertRow(row)) {
		model->setData(model->index(row, 1), name);
		model->setData(model->index(row, 2), status);
		model->setData(model->index(row, 3), "Подготовка");
		model->setData(model->index(row, 4), QDate::currentDate().toString());
		model->setData(model->index(row, 8), id);
		model->setData(model->index(row, 11), deadline);
		model->setData(model->index(row, 13), company);
	}
	model->submitAll();
	model->select();
	getContactID(row);
}

void createProjectDialog::createComponyBox() {
	query->prepare("SELECT * FROM counterpars");
	query->exec();
	QSqlQueryModel* temp_model = new QSqlQueryModel(this);
	temp_model->setQuery(*query);
	ui->company->setModel(temp_model);
	ui->company->setModelColumn(1);
	if (!ui->company->isEditable()) {
		createContactBox(0);
	}
}
void createProjectDialog::createContactBox(int id)
{
	query->prepare("SELECT * FROM contacts where \"companyID\" = :id");
	query->bindValue(":id", ui->company->model()->index(id, 0).data().toString());
	query->exec();
	QSqlQueryModel* temp_model = new QSqlQueryModel(this);
	temp_model->setQuery(*query);
	ui->contact->setModel(temp_model);
	ui->contact->setModelColumn(1);
}
void createProjectDialog::getContactID(const int& row) {
		query->prepare("INSERT INTO \"executorsProjects\" (executor, project) VALUES(:contact, :project)");
		query->bindValue(":contact", ui->contact->model()->index(ui->contact->currentIndex(), 0).data().toString());
		query->bindValue(":project", model->index(row, 0).data().toString());
		query->exec();
}
createProjectDialog::~createProjectDialog()
{}
