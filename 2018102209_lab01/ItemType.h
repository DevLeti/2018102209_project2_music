#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
*	ItemType Class
*	@Author : MyeongHyun Lew
*	@Date : 2019-10-06
*/

/**
*	Relation between two items.
*/
enum RelationType { LESS, GREATER, EQUAL };

class ItemType
{
public:
	ItemType();							// default constructor
	~ItemType();							// default destructor

	//Getter
	/**
	*	@brief	Get Song Type.
	*	@pre	Song Type is set.
	*	@post	none.
	*	@return	Song Type.
	*/
	int GetType();
	/**
	*	@brief	Get Song Genre.
	*	@pre	Song Genre is set.
	*	@post	none.
	*	@return	Song Genre.
	*/
	int GetGenre();

	/**
	*	@brief	Get Song Name
	*	@pre	Song Name is set.
	*	@post	none.
	*	@return	Song Name.
	*/
	string GetName();

	/**
	*	@brief	Get Song Composer
	*	@pre	Song Composer is set.
	*	@post	none.
	*	@return	Song Composer.
	*/
	string GetComposer();

	/**
	*	@brief	Get Song Singer
	*	@pre	Song Singer is set.
	*	@post	none.
	*	@return	Song Singer.
	*/
	string GetSinger();

	/**
	*	@brief	Get Song id.
	*	@pre	Song id is set.
	*	@post	none.
	*	@return	Song id.
	*/
	string GetId();
	
	//Setter
	/*
	*	@brief	Set Song Type.
	*	@pre	none.
	*	@post	Song Type is set.
	*	@param	inType	Song Type.
	*/
	void SetType(int inType);

	/*
	*	@brief	Set Song Genre.
	*	@pre	none.
	*	@post	Song Genre is set.
	*	@param	inGenre	Song Genre.
	*/
	void SetGenre(int inGenre);

	/*
	*	@brief	Set Song Name.
	*	@pre	none.
	*	@post	Song Name is set.
	*	@param	inName	Song Name.
	*/
	void SetName(string inName);

	/*
	*	@brief	Set Song Composer.
	*	@pre	none.
	*	@post	Song Composer is set.
	*	@param	inComposer	Song Composer.
	*/
	void SetComposer(string inComposer);

	/*
	*	@brief	Set Song Singer.
	*	@pre	none.
	*	@post	Song Singer is set.
	*	@param	inSinger	Song Singer.
	*/
	void SetSinger(string inSinger);

	/*
	*	@brief	Set Song Id.
	*	@pre	none.
	*	@post	Song Id is set.
	*	@param	inId	Song Id.
	*/
	void SetId(string inId);

	/**
	*	@brief	Set Song record.
	*	@pre	none.
	*	@post	Song record is set.
	*	@param	inType	Song Type.
	*	@param	inGenre	Song Genre.
	*	@param	inName	Song Name.
	*	@param	inComposer	Song Composer.
	*	@param	inSinger	Song Singer.
	*	@param	inId	Song Id.
	*/
	void SetRecord(int inType, int inGenre, string inName, string inComposer, string inSinger, string inId);
	
	/**
	*	@brief	Set Song Type from keyboard.
	*	@pre	none.
	*	@post	Song Type is set.
	*/
	void SetTypeFromKB();

	/**
	*	@brief	Set Song Genre from keyboard.
	*	@pre	none.
	*	@post	Song Genre is set.
	*/
	void SetGenreFromKB();

	/**
	*	@brief	Set Song Name from keyboard.
	*	@pre	none.
	*	@post	Song Name is set.
	*/
	void SetNameFromKB();

	/**
	*	@brief	Set Song Composer from keyboard.
	*	@pre	none.
	*	@post	Song Composer is set.
	*/
	void SetComposerFromKB();

	/**
	*	@brief	Set Song Singer from keyboard.
	*	@pre	none.
	*	@post	Song Singer is set.
	*/
	void SetSingerFromKB();

	/**
	*	@brief	Set Song Id from keyboard.
	*	@pre	none.
	*	@post	Song Id is set.
	*/
	void SetIdFromKB();

	/**
	*	@brief	Set Song Record from keyboard.
	*	@pre	none.
	*	@post	Song Record is set.
	*/
	void SetRecordFromKB();			// 키보드로 음악 정보 입력 함수

	//Display On Screen
	/**
	*	@brief	Display Song Type on screen.
	*	@pre	Song Type is set.
	*	@post	Song Type is on screen.
	*/
	void DisplayTypeOnScreen();

	/**
	*	@brief	Display Song Genre on screen.
	*	@pre	Song Genre is set.
	*	@post	Song Genre is on screen.
	*/
	void DisplayGenreOnScreen();

