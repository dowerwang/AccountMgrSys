#pragma once

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QObject>
#include "CommentData.h"

#define gDataBaseMgr SQLiteHelper::getInstence()

class SQLiteHelper : public QObject
{
	Q_OBJECT

public:
	static SQLiteHelper* getInstence();
	~SQLiteHelper();

public:
	int isOpened();

	//�������ݿⲢ��������
	bool openAccountDB(void);
	bool openAreaDB(void);
	//�ر����ݿ�
	void closeDb(void);
	//��ȡ���ݿ����
	QSqlDatabase& getAccountDB();
	QSqlDatabase& getAreaDB();
	//**Account**//
	//��ӹ���Ա
	bool addSupUser(const SupUserInfo&);
	//ɾ������Ա
	bool deleteSupUser(const SupUserInfo&);
	//���¹���Ա��Ϣ
	bool updateSupUser(const SupUserInfo&);
	//��ѯ����Ա��ϢBy����ԱID
	bool querySupUser(QList<SupUserInfo>&);
	//��ѯ����Ա��ϢBy����ԱID
	bool querySupUserByID(const int & id, SupUserInfo&);
	//��ѯ����Ա��ϢBy����Ա����
	bool querySupUserByName(const QString & supUserName, QList<SupUserInfo>&);
	//��ѯ����Ա��ϢBy�Զ�����Ϣ
	bool querySupUserByCustom(const QString & name, const QString propertyName, QList<SupUserInfo>&);

	//**Patient**//
	//�����Ա
	bool addPatient(const PatientInfo&);
	//ɾ����Ա
	bool deletePatient(const PatientInfo&);
	bool deletePatient(const QString& patientID);
	//������Ա��Ϣ
	bool updatePatient(const QString &_oldIDCar, const PatientInfo&);
	bool updatePatient(const QString &id, const QString &name);
	//��ѯ��Ա��ϢBy��ԱID
	bool queryPatientByID(const QString & id, PatientInfo&);
	QString queryPatientNameByID(const QString & id);
	//��ѯ��Ա��ϢBy��Ա����
	bool queryPatientByName(const QString & patientName, QList<PatientInfo>&);
	//��ѯ��Ա��ϢBy����
	bool queryPatientByGroup(const QString & groupName, QList<PatientInfo>&);
	//��ѯ��Ա��ϢBy�Զ�����Ϣ
	bool queryPatientByCustom(const QString & name, const QString & propertyName, QList<PatientInfo>&);

	//**Medicine**//
	//���ҩƷ
	bool addMedicine(const MedicineInfo&);
	//ɾ��ҩƷ
	bool deleteMedicine(const MedicineInfo&);
	//����ҩƷ��Ϣ
	bool updateMedicine(const MedicineInfo&);
	//��ѯ����ҩƷ
	bool queryMedicine(QList<MedicineInfo>&);
	//��ѯҩƷ��ϢByID
	bool queryMedicineByID(const int & id, MedicineInfo&);
	//��ѯҩƷ��ϢByName
	bool queryMedicineByName(const QString & medicineName, QList<MedicineInfo>&);
	//��ѯҩƷ��ϢBy�Զ�����Ϣ
	bool queryMedicineByCustom(const QString & name, const QString & propertyName, QList<MedicineInfo>&);
	//��ѯ����
	int medicineRawQuery();

	//**Record**//
	//��Ӽ�¼
	bool addRecord(const RecordInfo&);
	//ɾ����¼
	bool deleteRecord(const RecordInfo&);
	//���¼�¼��Ϣ
	bool updateRecord(const RecordInfo&);
	//��ѯ��¼ByID
	bool queryRecordByID(const int & id, RecordInfo&);
	//��ѯ��¼By��Ա����
	bool queryRecordByPatientID(const QString & patientName, QList<RecordInfo>&);
	//��ѯ��¼By�Զ�����Ϣ
	bool queryRecordByCustom(const QString & name, const QString & propertyName, QList<RecordInfo>&);

	//****Area****//
	//**������Ϣ**//
	//��ȡ����ʡ
	bool getProvince(QMap<int,QString> &);
	//��ȡ�����б�ByʡID
	bool getCityByProvinceID(const int &, QMap<int, QString> &);
	//��ȡ���б�By��ID
	bool getAreaByCityID(const int &, QMap<int, QString> &);
	//��ȡ���б�By��ID
	bool getTownByAreaID(const int &, QMap<int, QString> &);
	//��ȡ���б�By��ID
	bool getVillageByTownID(const int &, QMap<int, QString> &);
	//��ȡ���б�By��ID
	bool getGroupByVillageID(const int &, QMap<int, QString> &);
	//��ȡ�����б�By��ID
	bool getHouseHoldByGroupID(const int &, QMap<QString, QString> &);
	//��ȡ��Ա�б�By����ID
	bool getPatientByHouseHoldID(const QString &, QMap<QString, QString> &);

	//�����
	bool addTown(const QString &name, const int & areaCode);
	//�޸���
	bool updateTown(const int &id, const QString &name);
	//ɾ����
	bool deleteTown(const int &id);
	//������
	int queryTown(const QString &name);

	//��Ӵ�
	bool addVillage(const QString &name, const int & townCode);
	//�޸Ĵ�
	bool updateVillage(const int &id, const QString &name);
	//ɾ����
	bool deleteVillage(const int &id);
	//���Ҵ�
	int queryVillage(const QString &name);

	//�����
	bool addGroup(const QString &name, const int & villageCode);
	//�޸���
	bool updateGroup(const int &id, const QString &name);
	//ɾ����
	bool deleteGroup(const int &id);
	//������
	int queryGroup(const QString &name);

	//��ӻ���
	bool addHouseHold(const QString &id, const QString &name, const int & loacalGroupCode);
	//�޸Ļ���
	bool updateHouseHold(const QString &id, const QString &name);
	bool updateHouseHold(const QString &oldid,const QString &id, const QString &name);
	//ɾ������
	bool deleteHouseHold(const QString &id);
	//���һ���
	QString queryHouseHold(const QString &name);
	QString queryHouseHoldByID(const QString &id);
private:
	static SQLiteHelper* m_DatabaseMgr;
	SQLiteHelper(QObject *parent = nullptr);
	void initAccountDB();
	void initAreaInfoDB();
	QSqlDatabase m_AccountDB;
	QSqlDatabase m_AreaDB;
};
