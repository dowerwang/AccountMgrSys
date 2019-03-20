#pragma once
#pragma execution_character_set("utf-8") 

#include <QDialog>
#include "ui_PatientAddDialog.h"

#include "CommentData.h"
class PatientAddDialog : public QDialog
{
	Q_OBJECT

public:
	enum OptMode
	{
		AddPatient,
		ModifyPatient
	};
	PatientAddDialog(QWidget *parent = Q_NULLPTR);
	PatientAddDialog(OptMode _mode, QWidget *parent = Q_NULLPTR);
	PatientAddDialog(OptMode _mode, const QString & householdname,const QString &householdID, const QString &adds, QWidget *parent = Q_NULLPTR);
	~PatientAddDialog();
	void initPatientInfo(const PatientInfo&);
	const QString& getAddPatientName() { return m_addPatientName; }
	const QString& getAddPatientID() { return m_addPatientID; }
	void clearInfo();
public slots:
	void slotCancelBtnClicked();
	void slotOkBtnclicked();
private:
	Ui::PatientAddDialog ui;
	OptMode m_mode;
	QString m_houseHoldName;
	QString m_houseHoldID;
	QString m_adds;

	QString m_addPatientName;
	QString m_addPatientID;
	QString m_oldIDCar;
};
