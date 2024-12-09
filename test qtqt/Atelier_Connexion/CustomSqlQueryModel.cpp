#include "CustomSqlQueryModel.h"

CustomSqlQueryModel::CustomSqlQueryModel(QObject *parent)
    : QSqlQueryModel(parent)
{
}

QVariant CustomSqlQueryModel::data(const QModelIndex &index, int role) const
{
    QVariant value = QSqlQueryModel::data(index, role);

    if (role == Qt::DisplayRole && index.column() == 3) { // 3 is the column index for TEL_CL
        return QString::number(value.toLongLong());
    }

    return value;
}

