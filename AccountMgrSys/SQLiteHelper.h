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

	//创建数据库并建立连接
	bool openAccountDB(void);
	bool openAreaDB(void);
	//关闭数据库
	void closeDb(void);
	//获取数据库对象
	QSqlDatabase& getAccountDB();
	QSqlDatabase& getAreaDB();
	//**Account**//
	//添加管理员
	bool addSupUser(const SupUserInfo&);
	//删除管理员
	bool deleteSupUser(const SupUserInfo&);
	//更新管理员信息
	bool updateSupUser(const SupUserInfo&);
	//查询管理员信息By管理员ID
	bool querySupUser(QList<SupUserInfo>&);
	//查询管理员信息By管理员ID
	bool querySupUserByID(const int & id, SupUserInfo&);
	//查询管理员信息By管理员名字
	bool querySupUserByName(const QString & supUserName, QList<SupUserInfo>&);
	//查询管理员信息By自定义信息
	bool querySupUserByCustom(const QString & name, const QString propertyName, QList<SupUserInfo>&);

	//**Patient**//
	//添加人员
	bool addPatient(const PatientInfo&);
	//删除人员
	bool deletePatient(const PatientInfo&);
	bool deletePatient(const QString& patientID);
	//更新人员信息
	bool updatePatient(const QString &_oldIDCar, const PatientInfo&);
	bool updatePatient(const QString &id, const QString &name);
	//查询人员信息By人员ID
	bool queryPatientByID(const QString & id, PatientInfo&);
	QString queryPatientNameByID(const QString & id);
	//查询人员信息By人员名字
	bool queryPatientByName(const QString & patientName, QList<PatientInfo>&);
	//查询人员信息By组名
	bool queryPatientByGroup(const QString & groupName, QList<PatientInfo>&);
	//查询人员信息By自定义信息
	bool queryPatientByCustom(const QString & name, const QString & propertyName, QList<PatientInfo>&);

	//**Medicine**//
	//添加药品
	bool addMedicine(const MedicineInfo&);
	//删除药品
	bool deleteMedicine(const MedicineInfo&);
	//更新药品信息
	bool updateMedicine(const MedicineInfo&);
	//查询所有药品
	bool queryMedicine(QList<MedicineInfo>&);
	//查询药品信息ByID
	bool queryMedicineByID(const int & id, MedicineInfo&);
	//查询药品信息ByName
	bool queryMedicineByName(const QString & medicineName, QList<MedicineInfo>&);
	//查询药品信息By自定义信息
	bool queryMedicineByCustom(const QString & name, const QString & propertyName, QList<MedicineInfo>&);
	//查询行数
	int medicineRawQuery();

	//**Record**//
	//添加记录
	bool addRecord(const RecordInfo&);
	//删除记录
	bool deleteRecord(const RecordInfo&);
	//更新记录信息
	bool updateRecord(const RecordInfo&);
	//查询记录ByID
	bool queryRecordByID(const int & id, RecordInfo&);
	//查询记录By人员姓名
	bool queryRecordByPatientID(const QString & patientName, QList<RecordInfo>&);
	//查询记录By自定义信息
	bool queryRecordByCustom(const QString & name, const QString & propertyName, QList<RecordInfo>&);

	//****Area****//
	//**区域信息**//
	//获取所有省
	bool getProvince(QMap<int,QString> &);
	//获取城市列表By省ID
	bool getCityByProvinceID(const int &, QMap<int, QString> &);
	//获取区列表By市ID
	bool getAreaByCityID(const int &, QMap<int, QString> &);
	//获取镇列表By区ID
	bool getTownByAreaID(const int &, QMap<int, QString> &);
	//获取村列表By镇ID
	bool getVillageByTownID(const int &, QMap<int, QString> &);
	//获取组列表By村ID
	bool getGroupByVillageID(const int &, QMap<int, QString> &);
	//获取户主列表By组ID
	bool getHouseHoldByGroupID(const int &, QMap<QString, QString> &);
	//获取人员列表By户主ID
	bool getPatientByHouseHoldID(const QString &, QMap<QString, QString> &);

	//添加镇
	bool addTown(const QString &name, const int & areaCode);
	//修改镇
	bool updateTown(const int &id, const QString &name);
	//删除镇
	bool deleteTown(const int &id);
	//查找镇
	int queryTown(const QString &name);

	//添加村
	bool addVillage(const QString &name, const int & townCode);
	//修改村
	bool updateVillage(const int &id, const QString &name);
	//删除村
	bool deleteVillage(const int &id);
	//查找村
	int queryVillage(const QString &name);

	//添加组
	bool addGroup(const QString &name, const int & villageCode);
	//修改组
	bool updateGroup(const int &id, const QString &name);
	//删除组
	bool deleteGroup(const int &id);
	//查找组
	int queryGroup(const QString &name);

	//添加户主
	bool addHouseHold(const QString &id, const QString &name, const int & loacalGroupCode);
	//修改户主
	bool updateHouseHold(const QString &id, const QString &name);
	bool updateHouseHold(const QString &oldid,const QString &id, const QString &name);
	//删除户主
	bool deleteHouseHold(const QString &id);
	//查找户主
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
