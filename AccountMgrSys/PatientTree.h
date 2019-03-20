#pragma once
#pragma execution_character_set("utf-8") 

#include <QObject>
#include <QDebug>
#include <QMenu>
#include <QAction>
#include <QStandardItemModel>
#include <QDate>
#include "DataCenter.h"
#include "AddsSelectWidget.h"
#include "MultAddDialog.h"
#include "PatientAddDialog.h"
#include "SQLiteHelper.h"
#include "ui_AccountMgrSys.h"
#include "ui_PatientBrowseDialog.h"
#include "CustomFilterProxyModel.h"

#define ROLE_MARK Qt::UserRole + 1   //标识节点类型
#define ROLE_MARK_ID Qt::UserRole + 2 //表示ID
#define ROLE_MARK_Info Qt::UserRole + 3 //表示ID
//对应ROLE_MARK
#define MARK_Village 1 //这是村标记
#define MARK_Group 2 //这是组标记
#define MARK_HouseHold 3 //户主标记
#define MARK_Patient 4 //人员标记
class AccountMgrSys;
class PatientBrowseDialog;
class PatientTree : public QObject
{
	Q_OBJECT
public:
	enum Opt_Mode
	{
		Mode_Edit,
		Mode_View
	};
	PatientTree();
	PatientTree(Ui::AccountMgrSysClass*,AccountMgrSys*);
	PatientTree(Ui::PatientBrowseDialog*, PatientBrowseDialog*);
	virtual ~PatientTree();
	void initTree();
	void initMenu();

	void displayPatientInfo(const QStandardItem* item,const PatientInfo& patient);

	void checkAllItem(QStandardItem *item,QString _text);
public slots:
	void slotAddVillage(); //增加村
	void slotAddGroup();	//增加组
	void slotAddHouseHold();	//添加户主
	void slotModifyHouseHold();	//修改户主
	void slotAddPatient();		//添加人员
	void slotModifyPatient();	//修改人员
	void slotDeletSelect();		//删除所选
	void slotSubmitBtnClicked(); //提交
	void slotCustomContextMenuRequested(const QPoint &pos);	//右键菜单

	void slotItemDoubleClicked(const QModelIndex &index);
	void slotItemClicked(const QModelIndex &index);
	void slotItemChanged(QStandardItem *item);

	void slotSearchItem(const QString &text);
private:
	Ui::AccountMgrSysClass* m_MainUi = nullptr;
	Ui::PatientBrowseDialog* m_EditUi = nullptr;
	QWidget * m_mainWindow = nullptr;
	Opt_Mode m_mode;

	QMap<int, QString> m_villageMap;
	QMap<int, QString> m_groupMap;
	QMap<QString, QString> m_houseHoldMap;
	QMap<QString, QString> m_patientMap;

	QString m_oldText;

	QMenu* m_villageMenu, *m_groupMenu, *m_houseHoldMenu, *m_patientMenu;
	QAction *m_addGroup, *m_deleteVillage;  //村
	QAction *m_addHouseHold, *m_deletGroup;   //组
	QAction *m_addPatient, *m_modifyHouseHoldInfo, *m_deleteHouseHold; //户主
	QAction *m_modifyPatientInfo, *m_deletePatient; //人员

	CustomFilterProxyModel *m_filterModel = nullptr;
	QStandardItem * getCurrentSourceItem();
	QString getPatientAge(QString _IdCar);
};

