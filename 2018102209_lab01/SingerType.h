#pragma once
#include <string>
#include "QList.h"
using namespace std;


/**
*@brief SingerType Class
*@details Singer information, SongList
*@author MyeongHyunLew
*@date 2019-10-14
*/
class SingerType
{
public:
	SingerType(); // Default constructor;
	~SingerType();// Default destructor
	SingerType(const SingerType& item); // deep copy function

	//Getter
	string GetName();
	int GetAge();
	int GetSex();


	/**
	*@brief get SongList's 'POINTER' (= access real queue)
	*@post SongList's Address value is returned.
	*/
	QList<string>* GetSongList();

	
	//Setter
	void SetName(string inName);
	void SetAge(int inAge);
	void SetSex(int inSex);
	void SetRecord(string inName, int inAge, int inSex);
	void Addsong(string inId);
	void DeleteSong(string inId);
	void SetRecordByKB();


	// operator overloading, compare by Name
	bool operator == (SingerType item)
	{
		if (this->m_sName == item.m_sName)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator > (SingerType item)
	{
		if (this->m_sName > item.m_sName)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (SingerType item)
	{
		if (this->m_sName < item.m_sName)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	string m_sName;// �̸�
	int m_Age;		// ����
	int m_Sex;	// ���� 1: ����, 2: ���� 
	QList<string> songList; // SongList
};

