#include "MedicineAddDialog.h"
#include <QMessageBox>
#include <QButtonGroup>
#include "CommentData.h"
#include "SQLiteHelper.h"

MedicineAddDialog::MedicineAddDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	QStringList _measurement;
	_measurement << "��" << "��" << "Ƭ" << "ƿ" << "֧" << "����";
	ui.comboBox->addItems(_measurement);
	connect(ui.pushButton, &QPushButton::clicked, this, &MedicineAddDialog::slotOkBtnclicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &MedicineAddDialog::slotCancelBtnClicked);
}

MedicineAddDialog::~MedicineAddDialog()
{
}

void MedicineAddDialog::initMedicineInfo(const MedicineInfo&medicien)
{

}

void MedicineAddDialog::clearInfo()
{
	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
	ui.lineEdit_4->clear();
	ui.textEdit->clear();
}

void MedicineAddDialog::slotCancelBtnClicked()
{
	this->close();
}

void MedicineAddDialog::slotOkBtnclicked()
{
	if (!ui.lineEdit->text().isEmpty() && !ui.lineEdit_2->text().isEmpty() && !ui.lineEdit_4->text().isEmpty())
	{
		int _id = gDataBaseMgr->medicineRawQuery() + 1;
		MedicineInfo _newMedicineInfo;
		_newMedicineInfo.m_medicineID = _id;
		_newMedicineInfo.m_medicineName = ui.lineEdit->text();
		_newMedicineInfo.m_medicinePrice = ui.lineEdit_2->text().toDouble();
		_newMedicineInfo.m_medicineUnit = ui.comboBox->currentText();
		_newMedicineInfo.m_medicineInventory = ui.lineEdit_4->text().toInt();
		_newMedicineInfo.m_medicineDiscript = ui.textEdit->toPlainText();
		MedicineInfo _isExcist;
		/*if (gDataBaseMgr->queryMedicineByID(_newMedicineInfo.m_medicineID, _isExcist))
		{
			QMessageBox _msgBox;
			_msgBox.setText("�Ѵ���IDΪ��" + QString::number(_newMedicineInfo.m_medicineID) + " ��ҩƷ��");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			this->reject();
		}*/
		if (gDataBaseMgr->addMedicine(_newMedicineInfo))
		{
			QMessageBox _msgBox;
			_msgBox.setText("��ӳɹ���");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			this->clearInfo();
			return;
			//this->accept();
		}
		else
		{
			QMessageBox _msgBox;
			_msgBox.setText("���ʧ�ܡ�");
			_msgBox.setStandardButtons(QMessageBox::Ok);
			_msgBox.setDefaultButton(QMessageBox::Ok);
			_msgBox.exec();
			return;
			//this->reject();
		}
	}
	else
	{
		QString _tip;
		if (ui.lineEdit->text().isEmpty())
			_tip = "��Ʒ���Ʋ���Ϊ�ա�";
		else if (ui.lineEdit_2->text().isEmpty())
			_tip = "��Ʒ���۲���Ϊ�ա�";
		else if (ui.comboBox->currentText().isEmpty())
			_tip = "��ѡ��ҩƷ������λ��";
		else if (ui.lineEdit_4->text().isEmpty())
			_tip = "������ҩƷ��ǰ��档";
		/*else if (ui.lineEdit_5->text().isEmpty())
			_tip = "��ϵ��ʽ����Ϊ�ա�";*/
		QMessageBox _msgBox;
		_msgBox.setText(_tip);
		_msgBox.setStandardButtons(QMessageBox::Ok);
		_msgBox.setDefaultButton(QMessageBox::Ok);
		_msgBox.exec();
		return;
		//this->reject();
	}
}
