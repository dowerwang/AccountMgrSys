#include "AccountMgrSys.h"
#include "PatientTree.h"
#include <QMessageBox>
AccountMgrSys::AccountMgrSys(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this); 
	this->setWindowTitle("账目管理系统 V1.0 测试版");
	gDataBaseMgr;
	gDataCenter;
	initMainWindowLayout();
}

void AccountMgrSys::initMainWindowLayout()
{
	m_userLogin		= new QAction(tr("添加管理员"), this);
	m_localArea		= new QAction(tr("操作地区选择"));
	m_sysSetting	= new QAction(tr("系统设置"));

	m_addVillage	= new QAction(tr("添加村"), this);
	m_addGroup		= new QAction(tr("添加组"), this);
	m_addHousehold	= new QAction(tr("添加户主"), this);
	m_addMember		= new QAction(tr("添加家庭成员"), this);
	m_findHousehold = new QAction(tr("查找户主"), this);
	m_findeMember	= new QAction(tr("查找家庭成员"), this);
	m_useHelp		= new QAction(tr("帮助"), this);

	m_UserMgr		= new QAction(tr("用户管理"));
	m_medicineMgr	= new QAction(tr("药品管理"));
	m_patientMgr	= new QAction(tr("人员管理"));
	m_recordMgr		= new QAction(tr("记录管理"));
	m_AreaMgr		= new QAction(tr("区域信息管理"));

	m_help			= new QAction(tr("帮助"));
	connect(m_userLogin, &QAction::triggered, this, &AccountMgrSys::slotUserLogin);
	connect(m_localArea, &QAction::triggered, this, &AccountMgrSys::slotSelectLocList);
	connect(m_sysSetting, &QAction::triggered, this, &AccountMgrSys::slotSysSetting);

	connect(m_addVillage, &QAction::triggered, this, &AccountMgrSys::slotAddVillage);
	connect(m_addGroup, &QAction::triggered, this, &AccountMgrSys::slotAddGroup);
	connect(m_addHousehold, &QAction::triggered, this, &AccountMgrSys::slotAddHousehold);
	connect(m_addMember, &QAction::triggered, this, &AccountMgrSys::slotAddMember);
	connect(m_findHousehold, &QAction::triggered, this, &AccountMgrSys::slotFindHousehold);
	connect(m_findeMember, &QAction::triggered, this, &AccountMgrSys::slotFindMember);
	connect(m_useHelp, &QAction::triggered, this, &AccountMgrSys::slotUseHelp);

	connect(m_UserMgr, &QAction::triggered, this, &AccountMgrSys::slotUserMgr);
	connect(m_medicineMgr, &QAction::triggered, this, &AccountMgrSys::slotMedicineMgr);
	connect(m_patientMgr, &QAction::triggered, this, &AccountMgrSys::slotPatientMgr);
	connect(m_recordMgr, &QAction::triggered, this, &AccountMgrSys::slotRecordMgr);
	connect(m_AreaMgr, &QAction::triggered, this, &AccountMgrSys::slotAreaMgr);
	connect(m_help, &QAction::triggered, this, &AccountMgrSys::slotAboutButtonClicked);
	creatMenu();
	creatToolBtn();
	//隐藏人员信息页面
	ui.frame_2->setVisible(false);
	ui.frame_6->setVisible(false);
	ui.tableView->setVisible(false);

	m_sysSettingDialog = new SysSettings();
	PatientTree *_patientTree = new PatientTree(&ui, this);
	RecordList *_recordList = new RecordList(&ui, this);
	gDataCenter->setRecordList(_recordList);
}

void AccountMgrSys::creatMenu()
{
	QMenu* _menu = this->menuBar()->addMenu(tr("文件"));
	//_menu->addAction(m_userLogin);
	//_menu->addAction(m_sysSetting);

	/*_menu = this->menuBar()->addMenu(tr("编辑"));
	_menu->addAction(m_addVillage);
	_menu->addAction(m_addGroup);
	_menu->addAction(m_addHousehold);
	_menu->addAction(m_addMember);*/

	/*_menu = this->menuBar()->addMenu(tr("查找"));
	_menu->addAction(m_findHousehold);
	_menu->addAction(m_findeMember);*/

	_menu = this->menuBar()->addMenu(tr("数据管理"));
	//_menu->addAction(m_UserMgr);
	_menu->addAction(m_medicineMgr);
	_menu->addAction(m_patientMgr);
	_menu->addAction(m_recordMgr);
	//_menu->addAction(m_AreaMgr);

	this->menuBar()->addAction(m_help);
	//_menu->addAction(m_help);

}

