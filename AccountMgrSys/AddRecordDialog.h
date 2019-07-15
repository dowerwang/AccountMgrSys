#pragma once
#pragma execution_character_set("utf-8") 

#include <QDialog>
#include <QMenu>
#include <QAction>
#include "CommentData.h"
#include "QStandardItem"
#include "ui_AddRecordDialog.h"

class AddRecordDialog : public QDialog
{
	Q_OBJECT

public:
	enum OptMode
	{
		Add_Mode,
		Init_Mode
	};
	AddRecordDialog(QWidget *parent = Q_NULLPTR);
	AddRecordDialog(OptMode _mode,int _recordId, QWidget *parent = Q_NULLPTR);
	~AddRecordDialog();

	void initDialogData();
public slots:
	//void slotSearchTextChanged(const QString &text);
	void slotAddUseMedicne();
	void slotAutoCalculatMoney();
	void slotRecordStatusChanged(int _id);

	void slotDeleteMedicine();
	void slotOkBtnClicked();
	void sortByColumn(int);
	void slotItemChanged(QStandardItem *item);
	void slotReciveUseMedicne(const MedicineInfo& medicine);
	void slotRecordDataChanged();
protected:
	bool eventFilter(QObject* obj, QEvent *evt);
private:
	Ui::AddRecordDialog ui;
	OptMode m_mode = Add_Mode;
	int m_recordId;

	PatientInfo m_currentPatient;
	MedicineInfo m_currentMedicine;
	QMap<int,MedicineInfo> m_MedicineMap;
	bool m_currentStatus = false; //Î´½á
	double m_currentMoney = 0.0;
	QMenu   m_Menu;
	void clearAddLineEdit();
	void autoCalculaAllMoney();
	QString getPatientAge(QString _IdCar);
};
