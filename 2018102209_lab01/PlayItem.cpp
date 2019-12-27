#include "PlayItem.h"

PlayItem::PlayItem()
{
	this->ID = "";
	this->numPlay = 0;
	this->inTime = 0;
}

string PlayItem::GetID()
{
	return this->ID;
}

int PlayItem::GetNumPlay()
{
	return this->numPlay;
}

int PlayItem::GetInTime()
{
	return this->inTime;
}

void PlayItem::SetID(string inID)
{
	this->ID = inID;
}

void PlayItem::SetNumPlay(int inNumPlay)
{
	this->numPlay = inNumPlay;
}

void PlayItem::SetInTime(int inInTime)
{
	this->inTime = inInTime;
}

void PlayItem::SetItem(string inID, int inNumplay, int inInTime)
{
	SetID(inID);
	SetNumPlay(inNumplay);
	SetInTime(inInTime);
}

void PlayItem::PlusNumPlay()
{
	this->numPlay++;
}

void PlayItem::DisplayNumPlay()
{
	cout << "\tNumber of Play : " << this->numPlay << endl;
}

void PlayItem::DisplayInTime()
{
	cout << "\t Inserted Time : " << this->inTime <<endl;
}
