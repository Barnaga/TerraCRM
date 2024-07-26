#include "RateDelegate.h"
#include <QPainter>
#include <QAbstractItemView>
#include <QComboBox>
#include <qmessagebox.h>
RateDelegate::RateDelegate(QObject* parent):QStyledItemDelegate(parent)
{
}

void RateDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{	
	QAbstractItemView* tableView;
	if (tableView = qobject_cast<QAbstractItemView*>(this->parent())) {
		if (index.data().toString() == "Сделать")
		{
			painter->fillRect(option.rect, Qt::red);
		}
		else if (index.data().toString() == "В работе")
		{
			painter->fillRect(option.rect, Qt::yellow);
		}
		else if (index.data().toString() == "Сделано")
		{
			painter->fillRect(option.rect, Qt::blue);
		}
		else
		{
			painter->fillRect(option.rect, Qt::green);
		}
	}
	QStyledItemDelegate::paint(painter, option, index);
	
}
QSize RateDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	return QSize();
}

QWidget* RateDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

	QComboBox* dlg = new QComboBox(parent);
	dlg->addItem("Сделать");
	dlg->addItem("В работе");
	dlg->addItem("Сделано");
	dlg->addItem("Завершено");

	return dlg;
}

void RateDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
	QComboBox* comboBox = dynamic_cast<QComboBox*>(editor);
	int value = index.data(Qt::EditRole).toInt();

	comboBox->setCurrentIndex(value);
}

void RateDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
	QComboBox* dialog = static_cast<QComboBox*>(editor);
	if (dialog->model()->rowCount() != 0) {
		model->setData(index, dialog->currentData(Qt::DisplayRole));
	}
	else {
		QMessageBox msgBox;
		msgBox.setText("is Empty");
		msgBox.exec();
	}
}


void RateDelegate::commitAndCloseEditor() {

}
