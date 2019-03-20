#pragma once
#include <QObject>
#include "ui_AccountMgrSys.h"
#include "CommentData.h"
#include "AddRecordDialog.h"
#include <QMenu>
class AccountMgrSys;
//class PatientInfo;
class RecordList : public QObject
{
	Q_OBJECT
public:;
	RecordList();
	RecordList(Ui::AccountMgrSysClass*, AccountMgrSys*);
	virtual ~RecordList();
	void setCurrentPatient(const PatientInfo&);
	void reLoadAllRecord();
	void updateRecordInfoView();
public slots:
	void slotSearchRecord(const QString &text);
	void slotAddRecord();
	void slotDeleteRecord();
	void slotSubmitBtnClicked();
	void slotTableDoubleClicked(const QModelIndex &index);
	void sortByColumn(int);
	void slotUpdateRecordList();
	void slotItemDataChanged();
private:
	Ui::AccountMgrSysClass* m_MainUi = nullptr;
	AccountMgrSys * m_mainWindow = nullptr;
	PatientInfo m_patientInfo;
	QMenu   m_Menu;
};

