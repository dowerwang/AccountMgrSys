#pragma once
#pragma execution_character_set("utf-8") 

#include <QtWidgets/QMainWindow>
#include "SQLiteHelper.h"
#include "ui_AccountMgrSys.h"
#include "AccountEditer.h"
#include "MedicineEditor.h"
#include "PatientBrowseDialog.h"
#include "RecordBrowseDialog.h"
#include "AreaEditor.h"
#include "SysSettings.h"
#include "DataCenter.h"
#include "RecordList.h"
#include "AddRecordDialog.h"
#include <QCloseEvent>
#include <QMessageBox>

class PatientTree;
class AccountMgrSys : public QMainWindow
{
	Q_OBJECT

public:
	AccountMgrSys(QWidget *parent = Q_NULLPTR);
	void initMainWindowLayout();
	void creatMenu();
	void creatToolBtn();
	//²Ëµ¥À¸¹¤¾ßÀ¸
public slots:
	void slotUserLogin();
	void slotSelectLocList();
	void slotSysSetting();

	void slotAddVillage();
	void slotAddGroup();
	void slotAddHousehold();
	void slotAddMember();
	void slotFindHousehold();
	void slotFindMember();
	void slotUseHelp();

	void slotUserMgr();
	void slotMedicineMgr();
	void slotPatientMgr();
	void slotRecordMgr();
	void slotAreaMgr();

	void slotAboutButtonClicked();

	void slotSearchItem(const QString &text);
	void slotAddRecord();
	void slotDeleteRecord();
	void slotSubmitRecord();
protected:
	void closeEvent(QCloseEvent *event);

private:
	Ui::AccountMgrSysClass ui;
	QAction *m_userLogin, *m_localArea, *m_sysSetting, *m_addVillage, *m_addGroup, *m_addHousehold, *m_addMember, *m_findHousehold, *m_findeMember, *m_useHelp;
	QAction *m_UserMgr, *m_medicineMgr, *m_patientMgr, *m_recordMgr;
	QAction *m_AreaMgr;
	QAction *m_help;
	SysSettings *m_sysSettingDialog = nullptr;
};
