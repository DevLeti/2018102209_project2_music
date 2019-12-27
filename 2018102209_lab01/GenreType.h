#pragma once

//#include "ArrayList.h"
#include "DoublySortedLinkedList.h"
#include "DoublyIterator.h"
#include <string>

using namespace std;


class GenreType
{
private:
	DoublySortedLinkedList<string> songList;
	DoublyIterator<string> itor;
public:
	
	GenreType() : itor(songList) {}
	//getter
	void ResetList();
	int GetNextItem(string& item);
	int IsEmpty();
	//setter
	void Add(string inName);
	int Delete(string inName);

	GenreType& operator= (const GenreType& data);
	bool operator== (const GenreType& data);
};

