#pragma once
#include <QSortFilterProxyModel>
class CustomFilterProxyModel :
	public QSortFilterProxyModel
{
public:
	CustomFilterProxyModel(QObject *parent = Q_NULLPTR);
	virtual ~CustomFilterProxyModel();
protected:
	bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
	bool filterAcceptsRowItself(int source_row, const QModelIndex &source_parent) const;
	bool hasAcceptedChildren(int source_row, const QModelIndex &source_parent) const;
};

