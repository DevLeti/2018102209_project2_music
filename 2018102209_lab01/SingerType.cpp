#include "SingerType.h"

SingerType::SingerType()
{
	this->m_Sex = -1;
	this->m_Age = -1;
}

SingerType::~SingerType()
{
}

SingerType::SingerType(const SingerType& item)
{
	this->m_sName = item.m_sName;
	this->m_Age = item.m_Age;
	this->m_Sex = item.m_Sex;
	this->songList = item.songList; // 깊은 복사가 일어나야함
}

string SingerType::GetName()
{
	return this->m_sName;
}

int SingerType::GetAge()
{
	return this->m_Age;
}

int SingerType::GetSex()
{
	return this->m_Sex;
}

QList<string>* SingerType::GetSongList()
{
	return &this->songList;
}

void SingerType::SetName(string inName)
{
	this->m_sName = inName;
}

void SingerType::SetAge(int inAge)
{
	this->m_Age = inAge;
}

void SingerType::SetSex(int inSex)
{
	this->m_Sex = inSex;
}

void SingerType::SetRecord(string inName, int inAge, int inSex)
{
	this->m_sName = inName;
	this->m_Age = inAge;
	this->m_Sex = inSex;
}

void SingerType::Addsong(string inId)
{
	this->songList.EnQueue(inId);
}

void SingerType::DeleteSong(string inId)
{
	this->songList.DeQueue(inId);
}

void SingerType::SetRecordByKB()
{
	string inName;
	int inAge;
	int inSex;

	cout << "\tEnter Name : ";
	cin >> inName;
	cout << "\tEnter Age : ";
	cin >> inAge;
	cout << "\tEnter Sex (1 : Male, 2 : Female) : ";
	cin >> inSex;

	this->SetRecord(inName, inAge, inSex);
}

