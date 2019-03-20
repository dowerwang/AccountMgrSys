#include "RecordList.h"
#include "AccountMgrSys.h"
#include "SQLiteHelper.h"
#include <QSqlTableModel>
#include "ItemDelegate.h"
#include <QMessageBox>
//#include "CommentData.h"
RecordList::RecordList()
{
}


RecordList::RecordList(Ui::AccountMgrSysClass* _ui, AccountMgrSys* _mainwindow)
	:m_MainUi(_ui),m_mainWindow(_mainwindow)
{
	//connect(m_MainUi->lineEdit_2, &QLineEdit::textChanged, this, &RecordList::slotqueryRecord);
	//connect(m_MainUi->pushButton, &QPushButton::clicked, this, &RecordList::slotAddRecord);
	//connect(m_MainUi->pushButton_2, &QPushButton::clicked, this, &RecordList::slotDeleteRecord);
	//connect(m_MainUi->pushButton_3, &QPushButton::clicked, this, &RecordList::slotSubmitBtnClicked);
	QSqlTableModel *pModel = new QSqlTableModel(this, gDataBaseMgr->getAccountDB());
	pModel->setTable("Record");
	// �����ύ��ʽ���Ķ����ύ��ѡ��������ʱ�ύ���ֶ��ύ����ʵ�ʲ��ԣ�����ֻ���ֶ��ύ����ʾЧ��������õ�
	pModel->setEditStrategy(QSqlTableModel::OnFieldChange);
	//pModel->select();
	pModel->setHeaderData(0, Qt::Horizontal, "��¼ID");
	pModel->setHeaderData(1, Qt::Horizontal, "����Ա");
	pModel->setHeaderData(2, Qt::Horizontal, "��Ա��");
	pModel->setHeaderData(3, Qt::Horizontal, "���");
	pModel->setHeaderData(4, Qt::Horizontal, "ҩƷID�б�");
	pModel->setHeaderData(5, Qt::Horizontal, "��¼״̬");
	pModel->setHeaderData(6, Qt::Horizontal, "����ʱ��");
	pModel->setHeaderData(7, Qt::Horizontal, "�޸�ʱ��");
	pModel->setHeaderData(8, Qt::Horizontal, "����");
	pModel->sort(0, Qt::AscendingOrder); // ��0����������

	/*QSortFilterProxyModel *m_filterModel = new QSortFilterProxyModel(this);
	m_filterModel->setSourceModel(pModel);
	m_filterModel->setFilterKeyColumn(0);
	m_filterModel->setFilterRole(Qt::DisplayRole);*/
	
	//m_MainUi->tableView->setFocusPolicy(Qt::NoFocus); //��ֹ����
	m_MainUi->tableView->setModel(pModel);
	m_MainUi->tableView->setShowGrid(false);
	m_MainUi->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //�п�����Ӧ
	m_MainUi->tableView->horizontalHeader()->setMinimumSectionSize(90);
	m_MainUi->tableView->horizontalHeader()->setStretchLastSection(true); //���һ���Զ���ȫ
	m_MainUi->tableView->horizontalHeader()->setSortIndicatorShown(true); //����С��ͷ
	m_MainUi->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

	//m_MainUi->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //ѡ������
	//m_MainUi->tableView->setSelectionMode(QAbstractItemView::SingleSelection);// ֻ�ܵ�ѡ

	m_MainUi->tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);// ������Ϊѡ���׼
	//m_MainUi->tableView->verticalHeader()->hide();	// ��ͷ����

	m_MainUi->tableView->horizontalHeader()->setSectionsClickable(true);// ����ͷ�ɱ��������������¼�

	m_MainUi->tableView->horizontalHeader()->setHighlightSections(false);// ȥ��ѡ�б��ʱ����ͷ�����ָ���
	m_MainUi->tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);

	//m_MainUi->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");// ��ͷ��ɫ
	connect(m_MainUi->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
	connect(m_MainUi->tableView, &QTableView::doubleClicked, this, &RecordList::slotTableDoubleClicked);
	connect(m_MainUi->pushButton, &QPushButton::clicked, this, &RecordList::slotAddRecord);
	connect(m_MainUi->pushButton_2, &QPushButton::clicked, this, &RecordList::slotDeleteRecord);
	connect(m_MainUi->pushButton_3, &QPushButton::clicked, this, &RecordList::slotSubmitBtnClicked);
	connect(m_MainUi->lineEdit_2, &QLineEdit::textChanged, this, &RecordList::slotSearchRecord);

	m_MainUi->lineEdit_2->setPlaceholderText("������������ѯ");

	m_MainUi->tableView->setItemDelegate(new RecordDelegate(this));
	connect(m_MainUi->tableView->itemDelegate(), &QStyledItemDelegate::closeEditor, this, &RecordList::slotItemDataChanged);

	/*RecordStatusDelegate *_itemDelegate = new RecordStatusDelegate(this);
	m_MainUi->tableView->setItemDelegateForColumn(5, _itemDelegate);

	m_MainUi->tableView->setItemDelegateForColumn(0, new ReadOnlyDelegate(this));
	m_MainUi->tableView->setItemDelegateForColumn(1, new ReadOnlyDelegate(this));
	m_MainUi->tableView->setItemDelegateForColumn(3, new ReadOnlyDelegate(this));
	m_MainUi->tableView->setItemDelegateForColumn(6, new ReadOnlyDelegate(this));
	m_MainUi->tableView->setItemDelegateForColumn(7, new ReadOnlyDelegate(this));
	m_MainUi->tableView->setItemDelegateForColumn(8, new ReadOnlyDelegate(this));*/

	//m_MainUi->tableView->hideColumn(1);
	m_MainUi->tableView->hideColumn(2);
	m_MainUi->tableView->hideColumn(4);
	
}

