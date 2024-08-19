#include "TaskWidget.h"

TaskWidget::TaskWidget(QWidget *parent)
	: QDialog(parent)
{
	ui->setupUi(this); 
	this->setModal(true);
}
TaskWidget::~TaskWidget()
{}
