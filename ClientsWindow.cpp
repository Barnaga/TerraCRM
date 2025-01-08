#include "ClientsWindow.h"

ClientsWindow::ClientsWindow(QWidget *parent)
	: ui(std::make_unique<Ui::ClientsWindowClass>()), QWidget(parent),
	client_model(std::make_unique<QSqlRelationalTableModel>()),
	client_view(std::make_unique<QTableView>()),
	company_model(std::make_unique<QSqlRelationalTableModel>()),
	company_view(std::make_unique<QTableView>())
{
	ui->setupUi(this);
	createClientModel();
	createClientView();
	createCompanyModel();
	createCompanyView();
	connect(client_view.get(), SIGNAL(clicked(const QModelIndex&)), this, SLOT(openClient(const QModelIndex&)));
	connect(company_view.get(), SIGNAL(clicked(const QModelIndex&)), this, SLOT(openCompany(const QModelIndex&)));
}

ClientsWindow::~ClientsWindow()
{
}

void ClientsWindow::openClient(const QModelIndex& index)
{
	QStringList data;
	for (auto i = 0; i < index.model()->columnCount(); ++i)
		data.append(index.model()->index(index.row(), i).data().toString());
	client_widget = std::make_unique<ClientWidget>(data);
	client_widget->show();
	data.clear();
}
void ClientsWindow::openCompany(const QModelIndex& index)
{
	QStringList data;
	for (auto i = 0; i < index.model()->columnCount(); ++i)
		data.append(index.model()->index(index.row(), i).data().toString());
	company_widget = std::make_unique<CompanyWidget>(data);
	company_widget->show();
	data.clear();
}

void ClientsWindow::createClientModel()
{
	client_model->setTable("contacts");
	client_model->setHeaderData(1, Qt::Horizontal, "Название");
	client_model->setHeaderData(2, Qt::Horizontal, "Телефон");
	client_model->setHeaderData(3, Qt::Horizontal, "Email");
	client_model->setHeaderData(4, Qt::Horizontal, "Категория");
	client_model->setRelation(client_model->fieldIndex("category"), QSqlRelation("\"categoryClients\"", "id", "category"));
	client_model->select();

}

void ClientsWindow::createClientView()
{
	auto clients = new QWidget;
	client_view->setModel(client_model.get());
	client_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	client_view->setColumnHidden(0, true);
	client_view->setColumnHidden(5, true);
	client_view->setColumnHidden(6, true);
	client_view->setColumnHidden(7, true);
	auto layout = new QVBoxLayout;
	layout->addWidget(client_view.get());
	clients->setLayout(layout);
	ui->tabWidget->addTab(clients, "Клиенты");
}

void ClientsWindow::createCompanyModel()
{
	company_model->setTable("companies");
	company_model->setHeaderData(1, Qt::Horizontal, "Название");
	company_model->setHeaderData(2, Qt::Horizontal, "Телефон");
	company_model->setHeaderData(3, Qt::Horizontal, "Email");
	company_model->setHeaderData(4, Qt::Horizontal, "Категория");
	company_model->setRelation(company_model->fieldIndex("category"), QSqlRelation("\"categoryClients\"", "id", "category"));
	company_model->setEditStrategy(QSqlTableModel::OnFieldChange);
	company_model->select();
}

void ClientsWindow::createCompanyView()
{
	auto companies = new QWidget;
	company_view->setModel(company_model.get());
	company_view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	company_view->setColumnHidden(0, true);
	company_view->setColumnHidden(5, true);
	auto layout = new QVBoxLayout;
	layout->addWidget(company_view.get());
	companies->setLayout(layout);
	ui->tabWidget->addTab(companies, "Компании");
}
