#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

LoginDialog::~LoginDialog()
{
}

bool LoginDialog::showLoginDialog()
{
	this->exec();
	return true;
}
