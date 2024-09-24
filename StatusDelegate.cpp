#include "StatusDelegate.h"
#include <QAbstractItemView>
#include <QPainter>
StatusDelegate::StatusDelegate(QObject* parent):QStyledItemDelegate(parent)
{
}

void StatusDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QAbstractItemView* tableView;
	if (tableView = qobject_cast<QAbstractItemView*>(this->parent())) {
		if (index.data().toString() == "Новая заявка")
		{		
			painter->fillRect(option.rect, Qt::red);
		}
		else if (index.data().toString() == "Переговоры")
		{
			painter->fillRect(option.rect, Qt::yellow);
		}
		else if (index.data().toString() == "Принятие решения")
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
