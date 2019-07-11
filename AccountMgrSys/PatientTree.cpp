#include "PatientTree.h"
#include "AccountMgrSys.h"
#include "PatientBrowseDialog.h"
#include <QSortFilterProxyModel>

PatientTree::PatientTree()
{
}


PatientTree::PatientTree(Ui::AccountMgrSysClass* _ui, AccountMgrSys*_mainwindow)
	:m_MainUi(_ui), m_mainWindow(_mainwindow)
{
	m_mode = Mode_View;
	QStandardItemModel* model = gDataCenter->getPatientTreeModel();

	m_filterModel = new CustomFilterProxyModel();
	m_filterModel->setSourceModel(model);
	m_filterModel->setFilterKeyColumn(0);
	m_filterModel->setFilterRole(Qt::DisplayRole);

	m_MainUi->treeView->setModel(m_filterModel);
	m_MainUi->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
	m_MainUi->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	connect(m_MainUi->treeView, &QTreeView::customContextMenuRequested, this, &PatientTree::slotCustomContextMenuRequested);
	connect(m_MainUi->treeView, &QTreeView::doubleClicked, this, &PatientTree::slotItemDoubleClicked);
	model->setHorizontalHeaderLabels(QStringList() << "人员信息");
	//connect(model, &QStandardItemModel::itemChanged, this, &PatientTree::slotItemChanged);
	m_MainUi->lineEdit->setPlaceholderText("查询户主/人员");
	connect(m_MainUi->lineEdit, &QLineEdit::textChanged, this, &PatientTree::slotSearchItem);
	initTree();
	initMenu();
}

PatientTree::PatientTree(Ui::PatientBrowseDialog* _ui, PatientBrowseDialog* _mainwindow)
	:m_EditUi(_ui), m_mainWindow(_mainwindow)
{
	m_mode = Mode_Edit;
	QStandardItemModel* model = gDataCenter->getPatientTreeModel();

	m_filterModel = new CustomFilterProxyModel();
	m_filterModel->setSourceModel(model);
	m_filterModel->setFilterKeyColumn(0);
	m_filterModel->setFilterRole(Qt::DisplayRole);

	m_EditUi->treeView->setModel(m_filterModel);
	m_EditUi->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
	m_EditUi->treeView->setEditTriggers(QAbstractItemView::SelectedClicked);
	connect(m_EditUi->treeView, &QTreeView::customContextMenuRequested, this, &PatientTree::slotCustomContextMenuRequested);
	connect(m_EditUi->treeView, &QTreeView::clicked, this, &PatientTree::slotItemClicked);
	model->setHorizontalHeaderLabels(QStringList() << "人员信息");
	connect(model, &QStandardItemModel::itemChanged, this, &PatientTree::slotItemChanged);
	m_EditUi->lineEdit->setPlaceholderText("查询户主/人员");
	connect(m_EditUi->lineEdit, &QLineEdit::textChanged, this, &PatientTree::slotSearchItem);
	//initTree();
	initMenu();
}

PatientTree::~PatientTree()
{
}

