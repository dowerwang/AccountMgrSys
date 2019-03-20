#pragma once
#pragma execution_character_set("utf-8") 

#include <QDialog>
#include "ui_SysSettings.h"
#include "AddsSelectWidget.h"

class SysSettings : public QDialog
{
	Q_OBJECT

public:
	SysSettings(QWidget *parent = Q_NULLPTR);
	~SysSettings();
//	void initAreaInfo();
//	QStringList& getProvince() { return m_province; }
//	QStringList& getCity() { return m_city; }
//	QStringList& getArea() { return m_area; }
//	QStringList& getTown() { return m_town; }
//	QStringList& getVillage() { return m_village; }
//	void initProvinceList();
//	void initCityList();
//	void initAreaList();
//	void initTownList();
//	void initVillageList();
//public slots:
//	void slotUpdateProvinceList(const QString& str);
//	void slotUpdateCityList(const QString& str);
//	void slotUpdateAreaList(const QString& str);
//	void slotUpdateTownList(const QString& str);
	//void slotUpdateVillageList(const QString& str);
private:
	Ui::SysSettings ui;
	AddsSelectWidget* m_addselectWidget = nullptr;
	//int m_provinceCode;
	//QStringList m_province;
	//int m_cityCode;
	//QStringList m_city;
	//int m_areaCode;
	//QStringList m_area;
	//int m_townCode;
	//QStringList m_town;
	//int m_villageCode;
	//QStringList m_village;

	//QMap<int, QString> m_provinceMap;
	//QMap<int, QString> m_cityMap;
	//QMap<int, QString> m_areaMap;
	//QMap<int, QString> m_townMap;
	//QMap<int, QString> m_villageMap;
	//QMap<int, QString> m_groupMap;
};
