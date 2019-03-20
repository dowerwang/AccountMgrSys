#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "ui_MedicineEditor.h"
#include "MedicineAddDialog.h"

class MedicineEditor : public QDialog
{
	Q_OBJECT

public:
	MedicineEditor(QWidget *parent = Q_NULLPTR);
	~MedicineEditor();

	void updateMedicineList();
public slots:
	void slotAddMedicine(); //����
	void slotDeleteMedicine(); //ɾ��
	void slotSubmitBtnClicked(); //�ύ
	void slotqueryMedicine();  //��ѯ

	void sortByColumn(int);
private:
	Ui::MedicineEditor ui;
};
