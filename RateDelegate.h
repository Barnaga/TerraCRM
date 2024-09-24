#pragma once
#include <QStyledItemDelegate>

class RateDelegate :
    public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate = QStyledItemDelegate;
    RateDelegate(QObject* parent = nullptr);
    void paint(QPainter* painter, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
private slots:
    void commitAndCloseEditor();
};

