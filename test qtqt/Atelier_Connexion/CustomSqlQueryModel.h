#ifndef CUSTOMSQLQUERYMODEL_H
#define CUSTOMSQLQUERYMODEL_H

#include <QSqlQueryModel>

class CustomSqlQueryModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit CustomSqlQueryModel(QObject *parent = nullptr);

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif // CUSTOMSQLQUERYMODEL_H
