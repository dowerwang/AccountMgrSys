#pragma once
#include <QString>
#include <QUuid>
#include <QtGlobal>
#include<QTime>

//Account  管理员账户信息
struct SupUserInfo
{
	int		m_userID;		//管理员ID
	QString m_userName;		//管理员名
	QString		m_userSex;		//管理员性别 0-保密 1-男 2-女
	QString		m_userType;		//管理员类型 0-普通管理员 1-超级管理员
	QString m_userIDCar;	//管理员身份证号
	QString m_userPsw;		//管理员登陆密码
	QString m_userTel;		//管理员联系电话
	QString m_userAdds;		//管理员住址
	QString m_Discript;		//描述
};

//Patient  人员信息
struct PatientInfo
{
	QString m_patientID;		//人员ID
	QString m_patientName;		//人员姓名
	QString	m_patientSex;		//人员性别 0-保密 1-男 2-女
	QString m_patientHouseHold;	//人员户主
	QString m_patientIDCar;		//人员身份证号
	QString m_patientTel;		//人员联系电话
	QString m_patientAdds;		//人员住址
	QList<int> m_recordList;	
	QString m_Discript;			//描述
};

//HouseHold 户主
struct HouseHoldInfo
{
	QString m_houseHoldID;		//户主ID
	QString m_houseHoldName;	//户主姓名
	QString	m_houseHoldSex;		//户主性别 0-保密 1-男 2-女
	int		m_loacalGroupID;	//所属组ID
	QString m_houseHoldIDCar;	//户主身份证号
	QString m_houseHoldTel;		//户主联系电话
	QString m_phouseHoldAdds;	//户主住址
	QList<int> m_patientList;	//成员列表
	QString m_Discript;			//描述
};

//RecordContent 单条记录内的Item
struct RecordContentInfo
{
	QString m_MedicineName;		//所拿药名
	int		m_MedicineCount;	//所拿药数量
	double	m_TotalMoney;		//该条Item的总金额
	QString m_Discript;			//该条Item的描述
};
//Record   记录信息
struct RecordInfo
{
	int		m_recID;			//记录ID
	QString m_optSupUserID;		//记录的操作员ID
	QString m_recOfPatientID;	//记录的人员ID
	double m_recTotalMoney;		//记录的总金额
	QString m_MedicienList;		//记录的所有药品
	QString m_recStatus;			//记录的状态
	QString m_recCreatDate;		//记录的创建时间
	QString m_recModifyDate;	//记录的修改时间
	QString m_recDiscript;		//记录描述
};

//Medicine 药品信息
struct MedicineInfo
{
	int		m_medicineID;		//药品ID
	QString m_medicineName;		//药品名称
	int m_medicineInventory;	//药品库存
	double m_medicinePrice;		//药品单价
	QString m_medicineUnit;		//药品计量单位
	QString m_medicineDiscript;	//药品描述
};