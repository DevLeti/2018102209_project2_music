#pragma once
#include <iostream>
using namespace std;

class PlaylistInsertCount
{
public:
	//default constructor
	PlaylistInsertCount();

	//getter
	int GetInsertCount();
	void DisplayInsertCount();

	//setter
	void SetInsertCount(int inCount);
	void PlusInsertCount();
	void ResetCount();
private:
	int insertCount; // �� ����. 0���� ����.
};

