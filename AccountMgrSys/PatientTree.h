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

#define ROLE_MARK Qt::UserRole + 1   //��ʶ�ڵ�����
#define ROLE_MARK_ID Qt::UserRole + 2 //��ʾID
#define ROLE_MARK_Info Qt::UserRole + 3 //��ʾID
//��ӦROLE_MARK
#define MARK_Village 1 //���Ǵ���
#define MARK_Group 2 //��������
#define MARK_HouseHold 3 //�������
#define MARK_Patient 4 //��Ա���
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
	void slotAddVillage(); //���Ӵ�
	void slotAddGroup();	//������
	void slotAddHouseHold();	//��ӻ���
	void slotModifyHouseHold();	//�޸Ļ���
	void slotAddPatient();		//�����Ա
	void slotModifyPatient();	//�޸���Ա
	void slotDeletSelect();		//ɾ����ѡ
	void slotSubmitBtnClicked(); //�ύ
	void slotCustomContextMenuRequested(const QPoint &pos);	//�Ҽ��˵�

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
	QAction *m_addGroup, *m_deleteVillage;  //��
	QAction *m_addHouseHold, *m_deletGroup;   //��
	QAction *m_addPatient, *m_modifyHouseHoldInfo, *m_deleteHouseHold; //����
	QAction *m_modifyPatientInfo, *m_deletePatient; //��Ա

	CustomFilterProxyModel *m_filterModel = nullptr;
	QStandardItem * getCurrentSourceItem();
	QString getPatientAge(QString _IdCar);
};

