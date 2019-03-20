#pragma once

#include <QDialog>
#include "ui_LoginDialog.h"

class LoginDialog : public QDialog
{
	Q_OBJECT

public:
	LoginDialog(QWidget *parent = Q_NULLPTR);
	~LoginDialog();
	bool showLoginDialog();
private:
	Ui::LoginDialog ui;
};
