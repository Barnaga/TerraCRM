#include "ClientWidget.h"

ClientWidget::ClientWidget(QStringList data)
	:ui(new Ui::ClientWidgetClass),  data(data)
{
	ui->setupUi(this);
	ui->fullname->setText(data[5]+" " + data[1]+" " + data[6]);
	ui->birth->setText(data[7].replace("-","."));
	ui->category->setText(data[4]);
	ui->email->setText(data[3]);
	ui->phone->setText(data[2]);	
	createProjects("project", ui->projectsView);
}

void ClientWidget::createProjects(QString table, QTableView* view)
{
	QSqlQueryModel* queryModel = new QSqlQueryModel;
	QSqlQuery* query = new QSqlQuery;
	query->prepare("Select name from "+ table +" where client = :id");
	query->bindValue(":id", data[0]);
	query->exec();
	queryModel->setQuery(*query);
	queryModel->setHeaderData(0, Qt::Horizontal, tr("Name"));
	view->setModel(queryModel);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->show();
}

ClientWidget::~ClientWidget()
{}