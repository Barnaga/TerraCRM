#include "TaskWindow.h"

TaskWindow::TaskWindow(QMainWindow* parent)
	: ui(new Ui::TaskWindowClass), parent(dynamic_cast<MainWindow*>(parent)), model(new QSqlTableModel)
{
	ui->setupUi(this);

	createModel();
	createView();
	createConnections();
}
TaskWindow::~TaskWindow()
{
	delete ui;
}
void TaskWindow::createModel()
{
	model->setTable("tasks");
	model->setHeaderData(0, Qt::Horizontal, "ID");
	model->setHeaderData(1, Qt::Horizontal, "Задание");
	model->setHeaderData(2, Qt::Horizontal, "Статус");
	model->setHeaderData(3, Qt::Horizontal, "Постановщик");
	model->setEditStrategy(QSqlTableModel::OnFieldChange);
	model->select();
}
void TaskWindow::createConnections()
{
	connect(ui->createTaskBtn, SIGNAL(clicked()), this, SLOT(onClickCreateTaskBtn()));
	connect(formTask, SIGNAL(accepted()), this, SLOT(addData()));
	connect(formTask->okBtn, SIGNAL(clicked()), formTask, SLOT(accept()));
	connect(formTask->cancelBtn, SIGNAL(clicked()), formTask,  SLOT(reject()));	
}
void TaskWindow::createView() {
	view = new QTableView(this);	
	view->setItemDelegateForColumn(2, new RateDelegate(view));
	view->setModel(model);
	view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	view->setColumnHidden(0, true);
	view->setContextMenuPolicy(Qt::CustomContextMenu);
	ui->tasksLayout->addWidget(view);
	connect(view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(slotCustomMenuRequested(QPoint)));
	if (!formTask) formTask = new FormTask(this, true);
}
void TaskWindow::onClickCreateTaskBtn()
{
	formTask->createTask();
	formTask->show();
}
void TaskWindow::addData()
{
	const auto& nameTask = formTask->nameTask->text();
	const auto& statusTask = "Сделать";
	const auto& creatorTask = "Я";
	const auto& row = model->rowCount();
	if (!formTask->nameTask->text().isEmpty()) {
		model->insertRows(row, 1);
		model->setData(model->index(row, 1), nameTask);
		model->setData(model->index(row, 2), statusTask);
		model->setData(model->index(row, 3), creatorTask);
		model->submit();
		model->select();
	}
	else formTask->warningLbl->setEnabled(true);
}

void TaskWindow::slotCustomMenuRequested(QPoint pos)
{
	/* Создаем объект контекстного меню */
	QMenu* menu = new QMenu(this);
	/* Создаём действия для контекстного меню */
	QAction* editDevice = new QAction("Редактировать", this);
	QAction* deleteDevice = new QAction("Удалить", this);
	/* Подключаем СЛОТы обработчики для действий контекстного меню */
	connect(editDevice, SIGNAL(triggered()), this, SLOT(slotEditRecord()));     // Обработчик вызова диалога редактирования
	connect(deleteDevice, SIGNAL(triggered()), this, SLOT(slotRemoveRecord())); // Обработчик удаления записи
	/* Устанавливаем действия в меню */
	menu->addAction(editDevice);
	menu->addAction(deleteDevice);
	/* Вызываем контекстное меню */
	menu->popup(view->viewport()->mapToGlobal(pos));
}
