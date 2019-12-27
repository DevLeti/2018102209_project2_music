#include "ItemType.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

ItemType::ItemType()
{
	this->m_sId = "";
	this->m_sComposer = "";
	this->m_sName = "";
	this->m_sSinger = "";
	this->m_Genre = 0;
	this->m_Type = 0;
}

ItemType::~ItemType()
{

}

int ItemType::GetType()
{
	return this->m_Type;
}

int ItemType::GetGenre()
{
	return this->m_Genre;
}

string ItemType::GetName()
{
	return this->m_sName;
}

string ItemType::GetComposer()
{
	return this->m_sComposer;
}

string ItemType::GetSinger()
{
	return this->m_sSinger;
}

string ItemType::GetId()
{
	return this->m_sId;
}

void ItemType::SetType(int inType)
{
	this->m_Type = inType;
}

void ItemType::SetGenre(int inGenre)
{
	this->m_Genre = inGenre;
}

void ItemType::SetName(string inName)
{
	this->m_sName = inName;
}

void ItemType::SetComposer(string inComposer)
{
	this->m_sComposer = inComposer;
}

void ItemType::SetSinger(string inSinger)
{
	this->m_sSinger = inSinger;
}

void ItemType::SetId(string inId)
{
	this->m_sId = inId;
}

void ItemType::SetRecord(int inType, int inGenre, string inName, string inComposer, string inSinger, string inId)
{
	this->SetType(inType);
	this->SetGenre(inGenre);
	this->SetName(inName);
	this->SetComposer(inComposer);
	this->SetSinger(inSinger);
	this->SetId(inId);
}

void ItemType::SetTypeFromKB()
{
	int inType;
	cout << "\tType : ";
	cin >> inType;
	SetType(inType);
}

void ItemType::SetGenreFromKB()
{
	int inGenre;
	cout << "\tGenre (0: Balad, 1: Pop, 2: R&B, 3: EDM, 4: Etc.) : ";
	cin >> inGenre;
	if (inGenre > 4 || inGenre < 0)
	{
		cout << "\tInvalid GenreType." << endl;
		cout << "\tGenre (0: Balad, 1: Pop, 2: R&B, 3: EDM, 4: Etc.) : ";
		cin >> inGenre;
	}
	SetGenre(inGenre);
}

void ItemType::SetNameFromKB()
{
	string inName;
	cout << "\tName : ";
	cin >> inName;
	SetName(inName);
}

void ItemType::SetComposerFromKB()
{
	string inComposer;
	cout << "\tComposer : ";
	cin >> inComposer;
	SetComposer(inComposer);
}

void ItemType::SetSingerFromKB()
{
	string inSinger;
	cout << "\tSinger : ";
	cin >> inSinger;
	SetSinger(inSinger);
}

void ItemType::SetIdFromKB()
{
	string inId;
	cout << "\tId : ";
	cin >> inId;
	SetId(inId);
}

void ItemType::SetRecordFromKB()
{
	SetTypeFromKB();
	SetGenreFromKB();
	SetNameFromKB();
	SetComposerFromKB();
	SetSingerFromKB();
	SetIdFromKB();
}

void ItemType::DisplayTypeOnScreen()
{
	cout << "\tType : " << this->m_Type << endl;
}

void ItemType::DisplayGenreOnScreen()
{
	cout << "\tGenre : " << this->m_Genre << endl;
}

void ItemType::DisplayNameOnScreen()
{
	cout << "\tName : " << this->m_sName << endl;
}

void ItemType::DisplayComposerOnScreen()
{
	cout << "\tComposer : " << this->m_sComposer << endl;
}

void ItemType::DisplaySingerOnScreen()
{
	cout << "\tSinger : " << this->m_sSinger << endl;
}

void ItemType::DisplayIdOnScreen()
{
	cout << "\tId : " << this->m_sId << endl;
}

