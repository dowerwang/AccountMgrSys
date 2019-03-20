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
	this->setWindowTitle("��¼����");
	Qt::WindowFlags flags = Qt::Dialog;
	flags |= Qt::WindowMinMaxButtonsHint;
	flags |= Qt::WindowCloseButtonHint;
	this->setWindowFlags(flags);
	//connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &RecordBrowseDialog::slotqueryRecord);
	//connect(ui.pushButton_2, &QPushButton::clicked, this, &RecordBrowseDialog::slotDeleteRecord);

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
	ui.tableView->setModel(pModel);
	ui.tableView->setShowGrid(false);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); //�п�����Ӧ
	//ui.tableView->horizontalHeader()->setMinimumSectionSize(90);
	ui.tableView->horizontalHeader()->setStretchLastSection(true); //���һ���Զ���ȫ
	ui.tableView->horizontalHeader()->setSortIndicatorShown(true); //����С��ͷ
	ui.tableView->setEditTriggers(QAbstractItemView::DoubleClicked);

	ui.tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);// ������Ϊѡ���׼
	//m_MainUi->tableView->verticalHeader()->hide();	// ��ͷ����

	ui.tableView->horizontalHeader()->setSectionsClickable(true);// ����ͷ�ɱ��������������¼�

	ui.tableView->horizontalHeader()->setHighlightSections(false);// ȥ��ѡ�б��ʱ����ͷ�����ָ���
	ui.tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);

	//m_MainUi->tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");// ��ͷ��ɫ
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));
	connect(ui.tableView, &QTableView::doubleClicked, this, &RecordBrowseDialog::slotTableDoubleClicked);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &RecordBrowseDialog::slotDeleteRecord);
	connect(ui.lineEdit_2, &QLineEdit::textChanged, this, &RecordBrowseDialog::slotSearchRecord);
	connect(ui.pushButton, &QPushButton::clicked, this, &RecordBrowseDialog::slotAdvancedSearchBtnClicked);


	ui.tableView->setItemDelegate(new RecordDelegate(this));

	ui.lineEdit_2->setPlaceholderText("��ѯ��ԱID/����ʱ��");

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
		int ret = QMessageBox::warning(this, tr("����"), tr("û��ѡ�еļ�¼��"), QMessageBox::Ok);
		return;
	}
	int ret = QMessageBox::warning(this, tr("����"), tr("�Ƿ�ɾ����ѡ��¼��"), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Cancel)
		return;
	QMapIterator<int, int> r(rows);
	r.toBack();
	while (r.hasPrevious()) {
		r.previous();
		static_cast<QSqlTableModel*>(ui.tableView->model())->removeRow(r.key());
	}
	// ÿ���ֶ��ύ����������ˢ��tableView������mode��tableViewһ��
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