RecordList::~RecordList()
{
}

void RecordList::setCurrentPatient(const PatientInfo&patient)
{
	m_patientInfo = patient;
	dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model())->setFilter(QString("PatientID = '%1'").arg(m_patientInfo.m_patientIDCar));
	dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model())->select();
	updateRecordInfoView();
}

void RecordList::reLoadAllRecord()
{
	dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model())->select();
	updateRecordInfoView();
}

void RecordList::updateRecordInfoView()
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model());
	int _allRecordCount = 0, _unPaidCount = 0;
	double _totalAmount = 0.0, _unPaidMoney = 0.0;
	for (int i = 0; i < pMode->rowCount(); ++i)
	{
		_totalAmount += pMode->record(i).value("TotalMoney").toDouble();
		if (pMode->record(i).value("RecStatus").toString() == "δ��")
		{
			++_unPaidCount;
			_unPaidMoney += pMode->record(i).value("TotalMoney").toDouble();
		}
	}
	m_MainUi->label_18->setText(QString::number(pMode->rowCount()) + "��");
	m_MainUi->label_20->setText(QString::number(_totalAmount) + "Ԫ");
	m_MainUi->label_22->setText(QString::number(_unPaidCount) + "��");
	m_MainUi->label_24->setText(QString::number(_unPaidMoney) + "Ԫ");
}

void RecordList::slotSearchRecord(const QString &text)
{
	dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model())->setFilter(QString("PatientID = '%1' AND  CreatDate Like '%%2%'").arg(m_patientInfo.m_patientIDCar).arg(text));
	dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model())->select();
}

void RecordList::slotAddRecord()
{
	AddRecordDialog *_addrecordDialog = new AddRecordDialog();
	if (_addrecordDialog->exec())
		reLoadAllRecord();
	if (_addrecordDialog)
		delete _addrecordDialog;
	_addrecordDialog = nullptr;
}

void RecordList::slotDeleteRecord()
{
	QItemSelectionModel *selections =m_MainUi->tableView->selectionModel();
	QModelIndexList selected = selections->selectedIndexes();
	QMap<int, int> rows;
	foreach(QModelIndex index, selected)
	{
		rows.insert(index.row(), 0);
	}
	if (rows.isEmpty())
	{
		int ret = QMessageBox::warning(m_mainWindow, tr("����"), tr("û��ѡ�еļ�¼��"), QMessageBox::Ok);
		return;
	}
	int ret = QMessageBox::warning(m_mainWindow, tr("����"), tr("�Ƿ�ɾ����ѡ��¼��"), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Cancel)
		return;
	QMapIterator<int, int> r(rows);
	r.toBack();
	while (r.hasPrevious()) {
		r.previous();
		static_cast<QSqlTableModel*>(m_MainUi->tableView->model())->removeRow(r.key());
	}
	// ÿ���ֶ��ύ����������ˢ��tableView������mode��tableViewһ��
	static_cast<QSqlTableModel*>(m_MainUi->tableView->model())->submitAll();
}

void RecordList::slotSubmitBtnClicked()
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model());
	pMode->database().transaction(); //��ʼ�������
	if (pMode->submitAll()) // �ύ���б��޸ĵ����ݵ����ݿ���
	{
		pMode->database().commit(); //�ύ�ɹ������������޸����ݿ�����
		QMessageBox::information(m_mainWindow, tr("��ʾ"), tr("�����ύ�ɹ���"));
	}
	else {
		pMode->database().rollback(); //�ύʧ�ܣ�����ع�
		QMessageBox::warning(m_mainWindow, tr("tableModel"), tr("���ݿ����: %1").arg(pMode->lastError().text()));
	}
	pMode->revertAll(); //�����޸�
}

void RecordList::slotTableDoubleClicked(const QModelIndex &index)
{
	if (index.isValid()&& index.column() != 5)
	{
		QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model());
		int _currentID = pMode->record(index.row()).value("ID").toInt();
		AddRecordDialog *_addrecordDialog = new AddRecordDialog(AddRecordDialog::Init_Mode, _currentID, m_mainWindow);
		if (_addrecordDialog->exec())
		{
			reLoadAllRecord();
		}
		if (_addrecordDialog)
			delete _addrecordDialog;
		_addrecordDialog = nullptr;
	}
}

void RecordList::sortByColumn(int col)
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model());
	bool ascending = (m_MainUi->tableView->horizontalHeader()->sortIndicatorSection() == col
		&& m_MainUi->tableView->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);
	Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
	pMode->sort(col, order);
}

void RecordList::slotUpdateRecordList()
{
	reLoadAllRecord();
}

void RecordList::slotItemDataChanged()
{
	reLoadAllRecord();
}
