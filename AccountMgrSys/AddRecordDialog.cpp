#include "AddRecordDialog.h"
#include <QMessageBox>
#include <QStandardItemModel>
#include <QButtonGroup>
#include <QDomDocument>
#include <QDomElement>
#include <QDate>
#include <QDateTime>
#include <QKeyEvent>
#include "DataCenter.h"
#include "SQLiteHelper.h"

AddRecordDialog::AddRecordDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("添加记录");
	QButtonGroup* _pButtonGroup = new QButtonGroup(this);
	_pButtonGroup->setExclusive(true);
	_pButtonGroup->addButton(ui.pushButton_Unpaid,0);
	_pButtonGroup->addButton(ui.pushButton_Paid,1);
	ui.pushButton_Unpaid->setCheckable(true);
	ui.pushButton_Paid->setCheckable(true);
	connect(_pButtonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &AddRecordDialog::slotRecordStatusChanged);
	slotRecordStatusChanged(0);

	QStandardItemModel* model = new QStandardItemModel(this);
	model->setColumnCount(5);
	model->setHeaderData(0, Qt::Horizontal, "药品ID");
	model->setHeaderData(1, Qt::Horizontal, "药品名称");
	model->setHeaderData(2, Qt::Horizontal, "药品单价");
	model->setHeaderData(3, Qt::Horizontal, "药品数量");
	model->setHeaderData(4, Qt::Horizontal, "药品金额");
	model->sort(0, Qt::AscendingOrder); // 第0列升序排序
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //列宽自适应
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //选择整行
	ui.tableView->setFocusPolicy(Qt::NoFocus); //禁止焦点
	ui.tableView->installEventFilter(this); //设置事件过滤
	ui.tableView->horizontalHeader()->setSortIndicatorShown(true); //排序小箭头
	m_Menu.addAction("删除", this, &AddRecordDialog::slotDeleteMedicine);
	ui.tableView->setModel(model);
	connect(model, &QStandardItemModel::itemChanged, this, &AddRecordDialog::slotItemChanged);
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
	connect(dynamic_cast<CompleteLineEdit*>(ui.lineEdit), &CompleteLineEdit::addUsemedicine, this, &AddRecordDialog::slotReciveUseMedicne);
	connect(ui.lineEdit_4, &QLineEdit::textChanged, this, &AddRecordDialog::slotAutoCalculatMoney);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &AddRecordDialog::slotAutoCalculatMoney);
	connect(ui.pushButton, &QPushButton::clicked, this, &AddRecordDialog::slotAddUseMedicne);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &AddRecordDialog::slotOkBtnClicked);
	connect(ui.pushButton_5, &QPushButton::clicked, this, &AddRecordDialog::close);
	m_currentPatient = gDataCenter->getCurrentPatientInfo();
	ui.label_2->setText(m_currentPatient.m_patientName);
	ui.label_4->setText(m_currentPatient.m_patientSex);
	QString _age = getPatientAge(m_currentPatient.m_patientIDCar);
	ui.label_6->setText(_age);
	ui.label_8->setText(m_currentPatient.m_patientIDCar);

	ui.lineEdit_2->setValidator(new QIntValidator(0, 1000, this));
	QRegExp rx("^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$");
	ui.lineEdit_4->setValidator(new QRegExpValidator(rx, this));
	ui.lineEdit_3->setValidator(new QRegExpValidator(rx, this));
	ui.lineEdit->installEventFilter(this);
	ui.lineEdit_2->installEventFilter(this);
	ui.lineEdit_3->installEventFilter(this);
	ui.lineEdit_4->installEventFilter(this);
	ui.pushButton->installEventFilter(this);
	ui.dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
	ui.dateTimeEdit->setCalendarPopup(true);
	ui.dateTimeEdit->setDateTime(QDateTime::currentDateTime());
	connect(ui.dateTimeEdit, &QDateTimeEdit::dateChanged, this, &AddRecordDialog::slotRecordDataChanged);
	//initDialogData();

	ui.pushButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}

