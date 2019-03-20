#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "ui_MedicineAddDialog.h"

class MedicineInfo;
class MedicineAddDialog : public QDialog
{
	Q_OBJECT

public:
	MedicineAddDialog(QWidget *parent = Q_NULLPTR);
	~MedicineAddDialog();
	void initMedicineInfo(const MedicineInfo&);
	void clearInfo();
public slots:
	void slotCancelBtnClicked();
	void slotOkBtnclicked();
private:
	Ui::MedicineAddDialog ui;
};
