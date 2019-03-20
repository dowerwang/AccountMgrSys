#pragma once
#pragma execution_character_set("utf-8")
#include <QDialog>
#include "ui_AccountAddDialog.h"

class SupUserInfo;
class AccountAddDialog : public QDialog
{
	Q_OBJECT

public:
	AccountAddDialog(QWidget *parent = Q_NULLPTR);
	AccountAddDialog(const SupUserInfo&, QWidget *parent = Q_NULLPTR);
	~AccountAddDialog();
	void initAccountInfo(const SupUserInfo&);
public slots:
	void slotCancelBtnClicked();
	void slotOkBtnclicked();

private:
	Ui::AccountAddDialog ui;
	QButtonGroup *m_group1;
	QButtonGroup *m_group2;
};
