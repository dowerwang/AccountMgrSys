#pragma once
#include <QString>
#include <QUuid>
#include <QtGlobal>
#include<QTime>

//Account  ����Ա�˻���Ϣ
struct SupUserInfo
{
	int		m_userID;		//����ԱID
	QString m_userName;		//����Ա��
	QString		m_userSex;		//����Ա�Ա� 0-���� 1-�� 2-Ů
	QString		m_userType;		//����Ա���� 0-��ͨ����Ա 1-��������Ա
	QString m_userIDCar;	//����Ա���֤��
	QString m_userPsw;		//����Ա��½����
	QString m_userTel;		//����Ա��ϵ�绰
	QString m_userAdds;		//����Աסַ
	QString m_Discript;		//����
};

//Patient  ��Ա��Ϣ
struct PatientInfo
{
	QString m_patientID;		//��ԱID
	QString m_patientName;		//��Ա����
	QString	m_patientSex;		//��Ա�Ա� 0-���� 1-�� 2-Ů
	QString m_patientHouseHold;	//��Ա����
	QString m_patientIDCar;		//��Ա���֤��
	QString m_patientTel;		//��Ա��ϵ�绰
	QString m_patientAdds;		//��Աסַ
	QList<int> m_recordList;	
	QString m_Discript;			//����
};

//HouseHold ����
struct HouseHoldInfo
{
	QString m_houseHoldID;		//����ID
	QString m_houseHoldName;	//��������
	QString	m_houseHoldSex;		//�����Ա� 0-���� 1-�� 2-Ů
	int		m_loacalGroupID;	//������ID
	QString m_houseHoldIDCar;	//�������֤��
	QString m_houseHoldTel;		//������ϵ�绰
	QString m_phouseHoldAdds;	//����סַ
	QList<int> m_patientList;	//��Ա�б�
	QString m_Discript;			//����
};

//RecordContent ������¼�ڵ�Item
struct RecordContentInfo
{
	QString m_MedicineName;		//����ҩ��
	int		m_MedicineCount;	//����ҩ����
	double	m_TotalMoney;		//����Item���ܽ��
	QString m_Discript;			//����Item������
};
//Record   ��¼��Ϣ
struct RecordInfo
{
	int		m_recID;			//��¼ID
	QString m_optSupUserID;		//��¼�Ĳ���ԱID
	QString m_recOfPatientID;	//��¼����ԱID
	double m_recTotalMoney;		//��¼���ܽ��
	QString m_MedicienList;		//��¼������ҩƷ
	QString m_recStatus;			//��¼��״̬
	QString m_recCreatDate;		//��¼�Ĵ���ʱ��
	QString m_recModifyDate;	//��¼���޸�ʱ��
	QString m_recDiscript;		//��¼����
};

//Medicine ҩƷ��Ϣ
struct MedicineInfo
{
	int		m_medicineID;		//ҩƷID
	QString m_medicineName;		//ҩƷ����
	int m_medicineInventory;	//ҩƷ���
	double m_medicinePrice;		//ҩƷ����
	QString m_medicineUnit;		//ҩƷ������λ
	QString m_medicineDiscript;	//ҩƷ����
};