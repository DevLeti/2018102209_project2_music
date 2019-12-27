#include "PlaylistInsertCount.h"

PlaylistInsertCount::PlaylistInsertCount()
{
	insertCount = 0;
}

int PlaylistInsertCount::GetInsertCount()
{
	return this->insertCount;
}

void PlaylistInsertCount::DisplayInsertCount()
{
	cout << "Insert Count : " << this->insertCount << endl;
}

void PlaylistInsertCount::SetInsertCount(int inCount)
{
	this->insertCount = inCount;
}

void PlaylistInsertCount::PlusInsertCount()
{
	this->insertCount++;
}

void PlaylistInsertCount::ResetCount()
{
	this->insertCount = 0;
}