void PatientTree::initTree()
{
	QStandardItemModel* _tempModel = qobject_cast<QStandardItemModel*>(dynamic_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model())->sourceModel());
	//初始化村
	m_villageMap.clear();
	QStringList villageList = gDataCenter->getVillage();
	if (villageList.isEmpty())
		return;
	QStandardItem* itemVillage = new QStandardItem(gDataCenter->getVillage()[1]);
	itemVillage->setData(MARK_Village, ROLE_MARK);
	itemVillage->setData(gDataCenter->getVillage()[0], ROLE_MARK_ID);
	_tempModel->appendRow(itemVillage);
	//初始化组
	m_groupMap.clear();
	gDataBaseMgr->getGroupByVillageID((gDataCenter->getVillage()[0]).toInt(), m_groupMap);
	if (!m_groupMap.isEmpty())
	{
		QMap<int, QString>::const_iterator it = m_groupMap.constBegin();
		for (it; it != m_groupMap.constEnd(); ++it)
		{
			QStandardItem* itemGroup = new QStandardItem(it.value());
			itemGroup->setData(MARK_Group, ROLE_MARK);
			itemGroup->setData(it.key(), ROLE_MARK_ID);
			itemVillage->appendRow(itemGroup);
			//初始化户主
			m_houseHoldMap.clear();
			gDataBaseMgr->getHouseHoldByGroupID(it.key(), m_houseHoldMap);
			if (!m_houseHoldMap.isEmpty())
			{
				QMap<QString, QString>::const_iterator itt = m_houseHoldMap.constBegin();
				for (itt; itt != m_houseHoldMap.constEnd(); ++itt)
				{
					QStandardItem* itemHouseHold = new QStandardItem(itt.value());
					itemHouseHold->setFlags(itemHouseHold->flags()&(~Qt::ItemIsEditable));
					itemHouseHold->setData(MARK_HouseHold, ROLE_MARK);
					itemHouseHold->setData(itt.key(), ROLE_MARK_ID);
					itemGroup->appendRow(itemHouseHold);
					//初始化人员
					m_patientMap.clear();
					gDataBaseMgr->getPatientByHouseHoldID(itt.key(), m_patientMap);
					if (!m_patientMap.isEmpty())
					{
						QMap<QString, QString>::const_iterator ittt = m_patientMap.constBegin();
						for (ittt; ittt != m_patientMap.constEnd(); ++ittt)
						{
							QStandardItem* itemPatient = new QStandardItem(ittt.value());
							itemPatient->setFlags(itemPatient->flags()&(~Qt::ItemIsEditable));
							itemPatient->setData(MARK_Patient, ROLE_MARK);
							itemPatient->setData(ittt.key(), ROLE_MARK_ID);
							itemHouseHold->appendRow(itemPatient);
						}
					}
				}
			}
		}
	}
	//}
//}
}

void PatientTree::initMenu()
{
	if (m_mode == PatientTree::Mode_Edit)
	{
		m_villageMenu = new QMenu(m_mainWindow);

		m_addGroup = new QAction("添加组", m_mainWindow);
		m_deleteVillage = new QAction("删除组", m_mainWindow);

		m_villageMenu->addAction(m_addGroup);
		m_villageMenu->addAction(m_deleteVillage);

		connect(m_addGroup, &QAction::triggered, this, &PatientTree::slotAddGroup);
		connect(m_deleteVillage, &QAction::triggered, this, &PatientTree::slotDeletSelect);
	}
	m_groupMenu = new QMenu(m_mainWindow);

	m_addHouseHold = new QAction("添加户主", m_mainWindow);
	m_deletGroup = new QAction("删除组", m_mainWindow);

	m_groupMenu->addAction(m_addHouseHold);
	m_groupMenu->addAction(m_deletGroup);

	connect(m_addHouseHold, &QAction::triggered, this, &PatientTree::slotAddHouseHold);
	connect(m_deletGroup, &QAction::triggered, this, &PatientTree::slotDeletSelect);

	m_houseHoldMenu = new QMenu(m_mainWindow);

	m_addPatient = new QAction("添加人员", m_mainWindow);
	m_modifyHouseHoldInfo = new QAction("修改户主信息", m_mainWindow);
	m_deleteHouseHold = new QAction("删除户主", m_mainWindow);

	m_houseHoldMenu->addAction(m_addPatient);
	m_houseHoldMenu->addAction(m_modifyHouseHoldInfo);
	m_houseHoldMenu->addAction(m_deleteHouseHold);

	connect(m_addPatient, &QAction::triggered, this, &PatientTree::slotAddPatient);
	connect(m_modifyHouseHoldInfo, &QAction::triggered, this, &PatientTree::slotModifyHouseHold);
	connect(m_deleteHouseHold, &QAction::triggered, this, &PatientTree::slotDeletSelect);

	m_patientMenu = new QMenu(m_mainWindow);

	m_modifyPatientInfo = new QAction("修改人员信息", m_mainWindow);
	m_deletePatient = new QAction("删除人员", m_mainWindow);

	m_patientMenu->addAction(m_modifyPatientInfo);
	m_patientMenu->addAction(m_deletePatient);

	connect(m_modifyPatientInfo, &QAction::triggered, this, &PatientTree::slotModifyPatient);
	connect(m_deletePatient, &QAction::triggered, this, &PatientTree::slotDeletSelect);
}

