#pragma once
#pragma execution_character_set("utf-8") 

#include "CommentData.h"
#include <QLineEdit>
#include <QMetaType>
class QListView;
class QStringListModel;
class QModelIndex;
class QStandardItemModel;
class QSortFilterProxyModel;
Q_DECLARE_METATYPE(MedicineInfo)
class CompleteLineEdit : public QLineEdit
{
	Q_OBJECT

public:
	CompleteLineEdit(QWidget *parent);
	~CompleteLineEdit();
	void initMedicineModel();
	bool isListViewHidden();
signals:
	void addUsemedicine(const MedicineInfo& medicine);
public slots:

	void setCompleter(const QString &text); // 动态的显示完成列表

	void completeText(const QModelIndex &index); // 点击完成列表中的项，使用此项自动完成输入的单词

protected:

	virtual void keyPressEvent(QKeyEvent *e);

	virtual void focusOutEvent(QFocusEvent *e);



private:

	QStringList m_words; // 整个完成列表的单词

	QListView *m_listView=nullptr; // 完成列表

	QStringListModel *m_model=nullptr; // 完成列表的model
	QStandardItemModel *m_stdmodel=nullptr; // 完成列表的model
	QSortFilterProxyModel *m_filterModel = nullptr;

	QList<MedicineInfo> m_medicineList;
	MedicineInfo m_currentMedicine;
};
