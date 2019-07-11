#pragma once

#define gDataCenter DataCenter::getInstence()
#include <QStringList>
#include <QStandardItemModel>
#include "RecordList.h"
class DataCenter
{
public:
	static DataCenter* getInstence();
	virtual ~DataCenter();
	QStringList& getProvince() { return m_province; }
	QStringList& getCity() { return m_city; }
	QStringList& getArea() { return m_area; }
	QStringList& getTown() { return m_town; }
	QStringList& getVillage() { 
		return m_village; 
	}
	QString getAddsStr();

	void setPatientTreeModel(QStandardItemModel *_model) { m_patientModel = _model; }
	QStandardItemModel* getPatientTreeModel();

	void setRecordList(RecordList* _recordList) { m_recordList = _recordList; }
	RecordList* getRecordList();

	void setCurrentPatienInfo(const PatientInfo & patient) { m_currentPatientInfo = patient; }
	PatientInfo getCurrentPatientInfo() { return m_currentPatientInfo; }

	void setCurrentSupUserInfo(const SupUserInfo & supUser) { m_currentSupUserInfo = supUser; }
	SupUserInfo getCurrentSupUserInfo() { return m_currentSupUserInfo; }
	//
	QStringList m_province;
	QStringList m_city;
	QStringList m_area;
	QStringList m_town;
	QStringList m_village;
private:
	DataCenter();
	static DataCenter* m_dataCenter;
	static QStandardItemModel* m_patientModel;
	RecordList* m_recordList = nullptr;
	SupUserInfo m_currentSupUserInfo;
	PatientInfo m_currentPatientInfo;
};

