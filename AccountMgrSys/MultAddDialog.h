#pragma once
#pragma execution_character_set("utf-8") 

#include <QDialog>
#include <QMessageBox>
#include "ui_MultAddDialog.h"

class MultAddDialog : public QDialog
{
	Q_OBJECT

public:
	enum OptMode
	{
		AddTown,
		UpdateTown,
		AddVillage,
		UpdateVillage,
		AddGroup,
		UpdateGroup,
		AddHouseHold,
		UpdateHouseHold
	};
	MultAddDialog(QWidget *parent = Q_NULLPTR);
	MultAddDialog(OptMode mode, QWidget *parent = Q_NULLPTR);
	~MultAddDialog();
	void initDialog();
	void setShowText(const QString & str);
	void setShowIDText(const QString & str);
	QString & getNameText();
	QString & getCarIDText();

public slots:
	void slotOkBtnclicked();
private:
	Ui::MultAddDialog ui;
	OptMode m_mode;
	QString m_NameText;
	QString m_CarIDText;
	QString m_oldIDCard;
};
