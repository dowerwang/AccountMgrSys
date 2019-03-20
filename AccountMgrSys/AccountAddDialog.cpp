#include "AccountAddDialog.h"
#include <QMessageBox>
#include <QButtonGroup>
#include "CommentData.h"
#include "SQLiteHelper.h"

AccountAddDialog::AccountAddDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	m_group1 = new QButtonGroup;
	m_group2 = new QButtonGroup;
	m_group1->addButton(ui.radioButton, 0);
	m_group1->addButton(ui.radioButton_2, 1);
	m_group1->setExclusive(true);
	m_group2->addButton(ui.radioButton_3, 0);
	m_group2->addButton(ui.radioButton_4, 1);
	m_group2->setExclusive(true);
	ui.radioButton->setChecked(true);
	ui.radioButton_3->setChecked(true);
	connect(ui.pushButton, &QPushButton::clicked, this, &AccountAddDialog::slotOkBtnclicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &AccountAddDialog::slotCancelBtnClicked);
}

AccountAddDialog::AccountAddDialog(const SupUserInfo& supUser, QWidget *parent /*= Q_NULLPTR*/)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	m_group1 = new QButtonGroup;
	m_group2 = new QButtonGroup;
	m_group1->addButton(ui.radioButton, 0);
	m_group1->addButton(ui.radioButton_2, 1);
	m_group1->setExclusive(true);
	m_group2->addButton(ui.radioButton_3, 0);
	m_group2->addButton(ui.radioButton_4, 1);
	m_group2->setExclusive(true);
	ui.radioButton->setChecked(true);
	ui.radioButton_3->setChecked(true);
	connect(ui.pushButton, &QPushButton::clicked, this, &AccountAddDialog::slotOkBtnclicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &AccountAddDialog::slotCancelBtnClicked);
	initAccountInfo(supUser);
}

AccountAddDialog::~AccountAddDialog()
{
	delete m_group1;
	delete m_group2;
}

void AccountAddDialog::initAccountInfo(const SupUserInfo& supUser)
{
	ui.lineEdit->setText(QString::number(supUser.m_userID));
	ui.lineEdit_2->setText(supUser.m_userName);
	if (supUser.m_userSex == 1)
		ui.radioButton->setChecked(true);
	else
		ui.radioButton_2->setChecked(true);
	if (supUser.m_userType == 0)
		ui.radioButton_3->setChecked(true);
	else
		ui.radioButton_4->setChecked(true);
	ui.lineEdit_3->setText(supUser.m_userIDCar);
	ui.lineEdit_4->setText(supUser.m_userPsw);
	ui.lineEdit_5->setText(supUser.m_userTel);
	ui.lineEdit_6->setText(supUser.m_userAdds);
	ui.lineEdit_7->setText(supUser.m_Discript);
}

void AccountAddDialog::slotCancelBtnClicked()
{
	this->close();
}

void AccountAddDialog::slotOkBtnclicked()
{
	if (!ui.lineEdit->text().isEmpty()&&!ui.lineEdit_2->text().isEmpty()&&!ui.lineEdit_3->text().isEmpty()&&!ui.lineEdit_4->text().isEmpty()
		&&!ui.lineEdit_5->text().isEmpty()&&!ui.lineEdit_6->text().isEmpty())
	{
		SupUserInfo _newSupUser;
		_newSupUser.m_userID = ui.lineEdit->text().toInt();
		_newSupUser.m_userName = ui.lineEdit_2->text();
		if (ui.radioButton->isChecked())
			_newSupUser.m_userSex = "男";
		else
			_newSupUser.m_userSex = "女";
		if (ui.radioButton_3->isChecked())
			_newSupUser.m_userType = "普通";
		else
			_newSupUser.m_userType = "超级";
		_newSupUser.m_userIDCar = ui.lineEdit_3->text();
		_newSupUser.m_userPsw = ui.lineEdit_4->text();
		_newSupUser.m_userTel = ui.lineEdit_5->text();
		_newSupUser.m_userAdds = ui.lineEdit_6->text();
		_newSupUser.m_Discript = ui.lineEdit_7->text();
		SupUserInfo _isExcist;
		if (gDataBaseMgr->querySupUserByID(_newSupUser.m_userID, _isExcist))
		{
			QMessageBox _msgBox;
			_msgBox.setText("已存在ID为：" + QString::number(_newSupUser.m_userID) + "的管理员。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			this->reject();
		}
		if (gDataBaseMgr->addSupUser(_newSupUser))
		{
			QMessageBox _msgBox;
			_msgBox.setText("添加成功。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			this->accept();
		}
		else 
		{
			QMessageBox _msgBox;
			_msgBox.setText("添加失败。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			this->reject();
		}
	}
	else
	{
		QString _tip;
		if (ui.lineEdit->text().isEmpty())
			_tip = "管理员ID不能为空。";
		else if (ui.lineEdit_2->text().isEmpty())
			_tip = "姓名不能为空。";
		else if (ui.lineEdit_3->text().isEmpty())
			_tip = "身份证号码不能为空。";
		else if (ui.lineEdit_4->text().isEmpty())
			_tip = "登陆密码不能为空。";
		else if (ui.lineEdit_5->text().isEmpty())
			_tip = "联系方式不能为空。";
		else if (ui.lineEdit_6->text().isEmpty())
			_tip = "住址不能为空。";
		QMessageBox _msgBox;
		_msgBox.setText(_tip);
		_msgBox.setStandardButtons(QMessageBox::Ok);
		_msgBox.setDefaultButton(QMessageBox::Ok);
		_msgBox.exec();
		this->reject();
	}
}
