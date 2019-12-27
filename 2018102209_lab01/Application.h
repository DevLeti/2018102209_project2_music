#pragma once

//전처리
#define CURL_STATICLIB
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Wldap32.lib")
//#pragma comment(lib, "CRYPT32.LIB")

//기본 라이브러리
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm> // curl return된 string replace
#include <windows.h> // cmd clear

//외부 라이브러리
#include <curl/curl.h>
#include <json/json.h>

//DS
#include "ArrayList.h"
//#include "QList.h"
#include "PlayItem.h"
#include "ItemType.h"
#include "SingerType.h"
//#include "LinkedList.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include "PlaylistInsertCount.h"
#include "UnsortedList.h"
#include "EqualizerType.h"
#include "GenreType.h"
#include "LanguageType.h"

using namespace std;

/**
*	Application Class
*	@Author : MyeongHyun Lew
*	@Date : 2019-10-06
*/
class Application
{
public:

	Application(); //: GenreList(5) {}
	
	/**
	*	@brief	Program driver.
	*	@pre	program is started.
	*	@post	program is finished.
	*/
	void Run();
	/**
	*	@brief	Display command on screen and get a input from keyboard.
	*	@pre	none.
	*	@post	none.
	*	@return	user's command.
	*/
	int GetCommand();

	/**
	*	@brief	Add New Item into list.
	*	@pre	list should be initialized
	*	@post	new Item is added into list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddMusic();

	/**
	*	@brief	Delete Song which has same id with input data.
	*	@pre	input data's id should be existed in the list.
	*	@post	Data will be deleted in the list which has same id with input data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteMusic();

	/**
	*	@brief	Replace Data info. Replaced data's id is same as input data's name.
	*	@pre	input data should be included the list item.
	*	@post	Song info will be replaced.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceMusic();

	/**
	*	@brief	Search Music in the list.
	*	@pre	The list should be initialized.
	*	@post	display found Music.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int RetrieveMusic();

	/**
	*	@brief	Display All Item in the list.
	*	@pre	None.
	*	@post	None.
	*/
	void DisplayAllMusic();

	/**
	*	@brief	Make list Empty.
	*	@pre	None.
	*	@post	List is made empty.
	*/
	int MakeEmpty();

	/**
	*	@brief	Open a file as a read mode, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadDataFromFile();

	/**
	*	@brief	Open a file as a write mode, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int WriteDataToFile();

	/**
	*	@brief	Open a file as a read mode, get fileName with keyboard input, read all data on the file, and set list by the data.
	*	@pre	The file is not opened.
	*	@post	list holds all records from the file.
	*	@return	return 1 if this function works well, otherwise 0.
	*	@param	fileName fileName to read data.
	*/
	int OpenInFile(char* fileName);

	/**
	*	@brief	Open a file as a write mode, get fileName with keyboard input, and write all data into the file,
	*	@pre	The file is not opened.
	*	@post	the list is stored in the output file.
	*	@return	return 1 if this function works well, otherwise 0.
	*	@param	fileName fileName to write data.
	*/
	int OpenOutFile(char* fileName);

	// lab 02 추가 함수

	/**
	*	@brief	Search data using ID with Binary Search.
	*	@pre	The list should be initialized.
	*	@post	Display Found Song.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchByID_BinaryS();

	/**
	*	@brief	Search data using ID.
	*	@pre	The list should be initialized.
	*	@post	Display Found Song.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchByID_SequenS();

	/**
	*	@brief	Display all data in which Genre has input Genre. (partially included is also be displayed)
	*	@pre	input Genre should be included the list item's Genre.
	*	@post	Display All Song.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchByGenre();

	/**
	*	@brief	Display all data in which Singer has input Singer. (partially included is also be displayed)
	*	@pre	input Name should be included the list item's Singer.
	*	@post	Display All Song.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchBySingerOld();

	/**
	*	@brief	Replace Data info. Replaced data's id is same as input data's name.
	*	@pre	input data should be included the list item.
	*	@post	Song info will be replaced.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceItem();

	// lab 03 추가 함수 - PlayList
	/**
	*	@brief	Add Song to QList.
	*	@pre	none.
	*	@post	Song will be added to QList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddSongToPL();

	/**
	*	@brief	Print list of QList.
	*	@pre	none.
	*	@post	none.
	*/
	void PlayInsertOrder();

