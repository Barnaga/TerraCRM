#pragma once
#include "QDate"
#include "QStyledItemDelegate"


class DateDelegate :
    public QStyledItemDelegate
{
    Q_OBJECT
    public:
        DateDelegate() {};
        QString displayText(const QVariant& value, const QLocale& locale) const;
};