void PatientTree::displayPatientInfo(const QStandardItem* item, const PatientInfo& patient)
{
	m_MainUi->label_2->setText(patient.m_patientName);
	m_MainUi->label_4->setText(patient.m_patientSex);
	QString _age = getPatientAge(patient.m_patientIDCar);
	m_MainUi->label_6->setText(_age);//年龄
	m_MainUi->label_10->setText(patient.m_patientIDCar);
	m_MainUi->label_8->setText(patient.m_patientHouseHold);
	m_MainUi->label_12->setText(patient.m_patientTel);
	m_MainUi->label_14->setText(patient.m_patientAdds);
	m_MainUi->label_16->setText(patient.m_Discript);
	gDataCenter->getRecordList()->setCurrentPatient(patient);
}

void PatientTree::checkAllItem(QStandardItem *item, QString _text)
{
	if (item == nullptr)
		return;
	int _rowCount = item->rowCount();
	for (int i = 0; i < _rowCount; ++i)
	{
		QStandardItem* childItems = item->child(i);
		checkAllItem(childItems, _text);
	}
	if (!item->text().contains(_text, Qt::CaseInsensitive))
	{
		
	}
}

/*!
 *\brief:添加村
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotAddVillage()
{
	MultAddDialog* _nameDialog = new MultAddDialog(MultAddDialog::AddVillage);
	_nameDialog->exec();
	QString _name = _nameDialog->getNameText();
	//查重
	if (gDataBaseMgr->queryVillage(_name) != -1)
	{
		QMessageBox _msgBox;
		_msgBox.setText("村已存在。");
		_msgBox.setStandardButtons(QMessageBox::Ok);
		_msgBox.setDefaultButton(QMessageBox::Ok);
		_msgBox.exec();
		return;
	}
	//添加
	bool ret = gDataBaseMgr->addVillage(_name, (gDataCenter->m_town[0]).toInt());
	if (ret == false)
	{
		qDebug() << "faild add Village.";
		return;
	}
	int _id = gDataBaseMgr->queryVillage(_name);
	if (_id == -1)
		return;
	QStandardItemModel* _tempModel = qobject_cast<QStandardItemModel*>(dynamic_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model())->sourceModel());
	QStandardItem* itemVillage = new QStandardItem(_name);
	itemVillage->setData(MARK_Village, ROLE_MARK);
	itemVillage->setData(_id, ROLE_MARK_ID);
	_tempModel->appendRow(itemVillage);
	delete _nameDialog;
	_nameDialog = nullptr;
}

/*!
 *\brief:添加组
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotAddGroup()
{
	//读取当前点击村Item信息
	//QSortFilterProxyModel* _tempModel = nullptr;
	//QModelIndex currentIndex;
	//switch (m_mode)
	//{
	//case PatientTree::Mode_Edit:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
	//	currentIndex = m_EditUi->treeView->currentIndex();
	//	break;
	//case PatientTree::Mode_View:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
	//	currentIndex = m_MainUi->treeView->currentIndex();
	//	break;
	//default:
	//	return;
	//	break;
	//}
	////QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_EditUi->treeView->model());
	////QModelIndex currentIndex = m_EditUi->treeView->currentIndex();
	//QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(currentIndex));
	QStandardItem* currentItem = getCurrentSourceItem();
	QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
	QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 村ID
	//判断是否在村级
	if (_itemType.isValid() && MARK_Village == _itemType.toInt())
	{
		MultAddDialog* _nameDialog = new MultAddDialog(MultAddDialog::AddGroup);
		if (_nameDialog->exec() != 1)
			return;
		QString _name = _nameDialog->getNameText();
		//查重
		if (gDataBaseMgr->queryGroup(_name) != -1)
		{
			QMessageBox _msgBox;
			_msgBox.setText("组已存在。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
		}
		//添加
		bool ret = gDataBaseMgr->addGroup(_name, _itemID.toInt());
		if (ret == false)
		{
			qDebug() << "faild add Group.";
			return;
		}
		int _id = gDataBaseMgr->queryGroup(_name);
		if (_id == -1)
			return;
		QStandardItem* itemGroup = new QStandardItem(_name);
		itemGroup->setData(MARK_Group, ROLE_MARK);
		itemGroup->setData(_id, ROLE_MARK_ID);
		currentItem->appendRow(itemGroup);
		delete _nameDialog;
		_nameDialog = nullptr;
	}
}

/*!
 *\brief:添加户主
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotAddHouseHold()
{
	//读取当前点击村Item信息
	//QSortFilterProxyModel* _tempModel = nullptr;
	//QModelIndex currentIndex;
	//switch (m_mode)
	//{
	//case PatientTree::Mode_Edit:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
	//	currentIndex = m_EditUi->treeView->currentIndex();
	//	break;
	//case PatientTree::Mode_View:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
	//	currentIndex = m_MainUi->treeView->currentIndex();
	//	break;
	//default:
	//	return;
	//	break;
	//}
	////QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_EditUi->treeView->model());
	////QModelIndex currentIndex = m_EditUi->treeView->currentIndex();
	//QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(currentIndex));
	QStandardItem* currentItem = getCurrentSourceItem();
	QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
	QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 村ID
	//判断是否在组级
	if (_itemType.isValid() && MARK_Group == _itemType.toInt())
	{
		MultAddDialog* _nameDialog = new MultAddDialog(MultAddDialog::AddHouseHold);
		if (_nameDialog->exec() != 1)
			return;
		QString _name = _nameDialog->getNameText() + "(户主)";
		QString _carid = _nameDialog->getCarIDText();
		//查重
		if (gDataBaseMgr->queryHouseHoldByID(_carid) != "")
		{
			QMessageBox _msgBox;
			_msgBox.setText(QString("身份证为: %1 的户主已存在。").arg(_carid));
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
		}
		//添加
		bool ret = gDataBaseMgr->addHouseHold(_carid, _name, _itemID.toInt());
		if (ret == false)
		{
			qDebug() << "faild add Group.";
			return;
		}
		/*QString _id = gDataBaseMgr->queryHouseHold(_name);
		if (_id == "")
			return;*/
		QStandardItem* itemHouseHold = new QStandardItem(_name);
		itemHouseHold->setData(MARK_HouseHold, ROLE_MARK);
		itemHouseHold->setData(_carid, ROLE_MARK_ID);
		currentItem->appendRow(itemHouseHold);
		delete _nameDialog;
		_nameDialog = nullptr;
	}
}

