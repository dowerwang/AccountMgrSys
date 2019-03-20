#include "IDCarInfoMation.h"



IDCarInfoMation::IDCarInfoMation()
{
}


bool IDCarInfoMation::isVaildIDCar(CString str_id)
{
	int weight[] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char validate[] = { '1','0','X','9','8','7','6','5','4','3','2' };
	int sum = 0;
	int mode = 0;
	if (str_id.GetLength() == 18)
	{
		for (int i = 0; i < str_id.GetLength() - 1; i++) {
			sum = sum + (str_id[i] - '0')*weight[i];
		}
		mode = sum % 11;
		if (validate[mode] == str_id[17])
		{
			return true;
		}
	}
		return false;
}

bool IDCarInfoMation::iso7064_15To18(CString vSrc, CString& vDst)
{
	if (vSrc.GetLength() == 15)
	{
		vDst = vSrc.Mid(0, 6);
		vDst += L"19";
		vDst += vSrc.Right(9);
		vDst += L"?";
	}
	else
		vDst = vSrc;

	long result = 0;
	int wi[] = { 1, 2, 4, 8, 5, 10, 9, 7, 3, 6 };
	char hash_map[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	bool bModify = L"?" == vDst.Right(1);

	int sigma, i1, w1;
	sigma = i1 = w1 = 0;
	for (int i = 1; i < 18; ++i)
	{
		i1 = (vDst.GetAt(i - 1) - 48) * 1;
		w1 = wi[(18 - i) % 10];
		sigma += (i1 * w1) % 11;
	}

	if (bModify)
	{
		//设置的临时变量，无用！
		vDst.SetAt(17, hash_map[sigma % 11]);
		return 0;
	}
	else
		return vDst.Right(1) == hash_map[sigma % 11];
}

IDCarInfoMation::~IDCarInfoMation()
{
}
