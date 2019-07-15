#include "SQLiteHelper.h"
#include <QSqlDriver>

SQLiteHelper* SQLiteHelper::m_DatabaseMgr = nullptr;

SQLiteHelper::SQLiteHelper(QObject *parent)
	: QObject(parent)
{
	initAccountDB();
	initAreaInfoDB();
	openAccountDB();
	openAreaDB();
}

void SQLiteHelper::initAccountDB()
{
	if (QSqlDatabase::contains("account_sql_connection"))
	{
		m_AccountDB = QSqlDatabase::database("account_sql_connection");
	}
	else
	{
		QDir _dbFolder = QApplication::applicationDirPath() + "/database";
		if (!_dbFolder.exists())
			_dbFolder.mkpath(_dbFolder.absolutePath());
		QString _dbName = QApplication::applicationDirPath() + "/database/AccountDataBase.db";
		QFile _dbFile(_dbName);
		if (!_dbFile.exists())
		{
			m_AccountDB = QSqlDatabase::addDatabase("QSQLITE", "account_sql_connection");
			m_AccountDB.setDatabaseName(_dbName);
			m_AccountDB.setUserName("TiAmoPiccolo");
			m_AccountDB.setPassword("4rfv$RFV");
			if (!m_AccountDB.open())
			{
				qDebug() << "Error: Failed to connect Account database." << m_AccountDB.lastError();
			}
			else
			{
				qDebug() << "Succeed to connect Account database.";
			}

			QSqlQuery sql_query(m_AccountDB);
			QString create_sql = "PRAGMA FOREIGN_KEYS = ON";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to Turn FOREIGN_KEYS ON." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Turn FOREIGN_KEYS ON.!";
			}
			//Account表 账户id 账户名 性别 账户类型 身份证号 密码 电话 地址 描述
			create_sql = "create table IF NOT EXISTS Account (ID int primary key, Name text, Sex text,  AccountType text, IDCard text, Psw varchar(100), Tel text, Adds text, Discretion text)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Account." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Account created!";
			}
			//Medicine表 药品编号 药品名 库存数 单价 计量单位 描述
			create_sql = "create table IF NOT EXISTS Medicine(ID integer primary key autoincrement, Name text , Inventory double , Unitprice float , Measurement text, Discretion text)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Medicine." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Medicine created!";
			}

			//Town表
			create_sql = "create table IF NOT EXISTS Town(ID integer primary key autoincrement, Name text, AreaCode int)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Town." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Town created!";
			}
			//Village表
			create_sql = "create table IF NOT EXISTS Village(ID integer primary key autoincrement, Name text, TownCode int, FOREIGN KEY (TownCode) REFERENCES Town(ID) ON DELETE CASCADE ON UPDATE CASCADE)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Village." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Village created!";
			}
			//Group表
			create_sql = "create table IF NOT EXISTS LoacalGroup(ID integer primary key autoincrement, Name text, VillageCode int, FOREIGN KEY (VillageCode) REFERENCES Village(ID) ON DELETE CASCADE ON UPDATE CASCADE)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Group." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table LoacalGroup created!";
			}
			//HouseHold表 户主id 户主名 性别 所属村id 身份证号 电话 地址 家庭成员 描述
			create_sql = "create table IF NOT EXISTS HouseHold(ID text primary key, Name text , LoacalGroupID integer, FOREIGN KEY (LoacalGroupID) REFERENCES LoacalGroup(ID) ON DELETE CASCADE ON UPDATE CASCADE)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Record." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Record created!";
			}
			//Patient表 人员id 人员名 性别 户主 身份证号 电话 地址  记账记录 描述
			create_sql = "create table IF NOT EXISTS Patient(ID text primary key, Name text , Sex text , HouseholdID text, IDCard text, Tel text , Adds text , Recording text, Discretion text, FOREIGN KEY (HouseholdID) REFERENCES HouseHold(ID) ON DELETE CASCADE ON UPDATE CASCADE)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Patient." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Patient created!";
			}
			//Record表 记录编号 操作管理员ID 用户ID 账目金额 账目药品列表 账目状态 创建日期 修改日期 描述
			create_sql = "create table IF NOT EXISTS Record(ID integer primary key, OptID text , PatientID text , TotalMoney double , MedicineList text, RecStatus text, CreatDate text , ModifyDate text, Discretion text, FOREIGN KEY (PatientID) REFERENCES Patient(ID) ON DELETE CASCADE ON UPDATE CASCADE)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Record." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Record created!";
			}
		}
		else
		{
			m_AccountDB = QSqlDatabase::addDatabase("QSQLITE", "account_sql_connection");
			m_AccountDB.setDatabaseName(_dbName);
			m_AccountDB.setUserName("TiAmoPiccolo");
			m_AccountDB.setPassword("4rfv$RFV");
		}
	}
}

