#pragma once

#include <QDialog>
#include "ui_RecordBrowseDialog.h"
#include "CommentData.h"
#include <QCloseEvent>

class RecordBrowseDialog : public QDialog
{
	Q_OBJECT

public:
	RecordBrowseDialog(QWidget *parent = Q_NULLPTR);
	~RecordBrowseDialog();
signals:
	void sigUpdateRecordList();
public slots:
	void slotDeleteRecord(); //É¾³ý
	void slotSearchRecord(const QString &text);
	void slotTableDoubleClicked(const QModelIndex &index);
	void sortByColumn(int);
	void slotAdvancedSearchBtnClicked();
	void slotStartDateChanged();
	void slotEndDateChanged();

protected:
	void closeEvent(QCloseEvent *event);
private:
	Ui::RecordBrowseDialog ui;
	bool m_AdvSearch = false;
};
