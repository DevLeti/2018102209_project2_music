#pragma once
#include <string>
#include <iostream>
using namespace std;

/**
*	PlayItem Class
*	@Author : MyeongHyun Lew
*	@Date : 2019-10-06
*/
class PlayItem
{
public:

	PlayItem();

	/**
	*	@brief	Get a ID of PlayItem.
	*	@pre	none.
	*	@post	none.
	*	@return	ID of PlayItem.
	*/
	string GetID();

	/**
	*	@brief	Get a Play time of PlayItem.
	*	@pre	none.
	*	@post	none.
	*	@return	Play time of PlayItem.
	*/
	int GetNumPlay();

	/**
	*	@brief	Get a inserted time of PlayItem.
	*	@pre	none.
	*	@post	none.
	*	@return	Inserted time of PlayItem.
	*/
	int GetInTime();
	
	/*
	*	@brief	Set PlayItem ID.
	*	@pre	none.
	*	@post	PlayItem ID is set.
	*	@param	inID	Song ID.
	*/
	void SetID(string inID);

	/*
	*	@brief	Set PlayItem played number.
	*	@pre	none.
	*	@post	played number is set.
	*	@param	inNumPlay	Song played number.
	*/
	void SetNumPlay(int inNumPlay);

	/*
	*	@brief	Set PlayItem inserted time.
	*	@pre	none.
	*	@post	inserted time is set.
	*	@param	inInTime	Song inserted time.
	*/
	void SetInTime(int inInTime);

	/*
	*	@brief	Set PlayItem data.
	*	@pre	none.
	*	@post	data is set.
	*	@param	inID	Song ID.
	*			inNumPlay	Song played number.
	*			inInTime	Song inserted time.
	*/
	void SetItem(string inID, int inNumplay, int inInTime);

	void PlusNumPlay(); // NumPlay + 1
	
	void DisplayNumPlay(); // DisplayNumPlay
	void DisplayInTime(); // Display Inserted Time

	/*
	*	@brief	compare ID.
	*	@pre	PlayItem should be initialized.
	*	@post	none.
	*	@param	item item for compare.
	*	@return true is if ID is same as param's ID. otherwise return false.
	*/
	bool operator == (PlayItem item)
	{
		if (this->ID == item.ID)
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
	bool operator > (PlayItem inItem)
	{
		if (this->ID > inItem.ID)
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
	bool operator < (PlayItem inItem)
	{
		if (this->ID < inItem.ID)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
private:
	string ID;	//곡의 primary key 
	int numPlay;//곡이 play된 횟수
	int inTime; //곡이 play list에 삽입된 시간(이 과제에서는 들어온 순서를 사용)
};

