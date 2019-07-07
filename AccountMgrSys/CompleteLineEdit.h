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

	void setCompleter(const QString &text); // ��̬����ʾ����б�

	void completeText(const QModelIndex &index); // �������б��е��ʹ�ô����Զ��������ĵ���

protected:

	virtual void keyPressEvent(QKeyEvent *e);

	virtual void focusOutEvent(QFocusEvent *e);



private:

	QStringList m_words; // ��������б�ĵ���

	QListView *m_listView=nullptr; // ����б�

	QStringListModel *m_model=nullptr; // ����б��model
	QStandardItemModel *m_stdmodel=nullptr; // ����б��model
	QSortFilterProxyModel *m_filterModel = nullptr;

	QList<MedicineInfo> m_medicineList;
	MedicineInfo m_currentMedicine;
};