/*!
 *\brief:修改户主信息
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotModifyHouseHold()
{
	//读取当前点击村Item信息
	//QSortFilterProxyModel* _tempModel = nullptr;
	//QModelIndex currentIndex;
	//switch (m_mode)
	//{
	//case PatientTree::Mode_Edit:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
	//	currentIndex = m_EditUi->treeView->currentIndex();
	//	break;
	//case PatientTree::Mode_View:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
	//	currentIndex = m_MainUi->treeView->currentIndex();
	//	break;
	//default:
	//	return;
	//	break;
	//}
	////QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_EditUi->treeView->model());
	////QModelIndex currentIndex = m_EditUi->treeView->currentIndex();
	//QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(currentIndex));
	QStandardItem* currentItem = getCurrentSourceItem();
	QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
	QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 户主ID
	//判断是否在户主级
	if (_itemType.isValid() && MARK_HouseHold == _itemType.toInt())
	{
		MultAddDialog* _nameDialog = new MultAddDialog(MultAddDialog::UpdateHouseHold);
		QString _showtext = currentItem->text();
		_showtext = _showtext.left(_showtext.length() - 4);
		_nameDialog->setShowText(_showtext);
		_nameDialog->setShowIDText(_itemID.toString());
		if (_nameDialog->exec() != 1)
			return;
		QString _name = _nameDialog->getNameText() + "(户主)";
		QString _carid = _nameDialog->getCarIDText();
		//查重
		/*if (gDataBaseMgr->queryHouseHold(_name) != "")
		{
			QMessageBox _msgBox;
			_msgBox.setText("户主已存在。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
		}*/
		currentItem->setText(_name);
		currentItem->setData(MARK_HouseHold, ROLE_MARK);
		currentItem->setData(_carid, ROLE_MARK_ID);
		delete _nameDialog;
		_nameDialog = nullptr;
	}
}

