#pragma once
#include <QStyledItemDelegate>

class RateDelegate :
    public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate = QStyledItemDelegate;
    RateDelegate(QObject* parent = nullptr);
    RateDelegate(RateDelegate& r) = delete;
    RateDelegate(RateDelegate&& r) = delete;
    RateDelegate& operator=(const RateDelegate& r)= delete;
    RateDelegate& operator=(const RateDelegate&& r) = delete;
    void paint(QPainter* painter, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
    QSize sizeHint(const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;
private slots:
    void commitAndCloseEditor();
};

