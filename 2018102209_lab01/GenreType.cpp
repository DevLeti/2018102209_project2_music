#include "GenreType.h"

void GenreType::ResetList()
{
	itor.ResetList();
}

int GenreType::GetNextItem(string& item)
{
	if (itor.NextNotNull())
	{
		item = itor.Next();
		return 1;
	}
	else //listÀÇ ³¡
	{
		return 0;
	}
	
}

int GenreType::IsEmpty()
{
	if (this->songList.IsEmpty())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void GenreType::Add(string inName)
{
	this->songList.Add(inName);
}

int GenreType::Delete(string inName)
{
	return this->songList.Delete(inName);
}

GenreType& GenreType::operator=(const GenreType& data)
{
	DoublyIterator<string> temp(data.songList);
	while (temp.NextNotNull())
	{
		songList.Add(temp.Next());
	}

	return *this;
}

bool GenreType::operator==(const GenreType& data)
{
	if (this->songList.GetLength() == data.songList.GetLength())
		return true;
	else
		return false;
}
