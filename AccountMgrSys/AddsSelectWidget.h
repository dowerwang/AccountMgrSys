#pragma once
#pragma execution_character_set("utf-8") 

#include <QWidget>
#include "ui_AddsSelectWidget.h"
#include "DataCenter.h"

class AddsSelectWidget : public QWidget
{
	Q_OBJECT

public:
	enum WidgetMode {
		Setting_Mode,
		AddsSelect_Mode
	};
	AddsSelectWidget(QWidget *parent = Q_NULLPTR);
	AddsSelectWidget(WidgetMode _mode, QWidget *parent = Q_NULLPTR);
	~AddsSelectWidget();
	void initAreaInfo();
	QStringList& getProvince() { return m_province; }
	QStringList& getCity() { return m_city; }
	QStringList& getArea() { return m_area; }
	QStringList& getTown() { return m_town; }
	QStringList& getVillage() { return m_village; }
	void initProvinceList();
	void initCityList();
	void initAreaList();
	void initTownList();
	void initVillageList();
public slots:
	void slotUpdateProvinceList(const QString& str);
	void slotUpdateCityList(const QString& str);
	void slotUpdateAreaList(const QString& str);
	void slotUpdateTownList(const QString& str);
	void slotUpdateVillageList(const QString& str);
private:
	Ui::AddsSelectWidget ui;
	WidgetMode m_widgetMode;

	int m_provinceCode;
	QStringList m_province;
	int m_cityCode;
	QStringList m_city;
	int m_areaCode;
	QStringList m_area;
	int m_townCode;
	QStringList m_town;
	int m_villageCode;
	QStringList m_village;

	//´¢´æ²éÑ¯½á¹û
	QMap<int, QString> m_provinceMap;
	QMap<int, QString> m_cityMap;
	QMap<int, QString> m_areaMap;
	QMap<int, QString> m_townMap;
	QMap<int, QString> m_villageMap;
	QMap<int, QString> m_groupMap;
};
