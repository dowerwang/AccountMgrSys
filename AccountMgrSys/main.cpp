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
	screen.showMessage("正在启动。", Qt::AlignHCenter|Qt::AlignBottom, QColor(Qt::white));
	QTime n = QTime::currentTime();
	QTime now;
	do {
		now = QTime::currentTime();
	} while (n.msecsTo(now) <= 1000);//6为需要延时的秒数
	screen.showMessage("连接区域数据库成功。", Qt::AlignHCenter | Qt::AlignBottom, QColor(Qt::white));
	n = QTime::currentTime();
	do {
		now = QTime::currentTime();
	} while (n.msecsTo(now) <= 500);//6为需要延时的秒数
	screen.showMessage("连接账目数据库成功。", Qt::AlignHCenter | Qt::AlignBottom, QColor(Qt::white));

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
