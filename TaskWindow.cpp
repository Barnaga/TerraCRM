#include "TaskWindow.h"

TaskWindow::TaskWindow(MainWindow* parent)
	: ui(new Ui::TaskWindowClass), parent(dynamic_cast<MainWindow*>(parent)), model(new QSqlRelationalTableModel)
{
	ui->setupUi(this);
	createModel();
	createView();
	createConnections();
	ui->dateLbl->setText("Сегодня "+ QDateTime::currentDateTime().toString("dd.MM.yyyy"));
}
TaskWindow::~TaskWindow()
{
	delete ui;
}
void TaskWindow::createModel()
{
	model = new QSqlRelationalTableModel(this);
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

	if (user[4] == "Leader") 
		model->select();
	else {
		model->setFilter(QString("\"executorTask\"=\'%1\'").arg(user[3]));
		model->setQuery("Select nameTask, statusTask, creatorTask, users.name From public.tasks join users on tasks.executors = users.id");
		model->select();
	}
}
void TaskWindow::createConnections()
{
	connect(ui->createTaskBtn, SIGNAL(clicked()), this, SLOT(createTaskBtn()));
	connect(view, SIGNAL(clicked(const QModelIndex)), this, SLOT(openTask(const QModelIndex)));
}
void TaskWindow::createView() {
	view = new QTableView(this);
	view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	view->setItemDelegateForColumn(2, new RateDelegate(view));
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setColumnHidden(5, true);
	view->setColumnHidden(6, true);
	view->setColumnHidden(7, true);
	view->setColumnHidden(8, true);
	view->setColumnHidden(9, true);
	view->setColumnHidden(10, true);
	ui->tasksLayout->addWidget(view);
	if (!formTask) formTask = new FormTask(this, model, user[3].toInt());
}
void TaskWindow::openTask(const QModelIndex index)
{
	
	for (auto i = 0; i < index.model()->columnCount(); ++i)
		data.append(index.model()->index(index.row(), i).data().toString());
	task = new Task(this, data, model, index);

	task->show();
}
void TaskWindow::createTaskBtn()
{
	formTask = new FormTask(this, model, user[3].toInt());
	formTask->show();
}