AddRecordDialog::AddRecordDialog(OptMode _mode, int _recordId, QWidget *parent /*= Q_NULLPTR*/)
	:m_mode(_mode),m_recordId(_recordId), QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("编辑记录");
	QButtonGroup* _pButtonGroup = new QButtonGroup(this);
	_pButtonGroup->setExclusive(true);
	_pButtonGroup->addButton(ui.pushButton_Unpaid, 0);
	_pButtonGroup->addButton(ui.pushButton_Paid, 1);
	ui.pushButton_Unpaid->setCheckable(true);
	ui.pushButton_Paid->setCheckable(true);
	connect(_pButtonGroup, static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonClicked), this, &AddRecordDialog::slotRecordStatusChanged);
	slotRecordStatusChanged(0);

	QStandardItemModel* model = new QStandardItemModel(this);
	model->setColumnCount(5);
	model->setHeaderData(0, Qt::Horizontal, "药品ID");
	model->setHeaderData(1, Qt::Horizontal, "药品名称");
	model->setHeaderData(2, Qt::Horizontal, "药品单价");
	model->setHeaderData(3, Qt::Horizontal, "药品数量");
	model->setHeaderData(4, Qt::Horizontal, "药品金额");
	model->sort(0, Qt::AscendingOrder); // 第0列升序排序
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //列宽自适应
	ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //选择整行
	ui.tableView->setFocusPolicy(Qt::NoFocus); //禁止焦点
	ui.tableView->installEventFilter(this); //设置事件过滤
	ui.tableView->horizontalHeader()->setSortIndicatorShown(true); //排序小箭头
	m_Menu.addAction("删除", this, &AddRecordDialog::slotDeleteMedicine);
	ui.tableView->setModel(model);
	connect(model, &QStandardItemModel::itemChanged, this, &AddRecordDialog::slotItemChanged);
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
	connect(dynamic_cast<CompleteLineEdit*>(ui.lineEdit), &CompleteLineEdit::addUsemedicine, this, &AddRecordDialog::slotReciveUseMedicne);
	connect(ui.lineEdit_4, &QLineEdit::textChanged, this, &AddRecordDialog::slotAutoCalculatMoney);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &AddRecordDialog::slotAutoCalculatMoney);
	connect(ui.pushButton, &QPushButton::clicked, this, &AddRecordDialog::slotAddUseMedicne);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &AddRecordDialog::slotOkBtnClicked);
	connect(ui.pushButton_5, &QPushButton::clicked, this, &AddRecordDialog::close);
	/*m_currentPatient = gDataCenter->getCurrentPatientInfo();
	ui.label_2->setText(m_currentPatient.m_patientName);
	ui.label_4->setText(m_currentPatient.m_patientSex);
	ui.label_6->setText(m_currentPatient.m_patientIDCar);
	ui.label_8->setText(m_currentPatient.m_patientIDCar);*/

	ui.lineEdit_2->setValidator(new QIntValidator(0, 1000, this));
	QRegExp rx("^(([0-9]+\.[0-9]*[1-9][0-9]*)|([0-9]*[1-9][0-9]*\.[0-9]+)|([0-9]*[1-9][0-9]*))$");
	ui.lineEdit_4->setValidator(new QRegExpValidator(rx, this));
	ui.lineEdit_3->setValidator(new QRegExpValidator(rx, this));

	ui.lineEdit->installEventFilter(this);
	ui.lineEdit_2->installEventFilter(this);
	ui.lineEdit_3->installEventFilter(this);
	ui.lineEdit_4->installEventFilter(this);
	ui.pushButton->installEventFilter(this);

	ui.dateTimeEdit->setDisplayFormat("yyyy-MM-dd hh:mm:ss");
	ui.dateTimeEdit->setCalendarPopup(true);
	
	initDialogData();
	connect(ui.dateTimeEdit, &QDateTimeEdit::dateChanged, this, &AddRecordDialog::slotRecordDataChanged);
	ui.pushButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
}

AddRecordDialog::~AddRecordDialog()
{
}

