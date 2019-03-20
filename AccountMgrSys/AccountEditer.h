#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "ui_AccountEditer.h"
#include "AccountAddDialog.h"
#include <QTreeView>

class AccountEditer : public QDialog
{
	Q_OBJECT

public:
	AccountEditer(QWidget *parent = Q_NULLPTR);
	~AccountEditer();

	void updateAccountList();
public slots:
	void slotAddAccount(); //����
	void slotDeleteAccount(); //ɾ��
	void slotSubmitBtnClicked(); //�ύ
	void slotqueryAccount();  //��ѯ
	
	void sortByColumn(int);
private:
	Ui::AccountEditer ui;
};
