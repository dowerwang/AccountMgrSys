#include "RecordBrowseDialog.h"
#include "AccountMgrSys.h"
#include "SQLiteHelper.h"
#include <QSqlTableModel>
#include "ItemDelegate.h"
#include <QMessageBox>

RecordBrowseDialog::RecordBrowseDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("记录管理");
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowMinMaxButtonsHint;
	flags |= Qt::WindowCloseButtonHint;
	this->setWindowFlags(flags);
	//connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &RecordBrowseDialog::slotqueryRecord);
	//connect(ui.pushButton_2, &QPushButton::clicked, this, &RecordBrowseDialog::slotDeleteRecord);

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
	ui.tableView->setModel(pModel);
	ui.tableView->setShowGrid(false);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //列宽自适应
	//ui.tableView->horizontalHeader()->setMinimumSectionSize(90);
	ui.tableView->horizontalHeader()->setStretchLastSection(true); //最后一行自动补全
	ui.tableView->horizontalHeader()->setSortIndicatorShown(true); //排序小箭头
	ui.tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

	ui.tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);// 以行作为选择标准
	//m_MainUi->tableView->verticalHeader()->hide();	// 行头隐藏

	ui.tableView->horizontalHeader()->setSectionsClickable(true);// 让列头可被点击，触发点击事件

	ui.tableView->horizontalHeader()->setHighlightSections(false);// 去掉选中表格时，列头的文字高亮
	ui.tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);

	//m_MainUi->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");// 列头灰色
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
	connect(ui.tableView, &QTableView::doubleClicked, this, &RecordBrowseDialog::slotTableDoubleClicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &RecordBrowseDialog::slotDeleteRecord);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &RecordBrowseDialog::slotSearchRecord);
	connect(ui.pushButton, &QPushButton::clicked, this, &RecordBrowseDialog::slotAdvancedSearchBtnClicked);


	ui.tableView->setItemDelegate(new RecordDelegate(this));

	ui.lineEdit_2->setPlaceholderText("查询人员ID/创建时间");

	ui.dateEdit->setDisplayFormat("yyyy-MM-dd");
	ui.dateEdit_2->setDisplayFormat("yyyy-MM-dd");
	ui.dateEdit->setCalendarPopup(true);
	ui.dateEdit_2->setCalendarPopup(true);
	ui.frame->setVisible(false);
	//ui.tableView->hideColumn(2);
	ui.tableView->hideColumn(4);

}

RecordBrowseDialog::~RecordBrowseDialog()
{
}

void RecordBrowseDialog::slotDeleteRecord()
{
	QItemSelectionModel *selections = ui.tableView->selectionModel();
	QModelIndexList selected = selections->selectedIndexes();
	QMap<int, int> rows;
	foreach(QModelIndex index, selected)
	{
		rows.insert(index.row(), 0);
	}
	if (rows.isEmpty())
	{
		int ret = QMessageBox::warning(this, tr("警告"), tr("没有选中的记录。"), QMessageBox::Ok);
		return;
	}
	int ret = QMessageBox::warning(this, tr("警告"), tr("是否删除所选记录？"), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Cancel)
		return;
	QMapIterator<int, int> r(rows);
	r.toBack();
	while (r.hasPrevious()) {
		r.previous();
		static_cast<QSqlTableModel*>(ui.tableView->model())->removeRow(r.key());
	}
	// 每次手动提交，都会重新刷新tableView，保持mode和tableView一致
	static_cast<QSqlTableModel*>(ui.tableView->model())->submitAll();
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
}

void RecordBrowseDialog::slotSearchRecord(const QString &text)
{
	if (m_AdvSearch)
	{
		QString _startDate = ui.dateEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
		QString _endDate = ui.dateEdit_2->dateTime().toString("yyyy-MM-dd 23:59:59");
		dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("datetime(CreatDate)>=datetime('%1') and datetime(CreatDate)<=datetime('%2')"
			"AND (PatientID LIKE '%%3%' OR  CreatDate Like '%%4%')").arg(_startDate).arg(_endDate).arg(text).arg(text));
	}
	else
		dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("PatientID LIKE '%%1%' OR  CreatDate Like '%%2%'").arg(text).arg(text));
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
}

void RecordBrowseDialog::slotTableDoubleClicked(const QModelIndex &index)
{
	if (index.isValid() && index.column() != 5)
	{
		QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui.tableView->model());
		int _currentID = pMode->record(index.row()).value("ID").toInt();
		AddRecordDialog *_addrecordDialog = new AddRecordDialog(AddRecordDialog::Init_Mode, _currentID);
		if (_addrecordDialog->exec())
		{
			dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
		}
		if (_addrecordDialog)
			delete _addrecordDialog;
		_addrecordDialog = nullptr;
	}
}

void RecordBrowseDialog::sortByColumn(int col)
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui.tableView->model());
	bool ascending = (ui.tableView->horizontalHeader()->sortIndicatorSection() == col
		&& ui.tableView->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);
	Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
	pMode->sort(col, order);
}

void RecordBrowseDialog::slotAdvancedSearchBtnClicked()
{
	if (ui.frame->isVisible())
	{
		m_AdvSearch = false;
		ui.frame->setVisible(false);
		disconnect(ui.dateEdit, &QDateEdit::dateChanged, this, &RecordBrowseDialog::slotStartDateChanged);
		disconnect(ui.dateEdit_2, &QDateEdit::dateChanged, this, &RecordBrowseDialog::slotEndDateChanged);
		QString text = ui.lineEdit_2->text();
		dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("PatientID LIKE '%%1%' OR  CreatDate Like '%%2%'").arg(text).arg(text));
		dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
	}
	else
	{
		m_AdvSearch = true;
		ui.dateEdit->setDate(QDate::currentDate());
		ui.dateEdit_2->setDate(QDate::currentDate());
		connect(ui.dateEdit, &QDateEdit::dateChanged, this, &RecordBrowseDialog::slotStartDateChanged);
		connect(ui.dateEdit_2, &QDateEdit::dateChanged, this, &RecordBrowseDialog::slotEndDateChanged);
		ui.frame->setVisible(true);

	}
}

void RecordBrowseDialog::slotStartDateChanged()
{
	QString text = ui.lineEdit_2->text();
	QString _startDate = ui.dateEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString _endDate = ui.dateEdit_2->dateTime().toString("yyyy-MM-dd 23:59:59");
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("datetime(CreatDate)>=datetime('%1') and datetime(CreatDate)<=datetime('%2')"
		"AND (PatientID LIKE '%%3%' OR  CreatDate Like '%%4%')").arg(_startDate).arg(_endDate).arg(text).arg(text));
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
}

void RecordBrowseDialog::slotEndDateChanged()
{
	QString text = ui.lineEdit_2->text();
	QString _startDate = ui.dateEdit->dateTime().toString("yyyy-MM-dd hh:mm:ss");
	QString _endDate = ui.dateEdit_2->dateTime().toString("yyyy-MM-dd 23:59:59");
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("datetime(CreatDate)>=datetime('%1') and datetime(CreatDate)<=datetime('%2')"
		"AND (PatientID LIKE '%%3%' OR  CreatDate Like '%%4%')").arg(_startDate).arg(_endDate).arg(text).arg(text));
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
}

void RecordBrowseDialog::closeEvent(QCloseEvent *event)
{
	emit sigUpdateRecordList();
	QDialog::closeEvent(event);
}