void AddRecordDialog::initDialogData()
{
	//记录初始化模式
	if (m_mode == Init_Mode)
	{
		ui.groupBox->setTitle("编辑记录");
		RecordInfo _record;
		if (gDataBaseMgr->queryRecordByID(m_recordId, _record))
		{
			PatientInfo _isExcist;
			if (gDataBaseMgr->queryPatientByID(_record.m_recOfPatientID, _isExcist))
			{
				QString _medicineXml = _record.m_MedicienList;
				QDomDocument doc;
				doc.setContent(_medicineXml);
				QDomNode _node = doc.firstChild();
				while (!_node.isNull())
				{
					if (_node.isElement())
					{
						QDomElement _element = _node.toElement();
						qDebug() << "Element name: " << _element.tagName() << endl;
						if (_element.tagName() == "Medicines")
						{
							QDomNodeList _medicineList = _element.childNodes();
							for (int i = 0; i < _medicineList.count(); ++i)
							{
								QDomNode _item = _medicineList.at(i);
								if (_item.isElement())
								{
									QDomElement _medicine = _item.toElement();
									qDebug() << "Elementsssss name: " << _medicine.tagName() << endl;
									QStandardItemModel *_tempModel = static_cast<QStandardItemModel*>(ui.tableView->model());
									QStandardItem* itemID = new QStandardItem(_medicine.attribute("id"));
									itemID->setFlags(itemID->flags()&(~Qt::ItemIsEditable));
									itemID->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
									QStandardItem* itemName = new QStandardItem(_medicine.attribute("MedicineName"));
									itemName->setFlags(itemName->flags()&(~Qt::ItemIsEditable));
									itemName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
									QStandardItem* itemPrice = new QStandardItem(_medicine.attribute("Price"));
									//itemPrice->setFlags(itemPrice->flags()&(~Qt::ItemIsEditable));
									itemPrice->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
									QStandardItem* itemCount = new QStandardItem(_medicine.attribute("Count"));
									itemCount->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
									QStandardItem* itemMoeny = new QStandardItem(_medicine.attribute("Money"));
									itemMoeny->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
									_tempModel->appendRow(QList<QStandardItem*>() << itemID << itemName << itemPrice << itemCount << itemMoeny);
								}
							}
						}
					}
					_node = _node.nextSibling();
				}
				//更新记录状态
				if (_record.m_recStatus == "未结")
					slotRecordStatusChanged(0);
				else
					slotRecordStatusChanged(1);
				//更新账单添加页面人员信息
				ui.textEdit->setText(_record.m_recDiscript);
				ui.label_2->setText(_isExcist.m_patientName);
				ui.label_4->setText(_isExcist.m_patientSex);
				QString _age = getPatientAge(_isExcist.m_patientIDCar);
				ui.label_6->setText(_age);
				ui.label_8->setText(_isExcist.m_patientIDCar);
				ui.dateTimeEdit->setDateTime(QDateTime::fromString(_record.m_recCreatDate, "yyyy-MM-dd hh:mm:ss"));
			}
		}
	}
	autoCalculaAllMoney();
}

void AddRecordDialog::slotAddUseMedicne()
{
	if (ui.lineEdit->text().isEmpty())
	{
		QMessageBox::warning(this, tr("警告"),tr("药品名称不能为空。"),QMessageBox::Ok);
		return;
	}
	if (ui.lineEdit_4->text().isEmpty())
	{
		QMessageBox::warning(this, tr("警告"), tr("药品单价不能为空。"), QMessageBox::Ok);
		return;
	}
	if (ui.lineEdit_2->text().isEmpty())
	{
		QMessageBox::warning(this, tr("警告"), tr("药品数量不能为空。"), QMessageBox::Ok);
		return;
	}
	if (ui.lineEdit_3->text().isEmpty())
	{
		QMessageBox::warning(this, tr("警告"), tr("药品金额不能为空。"), QMessageBox::Ok);
		return;
	}
	if (ui.lineEdit->text() != m_currentMedicine.m_medicineName)
	{
		QList<MedicineInfo> _medicineList;
		if (gDataBaseMgr->queryMedicineByName(ui.lineEdit->text(), _medicineList))
		{
			if (_medicineList.count() != 1)
			{
				QMessageBox::critical(this, tr("错误"), tr("该药品存在多个，请在下拉框中选择。"), QMessageBox::Ok);
				return;
			}
			else
			{
				m_currentMedicine = _medicineList.first();
			}
		}
		else
		{
			QMessageBox::critical(this, tr("错误"), tr("无效药品。"), QMessageBox::Ok);
			return;
		}
	}
	QStandardItemModel *_tempModel = static_cast<QStandardItemModel*>(ui.tableView->model());
	QStandardItem* itemID = new QStandardItem(QString::number(m_currentMedicine.m_medicineID));
	itemID->setFlags(itemID->flags()&(~Qt::ItemIsEditable));
	itemID->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QStandardItem* itemName = new QStandardItem(m_currentMedicine.m_medicineName);
	itemName->setFlags(itemName->flags()&(~Qt::ItemIsEditable));
	itemName->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QStandardItem* itemPrice = new QStandardItem(ui.lineEdit_4->text());
	//itemPrice->setFlags(itemPrice->flags()&(~Qt::ItemIsEditable));
	itemPrice->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QStandardItem* itemCount = new QStandardItem(ui.lineEdit_2->text());
	itemCount->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	QStandardItem* itemMoeny = new QStandardItem(ui.lineEdit_3->text());
	itemMoeny->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	_tempModel->appendRow(QList<QStandardItem*>() << itemID << itemName << itemPrice << itemCount << itemMoeny);
	autoCalculaAllMoney();
	clearAddLineEdit();
}

