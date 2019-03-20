#include "DataCenter.h"

DataCenter* DataCenter::m_dataCenter = nullptr;
QStandardItemModel* DataCenter::m_patientModel = nullptr;

DataCenter::DataCenter()
{
}


DataCenter* DataCenter::getInstence()
{
	if (m_dataCenter == nullptr)
	{
		m_dataCenter = new DataCenter;
	}
	return m_dataCenter;
}

DataCenter::~DataCenter()
{
}

QString DataCenter::getAddsStr()
{
	if (m_village.isEmpty())
		return "";
	return m_province[1] + m_city[1] + m_area[1] + m_town[1] + m_village[1];
}

QStandardItemModel* DataCenter::getPatientTreeModel()
{
	if (m_patientModel)
		return m_patientModel;
	else
	{
		m_patientModel = new QStandardItemModel();
		return m_patientModel;
	}
}

RecordList* DataCenter::getRecordList()
{
	if (m_recordList)
		return m_recordList;
	else
		return nullptr;
}