	/**
	*	@brief	Display Song Name on screen.
	*	@pre	Song Name is set.
	*	@post	Song Name is on screen.
	*/
	void DisplayNameOnScreen();

	/**
	*	@brief	Display Song Composer on screen.
	*	@pre	Song Composer is set.
	*	@post	Song Composer is on screen.
	*/
	void DisplayComposerOnScreen();

	/**
	*	@brief	Display Song Singer on screen.
	*	@pre	Song Singer is set.
	*	@post	Song Singer is on screen.
	*/
	void DisplaySingerOnScreen();

	/**
	*	@brief	Display Song Id on screen.
	*	@pre	Song Id is set.
	*	@post	Song Id is on screen.
	*/
	void DisplayIdOnScreen();

	/**
	*	@brief	Display Song Record on screen.
	*	@pre	Song Record is set.
	*	@post	Song Record is on screen.
	*/
	void DisplayRecordOnScreen();

	//Read & Write From File
	/**
	*	@brief	Read a record from file.
	*	@pre	the target file is opened.
	*	@post	Song record is set.
	*	@param	fin	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile(ifstream& fin);

	/**
	*	@brief	Write a record into file.
	*	@pre	the target file is opened. And the list should be initialized.
	*	@post	the target file is included the new Song record.
	*	@param	fout	file descriptor.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile(ofstream& fout);		// 음악 정보를 파일로 출력하는 함수

	//Compare other ItemType data
	/**
	*	Compare two itemtypes.
	*	@brief	Compare two item types by item id.
	*	@pre	two item types should be initialized.
	*	@post	the target file is included the new item record.
	*	@param	data	target item for comparing.
	*	@return	return LESS if this.id < data.id,
	*			return GREATER if this.id > data.id then,
	*			otherwise return EQUAL.
	*/
	
	//Operator Overloading
	/*
	*	@brief	compare ID.
	*	@pre	PlayItem should be initialized.
	*	@post	none.
	*	@param	item item for compare.
	*	@return true is if ID is same as param's ID. otherwise return false.
	*/
	bool operator == (ItemType inItem)
	{
		if (this->m_sId == inItem.m_sId)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	/*
	*	@brief	compare ID.
	*	@pre	PlayItem should be initialized.
	*	@post	none.
	*	@param	item item for compare.
	*	@return true is if ID is larger than param's ID. otherwise return false.
	*/
	bool operator > (ItemType inItem)
	{
		if (this->m_sId > inItem.m_sId)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	/*
	*	@brief	compare ID.
	*	@pre	PlayItem should be initialized.
	*	@post	none.
	*	@param	item item for compare.
	*	@return true is if ID is less than param's ID. otherwise return false.
	*/
	bool operator < (ItemType inItem)
	{
		if (this->m_sId < inItem.m_sId)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
													/*
	학생 관리 프로그램 관련 함수
	int GetId();							// 학생 ID 반환 함수
	string GetName();						// 학생 이름 반환 함수
	string GetAddress();						// 학생 주소 반환 함수
	void SetId(int inId);						// 학생 ID 저장 함수
	void SetName(string inName);					// 학생 이름 저장 함수
	void SetAddress(string inAddress);				// 학생 주소 저장 함수
	void SetRecord(int inId, string inName, string inAddress); 	// 학생 정보 저장 함수
	void DisplayIdOnScreen();					// 학생 ID 출력 함수
	void DisplayNameOnScreen();					// 학생 이름 출력 함수
	void DisplayAddressOnScreen();				// 학생 주소 출력 함수
	void DisplayRecordOnScreen();					// 학생 정보 출력 함수
	void SetIdFromKB();				// 키보드로 학생 ID 입력 함수
	void SetNameFromKB();			// 키보드로 학생 이름 입력 함수
	void SetAddressFromKB();			// 키보드로 학생 주소 입력 함수
	void SetRecordFromKB();			// 키보드로 학생 정보 입력 함수
	int ReadDataFromFile(ifstream& fin);		// 학생 정보를 파일에서 읽는 함수
	int WriteDataToFile(ofstream& fout);		// 학생 정보를 파일로 출력하는 함수
	RelationType CompareByID(const ItemType& data);	// primary key (ID)를 기준으로 학생 정보를 비교하는 함수
	*/
private:
	int m_Type;		// 곡 타입 1: 가요, 2: 연주곡
	int m_Genre;	// 장르 
	string m_sName;// 곡명
	string m_sComposer; // 작곡가
	string m_sSinger;	// 가수 또는 연주자
	string m_sId;		// 곡의 고유번호

	/*학생 관리 프로그램 관련 변수*/
	//int m_Id;					// 학생 ID
	//string m_sName;				// 학생 이름 저장 변수
	//string m_sAddress;				// 학생 주소 저장 변수

};