#include "PatientAddDialog.h"
#include <QMessageBox>
#include <QButtonGroup>
#include "CommentData.h"
#include "SQLiteHelper.h"
#include <QRegExpValidator>
#include "IDCarInfoMation.h"

PatientAddDialog::PatientAddDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("修改人员");
	//this->setAttribute(Qt::WA_DeleteOnClose);
	ui.radioButton->setChecked(true);
	ui.lineEdit_3->setDisabled(true);
	ui.lineEdit_6->setDisabled(true);
	connect(ui.pushButton, &QPushButton::clicked, this, &PatientAddDialog::slotOkBtnclicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &PatientAddDialog::slotCancelBtnClicked);
}

PatientAddDialog::PatientAddDialog(OptMode _mode, const QString & householdname, const QString &householdID, const QString &adds, QWidget *parent /*= Q_NULLPTR*/)
	:m_mode(_mode),m_houseHoldName(householdname), m_houseHoldID(householdID), m_adds(adds), QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("添加人员");

	ui.label->setText("添加人员");
	//this->setAttribute(Qt::WA_DeleteOnClose);
	ui.radioButton->setChecked(true);
	//ui.lineEdit_3->setText(m_houseHoldID);
	ui.lineEdit_3->setText(m_houseHoldName + "(" + m_houseHoldID + ")");
	ui.lineEdit_6->setText(m_adds);
	ui.lineEdit_3->setDisabled(true);
	ui.lineEdit_6->setDisabled(true);
	connect(ui.pushButton, &QPushButton::clicked, this, &PatientAddDialog::slotOkBtnclicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &PatientAddDialog::slotCancelBtnClicked);
}

PatientAddDialog::PatientAddDialog(OptMode _mode, QWidget *parent /*= Q_NULLPTR*/)
	: m_mode(_mode), QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("修改人员");
	ui.label->setText("修改人员");
	//this->setAttribute(Qt::WA_DeleteOnClose);
	ui.radioButton->setChecked(true);
	ui.lineEdit_3->setDisabled(true);
	ui.lineEdit_6->setDisabled(true);
	connect(ui.pushButton, &QPushButton::clicked, this, &PatientAddDialog::slotOkBtnclicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &PatientAddDialog::slotCancelBtnClicked);
}

PatientAddDialog::~PatientAddDialog()
{
}

void PatientAddDialog::initPatientInfo(const PatientInfo&patient)
{
	ui.lineEdit->setText(patient.m_patientName);
	if (patient.m_patientSex == "男")
		ui.radioButton->setChecked(true);
	else
		ui.radioButton_2->setChecked(true);
	ui.lineEdit_3->setText(patient.m_patientHouseHold);
	ui.lineEdit_4->setText(patient.m_patientIDCar);
	ui.lineEdit_5->setText(patient.m_patientTel);
	ui.lineEdit_6->setText(patient.m_patientAdds);
	ui.textEdit->setText(patient.m_Discript);
	m_oldIDCar = patient.m_patientID;
}

void PatientAddDialog::clearInfo()
{
	ui.lineEdit->clear();
	ui.lineEdit_3->clear();
	ui.lineEdit_4->clear();
	ui.lineEdit_5->clear();
	ui.lineEdit_6->clear();
	ui.textEdit->clear();
}

void PatientAddDialog::slotCancelBtnClicked()
{
	this->reject();
}

void PatientAddDialog::slotOkBtnclicked()
{
	QString _tip = "";
	if (ui.lineEdit->text().isEmpty())
		_tip = "人员名称不能为空。";
	else if (ui.lineEdit_3->text().isEmpty())
		_tip = "户主信息不能为空。";
	else if (ui.lineEdit_4->text().isEmpty())
		_tip = "身份证号不能为空。";
	else if (ui.lineEdit_5->text().isEmpty())
		_tip = "联系方式不能为空。";
	else if (ui.lineEdit_6->text().isEmpty())
		_tip = "地址不能为空。";
	if (_tip != "")
	{
		QMessageBox _msgBox;
		_msgBox.setText(_tip);
		_msgBox.setStandardButtons(QMessageBox::Ok);
		_msgBox.setDefaultButton(QMessageBox::Ok);
		_msgBox.exec();
		return;
	}
	PatientInfo _newPatientInfo;
	_newPatientInfo.m_patientID = ui.lineEdit_4->text();
	_newPatientInfo.m_patientIDCar = ui.lineEdit_4->text();

	QString _dev;
	IDCarInfoMation _idcarInfo;
	bool _isVaildID = false;
	if (_newPatientInfo.m_patientID.length() == 18)
	{
		_isVaildID = _idcarInfo.isVaildIDCar(_newPatientInfo.m_patientID.toStdString().c_str());
	}
	else if (_newPatientInfo.m_patientID.length() == 15)
	{
		CString _newIDCar;
		bool b = _idcarInfo.iso7064_15To18(_newPatientInfo.m_patientID.toStdString().c_str(), _newIDCar);
		if (b)
		{
			_isVaildID = _idcarInfo.isVaildIDCar(_newIDCar);
		}
	}
	if (!_isVaildID)
	{
		int ret = QMessageBox::warning(this, tr("警告"), tr("身份证输入有误。"), QMessageBox::Ok);
		return;
	}

	_newPatientInfo.m_patientName = ui.lineEdit->text();
	if (ui.radioButton->isChecked())
		_newPatientInfo.m_patientSex = "男";
	else
		_newPatientInfo.m_patientSex = "女";
	_newPatientInfo.m_patientHouseHold = m_houseHoldID;
	_newPatientInfo.m_patientTel = ui.lineEdit_5->text();
	_newPatientInfo.m_patientAdds = ui.lineEdit_6->text();
	_newPatientInfo.m_Discript = ui.textEdit->toPlainText();
	
	if (m_mode == AddPatient)
	{
		PatientInfo _isExcist;
		if (gDataBaseMgr->queryPatientByID(_newPatientInfo.m_patientID, _isExcist))
		{
			QMessageBox _msgBox;
			_msgBox.setText("已存在ID为：" + _newPatientInfo.m_patientID + " 的人员。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
		}
		if (gDataBaseMgr->addPatient(_newPatientInfo))
		{
			m_addPatientName = _newPatientInfo.m_patientName;
			m_addPatientID = _newPatientInfo.m_patientID;
			QMessageBox _msgBox;
			_msgBox.setText("添加人员成功。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			//this->clearInfo();
			this->accept();
		}
		else
		{
			QMessageBox _msgBox;
			_msgBox.setText("添加失败。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
			//this->reject();
		}
	}
	else
	{
		if (gDataBaseMgr->updatePatient(m_oldIDCar,_newPatientInfo))
		{
			m_addPatientName = _newPatientInfo.m_patientName;
			m_addPatientID = _newPatientInfo.m_patientID;
			QMessageBox _msgBox;
			_msgBox.setText("修改人员信息成功。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			//this->clearInfo();
			this->accept();
		}
		else
		{
			QMessageBox _msgBox;
			_msgBox.setText("修改人员信息失败。");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
			//this->reject();
		}
	}
}
