#include "ProjectWindow.h"

ProjectWindow::ProjectWindow(MainWindow *parent)
	: ui(new Ui::ProjectWindowClass), parent(dynamic_cast<MainWindow*>(parent)), model(new QSqlRelationalTableModel)
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
	ui->dateLbl->setText("Сегодня " + QDateTime::currentDateTime().toString("dd.MM.yyyy"));
}

ProjectWindow::~ProjectWindow()
{}

void ProjectWindow::createProject()
{
	createProjectDialog* dialog = new createProjectDialog(this, model, parent->getUser()[3]);
	dialog->show();
}

void ProjectWindow::createModel()
{
	model = new QSqlRelationalTableModel(this);
	model->setTable("project");
	model->setHeaderData(1, Qt::Horizontal, "Имя");
	model->setHeaderData(2, Qt::Horizontal, "Статус");
	model->setHeaderData(3, Qt::Horizontal, "Этап");
	model->setHeaderData(4, Qt::Horizontal, "Начало");
	model->setHeaderData(11, Qt::Horizontal, "Дедлайн");
	model->setRelation(model->fieldIndex("manager"), QSqlRelation("users", "id", "name"));
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->setFilter(QString("\"status\" NOT IN (\'Закрыт успешно\', \'Провален\', \'Приостановлен\')"));
	model->select();
}

void ProjectWindow::createView()
{
	view = new QTableView(this);
	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(5, true);
	view->setColumnHidden(6, true);
	view->setColumnHidden(7, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	view->setColumnHidden(10, true);
	view->setColumnHidden(11, true);
	view->setColumnHidden(12, true);
	view->setColumnHidden(13, true);
	ui->projectsLayout->addWidget(view);
}
void ProjectWindow::openProject(const QModelIndex index) {
	QVector<QString> data;
	for (auto i = 0; i < index.model()->columnCount(); ++i)
		data.append(index.model()->index(index.row(), i).data().toString());
	project = new ProjectWidget(this, data, model, index);

	project->show();
}
void ProjectWindow::createConnections()
{
	connect(view, SIGNAL(clicked(const QModelIndex)), this, SLOT(openProject(const QModelIndex)));
	connect(ui->createBtn, SIGNAL(clicked()), this, SLOT(createProject()));
}
