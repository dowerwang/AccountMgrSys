#include "AccountEditer.h"
#include "CommentData.h"
#include "SQLiteHelper.h"
#include <QSqlTableModel>
#include "ItemDelegate.h"

AccountEditer::AccountEditer(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	ui.radioButton->setChecked(true);
	connect(ui.lineEdit, &QLineEdit::textChanged, this, &AccountEditer::slotqueryAccount);
	connect(ui.pushButton, &QPushButton::clicked, this, &AccountEditer::slotAddAccount);
	connect(ui.pushButton_3, &QPushButton::clicked, this, &AccountEditer::slotqueryAccount);
	connect(ui.pushButton_4, &QPushButton::clicked, this, &AccountEditer::slotDeleteAccount);
	connect(ui.pushButton_5, &QPushButton::clicked, this, &AccountEditer::slotSubmitBtnClicked);
	QSqlTableModel *pModel = new QSqlTableModel(this, gDataBaseMgr->getAccountDB());
	pModel->setTable("Account");
	// 三种提交方式，改动即提交，选择其他行时提交，手动提交；经实际测试，其中只有手动提交在显示效果上是最好的
	pModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	pModel->select();
	pModel->setHeaderData(0, Qt::Horizontal, "管理员ID");
	pModel->setHeaderData(1, Qt::Horizontal, "管理员名");
	pModel->setHeaderData(2, Qt::Horizontal, "性别");
	pModel->setHeaderData(3, Qt::Horizontal, "管理员类型");
	pModel->setHeaderData(4, Qt::Horizontal, "身份证号");
	pModel->setHeaderData(5, Qt::Horizontal, "登录密码");
	pModel->setHeaderData(6, Qt::Horizontal, "联系电话");
	pModel->setHeaderData(7, Qt::Horizontal, "地址");
	pModel->setHeaderData(8, Qt::Horizontal, "描述");
	pModel->sort(0, Qt::AscendingOrder); // 第0列升序排序
	ui.tableView->setModel(pModel);
	ui.tableView->setShowGrid(false);
	ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //列宽自适应
	ui.tableView->horizontalHeader()->setMinimumSectionSize(50); 
	ui.tableView->horizontalHeader()->setStretchLastSection(true); //最后一行自动补全
	ui.tableView->horizontalHeader()->setSortIndicatorShown(true); //排序小箭头
	
	ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);// 只能单选
	
	ui.tableView->setSelectionBehavior(QAbstractItemView::QAbstractItemView::SelectRows);// 以行作为选择标准

	//ui.tableView->verticalHeader()->hide();	// 行头隐藏
	
	ui.tableView->horizontalHeader()->setSectionsClickable(true);// 让列头可被点击，触发点击事件
	
	ui.tableView->horizontalHeader()->setHighlightSections(false);// 去掉选中表格时，列头的文字高亮
	ui.tableView->horizontalHeader()->setBackgroundRole(QPalette::Background);

	//ui.tableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:rgb(225,225,225)};");// 列头灰色
	connect(ui.tableView->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(sortByColumn(int)));

	AccountEditorDelegate *_sexDelegate = new AccountEditorDelegate;
	ui.tableView->setItemDelegateForColumn(2, _sexDelegate);
	AccountEditorDelegate *_sexDelegate2 = new AccountEditorDelegate;
	ui.tableView->setItemDelegateForColumn(3, _sexDelegate2);

}

AccountEditer::~AccountEditer()
{
}

void AccountEditer::updateAccountList()
{

}

void AccountEditer::slotAddAccount()
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui.tableView->model());
	AccountAddDialog *_accountAddDialog = new AccountAddDialog;
	if (_accountAddDialog->exec())
		pMode->submitAll();
}

void AccountEditer::slotDeleteAccount()
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui.tableView->model());
	QSqlRecord _record = pMode->record(ui.tableView->currentIndex().row());
	int ret = QMessageBox::warning(this, tr("警告"), tr("是否删除:%1？").arg(_record.value("Name").toString()), QMessageBox::Ok | QMessageBox::Cancel);
	if (ret == QMessageBox::Cancel)
		return;
	pMode->removeRow(ui.tableView->currentIndex().row());
	// 每次手动提交，都会重新刷新tableView，保持mode和tableView一致
	pMode->submitAll();
}

void AccountEditer::slotSubmitBtnClicked()
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui.tableView->model());
	pMode->database().transaction(); //开始事务操作
	if (pMode->submitAll()) // 提交所有被修改的数据到数据库中
	{
		pMode->database().commit(); //提交成功，事务将真正修改数据库数据
		QMessageBox::information(this, tr("提示"), tr("数据提交成功。"));
	}
	else {
		pMode->database().rollback(); //提交失败，事务回滚
		QMessageBox::warning(this, tr("tableModel"), tr("数据库错误: %1").arg(pMode->lastError().text()));
	}
	pMode->revertAll(); //撤销修改
}

void AccountEditer::slotqueryAccount()
{
	QString name = ui.lineEdit->text();
	//筛选
	if (!ui.lineEdit->text().isEmpty())
		//dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("(Name Like '%%1%') OR (ID Like '%%2%')").arg(name).arg(name));
		dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("Name Like '%%1%'").arg(name));
	if (ui.lineEdit->text().isEmpty())
	{
		dynamic_cast<QSqlTableModel *>(ui.tableView->model())->setFilter(QString("Name Like '%%'"));
	}
	//查询
	dynamic_cast<QSqlTableModel *>(ui.tableView->model())->select();
}

void AccountEditer::sortByColumn(int col)
{
	QSqlTableModel *pMode = dynamic_cast<QSqlTableModel *>(ui.tableView->model());
	bool ascending = (ui.tableView->horizontalHeader()->sortIndicatorSection() == col
		&& ui.tableView->horizontalHeader()->sortIndicatorOrder() == Qt::DescendingOrder);
	Qt::SortOrder order = ascending ? Qt::AscendingOrder : Qt::DescendingOrder;
	pMode->sort(col, order);
}