void AccountMgrSys::creatToolBtn()
{
	//ui.mainToolBar->addAction(m_UserMgr);
	ui.mainToolBar->addAction(m_medicineMgr);
	ui.mainToolBar->addAction(m_patientMgr);
	ui.mainToolBar->addAction(m_recordMgr);
}

void AccountMgrSys::slotUserLogin()
{

}

void AccountMgrSys::slotSelectLocList()
{

}

void AccountMgrSys::slotSysSetting()
{
	if (m_sysSettingDialog == nullptr)
		m_sysSettingDialog = new SysSettings();
	m_sysSettingDialog->show();
}

void AccountMgrSys::slotAddVillage()
{

}

void AccountMgrSys::slotAddGroup()
{

}

void AccountMgrSys::slotAddHousehold()
{

}

void AccountMgrSys::slotAddMember()
{

}

void AccountMgrSys::slotFindHousehold()
{

}

void AccountMgrSys::slotFindMember()
{

}

void AccountMgrSys::slotUseHelp()
{

}

void AccountMgrSys::slotUserMgr()
{
	AccountEditer *_accountEditer = new AccountEditer();
	_accountEditer->exec();
	if (_accountEditer)
		delete _accountEditer;
	_accountEditer = nullptr;
}

void AccountMgrSys::slotMedicineMgr()
{
	MedicineEditor *_medicineEditor = new MedicineEditor();
	_medicineEditor->exec();
	if (_medicineEditor)
		delete _medicineEditor;
	_medicineEditor = nullptr;
}

void AccountMgrSys::slotPatientMgr()
{
	if (gDataCenter->getVillage().isEmpty())
	{
		QMessageBox _msgBox;
		_msgBox.setText("请先选择区域。");
		_msgBox.setStandardButtons(QMessageBox::Ok);
		_msgBox.setDefaultButton(QMessageBox::Ok);
		_msgBox.exec();
		return;
	}
	PatientBrowseDialog *_patientEditor = new PatientBrowseDialog();
	_patientEditor->exec();
	delete _patientEditor;
	_patientEditor = nullptr;
}

void AccountMgrSys::slotRecordMgr()
{
	RecordBrowseDialog *_recordBrowse = new RecordBrowseDialog();
	connect(_recordBrowse, &RecordBrowseDialog::sigUpdateRecordList, gDataCenter->getRecordList(), &RecordList::slotUpdateRecordList);
	_recordBrowse->exec();
	if (_recordBrowse)
	{
		disconnect(_recordBrowse, &RecordBrowseDialog::sigUpdateRecordList, gDataCenter->getRecordList(), &RecordList::slotUpdateRecordList);
		delete _recordBrowse;
	}
	_recordBrowse = nullptr;
}

void AccountMgrSys::slotAreaMgr()
{

}

void AccountMgrSys::slotAboutButtonClicked()
{
	QMessageBox message(QMessageBox::Information, "关于", tr("<h1> AccountMgrSys 2019</h1>"

		"<p><h4>Release 1.0 Beat</h4>"
		//"<p>Copyright © 2019-2019 Inc. & isoft "
		"All rights reserved."
		//"<p>版权所有 © 2013-2014 Inc. & isoft。 保留所有权利。"
		"<p>仅供内部人员测试使用。"
	));
	message.setWindowIcon(QPixmap(":/login/Resources/loginbitmaps/gparted-icon16.png"));
	message.setIconPixmap(QPixmap(":/login/Resources/loginbitmaps/gparted-icon96.png"));
	message.exec();
	//QMessageBox::about(this, tr("About AccountMgrSys"),
	//	tr("<h1> AccountMgrSys 2019</h1>"

	//		"<p><h4>Release 1.0 Beat</h4>"
	//		//"<p>Copyright © 2019-2019 Inc. & isoft "
	//		"All rights reserved."
	//		//"<p>版权所有 © 2013-2014 Inc. & isoft。 保留所有权利。"
	//		"<p>仅供内部人员测试使用。"
	//	));
}

void AccountMgrSys::slotSearchItem(const QString &text)
{
}

void AccountMgrSys::slotAddRecord()
{
	
}

void AccountMgrSys::slotDeleteRecord()
{

}

void AccountMgrSys::slotSubmitRecord()
{

}

void AccountMgrSys::closeEvent(QCloseEvent *event)
{
	int ret = QMessageBox::warning(this, tr("退出"), tr("是否退出？"), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Cancel)
	{
		event->ignore();
		return;
	}
	QCoreApplication::quit();
	event->accept();
}
