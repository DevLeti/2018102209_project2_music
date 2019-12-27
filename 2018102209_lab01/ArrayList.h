#pragma once
#define MAXSIZE 5
//#include "ItemType.h"
#include <iostream>
using namespace std;

/**
*	ArrayList Class - Sorted
*	@Author : MyeongHyun Lew
*	@Date : 2019-10-06
*/
template <class T>
class ArrayList
{
public:
	ArrayList();			// default constructor
	~ArrayList();			// default destructor

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);

	//lab01 추가 함수

	/**
	*	@brief	Check capacity of list is empty
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity is zero, otherwise return false.
	*/
	bool IsEmpty();

	/**
	*	@brief	Search using Primary key and if founded, data will be copied.
	*	@pre	list should be initialized.
	*	@post	data is copied, iterator is set to founded index.
	*	@param	data	Used for search using Primary key. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int Get(T& data);

	//lab02 추가 함수

	/**
	*	@brief	Binary Search를 이용해 item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int RetrieveByBS(T& data);

	/**
	*	@brief	item을 찾아서 해당 item을 반환한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에서 찾은 item이 data에 입력된다.
	*	@param	data	찾고자 하는 id가 입력된 ItemType값. 발견한 item이 리턴된다.
	*	@return	성공(발견)시 1, 실패시 0을 리턴한다.
	*/
	int Retrieve_SeqS(T& data);

	//lab02 수정 함수

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	/**
	*	@brief	Replace a data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	Replaced data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Replace(T data);

	/**
	*	@brief	id가 일치하는 item을 찾아서 해당 item을 제거한다.
	*	@pre	인수 data에 있는 id가 list 내에 존재하는 값이어야 한다.
	*	@post	list 내에 해당 item이 제거된다.
	*	@param	data	제거하고자 하는 id가 입력된 ItemType값.
	*	@return	성공시 1, 실패시 0을 리턴한다.
	*/
	int Delete(T data);

private:
	T* m_Array;  		// 레코드 배열
	int m_Length;				// 리스트에 저장된 레코드 수
	int m_CurPointer;			// Pointer
};

template <class T>
ArrayList<T>::ArrayList() : m_Array(nullptr)
{
	this->m_Length = 0;
	this->m_CurPointer = -1;
	this->m_Array = new T[MAXSIZE];
}

template <class T>
ArrayList<T>::~ArrayList()
{
	delete[] this->m_Array;
}

template <class T>
void ArrayList<T>::MakeEmpty()
{
	this->m_Length = 0;
}

template <class T>
int ArrayList<T>::GetLength()
{
	return this->m_Length;
}