void SQLiteHelper::initAreaInfoDB()
{
	if (QSqlDatabase::contains("area_sql_connection"))
	{
		m_AreaDB = QSqlDatabase::database("area_sql_connection");
	}
	else
	{
		QDir _dbFolder = QApplication::applicationDirPath() + "/database";
		if (!_dbFolder.exists())
			_dbFolder.mkpath(_dbFolder.absolutePath());
		QString _dbName = QApplication::applicationDirPath() + "/database/AreaDataBase.db";
		QFile _dbFile(_dbName);
		if (!_dbFile.exists())
		{
			m_AreaDB = QSqlDatabase::addDatabase("QSQLITE", "area_sql_connection");
			m_AreaDB.setDatabaseName(_dbName);
			m_AreaDB.setUserName("TiAmoPiccolo");
			m_AreaDB.setPassword("4rfv$RFV");
			if (!m_AreaDB.open())
			{
				qDebug() << "Error: Failed to connect Area database." << m_AreaDB.lastError();
			}
			else
			{
				qDebug() << "Succeed to connect Area database.";
			}

			QSqlQuery sql_query(m_AreaDB);
			//Province表
			QString create_sql = "create table IF NOT EXISTS Province(ID integer primary key, Code int , Name text)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Province." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Province created!";
			}
			//City表
			create_sql = "create table IF NOT EXISTS City(ID integer primary key, Code int, Name text, ProvinceCode int)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table City." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table City created!";
			}
			//Area表
			create_sql = "create table IF NOT EXISTS Area(ID integer primary key, Code int, Name text, CityCode int)";
			sql_query.prepare(create_sql);
			if (!sql_query.exec())
			{
				qDebug() << "Error: Fail to create table Area." << sql_query.lastError();
			}
			else
			{
				qDebug() << "Table Area created!";
			}
			////Town表
			//create_sql = "create table Town if not exists (ID integer primary key autoincrement, Name text, AreaCode int)";
			//sql_query.prepare(create_sql);
			//if (!sql_query.exec())
			//{
			//	qDebug() << "Error: Fail to create table Town." << sql_query.lastError();
			//}
			//else
			//{
			//	qDebug() << "Table Town created!";
			//}
			////Village表
			//create_sql = "create table Village if not exists (ID integer primary key autoincrement, Name text, TownCode int)";
			//sql_query.prepare(create_sql);
			//if (!sql_query.exec())
			//{
			//	qDebug() << "Error: Fail to create table Village." << sql_query.lastError();
			//}
			//else
			//{
			//	qDebug() << "Table Village created!";
			//}
			////Group表
			//create_sql = "create table LoacalGroup if not exists (ID integer primary key autoincrement, Name text, VillageCode int)";
			//sql_query.prepare(create_sql);
			//if (!sql_query.exec())
			//{
			//	qDebug() << "Error: Fail to create table Group." << sql_query.lastError();
			//}
			//else
			//{
			//	qDebug() << "Table LoacalGroup created!";
			//}
		}
		else
		{
			m_AreaDB = QSqlDatabase::addDatabase("QSQLITE", "area_sql_connection");
			m_AreaDB.setDatabaseName(_dbName);
			m_AreaDB.setUserName("TiAmoPiccolo");
			m_AreaDB.setPassword("4rfv$RFV");
		}
	}
}

SQLiteHelper* SQLiteHelper::getInstence()
{
	if (m_DatabaseMgr == nullptr)
	{
		m_DatabaseMgr = new SQLiteHelper;
	}
	return m_DatabaseMgr;
}

SQLiteHelper::~SQLiteHelper()
{
	m_AccountDB.close();
	m_AreaDB.close();
}

int SQLiteHelper::isOpened()
{
	if (m_AccountDB.isOpen() && m_AreaDB.isOpen())
		return 1;
	else if (m_AccountDB.isOpen() && !m_AreaDB.isOpen())
		return -2;
	else if (!m_AccountDB.isOpen() && m_AreaDB.isOpen())
		return -1;
	else
		return 0;
}

bool SQLiteHelper::openAccountDB(void)
{
	//打开数据库
	if (m_AccountDB.open() == false) {
		qDebug() << QString::fromLocal8Bit("连接账目数据库失败！");
		return false;
	}
	QSqlQuery sql_query(m_AccountDB);
	QString create_sql = "PRAGMA FOREIGN_KEYS = ON";
	sql_query.prepare(create_sql);
	if (!sql_query.exec())
	{
		qDebug() << "Error: Fail to Turn FOREIGN_KEYS ON." << sql_query.lastError();
	}
	else
	{
		qDebug() << "Turn FOREIGN_KEYS ON.!";
	}
	qDebug() << QString::fromLocal8Bit("连接账目数据库成功");
	return true;
}

bool SQLiteHelper::openAreaDB(void)
{
	//打开数据库
	if (m_AreaDB.open() == false) {
		qDebug() << QString::fromLocal8Bit("连接区域数据库失败！");
		return false;
	}
	qDebug() << QString::fromLocal8Bit("连接区域数据库成功");
	return true;
}

void SQLiteHelper::closeDb(void)
{
	m_AccountDB.close();
	m_AreaDB.close();
	qDebug() << "关闭数据库成功";
}