	/**
	*	@brief	Delete Song From QList.
	*	@pre	none.
	*	@post	Song will be deleted from QList.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteSongFrPL();

	//LAB04 추가함수
	/**
	*	@brief	Add Singer to Singer List.
	*	@pre	none.
	*	@post	Singer will be added to Singer List.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddSinger();
	/**
	*	@brief	Add Singer to Singer List's Singer info.
	*	@pre	none.
	*	@post	Song will be added to Singer List's Singer info.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddSong();

	/**
	*	@brief	Search Singer From Singer List.
	*	@pre	none.
	*	@post	Singer will be added to Singer List.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SearchBySinger();

	//LAB05 추가함수
	/**
	*	@brief	Play Song depending on Added Time.
	*	@pre	none.
	*	@post	All song's playtime of Playlist will be increased. (1)
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int PlayIOAddTime();

	/**
	*	@brief	Play Song depending on Play count.
	*	@pre	none.
	*	@post	All song's playtime of Playlist will be increased. (1)
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int PlayIOFreq();

	//Project01 추가함수
	/**
	*	@brief	Add Equalizer to Equalizer list.
	*	@pre	none.
	*	@post	Equalizer will be added to list.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int AddNewEqualizer();

	/**
	*	@brief	Change specified Equalizer's info.
	*	@pre	none.
	*	@post	Specified Equalizer's info will be changed.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReplaceEqualizer();

	/**
	*	@brief	Delete Equalizer From List.
	*	@pre	none.
	*	@post	Delete will be deleted from List.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteEqualizer();

	/**
	*	@brief	Set Equalizer.
	*	@pre	none.
	*	@post	curEqualizer will be changed.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SetCurrentEqualizer();

	/**
	*	@brief	Display Current Equalizer on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DisplayCurrentEqualizer();

	/**
	*	@brief	Display All Equalizer on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DisplayAllEqualizer();

	//project02 추가함수
	
	/*Language Functions*/

	/**
	*	@brief	Read Language from text file.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int ReadLanguageFromFile();

	/**
	*	@brief	Delete Language from list.
	*	@pre	none.
	*	@post	Language in list will deleted.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DeleteLanguage();

	/**
	*	@brief	Set Language from list.
	*	@pre	none.
	*	@post	curLanguage will be changed.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int SetCurLanguage();

	/**
	*	@brief	Display All Language on screen.
	*	@pre	none.
	*	@post	none.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int DisplayLanguageList();

	/*Recommend Song Functions*/

	/**
	*	@brief	Get Recommend Song Using Curl, API(AWS Lambda).
	*	@pre	none.
	*	@post	none.
	*	@param	inName : input song name to get recommend song name.
	*	@return	return Recommend Song Name if this function works well, otherwise return "error".
	*/
	string RecommendSong(string inName);

	/**
	*	@brief	Get Recommend Song Using Curl, API(AWS Lambda) by Keyboard input.
	*	@pre	none.
	*	@post	Recommend song name will be displayed.
	*	@return	return 1 if this function works well, otherwise return 0.
	*/
	int RecommendSongByKB();

	/**
	*	@brief	Get Recommend Song by master list, Add New song to master list.
	*	@pre	Master list should not be full.
	*	@post	New song will be added to master list.
	*	@return	return 1 if this function works well, otherwise return 0.
	*/
	int RecommendSongByList();

private:
	ifstream m_InFile;///< input file descriptor.
	ofstream m_OutFile;///< output file descriptor.
	ArrayList<ItemType> MasterList;///< MasterList. ArrayList
	int m_Command;///< current command number.
	DoublySortedLinkedList<PlayItem> m_PlayList;///< PlayList.
	DoublySortedLinkedList<SingerType> m_SingerList;///< SingerList.
	PlaylistInsertCount insertCount;///< PlayList insert Counter.

	//project 1 추가 변수
	DoublySortedLinkedList<EqualizerType> EqualizerList; ///< EqualizerList.
	EqualizerType curEqualizer; ///< Current Equalizer
	
	//project 2 추가 변수(구현 예정)
	//UnsortedList<GenreType> GenreList;///< Genre List.

	DoublySortedLinkedList<LanguageType> LanguageList; ///< Language List.
	LanguageType curLanguage; ///< current Language
	
};


/*****************GLOBAL FUNCTION FOR CURL******************/
size_t write_to_string(void* ptr, size_t size, size_t count, void* stream);
/***********************************************************/