template <class T>
bool ArrayList<T>::IsFull()
{
	if (GetLength() == MAXSIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
int ArrayList<T>::Add(T data)
{
	if (!this->IsFull())
	{
		//Unsorted
		//this->m_Array[this->GetLength()] = data;
		//this->m_Length++;
		//return 1;

		if (this->IsEmpty()) // If the list is empty
		{
			//we don't need to care about position.
			//add input data in 0 position.
			this->m_Array[0] = data;

			//length ++
			this->m_Length++;
			return 1;
		}
		else
		{
			//assign local variable ItenType nextItem
			T nextItem;

			//make m_Curpointer = -1
			this->ResetList();

			//repeat until next item is empty
			while (this->GetNextItem(nextItem) != -1)
			{
				//if input data's ID is bigger than list Item
				if (data > nextItem)
				{
					continue;
				}
				else if (data == nextItem)
				{
					cout << "the same item exist in the list " << endl;
					return 0;
				}
				else //less
				{
					//move items first
					for (int i = this->GetLength(); i > this->m_CurPointer; i--)
					{
						this->m_Array[i] = this->m_Array[i - 1];
					}

					//then add input data
					this->m_Array[this->m_CurPointer] = data;

					//length ++
					this->m_Length++;
					return 1;
				}
			}

			//If input data is the largest, will come here
			this->m_Array[this->GetLength()] = data;
			this->m_Length++;
			return 1;
		}
	}
	else //If item is Full
	{
		//Can't insert more items
		return 0;
	}
}

template <class T>
void ArrayList<T>::ResetList()
{
	this->m_CurPointer = -1;
}

template <class T>
int ArrayList<T>::GetNextItem(T& data)
{
	this->m_CurPointer++;
	if (this->GetLength() == this->m_CurPointer)
	{
		return -1;
	}
	else
	{
		data = this->m_Array[m_CurPointer];
		return this->m_CurPointer;
	}
}

template <class T>
bool ArrayList<T>::IsEmpty()
{
	if (this->GetLength() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*
	성공 하면 data의 값 변경 및 index return.
	실패시 0 return.
*/
template <class T>
int ArrayList<T>::Get(T& data)
{
	if (this->IsEmpty())
	{
		return 0;
	}
	else
	{
		T nextItem;
		this->ResetList();
		while (this->GetNextItem(nextItem) != -1)
		{
			if (nextItem == data)
			{
				data = nextItem;
				return this->m_CurPointer;
			}
			else
			{
				continue;
			}
		}

		return 0;
	}

	//if (this->IsEmpty())
	//{
	//	return 0;
	//}
	//else
	//{
	//	ItemType nextItem;
	//	this->ResetList();
	//	while (this->GetNextItem(nextItem) != -1)
	//	{
	//		if (nextItem.CompareByID(data) == EQUAL)
	//		{
	//			data = nextItem;
	//			return this->m_CurPointer;
	//		}
	//		else
	//		{
	//			continue;
	//		}
	//	}
	//	return -1;
	//}
}

template <class T>
int ArrayList<T>::Delete(T data)
{
	if (Retrieve_SeqS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length - 1; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴

	//int searchResult = this->Get(data);
	//if (searchResult == 0) // Search failure
	//{
	//	
	//	return 0;
	//}
	//else // Index Search Success
	//{
	//	ItemType copy;
	//	for (int i = this->m_CurPointer; i < this->GetLength() - 1; i++)
	//	{
	//		copy = this->m_Array[i + 1];
	//		this->m_Array[i] = copy;
	//	}
	//	this->m_Length--;
	//	return 1;

	//	//Unsorted
	//	//this->m_Array[searchResult] = this->m_Array[this->GetLength() - 1];
	//	//this->m_Length--;
	//	//return 1; 
	//}
}

template <class T>
int ArrayList<T>::RetrieveByBS(T& data)
{
	if (this->IsEmpty())
	{
		return 0;
	}
	else
	{
		this->ResetList();

		int head = 0;
		int last = this->m_Length - 1;

		int CurPos = this->m_Length / 2;
		while (head <= last)
		{
			if (this->m_Array[CurPos] == data)
			{
				data = this->m_Array[CurPos];
				return 1;
			}
			else if (this->m_Array[CurPos] > data)
			{
				last = CurPos - 1;
				CurPos = (head + last) / 2;
				continue;
			}
			else
			{
				head = CurPos + 1;
				CurPos = (head + last) / 2;
				continue;
			}
		}
		return 0;
	}
	return 0;
}

template <class T>
int ArrayList<T>::Retrieve_SeqS(T& data)
{
	this->ResetList();
	this->m_CurPointer++;
	//if m_Array Item's ID is LESS than input data
	while (this->m_Array[m_CurPointer] < data && m_CurPointer < this->m_Length)
	{
		m_CurPointer++;
	}

	if (this->m_Array[m_CurPointer] == data)
	{
		data = this->m_Array[m_CurPointer];
		return 1;
	}
	else if (this->m_Array[m_CurPointer] > data || m_CurPointer >= this->m_Length)
	{
		return 0;
	}

	return 0;
}

template <class T>
int ArrayList<T>::Replace(T data)
{
	int curPos = 0;
	while (this->m_Array[curPos] < data && curPos < this->m_Length)
	{
		curPos++;
	}

	if (this->m_Array[curPos] == data)
	{
		this->m_Array[curPos] = data;
		return 1;
	}

	else if (this->m_Array[curPos] > data || curPos >= this->m_Length)
	{
		return 0;
	}

	//Unsorted
	//ItemType searchData;
	//searchData = data;
	//int searchResult = this->Get(searchData);
	//if (searchResult == -1) // Search Failure
	//{
	//	return 0;
	//}
	//else
	//{
	//	this->m_Array[searchResult] = data;
	//	return 1;
	//}
}
