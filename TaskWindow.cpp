#include "TaskWindow.h"

TaskWindow::TaskWindow(QMainWindow *parent)
	:  ui(new Ui::TaskWindowClass), parent(dynamic_cast<MainWindow*>(parent))
{
	ui->setupUi(this);

	printCountStatusTask();
	createTaskWidget();
	
}

TaskWindow::~TaskWindow()
{
	delete ui;
}

QString TaskWindow::getCountTask(StatusTask status)
{
	result res;
	switch (status)
	{
	case StatusTask::Do:
		res = parent->pool->runQuery("SELECT COUNT('statusTask') FROM public.tasks WHERE \"statusTask\" = 1");
		break;
	case StatusTask::Work:
		res = parent->pool->runQuery("SELECT COUNT('statusTask') FROM public.tasks WHERE \"statusTask\" = 2");
		break;
	case StatusTask::Done:
		res = parent->pool->runQuery("SELECT COUNT('statusTask') FROM public.tasks WHERE \"statusTask\" = 3");
		break;
	case StatusTask::Completed:
		res = parent->pool->runQuery("SELECT COUNT('statusTask') FROM public.tasks WHERE \"statusTask\" = 4");
		break;
	case StatusTask::All: 
		res = parent->pool->runQuery("SELECT COUNT('statusTask') FROM public.tasks");
	}
	return res[0][0].c_str();
}

void TaskWindow::printCountStatusTask()
{
	ui->countDoLbl->setText(getCountTask(StatusTask::Do));
	ui->countWorkLbl->setText(getCountTask(StatusTask::Work));
	ui->countDoneLbl->setText(getCountTask(StatusTask::Done));
	ui->countCompletedLbl->setText(getCountTask(StatusTask::Completed));
}

void TaskWindow::createTaskWidget()
{	
	for (int i = 0; i < getTaskData().size(); ++i) {
		TaskWidget* taskWidget = new
			TaskWidget(this, getTaskData()[i][0], getTaskData()[i][1], getTaskData()[i][2], getTaskData()[i][3], getTaskData()[i][4]);
		tasksWidget <<taskWidget;	
	}
	int i = 0;
	foreach(TaskWidget *widget, tasksWidget) {
		if (getCountTask(StatusTask::Do).toInt() != 0 and widget->statusTask.toInt() == 1) {
			ui->tasksLayout->addWidget(widget, i, 0);
		}
		if (getCountTask(StatusTask::Work).toInt() != 0 and widget->statusTask.toInt() == 2) {
			i = 0;
			ui->tasksLayout->addWidget(widget, i, 1);
		}
		if (getCountTask(StatusTask::Done).toInt() != 0 and widget->statusTask.toInt() == 3) {
			i = 0;
			ui->tasksLayout->addWidget(widget, i, 2);
		}
		if (getCountTask(StatusTask::Completed).toInt() != 0 and widget->statusTask.toInt() == 4) {
			i = 0;
			ui->tasksLayout->addWidget(widget, i, 3);
		}
		i++;
	}
}

QList<QStringList> TaskWindow::getTaskData()
{	
	QList<QStringList> listTaskData;
	result res = parent->pool->runQuery("Select \"nameTask\", \"textTask\", \"dateTask\", \"executorTask\", \"statusTask\" from tasks");
	for(int i = 0; i<res.size();i++){
		taskData = { res[i][0].c_str(), res[i][1].c_str(), res[i][2].c_str(), res[i][3].c_str(), res[i][4].c_str() };
		listTaskData.append(taskData);
	}
	return listTaskData;
}

