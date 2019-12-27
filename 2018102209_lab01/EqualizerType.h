#pragma once
#include <string>
#include <iostream>
using namespace std;


class EqualizerType
{
private:
	string sName;
	int low;
	int mid;
	int high;
public:
	
	//constructor
	EqualizerType();
	//getter
	string GetName();
	int GetLow();
	int GetMid();
	int GetHigh();

	//setter
	void SetName(string inName);
	void SetLow(int inLow);
	void SetMid(int inMid);
	void SetHigh(int inHigh);
	void SetRecord(string inName, int inLow, int inMid, int inHigh);

	void SetNameByKB();
	void SetLowByKB();
	void SetMidByKB();
	void SetHighByKB();
	void SetRecordByKB();

	//display
	void DisplayName();
	void DisplayLow();
	void DisplayMid();
	void DisplayHigh();
	void DisplayRecord();
	
	bool operator == (const EqualizerType& item)
	{
		if (this->sName == item.sName)
			return true;
		else
			return false;
	}

	bool operator > (const EqualizerType& item)
	{
		if (this->sName > item.sName)
			return true;
		else
			return false;
	}

	bool operator < (const EqualizerType& item)
	{
		if (this->sName < item.sName)
			return true;
		else
			return false;
	}

};

