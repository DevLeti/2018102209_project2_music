#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "UnsortedList.h"

using namespace std;

enum descriptionCode
{
	LIST,
	PL, //PlayList Command
	SL, //Singer List command
	SC, //Streaming command
	EQ, // Equalizer Command
	LC, //Language Command
	RC, //Recommend Song Command
};
enum resultCode
{
	LE, // List Empty
	LF, // List Full
	D, // Deleted
	FD, // Failed to Delete
	Rp, // Replaced
	FRp, // Failed to Replace
	FRt, // Failed to Retrieve
	II, // Invalid Input
	IF, // ITEM FOUND!
	INF, // ITEM NOT FOUND!
	IG, //Input Genre
	SN, //Singer Name
	SASI, //Start Adding Song Info
	SNF, //Singer Not Found. Start Adding Singer Info First
	N, //Name
	A, //Age
	S, //Sex
	SMF, // (1: Male, 2: Female)
	SI, //Song Info
	NP, //Now Playing
	EL, //Equalizer List
	SE, //Select Equalizer
	ES, // Equalizer has been Set
	FN, // File Name
	LL, // Language List
	SL_rc, //Select Language
	LS, // Language has been Set
	CP, // Continue Print?
	SN2 // Select Number
};

class LanguageType
{
private:
	string name;
	UnsortedList<string> description;
	UnsortedList<string> command;
	UnsortedList<string> result;
public:
	LanguageType();
	void PrintDescriptionList();
	void PrintCommandList();
	void PrintResultList();

	void PrintAll();
	void PrintMusicCommand();
	void PrintPlayListCommand();
	void PrintSingerListCommand();
	void PrintPlayCommand();
	void PrintEqualizerCommand();
	void PrintQuitCommand();
	void PrintLanguageCommand();
	void PrintInputCommand();
	void PrintRecommendCommand();

	int ReadFromFile(string fileName);

	void SetDescription(int index, string inDes);
	void SetCommand(int index, string inCom);
	void SetResult(int index, string inRes);
	void SetName(string inName);

	string GetName();

	int GetMaxSizeOfDescriptionList();
	int GetMaxSizeOfCommandList();
	int GetMaxSizeOfResultList();

	LanguageType& operator = (const LanguageType& data);
	bool operator== (LanguageType inData);
	bool operator > (LanguageType inData);
	bool operator < (LanguageType inData);

	string operator[] (int index);

};

