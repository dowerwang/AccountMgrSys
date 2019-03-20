#include "AccountMgrSys.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include "LoginDialog.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setFont(QFont("Microsoft YaHei", 9));
	AccountMgrSys w;
	QPixmap pixmap(":/login/Resources/loginbitmaps/gparted-icon.png");
	QSplashScreen screen(pixmap);
	screen.show();
	a.processEvents();
	screen.showMessage("����������", Qt::AlignHCenter|Qt::AlignBottom, QColor(Qt::white));
	QTime n = QTime::currentTime();
	QTime now;
	do {
		now = QTime::currentTime();
	} while (n.msecsTo(now) <= 1000);//6Ϊ��Ҫ��ʱ������
	screen.showMessage("�����������ݿ�ɹ���", Qt::AlignHCenter | Qt::AlignBottom, QColor(Qt::white));
	n = QTime::currentTime();
	do {
		now = QTime::currentTime();
	} while (n.msecsTo(now) <= 500);//6Ϊ��Ҫ��ʱ������
	screen.showMessage("������Ŀ���ݿ�ɹ���", Qt::AlignHCenter | Qt::AlignBottom, QColor(Qt::white));

	QFile qss(":/qss/Resources/defaultstyle.qss");
	qss.open(QFile::ReadOnly);
	qApp->setStyleSheet(qss.readAll());
	qss.close();


	/*LoginDialog* _loginDialog = new LoginDialog;
	_loginDialog->exec();*/
	w.show();
	screen.finish(&w);
	return a.exec();
}
