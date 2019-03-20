#include "AddsSelectWidget.h"
#include "SQLiteHelper.h"

AddsSelectWidget::AddsSelectWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initAreaInfo();
	connect(ui.comboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateProvinceList);
	connect(ui.comboBox_2, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateCityList);
	connect(ui.comboBox_3, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateAreaList);
	connect(ui.comboBox_4, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateTownList);
	connect(ui.comboBox_5, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateVillageList);
}

AddsSelectWidget::AddsSelectWidget(WidgetMode _mode, QWidget *parent)
	:m_widgetMode(_mode),QWidget(parent)
{
	ui.setupUi(this);
	if (m_widgetMode == AddsSelect_Mode)
	{
		ui.label->setText("��ѡ�������");
		ui.label_5->setText("��ѡ����壺");
	}
	initAreaInfo();
	connect(ui.comboBox, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateProvinceList);
	connect(ui.comboBox_2, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateCityList);
	connect(ui.comboBox_3, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateAreaList);
	connect(ui.comboBox_4, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateTownList);
	connect(ui.comboBox_5, static_cast<void(QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged), this, &AddsSelectWidget::slotUpdateVillageList);
}

AddsSelectWidget::~AddsSelectWidget()
{
}

void AddsSelectWidget::initAreaInfo()
{
	//��ʼ��ʡ
	gDataBaseMgr->getProvince(m_provinceMap);
	if (!m_provinceMap.isEmpty())
	{
		ui.comboBox->addItems(m_provinceMap.values());
		int _ret = ui.comboBox->findText("����ʡ");
		if (_ret != -1)
		{
			m_province.append(QString::number(m_provinceMap.key("����ʡ")));
			m_province.append("����ʡ");
			if (m_widgetMode == Setting_Mode)
			{
				gDataCenter->m_province.clear();
				gDataCenter->m_province = m_province;
			}
			m_provinceCode = m_provinceMap.key("����ʡ");
			ui.comboBox->setCurrentIndex(_ret);
			//��ʼ����
			gDataBaseMgr->getCityByProvinceID(m_provinceCode, m_cityMap);
			if (!m_cityMap.isEmpty())
			{
				ui.comboBox_2->addItems(m_cityMap.values());
				int _ret = ui.comboBox_2->findText("������");
				if (_ret != -1)
				{
					m_city.append(QString::number(m_cityMap.key("������")));
					m_city.append("������");
					if (m_widgetMode == Setting_Mode)
					{
						gDataCenter->m_city.clear();
						gDataCenter->m_city = m_city;
					}
					m_cityCode = m_cityMap.key("������");
					ui.comboBox_2->setCurrentIndex(_ret);
					//��ʼ����
					gDataBaseMgr->getAreaByCityID(m_cityCode, m_areaMap);
					if (!m_areaMap.isEmpty())
					{
						ui.comboBox_3->addItems(m_areaMap.values());
						int _ret = ui.comboBox_3->findText("��ɽ��");
						if (_ret != -1)
						{
							m_area.append(QString::number(m_areaMap.key("��ɽ��")));
							m_area.append("��ɽ��");
							if (m_widgetMode == Setting_Mode)
							{
								gDataCenter->m_area.clear();
								gDataCenter->m_area = m_area;
							}
							m_areaCode = m_areaMap.key("��ɽ��");
							ui.comboBox_3->setCurrentIndex(_ret);
							//��ʼ����
							gDataBaseMgr->getTownByAreaID(m_areaCode, m_townMap);
							if (!m_townMap.isEmpty())
							{
								ui.comboBox_4->addItems(m_townMap.values());
								int _ret = ui.comboBox_4->findText("������");
								if (_ret != -1)
								{
									m_town.append(QString::number(m_townMap.key("������")));
									m_town.append("������");
									if (m_widgetMode == Setting_Mode)
									{
										gDataCenter->m_town.clear();
										gDataCenter->m_town = m_town;
									}
									m_townCode = m_townMap.key("������");
									ui.comboBox_4->setCurrentIndex(_ret);
									//��ʼ����
									gDataBaseMgr->getVillageByTownID(m_townCode, m_villageMap);
									if (!m_villageMap.isEmpty())
									{
										ui.comboBox_5->addItems(m_villageMap.values());
										int _ret = ui.comboBox_5->findText("�����");
										if (_ret != -1)
										{
											m_village.append(QString::number(m_villageMap.key("�����")));
											m_village.append("�����");
											if (m_widgetMode == Setting_Mode)
											{
												gDataCenter->m_village.clear();
												gDataCenter->m_village = m_village;
											}
											m_townCode = m_villageMap.key("�����");
											ui.comboBox_5->setCurrentIndex(_ret);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}


}

void AddsSelectWidget::initProvinceList()
{
	gDataBaseMgr->getProvince(m_provinceMap);
	if (!m_provinceMap.isEmpty())
	{
		ui.comboBox->addItems(m_provinceMap.values());
	}
}

void AddsSelectWidget::initCityList()
{
	//��ʼ����
	m_cityMap.clear();
	m_city.clear();
	m_cityCode = -1;
	ui.comboBox_2->clear();
	gDataBaseMgr->getCityByProvinceID(m_provinceCode, m_cityMap);
	if (!m_cityMap.isEmpty())
	{
		ui.comboBox_2->addItems(m_cityMap.values());
		ui.comboBox_2->setCurrentIndex(0);
		QString _curText = ui.comboBox_2->currentText();
		int _ret = ui.comboBox_2->findText(_curText);
		if (_ret != -1)
		{
			m_city.append(QString::number(m_cityMap.key(_curText)));
			m_city.append(_curText);
			m_cityCode = m_cityMap.key(_curText);
			//ui.comboBox_2->setCurrentIndex(_ret);
		}
	}
	initAreaList();
}

void AddsSelectWidget::initAreaList()
{
	//��ʼ����
	m_areaMap.clear();
	m_area.clear();
	m_areaCode = -1;
	ui.comboBox_3->clear();
	gDataBaseMgr->getAreaByCityID(m_cityCode, m_areaMap);
	if (!m_areaMap.isEmpty())
	{
		ui.comboBox_3->addItems(m_areaMap.values());
		ui.comboBox_3->setCurrentIndex(0);
		QString _curText = ui.comboBox_3->currentText();
		int _ret = ui.comboBox_3->findText(_curText);
		if (_ret != -1)
		{
			m_area.append(QString::number(m_areaMap.key(_curText)));
			m_area.append(_curText);
			m_areaCode = m_areaMap.key(_curText);
			//ui.comboBox_3->setCurrentIndex(_ret);
		}
	}
	initTownList();
}

void AddsSelectWidget::initTownList()
{
	//��ʼ����
	m_townMap.clear();
	m_town.clear();
	m_townCode = -1;
	ui.comboBox_4->clear();
	gDataBaseMgr->getTownByAreaID(m_areaCode, m_townMap);
	if (!m_townMap.isEmpty())
	{
		ui.comboBox_4->addItems(m_townMap.values());
		ui.comboBox_4->setCurrentIndex(0);
		QString _curText = ui.comboBox_4->currentText();
		int _ret = ui.comboBox_4->findText(_curText);
		if (_ret != -1)
		{
			m_town.append(QString::number(m_townMap.key(_curText)));
			m_town.append(_curText);
			m_townCode = m_townMap.key(_curText);
			//ui.comboBox_4->setCurrentIndex(_ret);

		}
	}
	initVillageList();
}

void AddsSelectWidget::initVillageList()
{
	//��ʼ����
	m_villageMap.clear();
	m_village.clear();
	m_villageCode = -1;
	ui.comboBox_5->clear();
	gDataBaseMgr->getVillageByTownID(m_townCode, m_villageMap);
	if (!m_villageMap.isEmpty())
	{
		ui.comboBox_5->addItems(m_villageMap.values());
		ui.comboBox_5->setCurrentIndex(0);
		QString _curText = ui.comboBox_5->currentText();
		int _ret = ui.comboBox_5->findText(_curText);
		if (_ret != -1)
		{
			m_village.append(QString::number(m_villageMap.key(_curText)));
			m_village.append(_curText);
			m_villageCode = m_villageMap.key(_curText);
			//ui.comboBox_5->setCurrentIndex(_ret);
		}
	}
}

void AddsSelectWidget::slotUpdateProvinceList(const QString& str)
{
	if (!m_provinceMap.isEmpty())
	{
		int _ret = ui.comboBox->findText(str);
		if (_ret != -1)
		{
			m_province.clear();
			m_province.append(QString::number(m_provinceMap.key(str)));
			m_province.append(str);
			if (m_widgetMode == Setting_Mode)
			{
				gDataCenter->m_province.clear();
				gDataCenter->m_province = m_province;
			}
			m_provinceCode = m_provinceMap.key(str);
			initCityList();
		}
	}
}

void AddsSelectWidget::slotUpdateCityList(const QString& str)
{
	if (!m_cityMap.isEmpty())
	{
		int _ret = ui.comboBox_2->findText(str);
		if (_ret != -1)
		{
			m_city.clear();
			m_city.append(QString::number(m_cityMap.key(str)));
			m_city.append(str);
			if (m_widgetMode == Setting_Mode)
			{
				gDataCenter->m_city.clear();
				gDataCenter->m_city = m_city;
			}
			m_cityCode = m_cityMap.key(str);
			initAreaList();
		}
	}
}

void AddsSelectWidget::slotUpdateAreaList(const QString& str)
{
	if (!m_areaMap.isEmpty())
	{
		int _ret = ui.comboBox_3->findText(str);
		if (_ret != -1)
		{
			m_area.clear();
			m_area.append(QString::number(m_areaMap.key(str)));
			m_area.append(str);
			if (m_widgetMode == Setting_Mode)
			{
				gDataCenter->m_area.clear();
				gDataCenter->m_area = m_area;
			}
			m_areaCode = m_areaMap.key(str);
			initTownList();
		}
	}
}

void AddsSelectWidget::slotUpdateTownList(const QString& str)
{
	if (!m_townMap.isEmpty())
	{
		int _ret = ui.comboBox_4->findText(str);
		if (_ret != -1)
		{
			m_town.clear();
			m_town.append(QString::number(m_townMap.key(str)));
			m_town.append(str);
			if (m_widgetMode == Setting_Mode)
			{
				gDataCenter->m_town.clear();
				gDataCenter->m_town = m_town;
			}
			m_townCode = m_townMap.key(str);
			initVillageList();
		}
	}
}

void AddsSelectWidget::slotUpdateVillageList(const QString& str)
{
	if (!m_villageMap.isEmpty())
	{
		int _ret = ui.comboBox_5->findText(str);
		if (_ret != -1)
		{
			m_village.clear();
			m_village.append(QString::number(m_villageMap.key(str)));
			m_village.append(str);
			if (m_widgetMode == Setting_Mode)
			{
				gDataCenter->m_village.clear();
				gDataCenter->m_village = m_village;
			}
			m_villageCode = m_villageMap.key(str);
		}
	}
}
