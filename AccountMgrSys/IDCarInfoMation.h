#pragma once
#include <atlstr.h>
#include <QString>

class IDCarInfoMation
{
public:
	IDCarInfoMation();
	bool isVaildIDCar(CString str_id);
	bool iso7064_15To18(CString vSrc, CString& vDst);

	~IDCarInfoMation();
};

