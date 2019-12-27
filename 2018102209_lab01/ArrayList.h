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

	//lab01 �߰� �Լ�

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

	//lab02 �߰� �Լ�

	/**
	*	@brief	Binary Search�� �̿��� item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int RetrieveByBS(T& data);

	/**
	*	@brief	item�� ã�Ƽ� �ش� item�� ��ȯ�Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ������ ã�� item�� data�� �Էµȴ�.
	*	@param	data	ã���� �ϴ� id�� �Էµ� ItemType��. �߰��� item�� ���ϵȴ�.
	*	@return	����(�߰�)�� 1, ���н� 0�� �����Ѵ�.
	*/
	int Retrieve_SeqS(T& data);

	//lab02 ���� �Լ�

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
	*	@brief	id�� ��ġ�ϴ� item�� ã�Ƽ� �ش� item�� �����Ѵ�.
	*	@pre	�μ� data�� �ִ� id�� list ���� �����ϴ� ���̾�� �Ѵ�.
	*	@post	list ���� �ش� item�� ���ŵȴ�.
	*	@param	data	�����ϰ��� �ϴ� id�� �Էµ� ItemType��.
	*	@return	������ 1, ���н� 0�� �����Ѵ�.
	*/
	int Delete(T data);

private:
	T* m_Array;  		// ���ڵ� �迭
	int m_Length;				// ����Ʈ�� ����� ���ڵ� ��
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
	���� �ϸ� data�� �� ���� �� index return.
	���н� 0 return.
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
	if (Retrieve_SeqS(data))	//Primary key�� ��ġ�ϴ� item�� �߰��Ѵٸ�(1)
	{
		for (int i = m_CurPointer; i < m_Length - 1; i++)	//���� �����ͺ��� �Էµ� �迭 ������ �ݺ�
			m_Array[i] = m_Array[i + 1];	//�迭 �ڿ��� ������ �ϳ��� ����
		m_Length--;	//������ ������ �ϳ� ����
		return 1;	//����(1)�� ����
	}
	return 0;	//Primary key��ġ�ϴ� item�� ã�� ���Ѵٸ� ����(0)�� ����

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
