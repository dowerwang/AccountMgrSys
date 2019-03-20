#include "MultAddDialog.h"
#include "IDCarInfoMation.h"
#include "SQLiteHelper.h"
MultAddDialog::MultAddDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

MultAddDialog::MultAddDialog(OptMode mode, QWidget *parent /*= Q_NULLPTR*/)
	:m_mode(mode),QDialog(parent)
{
	ui.setupUi(this);
	initDialog();
}

MultAddDialog::~MultAddDialog()
{
}

void MultAddDialog::initDialog()
{
	ui.label_2->setVisible(false);
	ui.lineEdit_2->setVisible(false);
	switch (m_mode)
	{
	case MultAddDialog::AddTown:
	{
		ui.groupBox->setTitle("�����");
		this->setWindowTitle("�����");
		break;
	}
	case MultAddDialog::UpdateTown:
	{
		ui.groupBox->setTitle("�༭��");
		this->setWindowTitle("�༭��");
		break;
	}
	case MultAddDialog::AddVillage:
	{
		ui.groupBox->setTitle("��Ӵ�");
		this->setWindowTitle("��Ӵ�");
		break;
	}
	case MultAddDialog::UpdateVillage:
	{
		ui.groupBox->setTitle("�༭��");
		this->setWindowTitle("�༭��");
		break;
	}
	case MultAddDialog::AddGroup:
	{
		ui.groupBox->setTitle("�����");
		this->setWindowTitle("�����");
		break;
	}
	case MultAddDialog::UpdateGroup:
	{
		ui.groupBox->setTitle("�༭��");
		this->setWindowTitle("�༭��");
		break;
	}
	case MultAddDialog::AddHouseHold:
	{
		ui.groupBox->setTitle("��ӻ���");
		this->setWindowTitle("��ӻ���");
		ui.label_2->setVisible(true);
		ui.lineEdit_2->setVisible(true);
		//QRegExp rx("^[1-9]\d{5}(18|19|20)\d{2}((0[1-9])|(1[0-2]))(([0-2][1-9])|10|20|30|31)\d{3}[0-9Xx]$");
		//ui.lineEdit_2->setValidator(new QRegExpValidator(rx, this));
		break;
	}
	case MultAddDialog::UpdateHouseHold:
	{
		ui.groupBox->setTitle("�༭����");
		this->setWindowTitle("�༭����");
		ui.label_2->setVisible(true);
		ui.lineEdit_2->setVisible(true);
		//QRegExp rx1("^\d{15}$)|(^\d{18}$)|(^\d{17}(\d|X|x)$");
		//ui.lineEdit_2->setValidator(new QRegExpValidator(rx1, this));
		break;
	}
	default:
		break;
	}
	ui.lineEdit->setFocus(Qt::MouseFocusReason);
	connect(ui.pushButton, &QPushButton::clicked, this, &MultAddDialog::slotOkBtnclicked);
}

void MultAddDialog::setShowText(const QString & str)
{
	ui.lineEdit->setText(str);
}

void MultAddDialog::setShowIDText(const QString & str)
{
	ui.lineEdit_2->setText(str);
	m_oldIDCard = str;
}

QString & MultAddDialog::getNameText()
{
	m_NameText = ui.lineEdit->text();
	return m_NameText;
}

QString & MultAddDialog::getCarIDText()
{
	m_CarIDText = ui.lineEdit_2->text();
	return m_CarIDText;
}

void MultAddDialog::slotOkBtnclicked()
{
	m_NameText = ui.lineEdit->text();
	m_CarIDText = ui.lineEdit_2->text(); 
	if (m_NameText.isEmpty())
	{
		QMessageBox _msgBox;
		_msgBox.setText("���Ʋ���Ϊ�ա�");
		_msgBox.setStandardButtons(QMessageBox::Ok);
		_msgBox.setDefaultButton(QMessageBox::Ok);
		_msgBox.exec();
		return;
	}
	switch (m_mode)
	{
	case MultAddDialog::AddTown:
		break;
	case MultAddDialog::UpdateTown:
		break;
	case MultAddDialog::AddVillage:
		break;
	case MultAddDialog::UpdateVillage:
		break;
	case MultAddDialog::AddGroup:
		break;
	case MultAddDialog::UpdateGroup:
		break;
	case MultAddDialog::AddHouseHold: case MultAddDialog::UpdateHouseHold:
	{
		if (m_CarIDText.isEmpty())
		{
			QMessageBox _msgBox;
			_msgBox.setText("���֤����Ϊ�ա�");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
		}
		else
		{
			QString _dev;
			IDCarInfoMation _idcarInfo;
			bool _isVaildID = false;
			if (m_CarIDText.length() == 18)
			{
				_isVaildID = _idcarInfo.isVaildIDCar(m_CarIDText.toStdString().c_str());
			}
			else if(m_CarIDText.length() == 15)
			{
				CString _newIDCar;
				bool b = _idcarInfo.iso7064_15To18(m_CarIDText.toStdString().c_str(), _newIDCar);
				if (b)
				{
					_isVaildID = _idcarInfo.isVaildIDCar(_newIDCar);
				}
			}
			if (!_isVaildID)
			{
				int ret = QMessageBox::warning(this, tr("����"), tr("���֤��������"), QMessageBox::Ok);
				return;
			}
			else
			{
				if (m_mode == MultAddDialog::UpdateHouseHold)
				{
					if (gDataBaseMgr->updateHouseHold(m_oldIDCard, m_CarIDText, m_NameText))
					{
						int ret = QMessageBox::information(this, tr("��Ϣ"), tr("�����ɹ���"), QMessageBox::Ok);
						this->accept();
					}
					else
					{
						int ret = QMessageBox::information(this, tr("��Ϣ"), tr("����ʧ�ܡ�"), QMessageBox::Ok);
						return;
						//this->reject();
					}
				}
			}
		}
		break;
	}
	default:
		break;
	}
	this->accept();
}
