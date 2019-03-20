#include "CustomSqlTableModel.h"

CustomSqlTableModel::CustomSqlTableModel(QObject *parent, QSqlDatabase db)
	:  QSqlTableModel(parent, db)
{
}

CustomSqlTableModel::~CustomSqlTableModel()
{
}

QVariant CustomSqlTableModel::data(const QModelIndex &index, int role) const
{
	QVariant value = QSqlQueryModel::data(index, role);
	/*if (role == Qt::DisplayRole)
	{
		if (index.column() == 2)
		{
			if (value.toInt() == 1)
				return value = "��";
			if (value.toInt() == 2)
				return value = "Ů";
			if (value.toInt() == 0)
				return value = "����";
		}
	}*/
	if (role == Qt::TextAlignmentRole)
	{
		value = (Qt::AlignCenter);
		return value;
	}
	return value;
}
