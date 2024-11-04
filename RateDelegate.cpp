#include "RateDelegate.h"
#include <QPainter>
#include <QAbstractItemView>
RateDelegate::RateDelegate(QObject* parent):QStyledItemDelegate(parent)
{
}

void RateDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{	
	if (auto tableView = qobject_cast<QAbstractItemView*>(this->parent())) {
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
		else if (index.data().toString() == "Архивировано")
		{
			painter->fillRect(option.rect, Qt::gray);
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
	return QStyledItemDelegate::sizeHint(option, index);
}
void RateDelegate::commitAndCloseEditor() {

}
