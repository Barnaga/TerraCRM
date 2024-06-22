#include "TaskWidget.h"
TaskWidget::TaskWidget(QWidget* parent, QString name, QString text, QString date, QString executor, QString status) :
	parent(dynamic_cast<MainWindow*>(parent)) 
{
	this->setStyleSheet("QWidget {background: rgb(255,253,253); padding: 10px 10px; }");
	
	taskLayout = new QVBoxLayout(this);
	taskLayout->setSpacing(0);
	taskLayout->setContentsMargins(0,10,0,0);
	nameTaskLbl = new QLabel(this);
	textTaskLbl = new QLabel(this);
	dateTaskLbl = new QLabel(this);
	executorTaskLbl = new QLabel(this);

	nameTaskLbl->setText(name);
	textTaskLbl->setText(text);
	dateTaskLbl->setText(date);
	statusTask = status;
	executorTaskLbl->setText(executor);
	
	taskLayout->addWidget(nameTaskLbl);
	taskLayout->addWidget(textTaskLbl);
	taskLayout->addWidget(dateTaskLbl);
	taskLayout->addWidget(executorTaskLbl);
	
	
}

TaskWidget::~TaskWidget() {
}