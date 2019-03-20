#pragma once
#pragma execution_character_set("utf-8") 

#include <QObject>
#include <QSql>
#include <QSqlTableModel>
#include <QVariant>
class CustomSqlTableModel : public QSqlTableModel
{
	Q_OBJECT

public:
	CustomSqlTableModel(QObject *parent, QSqlDatabase db = QSqlDatabase());
	~CustomSqlTableModel();
	QVariant data(const QModelIndex &index, int role) const;
};