/*!
 *\brief:添加人员
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotAddPatient()
{
	//读取当前点击村Item信息
	//QSortFilterProxyModel* _tempModel = nullptr;
	//QModelIndex currentIndex;
	//switch (m_mode)
	//{
	//case PatientTree::Mode_Edit:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
	//	currentIndex = m_EditUi->treeView->currentIndex();
	//	break;
	//case PatientTree::Mode_View:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
	//	currentIndex = m_MainUi->treeView->currentIndex();
	//	break;
	//default:
	//	return;
	//	break;
	//}
	////QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_EditUi->treeView->model());
	////QModelIndex currentIndex = m_EditUi->treeView->currentIndex();
	//QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(currentIndex));
	QStandardItem* currentItem = getCurrentSourceItem();
	QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
	QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 户主ID
	//判断是否在户主级
	if (_itemType.isValid() && MARK_HouseHold == _itemType.toInt())
	{
		QString _adds = gDataCenter->getAddsStr() + currentItem->parent()->text();
		PatientAddDialog* _nameDialog = new PatientAddDialog(PatientAddDialog::OptMode::AddPatient,currentItem->text(), _itemID.toString(), _adds);
		if (_nameDialog->exec() != 1)
			return;

		QStandardItem* itemGroup = new QStandardItem(_nameDialog->getAddPatientName());
		itemGroup->setData(MARK_Patient, ROLE_MARK);
		itemGroup->setData(_nameDialog->getAddPatientID(), ROLE_MARK_ID);
		currentItem->appendRow(itemGroup);
		if (_nameDialog)
			delete _nameDialog;
		_nameDialog = nullptr;
	}
}

/*!
 *\brief:修改人员信息
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotModifyPatient()
{
	//读取当前点击村Item信息
	//QSortFilterProxyModel* _tempModel = nullptr;
	//QModelIndex currentIndex;
	//switch (m_mode)
	//{
	//case PatientTree::Mode_Edit:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
	//	currentIndex = m_EditUi->treeView->currentIndex();
	//	break;
	//case PatientTree::Mode_View:
	//	_tempModel = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
	//	currentIndex = m_MainUi->treeView->currentIndex();
	//	break;
	//default:
	//	return;
	//	break;
	//}
	////QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_EditUi->treeView->model());
	////QModelIndex currentIndex = m_EditUi->treeView->currentIndex();
	//QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(currentIndex));
	QStandardItem* currentItem = getCurrentSourceItem();
	QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
	QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 ID
	//判断是否在组级
	if (_itemType.isValid() && MARK_Patient == _itemType.toInt())
	{
		PatientInfo _tempPatient;
		if (gDataBaseMgr->queryPatientByID(_itemID.toString(), _tempPatient))
		{
			PatientAddDialog* _nameDialog = new PatientAddDialog(PatientAddDialog::OptMode::ModifyPatient);
			_nameDialog->initPatientInfo(_tempPatient);
			if (_nameDialog->exec() != 1)
				return;
			currentItem->setText(_nameDialog->getAddPatientName());
			currentItem->setData(MARK_Patient, ROLE_MARK);
			currentItem->setData(_nameDialog->getAddPatientID(), ROLE_MARK_ID);
			if (_nameDialog)
				delete _nameDialog;
			_nameDialog = nullptr;
		}
	}
}

/*!
 *\brief:删除对象
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotDeletSelect()
{
	//读取当前点击村Item信息
	QSortFilterProxyModel* _tempModel1 = nullptr;
	QModelIndex currentIndex;
	switch (m_mode)
	{
	case PatientTree::Mode_Edit:
		_tempModel1 = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
		currentIndex = m_EditUi->treeView->currentIndex();
		break;
	case PatientTree::Mode_View:
		_tempModel1 = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
		currentIndex = m_MainUi->treeView->currentIndex();
		break;
	default:
		return;
		break;
	}
	currentIndex = _tempModel1->mapToSource(currentIndex);
	QStandardItemModel* _tempModel = gDataCenter->getPatientTreeModel();
	//QStandardItem* currentItem = _tempModel->itemFromIndex(currentIndex);

	QStandardItem* currentItem = getCurrentSourceItem();
	QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
	QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 ID
	if (_itemType.isValid())
	{
		int ret = QMessageBox::warning(m_mainWindow, tr("警告"),
			tr("是否删除 %1 ?").arg(currentItem->text()),
			QMessageBox::Ok | QMessageBox::Cancel);
		if (ret != QMessageBox::Ok)
			return;
		bool _needHide = false;
		if (MARK_Village == _itemType.toInt())
		{
			if (gDataBaseMgr->deleteVillage(_itemID.toInt()))
			{
				_tempModel->removeRow(currentIndex.row(), currentIndex);
			}

		}
		else if (MARK_Group == _itemType.toInt())
		{
			if (gDataCenter->getCurrentPatientInfo().m_patientAdds.contains(currentItem->text()))
			{
				_needHide = true;
			}
			if (gDataBaseMgr->deleteGroup(_itemID.toInt()))
				currentItem->parent()->removeRow(currentIndex.row());
		}
		else if (MARK_HouseHold == _itemType.toInt())
		{
			if (gDataCenter->getCurrentPatientInfo().m_patientHouseHold.contains(currentItem->text()))
			{
				_needHide = true;
			}
			if (gDataBaseMgr->deleteHouseHold(_itemID.toString()))
				currentItem->parent()->removeRow(currentIndex.row());
		}
		else if (MARK_Patient == _itemType.toInt())
		{
			if (gDataCenter->getCurrentPatientInfo().m_patientName.contains(currentItem->text()))
			{
				_needHide = true;
			}
			if (gDataBaseMgr->deletePatient(_itemID.toString()))
			{
				currentItem->parent()->removeRow(currentIndex.row());
			}
		}
		/*_tempModel->submit();
		if (m_mode == PatientTree::Mode_Edit)
		{
			m_EditUi->treeView->reset();
			m_EditUi->treeView->setModel(_tempModel);
		}
		else
		{
			m_MainUi->treeView->reset();
			m_MainUi->treeView->setModel(_tempModel);
		}*/
		if (_needHide)
		{
			//隐藏人员信息页面
			if (m_MainUi->tableView->isVisible() == true)
			{
				m_MainUi->frame_7->setVisible(true);
				m_MainUi->frame_2->setVisible(false);
				m_MainUi->frame_6->setVisible(false);
				m_MainUi->tableView->setVisible(false);
			}
		}
	}
}

