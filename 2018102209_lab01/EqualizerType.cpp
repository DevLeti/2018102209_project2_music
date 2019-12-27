#include "EqualizerType.h"

EqualizerType::EqualizerType()
{
	this->sName = "default";
	this->low = 0;
	this->mid = 0;
	this->high = 0;
}

string EqualizerType::GetName()
{
	return this->sName;
}

int EqualizerType::GetLow()
{
	return this->low;
}

int EqualizerType::GetMid()
{
	return this->mid;
}

int EqualizerType::GetHigh()
{
	return this->high;
}

void EqualizerType::SetName(string inName)
{
	this->sName = inName;	
}

void EqualizerType::SetLow(int inLow)
{
	this->low = inLow;
}

void EqualizerType::SetMid(int inMid)
{
	this->mid = inMid;
}

void EqualizerType::SetHigh(int inHigh)
{
	this->high = inHigh;
}

void EqualizerType::SetRecord(string inName, int inLow, int inMid, int inHigh)
{
	this->sName = inName;
	this->low = inLow;
	this->mid = inMid;
	this->high = inHigh;
}

void EqualizerType::SetNameByKB()
{
	string inName;
	cout << "\tEqualizer Name : "; cin >> inName;
	this->sName = inName;
}

void EqualizerType::SetLowByKB()
{
	int inLow;
	cout << "\tSet Low (-10 ~ 10, 0 = default) : "; cin >> inLow;
	while (inLow > 10 || inLow < -10)
	{
		cout << "\tInvalid range input." << endl;
		cout << "\tSet Low (-10 ~ 10, 0 = default) : "; cin >> inLow;
	}
	this->low = inLow;
}

void EqualizerType::SetMidByKB()
{
	int inMid;
	cout << "\tSet mid (-10 ~ 10, 0 = default) : "; cin >> inMid;
	while (inMid > 10 || inMid < -10)
	{
		cout << "\tInvalid range input." << endl;
		cout << "\tSet mid (-10 ~ 10, 0 = default) : "; cin >> inMid;
	}
	this->mid = inMid;
}

void EqualizerType::SetHighByKB()
{
	int inHigh;
	cout << "\tSet high (-10 ~ 10, 0 = default) : "; cin >> inHigh;
	while (inHigh > 10 || inHigh < -10)
	{
		cout << "\tInvalid range input." << endl;
		cout << "\tSet high (-10 ~ 10, 0 = default) : "; cin >> inHigh;
	}
	this->high = inHigh;
}

void EqualizerType::SetRecordByKB()
{
	SetNameByKB();
	SetLowByKB();
	SetMidByKB();
	SetHighByKB();
}

void EqualizerType::DisplayName()
{
	cout << "\tEqualizer Name : " << this->sName << endl;
}

void EqualizerType::DisplayLow()
{
	cout << "\tLow (-10 ~ 10) : " << this->low << endl;
}

void EqualizerType::DisplayMid()
{
	cout << "\tMid (-10 ~ 10) : " << this->mid << endl;
}

void EqualizerType::DisplayHigh()
{
	cout << "\tHigh (-10 ~ 10) : " << this->high << endl;
}

void EqualizerType::DisplayRecord()
{
	cout << "\tEqualizer Name : " << this->sName << endl;
	cout << "\tLow (-10 ~ 10) : " << this->low << endl;
	cout << "\tMid (-10 ~ 10) : " << this->mid << endl;
	cout << "\tHigh (-10 ~ 10) : " << this->high << endl;
}
