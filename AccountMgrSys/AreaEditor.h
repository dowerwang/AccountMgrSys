#pragma once

#include <QDialog>
#include "ui_AreaEditor.h"

class AreaEditor : public QDialog
{
	Q_OBJECT

public:
	AreaEditor(QWidget *parent = Q_NULLPTR);
	~AreaEditor();

private:
	Ui::AreaEditor ui;
};
