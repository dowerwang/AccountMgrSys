#pragma once
#pragma execution_character_set("utf-8")

#include <QDialog>
#include "ui_PatientBrowseDialog.h"
#include "PatientTree.h"

class PatientInfo;
class PatientBrowseDialog : public QDialog
{
	Q_OBJECT

public:
	PatientBrowseDialog(QWidget *parent = Q_NULLPTR);
	~PatientBrowseDialog();

private:
	Ui::PatientBrowseDialog ui;
	AddsSelectWidget *m_addsSelectWidget = nullptr;
};