void AddRecordDialog::slotAutoCalculatMoney()
{
	if (ui.lineEdit->text() != m_currentMedicine.m_medicineName)
		return;
	//ui.lineEdit_3->setText(QString::number(ui.lineEdit_2->text().toInt()*m_currentMedicine.m_medicinePrice));
	//if (!ui.lineEdit_2->text().isEmpty() && !ui.lineEdit_4->text().isEmpty())
	ui.lineEdit_3->setText(QString::number(ui.lineEdit_2->text().toInt()*(ui.lineEdit_4->text().toDouble())));
}

void AddRecordDialog::slotRecordStatusChanged(int _id)
{
	if (_id == 0)
	{
		ui.pushButton_Unpaid->setChecked(true);
		ui.label_14->setText("未结");
		m_currentStatus = false;
	}
	else
	{
		ui.pushButton_Paid->setChecked(true);
		ui.label_14->setText("已结");
		m_currentStatus = true;
	}
}

void AddRecordDialog::slotDeleteMedicine()
{
	QItemSelectionModel *selections = ui.tableView->selectionModel();
	QModelIndexList selected = selections->selectedIndexes();
	QMap<int, int> rows;
	foreach(QModelIndex index, selected)
	{
		rows.insert(index.row(), 0);
	}
	QMapIterator<int, int> r(rows);
	r.toBack();
	while (r.hasPrevious()) {
		r.previous();
		static_cast<QStandardItemModel*>(ui.tableView->model())->removeRow(r.key());
	}
	autoCalculaAllMoney();
}

void AddRecordDialog::slotOkBtnClicked()
{
	
	QStandardItemModel *_tempModel = static_cast<QStandardItemModel*>(ui.tableView->model());
	if (_tempModel->rowCount() == 0)
	{
		QMessageBox::critical(this, tr("错误"), tr("没有药品可提交。"), QMessageBox::Ok);
		return;
	}
	RecordInfo _record;
	QDomDocument doc;
	QDomElement _medicines = doc.createElement("Medicines");
	m_currentMoney = 0.0;
	for (int i = 0; i < _tempModel->rowCount(); ++i)
	{
		QDomElement _medicine = doc.createElement("Medicine");
		_medicine.setAttribute("id", _tempModel->item(i, 0)->text());
		_medicine.setAttribute("MedicineName", _tempModel->item(i, 1)->text());
		_medicine.setAttribute("Price", _tempModel->item(i, 2)->text());
		_medicine.setAttribute("Count", _tempModel->item(i, 3)->text());
		_medicine.setAttribute("Money", _tempModel->item(i, 4)->text());
		_medicines.appendChild(_medicine);
		m_currentMoney += _tempModel->item(i, 4)->text().toDouble();
	}
	doc.appendChild(_medicines);
	_record.m_optSupUserID = QString::number(123);
	//_record.m_optSupUserID = QString::number(gDataCenter->getCurrentSupUserInfo().m_userID);
	_record.m_recOfPatientID = m_currentPatient.m_patientID;
	_record.m_recTotalMoney = m_currentMoney;
	_record.m_MedicienList = doc.toString();
	_record.m_recStatus = ui.label_14->text();
	/*if (m_mode == Add_Mode)
		_record.m_recCreatDate = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");*/
	_record.m_recCreatDate = ui.dateTimeEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	_record.m_recModifyDate= QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
	_record.m_recDiscript = ui.textEdit->toPlainText();
	if (m_mode == Add_Mode)
	{
		if (gDataBaseMgr->addRecord(_record))
		{
			QMessageBox::information(this, tr("提示"), tr("记录提交成功。"), QMessageBox::Ok);
			this->accept();
		}
		else
		{
			QMessageBox::critical(this, tr("错误"), tr("记录提交失败。"), QMessageBox::Ok);
			this->reject();
		}
	}
	else
	{
		_record.m_recID = m_recordId;
		_record.m_recOfPatientID = ui.label_8->text();
		if (gDataBaseMgr->updateRecord(_record))
		{
			QMessageBox::information(this, tr("提示"), tr("记录更新成功。"), QMessageBox::Ok);
			this->accept();
		}
		else
		{
			QMessageBox::critical(this, tr("错误"), tr("记录更新失败。"), QMessageBox::Ok);
			this->reject();
		}
	}
}