void ItemType::DisplayRecordOnScreen()
{
	this->DisplayTypeOnScreen();
	this->DisplayGenreOnScreen();
	this->DisplayNameOnScreen();
	this->DisplayComposerOnScreen();
	this->DisplaySingerOnScreen();
	this->DisplayIdOnScreen();
	cout << endl;
}

int ItemType::ReadDataFromFile(ifstream& fin)
{
	if (fin.is_open())
	{
		int inType, inGenre;
		string inName, inComposer, inSinger, inId;

		fin >> inType >> inGenre >> inName >> inComposer >> inSinger >> inId;
		this->SetRecord(inType, inGenre, inName, inComposer, inSinger, inId);
		return 1;
	}
	else
	{
		return 0;
	}
}

int ItemType::WriteDataToFile(ofstream& fout)
{
	if (fout.is_open())
	{
		fout << endl;
		fout << this->m_Type << " ";
		fout << this->m_Genre << " ";
		fout << this->m_sName << " ";
		fout << this->m_sComposer << " ";
		fout << this->m_sSinger << " ";
		fout << this->m_sId << " ";
	}
	else
	{
		return 0;
	}
}

//RelationType ItemType::CompareByID(const ItemType& data)
//{
//	if (this->m_sId > data.m_sId)
//	{
//		return GREATER;
//	}
//	else if (this->m_sId < data.m_sId)
//	{
//		return LESS;
//	}
//	else
//	{
//		return EQUAL;
//	}
//}


/*
int ItemType::GetId()
{
	return this->m_Id;
}

string ItemType::GetName()
{
	return this->m_sName;
}

string ItemType::GetAddress()
{
	return this->m_sAddress;
}

void ItemType::SetId(int inId)
{
	this->m_Id = inId;
}

void ItemType::SetName(string inName)
{
	this->m_sName = inName;
}

void ItemType::SetAddress(string inAddress)
{
	this->m_sAddress = inAddress;
}

void ItemType::SetRecord(int inId, string inName, string inAddress)
{
	SetId(inId);
	SetName(inName);
	SetAddress(inAddress);
}

void ItemType::DisplayIdOnScreen()
{
	cout << "\tId : "<< GetId();
}

void ItemType::DisplayNameOnScreen()
{
	cout << "\tName : " << GetName();
}

void ItemType::DisplayAddressOnScreen()
{
	cout << "\tAddress : " << GetAddress();
}

void ItemType::DisplayRecordOnScreen()
{
	DisplayIdOnScreen();
	cout << endl;
	DisplayNameOnScreen();
	cout << endl;
	DisplayAddressOnScreen();
	cout << endl;
}

void ItemType::SetIdFromKB()
{
	int inId;
	cout << "\tInput Id : ";
	cin >> inId;
	SetId(inId);

}

void ItemType::SetNameFromKB()
{
	string inName;
	cout << "\tInput Name : ";
	cin >> inName;
	SetName(inName);
}

void ItemType::SetAddressFromKB()
{
	string inAddress;
	cout << "\tInput Address : ";
	cin >> inAddress;
	SetAddress(inAddress);
}

void ItemType::SetRecordFromKB()
{
	SetIdFromKB();
	SetNameFromKB();
	SetAddressFromKB();
}

int ItemType::ReadDataFromFile(ifstream& fin)
{
	int inId;
	string inName;
	string inAddress;

	fin >> inId >> inName >> inAddress;
	SetRecord(inId, inName, inAddress);

	return 1;
}

int ItemType::WriteDataToFile(ofstream& fout)
{
	fout << endl;
	fout << m_Id << " ";
	fout << m_sName << " ";
	fout << m_sAddress;

	return 1;
}

RelationType ItemType::CompareByID(const ItemType& data)
{
	if (this->m_Id > data.m_Id)
	{
		return GREATER;
	}
	else if (this->m_Id < data.m_Id)
	{
		return LESS;
	}
	else
	{
		return EQUAL;
	}
}
*/