/*!
 *\brief:提交按钮
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotSubmitBtnClicked()
{

}

/*!
 *\brief:右键菜单
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotCustomContextMenuRequested(const QPoint &pos)
{
	QModelIndex index;
	switch (m_mode)
	{
	case PatientTree::Mode_Edit:
	{
		index = m_EditUi->treeView->indexAt(pos);
		QVariant var = index.data(ROLE_MARK);
		if (var.isValid())
		{
			if (MARK_Village == var.toInt())
				m_villageMenu->exec(QCursor::pos());//弹出右键菜单，菜单位置为光标位置
			else if (MARK_Group == var.toInt())
				m_groupMenu->exec(QCursor::pos());
			else if (MARK_HouseHold == var.toInt())
				m_houseHoldMenu->exec(QCursor::pos());
			else if (MARK_Patient == var.toInt())
				m_patientMenu->exec(QCursor::pos());
		}
	}
		break;
	case PatientTree::Mode_View:
	{
		index = m_MainUi->treeView->indexAt(pos);
		QVariant var = index.data(ROLE_MARK);
		if (var.isValid())
		{
			if (MARK_Group == var.toInt())
				m_groupMenu->exec(QCursor::pos());
			else if (MARK_HouseHold == var.toInt())
				m_houseHoldMenu->exec(QCursor::pos());
			else if (MARK_Patient == var.toInt())
				m_patientMenu->exec(QCursor::pos());
		}
	}
		break;
	default:
		return;
		break;
	}
}

/*!
 *\brief:item点击时保存原字符信息
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotItemDoubleClicked(const QModelIndex &index)
{
	//return;
	switch (m_mode)
	{
	case PatientTree::Mode_Edit:
	{
		QSortFilterProxyModel* _tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
		QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(index));
		m_oldText = currentItem->text();
	}
		break;
	case PatientTree::Mode_View:
	{
		//QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_MainUi->treeView->model());
		QStandardItem* currentItem = getCurrentSourceItem();
		QVariant _itemType = currentItem->data(ROLE_MARK);  //节点类型
		QVariant _itemID = currentItem->data(ROLE_MARK_ID); //数据库 ID
		if (MARK_Patient == _itemType.toInt())
		{
			PatientInfo _currentPatientInfo;
			if (gDataBaseMgr->queryPatientByID(_itemID.toString(), _currentPatientInfo))
			{
				//显示人员信息页面
				if (m_MainUi->tableView->isVisible() == false)
				{
					m_MainUi->frame_7->setVisible(false);
					m_MainUi->frame_2->setVisible(true);
					m_MainUi->frame_6->setVisible(true);
					m_MainUi->tableView->setVisible(true);
				}
				if (gDataCenter->getRecordList() == nullptr)
				{
					RecordList *_recordList = new RecordList(m_MainUi,dynamic_cast<AccountMgrSys*>(m_mainWindow));
					gDataCenter->setRecordList(_recordList);
					
				}
				gDataCenter->setCurrentPatienInfo(_currentPatientInfo);
				displayPatientInfo(currentItem, _currentPatientInfo);
				//A41F72563042
			}
		}
	}
		break;
	default:
		break;
	}
	
}

void PatientTree::slotItemClicked(const QModelIndex &index)
{
	switch (m_mode)
	{
	case PatientTree::Mode_Edit:
	{
		QSortFilterProxyModel* _tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
		QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(index));
		m_oldText = currentItem->text();
		break;
	}
	case PatientTree::Mode_View:
		break;
	default:
		break;
	}
}

/*!
 *\brief:双击更改
 *
 *\param name:
 *
 *\return:
*/
void PatientTree::slotItemChanged(QStandardItem *item)
{
	if (item)
	{
		QVariant _itemType = item->data(ROLE_MARK);  //节点类型
		QVariant _itemID = item->data(ROLE_MARK_ID); //数据库 ID
		if (_itemType.isValid())
		{
			if (MARK_Village == _itemType.toInt())
			{
				QString _curText = item->text();
				//查重
				if (gDataBaseMgr->queryVillage(_curText) != -1)
				{
					item->setText(m_oldText);
					qDebug() << "faild rename Village name to " + _curText;
					QMessageBox _msgBox;
					_msgBox.setText("村已存在。");
					_msgBox.setStandardButtons(QMessageBox::Ok);
					_msgBox.setDefaultButton(QMessageBox::Ok);
					_msgBox.exec();
					return;
				}
				if (!gDataBaseMgr->updateVillage(_itemID.toInt(), _curText))
				{
					item->setText(m_oldText);
					qDebug() << "faild update Village name to " + _curText;
				}
			}
			else if (MARK_Group == _itemType.toInt())
			{
				QString _curText = item->text();
				//查重
				if (gDataBaseMgr->queryGroup(_curText) != -1)
				{
					item->setText(m_oldText);
					qDebug() << "faild rename Group name to " + _curText;
					QMessageBox _msgBox;
					_msgBox.setText("组已存在。");
					_msgBox.setStandardButtons(QMessageBox::Ok);
					_msgBox.setDefaultButton(QMessageBox::Ok);
					_msgBox.exec();
					return;
				}
				if (!gDataBaseMgr->updateGroup(_itemID.toInt(), _curText))
				{
					item->setText(m_oldText);
					qDebug() << "faild update Group name to " + _curText;
				}
			}
			else if (MARK_HouseHold == _itemType.toInt())
			{
				QString _curText = item->text();
				if (!gDataBaseMgr->updateHouseHold(_itemID.toString(), _curText))
				{
					item->setText(m_oldText);
					qDebug() << "faild update HouseHold name to " + _curText;
				}
			}
			else if (MARK_Patient == _itemType.toInt())
			{
				QString _curText = item->text();
				if (!gDataBaseMgr->updatePatient(_itemID.toString(), _curText))
				{
					item->setText(m_oldText);
					qDebug() << "faild update Patient name to " + _curText;
				}
			}
		}
	}
}