void AddRecordDialog::sortByColumn(int col)
{
	QStandardItemModel *_tempModel = static_cast<QStandardItemModel*>(ui.tableView->model());
	bool ascending = (ui.tableView->horizontalHeader()->sortIndicatorSection() == col
		&& ui.tableView->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);
	Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
	_tempModel->sort(col, order);
}

void AddRecordDialog::slotItemChanged(QStandardItem *item)
{
	QStandardItemModel *_tempModel = static_cast<QStandardItemModel*>(ui.tableView->model());
	QModelIndex _index = _tempModel->indexFromItem(item);
	if (_index.column() == 3|| _index.column() == 2)
	{
		_tempModel->item(_index.row(), 4)->setText(QString::number(item->text().toDouble()*_tempModel->item(_index.row(), 2)->text().toDouble()));
		autoCalculaAllMoney();
	}
}

void AddRecordDialog::slotReciveUseMedicne(const MedicineInfo& medicine)
{
	m_currentMedicine = medicine;
	ui.label_11->setText(m_currentMedicine.m_medicineUnit);
	//ui.lineEdit_2->setValidator(new QIntValidator(0, medicine.m_medicineInventory, this));
}

void AddRecordDialog::slotRecordDataChanged()
{

}

bool AddRecordDialog::eventFilter(QObject* obj, QEvent *evt)
{
	if (obj == ui.tableView  &&  evt->type() == QEvent::ContextMenu)
	{
		if (ui.tableView->currentIndex().isValid() == true)
		{
			m_Menu.exec(cursor().pos());           //在当前鼠标位置上运行菜单menu对象
		}
	}
	if (evt->type() == QEvent::KeyPress)
	{
		QKeyEvent *ke = static_cast<QKeyEvent*>(evt);
		if (ke->key() == Qt::Key_Enter|| ke->key() == Qt::Key_Return)
		{
			bool bMedicineEdit = ui.lineEdit->hasFocus();
			bool bUnitpriceEdit = ui.lineEdit_4->hasFocus();
			bool bCountEdit = ui.lineEdit_2->hasFocus();
			bool bPriceEdit = ui.lineEdit_3->hasFocus();
			if (bMedicineEdit&&ui.lineEdit->isListViewHidden())
			{
				this->focusNextChild();
				ui.lineEdit_4->setFocus();
			}
			else if (bUnitpriceEdit)
			{
				this->focusNextChild();
				ui.lineEdit_2->setFocus();
			}
			else if (bCountEdit)
			{
				this->focusNextChild();
				ui.lineEdit_3->setFocus();
			}
			else if (bPriceEdit)
			{
				this->focusNextChild(); 
				ui.lineEdit->setFocus();
				slotAddUseMedicne();
			}
		}
	}
	if (evt->type() == QEvent::KeyRelease)
	{

	}
	return QWidget::eventFilter(obj, evt);
}

void AddRecordDialog::clearAddLineEdit()
{
	ui.lineEdit->clear();
	ui.lineEdit_2->clear();
	ui.lineEdit_3->clear();
	ui.lineEdit_4->clear();
	//ui.lineEdit->setFocus(Qt::MouseFocusReason);
}

void AddRecordDialog::autoCalculaAllMoney()
{
	m_currentMoney = 0.0;
	QStandardItemModel *_tempModel = static_cast<QStandardItemModel*>(ui.tableView->model());
	for (int i = 0; i < _tempModel->rowCount(); ++i)
	{
		m_currentMoney += _tempModel->item(i, 4)->text().toDouble();
	}
	ui.label_17->setText(QString::number(m_currentMoney) + "元");
}

QString AddRecordDialog::getPatientAge(QString _IdCar)
{
	QString age;
	if (_IdCar.length() >= 15)
	{
		QString _borndata = _IdCar.mid(6, 8);
		int agee = (QDate::currentDate().toString("yyyyMMdd").toInt() - _borndata.toInt()) / 10000;
		age = QString::number(agee) + "岁";
		return age;
	}
	else
	{
		age = "未知";
		return age;
	}
}