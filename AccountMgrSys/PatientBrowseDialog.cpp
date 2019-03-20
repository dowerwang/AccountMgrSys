#include "PatientBrowseDialog.h"
#include "CommentData.h"
#include "SQLiteHelper.h"
#include <QMessageBox>

PatientBrowseDialog::PatientBrowseDialog(QWidget *parent)
	:QDialog(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("人员管理");
	ui.pushButton->setVisible(false);
	ui.pushButton_2->setVisible(false);
	ui.pushButton_4->setVisible(false);
	ui.pushButton_5->setVisible(false);
	ui.pushButton_7->setVisible(false);
	ui.radioButton->setVisible(false);
	ui.radioButton_2->setVisible(false);
	ui.radioButton_3->setVisible(false);
	//this->setAttribute(Qt::WA_DeleteOnClose);
	PatientTree *_patientTree = new PatientTree(&ui, this);
}

PatientBrowseDialog::~PatientBrowseDialog()
{
}