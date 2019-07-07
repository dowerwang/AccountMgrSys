#include "CompleteLineEdit.h"
#include <QKeyEvent>
#include <QListView>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QDebug>
#include "SQLiteHelper.h"


CompleteLineEdit::CompleteLineEdit(QWidget *parent)
	: QLineEdit(parent)
{
	m_listView = new QListView(this);
	//m_model = new QStringListModel(this);

	m_stdmodel = new QStandardItemModel(this);
	initMedicineModel();

	m_filterModel = new QSortFilterProxyModel(this);
	m_filterModel->setSourceModel(m_stdmodel);
	m_filterModel->setFilterKeyColumn(0);
	m_filterModel->setFilterRole(Qt::DisplayRole);
	//m_filterModel->setFilterRegExp("^[\u4e00-\u9fa5_a-zA-Z0-9]+$");

	m_listView->setWindowFlags(Qt::ToolTip);
	m_listView->setModel(m_filterModel);

	connect(this, &CompleteLineEdit::textChanged, this, &CompleteLineEdit::setCompleter);
	connect(m_listView, &QListView::clicked, this, &CompleteLineEdit::completeText);
}

CompleteLineEdit::~CompleteLineEdit()
{
}

void CompleteLineEdit::initMedicineModel()
{
	m_stdmodel->clear();
	if (gDataBaseMgr->queryMedicine(m_medicineList))
	{
		for (auto item : m_medicineList)
		{
			QStandardItem* itemMedicine = new QStandardItem(item.m_medicineName);
			itemMedicine->setData(QVariant::fromValue(item), Qt::UserRole);
			m_stdmodel->appendRow(itemMedicine);
		}
	}
}

bool CompleteLineEdit::isListViewHidden()
{
	if (m_listView != nullptr)
	{
		return m_listView->isHidden();
	}
	else
	{
		return true;
	}
}

void CompleteLineEdit::setCompleter(const QString &text)
{
	if (text.isEmpty()) {
		m_listView->hide();
		return;
	}
	//if ((text.length() > 1) && (!m_listView->isHidden())) {
	//	return;
	//}
	//// �������������б��е�ĳ�����ʰ���������ı��������Ҫ��ʾ������б���
	//QStringList sl;
	//foreach(QString word, words) {
	//	if (word.contains(text)) {
	//		sl << word;
	//	}
	//}
	//model->setStringList(sl);
	//m_listView->setModel(model);
	//if (model->rowCount() == 0) {
	//	return;
	//}
	// Position the text edit
	m_filterModel->setFilterFixedString(text);
	m_listView->setMinimumWidth(width());

	m_listView->setMaximumWidth(width());
	m_listView->setFocus();
	QPoint p(0, height());
	int x = mapToGlobal(p).x();
	int y = mapToGlobal(p).y() + 1;
	m_listView->move(x, y);
	m_listView->show();

}

void CompleteLineEdit::completeText(const QModelIndex &index)
{
	QString text = index.data().toString();
	this->setText(text);
	QVariant variant = index.data(Qt::UserRole);
	m_currentMedicine = variant.value<MedicineInfo>();
	emit addUsemedicine(m_currentMedicine);
	m_listView->hide();

}

void CompleteLineEdit::keyPressEvent(QKeyEvent *e)
{
	if (!m_listView->isHidden()) {
		int key = e->key();
		int count = m_listView->model()->rowCount();
		QModelIndex currentIndex = m_listView->currentIndex();
		if (Qt::Key_Down == key) {
			// �����·����ʱ���ƶ����ѡ����һ������б��е���
			int row = currentIndex.row() + 1;
			if (row >= count) {
				row = 0;
			}
			QModelIndex index = m_listView->model()->index(row, 0);
			m_listView->setCurrentIndex(index);
		}
		else if (Qt::Key_Up == key) {
			// �����·����ʱ���ƶ����ѡ����һ������б��е���
			int row = currentIndex.row() - 1;
			if (row < 0) {
				row = count - 1;
			}
			QModelIndex index = m_listView->model()->index(row, 0);
			m_listView->setCurrentIndex(index);
		}
		else if (Qt::Key_Escape == key) {
			// ����Esc��ʱ����������б�
			m_listView->hide();
		}
		else if (Qt::Key_Enter == key || Qt::Key_Return == key) {
			// ���»س���ʱ��ʹ������б���ѡ�е������������б�
			if (currentIndex.isValid()) {
				QString text = m_listView->currentIndex().data().toString();
				setText(text);
				QVariant variant = m_listView->currentIndex().data(Qt::UserRole);
				m_currentMedicine = variant.value<MedicineInfo>();
				emit addUsemedicine(m_currentMedicine);
			}
			m_listView->hide();
		}
		else {
			// �����������������б���ʹ��QLineEdit�ļ��̰����¼�
			m_listView->hide();
			QLineEdit::keyPressEvent(e);
		}
	}
	else {

		QLineEdit::keyPressEvent(e);
	}
}

void CompleteLineEdit::focusOutEvent(QFocusEvent *e)
{
	m_listView->hide();
}
