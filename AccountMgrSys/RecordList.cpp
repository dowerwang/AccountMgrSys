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
	// 三种提交方式，改动即提交，选择其他行时提交，手动提交；经实际测试，其中只有手动提交在显示效果上是最好的
	pModel->setEditStrategy(QSqlTableModel::OnFieldChange);
	//pModel->select();
	pModel->setHeaderData(0, Qt::Horizontal, "记录ID");
	pModel->setHeaderData(1, Qt::Horizontal, "操作员");
	pModel->setHeaderData(2, Qt::Horizontal, "人员名");
	pModel->setHeaderData(3, Qt::Horizontal, "金额");
	pModel->setHeaderData(4, Qt::Horizontal, "药品ID列表");
	pModel->setHeaderData(5, Qt::Horizontal, "记录状态");
	pModel->setHeaderData(6, Qt::Horizontal, "创建时间");
	pModel->setHeaderData(7, Qt::Horizontal, "修改时间");
	pModel->setHeaderData(8, Qt::Horizontal, "描述");
	pModel->sort(0, Qt::AscendingOrder); // 第0列升序排序

	/*QSortFilterProxyModel *m_filterModel = new QSortFilterProxyModel(this);
	m_filterModel->setSourceModel(pModel);
	m_filterModel->setFilterKeyColumn(0);
	m_filterModel->setFilterRole(Qt::DisplayRole);*/
	
	//m_MainUi->tableView->setFocusPolicy(Qt::NoFocus); //禁止焦点
	m_MainUi->tableView->setModel(pModel);
	m_MainUi->tableView->setShowGrid(false);
	m_MainUi->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //列宽自适应
	m_MainUi->tableView->horizontalHeader()->setMinimumSectionSize(90);
	m_MainUi->tableView->horizontalHeader()->setStretchLastSection(true); //最后一行自动补全
	m_MainUi->tableView->horizontalHeader()->setSortIndicatorShown(true); //排序小箭头
	m_MainUi->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

	//m_MainUi->tableView->setSelectionBehavior(QAbstractItemView::SelectRows); //选择整行
	//m_MainUi->tableView->setSelectionMode(QAbstractItemView::SingleSelection);// 只能单选

	m_MainUi->tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);// 以行作为选择标准
	//m_MainUi->tableView->verticalHeader()->hide();	// 行头隐藏

	m_MainUi->tableView->horizontalHeader()->setSectionsClickable(true);// 让列头可被点击，触发点击事件

	m_MainUi->tableView->horizontalHeader()->setHighlightSections(false);// 去掉选中表格时，列头的文字高亮
	m_MainUi->tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);

	//m_MainUi->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");// 列头灰色
	connect(m_MainUi->tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
	connect(m_MainUi->tableView, &QTableView::doubleClicked, this, &RecordList::slotTableDoubleClicked);
	connect(m_MainUi->pushButton, &QPushButton::clicked, this, &RecordList::slotAddRecord);
	connect(m_MainUi->pushButton_2, &QPushButton::clicked, this, &RecordList::slotDeleteRecord);
	connect(m_MainUi->pushButton_3, &QPushButton::clicked, this, &RecordList::slotSubmitBtnClicked);
	connect(m_MainUi->lineEdit_2, &QLineEdit::textChanged, this, &RecordList::slotSearchRecord);

	m_MainUi->lineEdit_2->setPlaceholderText("输入日期来查询");

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
		if (pMode->record(i).value("RecStatus").toString() == "未结")
		{
			++_unPaidCount;
			_unPaidMoney += pMode->record(i).value("TotalMoney").toDouble();
		}
	}
	m_MainUi->label_18->setText(QString::number(pMode->rowCount()) + "条");
	m_MainUi->label_20->setText(QString::number(_totalAmount) + "元");
	m_MainUi->label_22->setText(QString::number(_unPaidCount) + "条");
	m_MainUi->label_24->setText(QString::number(_unPaidMoney) + "元");
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
		int ret = QMessageBox::warning(m_mainWindow, tr("警告"), tr("没有选中的记录。"), QMessageBox::Ok);
		return;
	}
	int ret = QMessageBox::warning(m_mainWindow, tr("警告"), tr("是否删除所选记录？"), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Cancel)
		return;
	QMapIterator<int, int> r(rows);
	r.toBack();
	while (r.hasPrevious()) {
		r.previous();
		static_cast<QSqlTableModel*>(m_MainUi->tableView->model())->removeRow(r.key());
	}
	// 每次手动提交，都会重新刷新tableView，保持mode和tableView一致
	static_cast<QSqlTableModel*>(m_MainUi->tableView->model())->submitAll();
}

void RecordList::slotSubmitBtnClicked()
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(m_MainUi->tableView->model());
	pMode->database().transaction(); //开始事务操作
	if (pMode->submitAll()) // 提交所有被修改的数据到数据库中
	{
		pMode->database().commit(); //提交成功，事务将真正修改数据库数据
		QMessageBox::information(m_mainWindow, tr("提示"), tr("数据提交成功。"));
	}
	else {
		pMode->database().rollback(); //提交失败，事务回滚
		QMessageBox::warning(m_mainWindow, tr("tableModel"), tr("数据库错误: %1").arg(pMode->lastError().text()));
	}
	pMode->revertAll(); //撤销修改
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