QSqlDatabase& SQLiteHelper::getAccountDB()
{
	if (m_AccountDB.isValid())
		return m_AccountDB;
	else
		return QSqlDatabase();
}

QSqlDatabase& SQLiteHelper::getAreaDB()
{
	if (m_AreaDB.isValid())
		return m_AreaDB;
	else
		return QSqlDatabase();
}

#pragma region Account
bool SQLiteHelper::addSupUser(const SupUserInfo& supUser)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO Account VALUES(:ID,:Name,:Sex,:AccountType,:IDCard,:Psw,:Tel,:Adds,:Discretion)");
	query.bindValue(":ID", supUser.m_userID);
	query.bindValue(":Name", supUser.m_userName);
	query.bindValue(":Sex", supUser.m_userSex);
	query.bindValue(":AccountType", supUser.m_userType);
	query.bindValue(":IDCard", supUser.m_userIDCar);
	query.bindValue(":Psw", supUser.m_userPsw);
	query.bindValue(":Tel", supUser.m_userTel);
	query.bindValue(":Adds", supUser.m_userAdds);
	query.bindValue(":Discretion", supUser.m_Discript);
	if (query.exec())
	{
		qDebug() << "Inserted Account " + supUser.m_userName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteSupUser(const SupUserInfo& supUser)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM Account WHERE ID = ?");
	query.addBindValue(supUser.m_userID);
	if (query.exec())
	{
		qDebug() << "Deleted " + supUser.m_userName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateSupUser(const SupUserInfo& supUser)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Account SET Name = :name , Sex = :sex , AccountType = :accountType , IDCard = :idcard , Psw = :psw , Tel = :tel , Adds = :adds , Discreion = :discretion"
		"WHERE ID = :id");
	query.bindValue(":name", supUser.m_userName);
	query.bindValue(":sex", supUser.m_userSex);
	query.bindValue(":accountType", supUser.m_userType);
	query.bindValue(":idcard", supUser.m_userIDCar);
	query.bindValue(":psw", supUser.m_userPsw);
	query.bindValue(":tel", supUser.m_userTel);
	query.bindValue(":adds", supUser.m_userAdds);
	query.bindValue(":discretion", supUser.m_Discript);
	query.bindValue(":id", supUser.m_userID);
	if (query.exec())
	{
		qDebug() << "Updated " + supUser.m_userName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::querySupUser(QList<SupUserInfo>& supUserList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Account");
	if (query.exec())
	{
		while (query.next())
		{
			SupUserInfo _supUser;
			_supUser.m_userID = query.value(0).toInt();
			_supUser.m_userName = query.value(1).toString();
			_supUser.m_userSex = query.value(2).toString();
			_supUser.m_userType = query.value(3).toString();
			_supUser.m_userIDCar = query.value(4).toString();
			_supUser.m_userPsw = query.value(5).toString();
			_supUser.m_userTel = query.value(6).toString();
			_supUser.m_userAdds = query.value(7).toString();
			_supUser.m_Discript = query.value(8).toString();
			supUserList.append(_supUser);
		}
		if (!supUserList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::querySupUserByID(const int & id, SupUserInfo& supUser)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Account");
	if (query.exec())
	{
		while (query.next())
		{
			int _id = query.value(0).toInt();
			if (_id == id)
			{
				supUser.m_userID = query.value(0).toInt();
				supUser.m_userName = query.value(1).toString();
				supUser.m_userSex = query.value(2).toString();
				supUser.m_userType = query.value(3).toString();
				supUser.m_userIDCar = query.value(4).toString();
				supUser.m_userPsw = query.value(5).toString();
				supUser.m_userTel = query.value(6).toString();
				supUser.m_userAdds = query.value(7).toString();
				supUser.m_Discript = query.value(8).toString();
				return true;
			}
		}
		return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::querySupUserByName(const QString & supUserName, QList<SupUserInfo>& supUserList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Account");
	if (query.exec())
	{
		while (query.next())
		{
			QString _name = query.value(1).toInt();
			if (_name == supUserName)
			{
				SupUserInfo _supUser;
				_supUser.m_userID = query.value(0).toInt();
				_supUser.m_userName = query.value(1).toString();
				_supUser.m_userSex = query.value(2).toString();
				_supUser.m_userType = query.value(3).toString();
				_supUser.m_userIDCar = query.value(4).toString();
				_supUser.m_userPsw = query.value(5).toString();
				_supUser.m_userTel = query.value(6).toString();
				_supUser.m_userAdds = query.value(7).toString();
				_supUser.m_Discript = query.value(8).toString();
				supUserList.append(_supUser);
			}
		}
		if (!supUserList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::querySupUserByCustom(const QString & name, const QString propertyName, QList<SupUserInfo>&supUserList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Account");
	if (query.exec())
	{
		while (query.next())
		{
			int _column = query.record().indexOf(propertyName);
			if (_column < 0)
			{
				qDebug() << query.lastError();
				return false;
			}
			QString _name = query.value(_column).toString();
			if (name == _name)
			{
				SupUserInfo _supUser;
				_supUser.m_userID = query.value(0).toInt();
				_supUser.m_userName = query.value(1).toString();
				_supUser.m_userSex = query.value(2).toString();
				_supUser.m_userType = query.value(3).toString();
				_supUser.m_userIDCar = query.value(4).toString();
				_supUser.m_userPsw = query.value(5).toString();
				_supUser.m_userTel = query.value(6).toString();
				_supUser.m_userAdds = query.value(7).toString();
				_supUser.m_Discript = query.value(8).toString();
				supUserList.append(_supUser);
			}
		}
		if (!supUserList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

#pragma endregion

#pragma region Patient

bool SQLiteHelper::addPatient(const PatientInfo& patient)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO Patient VALUES(:ID,:Name,:Sex,:Household,:IDCard,:Tel,:Adds,:Recording,:Discretion)");
	query.bindValue(":ID", patient.m_patientID);
	query.bindValue(":Name", patient.m_patientName);
	query.bindValue(":Sex", patient.m_patientSex);
	query.bindValue(":Household", patient.m_patientHouseHold);
	query.bindValue(":IDCard", patient.m_patientIDCar);
	query.bindValue(":Tel", patient.m_patientTel);
	query.bindValue(":Adds", patient.m_patientAdds);
	query.bindValue(":Recording", "");
	query.bindValue(":Discretion", patient.m_Discript);
	if (query.exec())
	{
		qDebug() << "Inserted Account " + patient.m_patientName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deletePatient(const PatientInfo& patient)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM Patient WHERE ID = ?");
	query.addBindValue(patient.m_patientID);
	if (query.exec())
	{
		qDebug() << "Deleted " + patient.m_patientName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deletePatient(const QString& patientID)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM Patient WHERE ID = ?");
	query.addBindValue(patientID);
	if (query.exec())
	{
		qDebug() << "Deleted " + patientID;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updatePatient(const QString &_oldIDCar,const PatientInfo& patient)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Patient SET ID = :id , Name = :name ,Sex = :sex , IDCard = :idcard , Tel = :tel , Adds = :adds , Discretion = :discretion WHERE ID = :oldid");
	query.bindValue(":id", patient.m_patientID);
	query.bindValue(":name", patient.m_patientName);
	query.bindValue(":sex", patient.m_patientSex);
	//query.bindValue(":householdid", patient.m_patientHouseHold);
	query.bindValue(":idcard", patient.m_patientIDCar);
	query.bindValue(":tel", patient.m_patientTel);
	//query.bindValue(":recording", "");
	query.bindValue(":adds", patient.m_patientAdds);
	query.bindValue(":discretion", patient.m_Discript);
	query.bindValue(":oldid", _oldIDCar);
	if (!query.exec())
	{
		qDebug() << query.lastError();
		return false;
	}
	else
	{
		qDebug() << "Updated " + patient.m_patientName;
		return true;
	}
}

bool SQLiteHelper::updatePatient(const QString &id, const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Patient SET Name = :name WHERE ID = :id");
	query.bindValue(":name", name);
	query.bindValue(":id", id);
	if (query.exec())
	{
		qDebug() << QString("Updated %1 %2 ").arg(id).arg(name);
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryPatientByID(const QString & id, PatientInfo& patient)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Patient");
	if (query.exec())
	{
		while (query.next())
		{
			QString _id = query.value(0).toString();
			if (_id == id)
			{
				patient.m_patientID = query.value(0).toString();
				patient.m_patientName = query.value(1).toString();
				patient.m_patientSex = query.value(2).toString();
				patient.m_patientHouseHold = query.value(3).toString();
				patient.m_patientIDCar = query.value(4).toString();
				patient.m_patientTel = query.value(5).toString();
				patient.m_patientAdds = query.value(6).toString();
				//patient.m_recordList = query.value(7).toString();
				patient.m_Discript = query.value(8).toString();
				return true;
			}
		}
		return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

QString SQLiteHelper::queryPatientNameByID(const QString & id)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT ID , Name FROM Patient WHERE ID = :id");
	query.bindValue(":id", id);
	if (query.exec())
	{
		while (query.next())
		{
			QString _id = query.value(0).toString();
			if (_id == id)
			{
				return query.value(1).toString();
			}
		}
		return QString();
	}
	else
	{
		qDebug() << query.lastError();
		return QString();
	}
}

bool SQLiteHelper::queryPatientByName(const QString & patientName, QList<PatientInfo>& patientList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Patient");
	if (query.exec())
	{
		while (query.next())
		{
			QString _name = query.value(1).toString();
			if (_name == patientName)
			{
				PatientInfo _patient;
				_patient.m_patientID = query.value(0).toString();
				_patient.m_patientName = query.value(1).toString();
				_patient.m_patientSex = query.value(2).toString();
				_patient.m_patientHouseHold = query.value(3).toString();
				_patient.m_patientIDCar = query.value(4).toString();
				_patient.m_patientTel = query.value(5).toString();
				_patient.m_patientAdds = query.value(6).toString();
				//_patient.m_recordList = query.value(7).toString();
				_patient.m_Discript = query.value(8).toString();
				patientList.append(_patient);
			}
		}
		if (!patientList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryPatientByGroup(const QString & groupName, QList<PatientInfo>& patientList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Patient");
	if (query.exec())
	{
		while (query.next())
		{
			int _column = query.record().indexOf("Adds");
			QString _adds = query.value(6).toInt();
			if (_adds.contains(groupName))
			{
				PatientInfo _patient;
				_patient.m_patientID = query.value(0).toString();
				_patient.m_patientName = query.value(1).toString();
				_patient.m_patientSex = query.value(2).toString();
				_patient.m_patientHouseHold = query.value(3).toString();
				_patient.m_patientIDCar = query.value(4).toString();
				_patient.m_patientTel = query.value(5).toString();
				_patient.m_patientAdds = query.value(6).toString();
				//_patient.m_recordList = query.value(7).toString();
				_patient.m_Discript = query.value(8).toString();
				patientList.append(_patient);
			}
		}
		if (!patientList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryPatientByCustom(const QString & name, const QString & propertyName, QList<PatientInfo>& patientList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Patient");
	if (query.exec())
	{
		while (query.next())
		{
			int _column = query.record().indexOf(propertyName);
			if (_column < 0)
			{
				qDebug() << query.lastError();
				return false;
			}
			QString _name = query.value(_column).toString();
			if (name == _name)
			{
				PatientInfo _patient;
				_patient.m_patientID = query.value(0).toString();
				_patient.m_patientName = query.value(1).toString();
				_patient.m_patientSex = query.value(2).toString();
				_patient.m_patientHouseHold = query.value(3).toString();
				_patient.m_patientIDCar = query.value(4).toString();
				_patient.m_patientTel = query.value(5).toString();
				_patient.m_patientAdds = query.value(6).toString();
				//_patient.m_recordList = query.value(7).toString();
				_patient.m_Discript = query.value(8).toString();
				patientList.append(_patient);
			}
		}
		if (!patientList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

#pragma endregion

#pragma region Medicine

bool SQLiteHelper::addMedicine(const MedicineInfo& medicine)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO Medicine VALUES(:ID,:Name,:Inventory,:Unitprice,:Measurement,:Discretion)");
	//query.bindValue(":ID", NULL);
	query.bindValue(":Name", medicine.m_medicineName);
	query.bindValue(":Inventory", medicine.m_medicineInventory);
	query.bindValue(":Unitprice", medicine.m_medicinePrice);
	query.bindValue(":Measurement", medicine.m_medicineUnit);
	query.bindValue(":Discretion", medicine.m_medicineDiscript);
	if (query.exec())
	{
		qDebug() << "Inserted Medicine " + medicine.m_medicineName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteMedicine(const MedicineInfo& medicine)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM Medicine WHERE ID = ?");
	query.addBindValue(medicine.m_medicineID);
	if (query.exec())
	{
		qDebug() << "Deleted " + medicine.m_medicineName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateMedicine(const MedicineInfo& medicine)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Medicine SET Name = :name , Inventory = :inventory , Unitprice = :unitprice , Measurement = :measurement , Discretion = :discretion"
		"WHERE ID = :id");
	query.bindValue(":name", medicine.m_medicineName);
	query.bindValue(":inventory", medicine.m_medicineInventory);
	query.bindValue(":unitprice", medicine.m_medicinePrice);
	query.bindValue(":measurement", medicine.m_medicineUnit);
	query.bindValue(":discretion", medicine.m_medicineDiscript);
	query.bindValue(":id", medicine.m_medicineID);
	if (query.exec())
	{
		qDebug() << "Updated " + medicine.m_medicineName;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryMedicine(QList<MedicineInfo>& medicineList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Medicine");
	if (query.exec())
	{
		while (query.next())
		{
			MedicineInfo _medicineInfo;
			_medicineInfo.m_medicineID = query.value(0).toInt();
			_medicineInfo.m_medicineName = query.value(1).toString();
			_medicineInfo.m_medicineInventory = query.value(2).toInt();
			_medicineInfo.m_medicinePrice = query.value(3).toDouble();
			_medicineInfo.m_medicineUnit = query.value(4).toString();
			_medicineInfo.m_medicineDiscript = query.value(5).toString();
			medicineList.append(_medicineInfo);
		}
		if (!medicineList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryMedicineByID(const int & id, MedicineInfo& medicine)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT ID FROM Medicine");
	if (query.exec())
	{
		while (query.next())
		{
			int _id = query.value(0).toInt();
			if (_id == id)
			{
				medicine.m_medicineID = query.value(0).toInt();
				medicine.m_medicineName = query.value(1).toString();
				medicine.m_medicineInventory = query.value(2).toInt();
				medicine.m_medicinePrice = query.value(3).toDouble();
				medicine.m_medicineUnit = query.value(4).toString();
				medicine.m_medicineDiscript = query.value(5).toString();
				return true;
			}
		}
		return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryMedicineByName(const QString & medicineName, QList<MedicineInfo>& medicineList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Medicine");
	if (query.exec())
	{
		while (query.next())
		{
			QString _name = query.value(1).toString();
			if (_name == medicineName)
			{
				MedicineInfo _medicine;
				_medicine.m_medicineID = query.value(0).toInt();
				_medicine.m_medicineName = query.value(1).toString();
				_medicine.m_medicineInventory = query.value(2).toInt();
				_medicine.m_medicinePrice = query.value(3).toDouble();
				_medicine.m_medicineUnit = query.value(4).toString();
				_medicine.m_medicineDiscript = query.value(5).toString();
				medicineList.append(_medicine);
			}
		}
		if (!medicineList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryMedicineByCustom(const QString & name, const QString & propertyName, QList<MedicineInfo>& medicineList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT " + propertyName + " FROM Medicine");
	if (query.exec())
	{
		while (query.next())
		{
			int _column = query.record().indexOf(propertyName);
			if (_column < 0)
			{
				qDebug() << query.lastError();
				return false;
			}
			QString _name = query.value(_column).toString();
			if (name == _name)
			{
				MedicineInfo _medicine;
				_medicine.m_medicineID = query.value(0).toInt();
				_medicine.m_medicineName = query.value(1).toString();
				_medicine.m_medicineInventory = query.value(2).toInt();
				_medicine.m_medicinePrice = query.value(3).toDouble();
				_medicine.m_medicineUnit = query.value(4).toString();
				_medicine.m_medicineDiscript = query.value(5).toString();
				medicineList.append(_medicine);
			}
		}
		if (!medicineList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	};
}

int SQLiteHelper::medicineRawQuery()
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT count(*) FROM Medicine");
	if (query.exec())
	{
		query.next();
		int _count;
		_count = query.value(0).toInt();
		return _count;
	}
	/*第二种方法
	if (m_AccountDB.driver()->hasFeature(QSqlDriver::QuerySize))
	{
		_count = query.size();
	}
	else
	{
		query.last();
		_count = query.at() + 1;
	}*/
}

#pragma endregion

#pragma region Record

bool SQLiteHelper::addRecord(const RecordInfo& record)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO Record VALUES(:ID,:OptID,:PatientID,:TotalMoney,:MedicineList,:RecStatus,:CreatDate,:ModifyDate,:Discretion)");
	//query.bindValue(":ID", record.m_recID);
	query.bindValue(":OptID", record.m_optSupUserID);
	query.bindValue(":PatientID", record.m_recOfPatientID);
	query.bindValue(":TotalMoney", record.m_recTotalMoney);
	query.bindValue(":MedicineList", record.m_MedicienList);
	query.bindValue(":RecStatus", record.m_recStatus);
	query.bindValue(":CreatDate", record.m_recCreatDate);
	query.bindValue(":ModifyDate", record.m_recModifyDate);
	query.bindValue(":Discretion", record.m_recDiscript);
	if (query.exec())
	{
		qDebug() << "Inserted Record of" + record.m_recOfPatientID;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteRecord(const RecordInfo& record)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM Record WHERE ID = ?");
	query.addBindValue(record.m_recID);
	if (query.exec())
	{
		qDebug() << "Deleted " + record.m_recID;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateRecord(const RecordInfo& record)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Record SET OptID = :optid , PatientID = :patientid , TotalMoney = :totalmoney , MedicineList = :medicinelist , RecStatus = :recstatus ,CreatDate = :creatdate, ModifyDate = :modifydate , Discretion = :discretion"
		" WHERE ID = :id");
	query.bindValue(":optid", record.m_optSupUserID);
	query.bindValue(":patientid", record.m_recOfPatientID);
	query.bindValue(":totalmoney", record.m_recTotalMoney);
	query.bindValue(":medicinelist", record.m_MedicienList);
	query.bindValue(":recstatus", record.m_recStatus);
	query.bindValue(":creatdate", record.m_recCreatDate);
	query.bindValue(":modifydate", record.m_recModifyDate);
	query.bindValue(":discretion", record.m_recDiscript);
	query.bindValue(":id", record.m_recID);
	if (query.exec())
	{
		qDebug() << "Updated " + record.m_recID;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryRecordByID(const int & id, RecordInfo& record)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Record");
	if (query.exec())
	{
		while (query.next())
		{
			int _id = query.value(0).toInt();
			if (_id == id)
			{
				record.m_recID = query.value(0).toInt();
				record.m_optSupUserID = query.value(1).toString();
				record.m_recOfPatientID = query.value(2).toString();
				record.m_recTotalMoney = query.value(3).toDouble();
				record.m_MedicienList = query.value(4).toString();
				record.m_recStatus = query.value(5).toString();
				record.m_recCreatDate = query.value(6).toString();
				record.m_recModifyDate = query.value(7).toString();
				record.m_recDiscript = query.value(8).toString();
				return true;
			}
		}
		return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryRecordByPatientID(const QString & patientID, QList<RecordInfo>& recordList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Record");
	if (query.exec())
	{
		while (query.next())
		{
			QString _patientid = query.value(2).toString();
			if (_patientid == patientID)
			{
				RecordInfo _recordInfo;
				_recordInfo.m_recID = query.value(0).toInt();
				_recordInfo.m_optSupUserID = query.value(1).toString();
				_recordInfo.m_recOfPatientID = query.value(2).toString();
				_recordInfo.m_recTotalMoney = query.value(3).toDouble();
				_recordInfo.m_MedicienList = query.value(4).toString();
				_recordInfo.m_recStatus = query.value(5).toString();
				_recordInfo.m_recCreatDate = query.value(6).toString();
				_recordInfo.m_recModifyDate = query.value(7).toString();
				_recordInfo.m_recDiscript = query.value(8).toString();
				recordList.append(_recordInfo);
			}
		}
		if (!recordList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::queryRecordByCustom(const QString & name, const QString & propertyName, QList<RecordInfo>& recordList)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT " + propertyName + " FROM Record");
	if (query.exec())
	{
		while (query.next())
		{
			int _column = query.record().indexOf(propertyName);
			if (_column < 0)
			{
				qDebug() << query.lastError();
				return false;
			}
			QString _name = query.value(_column).toString();
			if (name == _name)
			{
				RecordInfo _recordInfo;
				_recordInfo.m_recID = query.value(0).toInt();
				_recordInfo.m_optSupUserID = query.value(1).toString();
				_recordInfo.m_recOfPatientID = query.value(2).toString();
				_recordInfo.m_recTotalMoney = query.value(3).toDouble();
				_recordInfo.m_MedicienList = query.value(4).toString();
				_recordInfo.m_recStatus = query.value(5).toString();
				_recordInfo.m_recCreatDate = query.value(6).toString();
				_recordInfo.m_recModifyDate = query.value(7).toString();
				_recordInfo.m_recDiscript = query.value(8).toString();
				recordList.append(_recordInfo);
			}
		}
		if (!recordList.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}



#pragma endregion

#pragma region Area

bool SQLiteHelper::getProvince(QMap<int, QString> &provinceMap)
{
	QSqlQuery query(m_AreaDB);
	query.prepare("SELECT * FROM Province");
	if (query.exec())
	{
		while (query.next())
		{
			provinceMap.insert(query.value(1).toInt(), query.value(2).toString());
		}
		if (!provinceMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getCityByProvinceID(const int &id, QMap<int, QString> & cityMap)
{
	QSqlQuery query(m_AreaDB);
	query.prepare("SELECT * FROM City WHERE ProvinceCode = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			cityMap.insert(query.value(1).toInt(), query.value(2).toString());
		}
		if (!cityMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getAreaByCityID(const int &id, QMap<int, QString> &areaMap)
{
	QSqlQuery query(m_AreaDB);
	query.prepare("SELECT * FROM Area WHERE CityCode = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			areaMap.insert(query.value(1).toInt(), query.value(2).toString());
		}
		if (!areaMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getTownByAreaID(const int &id, QMap<int, QString> &townMap)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Town WHERE AreaCode = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			townMap.insert(query.value(0).toInt(), query.value(1).toString());
		}
		if (!townMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getVillageByTownID(const int &id, QMap<int, QString> &villageMap)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Village WHERE TownCode = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			villageMap.insert(query.value(0).toInt(), query.value(1).toString());
		}
		if (!villageMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getGroupByVillageID(const int &id, QMap<int, QString> &groupMap)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM LoacalGroup WHERE VillageCode = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			groupMap.insert(query.value(0).toInt(), query.value(1).toString());
		}
		if (!groupMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getHouseHoldByGroupID(const int &id, QMap<QString, QString> &houseHoldMap)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM HouseHold WHERE LoacalGroupID = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			houseHoldMap.insert(query.value(0).toString(), query.value(1).toString());
		}
		if (!houseHoldMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::getPatientByHouseHoldID(const QString &id, QMap<QString, QString> &patientMap)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM Patient WHERE HouseholdID = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		while (query.next())
		{
			patientMap.insert(query.value(0).toString(), query.value(1).toString());
		}
		if (!patientMap.isEmpty())
			return true;
		else
			return false;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

//镇
bool SQLiteHelper::addTown(const QString &name, const int & areaCode)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO Town VALUES(:ID,:Name,:AreaCode)");
	//query.bindValue(":ID", NULL);
	query.bindValue(":Name", name);
	query.bindValue(":AreaCode", areaCode);
	if (query.exec())
	{
		qDebug() << "Inserted Town " + name;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateTown(const int &id, const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Town SET Name = :name WHERE ID = :id");
	query.bindValue(":name", name);
	query.bindValue(":id", id);
	if (query.exec())
	{
		qDebug() << QString("Updated %1 %2 ").arg(QString::number(id)).arg(name);
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteTown(const int &id)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM INTO WHERE ID = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		qDebug() << "Deleted Town " + id;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

int SQLiteHelper::queryTown(const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT Name FROM Town WHERE Name = :name");
	query.bindValue(":name", name);
	if (query.exec())
	{
		while (query.next())
		{
			int _id = query.value(0).toInt();
			return query.value(0).toInt();
		}
		return -1;
	}
	else
	{
		qDebug() << query.lastError();
		return -1;
	}
}

//村
bool SQLiteHelper::addVillage(const QString &name,const int & townCode)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO Village VALUES(:ID,:Name,:TownCode)");
	//query.bindValue(":ID", NULL);
	query.bindValue(":Name", name);
	query.bindValue(":TownCode", townCode);
	if (query.exec())
	{
		qDebug() << "Inserted Village " + name;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateVillage(const int &id, const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE Village SET Name = :name WHERE ID = :id");
	query.bindValue(":name", name);
	query.bindValue(":id", id);
	if (query.exec())
	{
		qDebug() << QString("Updated %1 %2 ").arg(QString::number(id)).arg(name);
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteVillage(const int &id)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM Village WHERE ID = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		qDebug() << "Deleted Village " + id;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

int SQLiteHelper::queryVillage(const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT Name FROM Village WHERE Name = :name");
	query.bindValue(":name", name);
	if (query.exec())
	{
		while (query.next())
		{
			int _id = query.value(0).toInt();
			return query.value(0).toInt();
		}
		return -1;
	}
	else
	{
		qDebug() << query.lastError();
		return -1;
	}
}

//组
bool SQLiteHelper::addGroup(const QString &name, const int & villageCode)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO LoacalGroup VALUES(:ID,:Name,:VillageCode)");
	//query.bindValue(":ID", NULL);
	query.bindValue(":Name", name);
	query.bindValue(":VillageCode", villageCode);
	if (query.exec())
	{
		qDebug() << "Inserted Group " + name;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateGroup(const int &id, const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE LoacalGroup SET Name = :name WHERE ID = :id");
	query.bindValue(":name", name);
	query.bindValue(":id", id);
	if (query.exec())
	{
		qDebug() << QString("Updated %1 %2 ").arg(QString::number(id)).arg(name);
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteGroup(const int &id)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM LoacalGroup WHERE ID = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		qDebug() << "Deleted Group " + id;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

int SQLiteHelper::queryGroup(const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM LoacalGroup WHERE Name = :name");
	query.bindValue(":name", name);
	if (query.exec())
	{
		while (query.next())
		{
			if(query.value(1).toString()==name)
				return query.value(0).toInt();
			int _id = query.value(0).toInt();
			
		}
		return -1;
	}
	else
	{
		qDebug() << query.lastError();
		return -1;
	}
}

//户主
bool SQLiteHelper::addHouseHold(const QString &id, const QString &name, const int & loacalGroupCode)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("INSERT INTO HouseHold VALUES(:ID,:Name,:LoacalGroupCode)");
	query.bindValue(":ID", id);
	query.bindValue(":Name", name);
	query.bindValue(":LoacalGroupCode", loacalGroupCode);
	if (query.exec())
	{
		qDebug() << "Inserted HouseHold " + name;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateHouseHold(const QString &id, const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE HouseHold SET Name = :name WHERE ID = :id");
	query.bindValue(":name", name);
	query.bindValue(":id", id);
	if (query.exec())
	{
		qDebug() << QString("Updated %1 %2 ").arg(id).arg(name);
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::updateHouseHold(const QString &oldid, const QString &id, const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("UPDATE HouseHold SET ID = :id , Name = :name WHERE ID = :oldid");
	query.bindValue(":id", id);
	query.bindValue(":name", name);
	query.bindValue(":oldid", oldid);
	if (query.exec())
	{
		qDebug() << QString("Updated %1 %2 ").arg(id).arg(name);
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

bool SQLiteHelper::deleteHouseHold(const QString &id)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("DELETE FROM HouseHold WHERE ID = ?");
	query.addBindValue(id);
	if (query.exec())
	{
		qDebug() << "Deleted HouseHold " + id;
		return true;
	}
	else
	{
		qDebug() << query.lastError();
		return false;
	}
}

QString SQLiteHelper::queryHouseHold(const QString &name)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM HouseHold WHERE Name = :name");
	query.bindValue(":name", name);
	if (query.exec())
	{
		while (query.next())
		{
			QString _id = query.value(0).toString();
			return query.value(0).toString();
		}
		return "";
	}
	else
	{
		qDebug() << query.lastError();
		return "";
	}
}

QString SQLiteHelper::queryHouseHoldByID(const QString &id)
{
	QSqlQuery query(m_AccountDB);
	query.prepare("SELECT * FROM HouseHold WHERE ID = :id");
	query.bindValue(":id", id);
	if (query.exec())
	{
		while (query.next())
		{
			QString _name = query.value(1).toString();
			return query.value(1).toString();
		}
		return "";
	}
	else
	{
		qDebug() << query.lastError();
		return "";
	}
}

#pragma endregion