void PatientTree::slotSearchItem(const QString &text)
{
	if (!text.isEmpty())
	{
		switch (m_mode)
		{
		case PatientTree::Mode_Edit:
		{
			m_EditUi->treeView->expandAll();
			break;
		}
		case PatientTree::Mode_View:
		{
			m_MainUi->treeView->expandAll();
			break;
		}
		default:
			break;
		}
	}
	m_filterModel->setFilterFixedString(text);

}

QStandardItem * PatientTree::getCurrentSourceItem()
{
	QSortFilterProxyModel* _tempModel = nullptr;
	QModelIndex currentIndex;
	switch (m_mode)
	{
	case PatientTree::Mode_Edit:
		_tempModel = static_cast<QSortFilterProxyModel*>(m_EditUi->treeView->model());
		currentIndex = m_EditUi->treeView->currentIndex();
		break;
	case PatientTree::Mode_View:
		_tempModel = static_cast<QSortFilterProxyModel*>(m_MainUi->treeView->model());
		currentIndex = m_MainUi->treeView->currentIndex();
		break;
	default:
		break;
	}
	//QStandardItemModel* _tempModel = static_cast<QStandardItemModel*>(m_EditUi->treeView->model());
	//QModelIndex currentIndex = m_EditUi->treeView->currentIndex();
	QStandardItem* currentItem = gDataCenter->getPatientTreeModel()->itemFromIndex(_tempModel->mapToSource(currentIndex));
	if (currentItem)
		return currentItem;
	else
		return nullptr;
}

QString PatientTree::getPatientAge(QString _IdCar)
{
	QString age;
	if (_IdCar.length() >= 15)
	{
		QString _borndata = _IdCar.mid(6, 8);
		int agee =(QDate::currentDate().toString("yyyyMMdd").toInt() -_borndata.toInt()) / 10000;
		age = QString::number(agee) + "岁";
		return age;
	}
	else
	{
		age = "未知";
		return age;
	}
}
