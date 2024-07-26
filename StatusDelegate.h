#pragma once
#include <QStyledItemDelegate>

class StatusDelegate :
    public QStyledItemDelegate
{
public:
    using QStyledItemDelegate = QStyledItemDelegate;
    StatusDelegate(QObject* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
};

