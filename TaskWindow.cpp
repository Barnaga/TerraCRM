#include "TaskWindow.h"

TaskWindow::TaskWindow(MainWindow* parent)
	: ui(std::make_unique<Ui::TaskWindowClass>()),
	parent(dynamic_cast<MainWindow*>(parent)),
	model(std::make_shared<QSqlRelationalTableModel>()),
	view(std::make_unique<QTableView>())
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
}
TaskWindow::~TaskWindow()
{
}
void TaskWindow::createModel()
{
	model->setTable("tasks");
	model->setHeaderData(1, Qt::Horizontal, "Задание");
	model->setHeaderData(2, Qt::Horizontal, "Этап");
	model->setHeaderData(3, Qt::Horizontal, "Постановщик");
	model->setHeaderData(4, Qt::Horizontal, "Исполнитель");
	model->setRelation(model->fieldIndex("creatorTask"), QSqlRelation("users", "id", "name"));
	model->setRelation(model->fieldIndex("executorTask"), QSqlRelation("users", "id", "name"));
	model->setRelation(model->fieldIndex("project"), QSqlRelation("project", "id", "name"));
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	user = parent->getUser();
	if (user[4] == "Директор")
		model->setFilter(QString("tasks.company_id =\'%2\'").arg(user[5]));
	else
		model->setFilter(QString("\"executorTask\"=\'%1\' and tasks.company_id =\'%2\'").arg(user[3], user[5]));
	model->select();
}
void TaskWindow::createConnections()
{
	connect(ui->createTaskBtn, SIGNAL(clicked()), this, SLOT(createTaskBtn()));
	connect(view.get(), SIGNAL(clicked(const QModelIndex&)), this, SLOT(openTask(const QModelIndex&)));
}
void TaskWindow::createView() {
	ui->dateLbl->setText("Сегодня " + QDateTime::currentDateTime().toString("dd.MM.yyyy"));
	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	view->setItemDelegateForColumn(2, new RateDelegate(view.get()));
	view->setModel(model.get());
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(5, true);
	view->setColumnHidden(6, true);
	view->setColumnHidden(7, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	view->setColumnHidden(10, true);
	view->setColumnHidden(11, true);
	ui->tasksLayout->addWidget(view.get());
	if (!formTask) auto formTask(std::make_unique<FormTask>(this, model.get(), user[3].toInt()));
}
void TaskWindow::openTask(const QModelIndex& index)
{
	for (auto i = 0; i < index.model()->columnCount(); ++i)
		data.append(index.model()->index(index.row(), i).data().toString());
	task = std::make_unique<Task>(this, data, model.get(), index);
	task->show();
	data.clear();
}
void TaskWindow::createTaskBtn()
{
	formTask = std::make_unique<FormTask>(this, model.get(), user[3].toInt());
	formTask->show();
}
