#include "CompanyWidget.h"

CompanyWidget::CompanyWidget(QStringList data)
	:ui(std::make_unique<Ui::CompanyWidgetClass>()), data(data)
{
	ui->setupUi(this);
	ui->fullname->setText(data[1]);
	ui->category->setText(data[4]);
	ui->email->setText(data[3]);
	ui->phone->setText(data[2]);
	ui->site->setText(data[5]);
	createProjects("project", "client", ui->projectsView);
}

CompanyWidget::~CompanyWidget()
{}

void CompanyWidget::createProjects(QString table, QString field, QTableView* view)
{
	auto queryModel = std::make_unique<QSqlQueryModel>();
	auto query = std::make_unique<QSqlQuery>();
	query->prepare("Select name from " + table + " where " + field +" = :id");
	query->bindValue(":id", data[0]);
	query->exec();
	queryModel->setQuery(*query);
	queryModel->setHeaderData(0, Qt::Horizontal, tr("Name"));
	view->setModel(queryModel.release());
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->show();
}
