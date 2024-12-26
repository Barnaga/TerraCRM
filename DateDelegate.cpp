#include "DateDelegate.h"
QString DateDelegate::displayText(const QVariant& value, const QLocale& locale) const
{
    return QStyledItemDelegate::displayText(value.toDate().toString("dd.MM.yyyy"), locale);
}