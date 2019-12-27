#pragma once
#define MAXSIZE 10
#include <iostream>
using namespace std;

template <class T>
class UnsortedList
{
public:
	/**
	*	default constructor.
	*/
	UnsortedList()
	{
		m_Length = 0;
		m_CurPointer = -1;
		m_Array = new T[MAXSIZE];
		m_Maxsize = MAXSIZE;
	}

	UnsortedList(int size) :m_Length(0), m_CurPointer(-1) {
		m_Array = new T[size];
		m_Maxsize = size;
	}
	/**
	*	destructor.
	*/
	~UnsortedList()
	{
		//delete[] m_Array;
		/*
		try
		{
			delete[] m_Array;
		}
		catch (char *e)
		{
			cout << "unsorted list destructor error occured." << endl;
		}
		*/
	}

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
	*	@brief	Get a Maxsize of current list.
	*	@pre	none.
	*	@post	none.
	*	@return	Maxsize of current list.
	*/
	int GetMaxSize();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(T data);

	int Replace(T data); //하단에 있는 정의부분도 주석 해제

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();
	void ResetListToLast();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized.
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(T& data);
	int GetPrevItem(T& data);

	int Retrieve_SeqS(T& data);
	int Delete(T data);
	UnsortedList<T>& operator= (const UnsortedList& data);

	T& operator[] (int index);
private:
	T* m_Array;  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
	int m_Maxsize; ///< list max size.
};



template <class T>
UnsortedList<T>& UnsortedList<T>::operator= (const UnsortedList& data)
{
	this->m_Array = new T[data.m_Maxsize];
	for (int i = 0; i < data.m_Maxsize; i++)
	{
		this->m_Array[i] = data.m_Array[i];
	}

	this->m_Length = data.m_Length;
	this->m_CurPointer = data.m_CurPointer;
	this->m_Maxsize = data.m_Maxsize;

	return *this;
}

template <class T>
inline T& UnsortedList<T>::operator[](int index)
{
	if (index <= this->m_Maxsize)
	{
		return this->m_Array[index];
	}
	cout << "array exception called" << endl;
	exit(1);
	return this->m_Array[index - 1];

	//if (index > (this->m_Length) || index < 0)
	//{
	//	cout << "Array Index out of bound exception" << endl;
	//	exit(1);
	//}
	//else
	//{
	//	return this->m_Array[index];
	//}

}
// Make list empty.
template <class T>
void UnsortedList<T>::MakeEmpty()
{
	m_Length = 0;
}


// Get a number of records in current list.
template <class T>
int UnsortedList<T>::GetLength()
{
	return m_Length;
}


template<class T>
inline int UnsortedList<T>::GetMaxSize()
{
	return this->m_Maxsize;
}

// Check capacity of list is full.
template <class T>
bool UnsortedList<T>::IsFull()
{
	if (m_Length > m_Maxsize - 1)
		return true;
	else
		return false;
}


// add a new data into list.
template <class T>
int UnsortedList<T>::Add(T inData)
{
	if (!IsFull())
	{
		m_Array[m_Length] = inData;
		m_Length++;
	}
	else
		return 0;

	return 1;
}



template<class T>
inline int UnsortedList<T>::Replace(T data)
{
	for (int i = 0; i < m_Length + 1; i++)
	{
		if (this->m_Array[i] == data)
		{
			this->m_Array[i] = data;
			return 1;
		}
		else
			return 0;
	}
	/*if (Retrieve_SeqS(data))
	{
		this->m_Array[m_CurPointer] = data;
		return 1;
	}*/
	return 0;
}

// Initialize list iterator.
template <class T>
void UnsortedList<T>::ResetList()
{
	m_CurPointer = -1;
}

template<class T>
inline void UnsortedList<T>::ResetListToLast()
{
	this->m_CurPointer = this->m_Length;
}


// move list iterator to the next item in list and get that item.
template <class T>
int UnsortedList<T>::GetNextItem(T& data)
{
	m_CurPointer++;	// list pointer 증가
	if (m_CurPointer == m_Maxsize)	// end of list이면 -1을 리턴
		return -1;
	data = m_Array[m_CurPointer];	// 현재 list pointer의 레코드를 복사

	return m_CurPointer;
}

template<class T>
inline int UnsortedList<T>::GetPrevItem(T& data)
{
	m_CurPointer--;
	if (m_CurPointer == -1)
		return -1;
	data = m_Array[m_CurPointer];

	return m_CurPointer;
}

template<class T>
int UnsortedList<T>::Retrieve_SeqS(T& data)
{
	T CurItem;

	ResetList();	//iterator 초기화
	GetNextItem(CurItem);	//첫아이템 가져옴
	while (m_CurPointer < m_Length)	//처음부터 끝까지
	{
		if (CurItem == data)
		{
			data = CurItem;	//data에 현재 아이템을 반환
			return 1;	//성공(1)을 리턴
		}
		else
		{
			GetNextItem(CurItem);	//다음 아이템을 가져온다.(계속 탐색)
		}
	}
	return 0; //실패시0
}

template<class T>
int UnsortedList<T>::Delete(T data)
{
	if (Retrieve_SeqS(data))	//Primary key가 일치하는 item을 발견한다면(1)
	{
		for (int i = m_CurPointer; i < m_Length; i++)	//현재 포인터부터 입력된 배열 끝까지 반복
			m_Array[i] = m_Array[i + 1];	//배열 뒤에걸 앞으로 하나씩 땡김
		m_Length--;	//아이템 개수를 하나 줄임
		return 1;	//성공(1)을 리턴
	}
	return 0;	//Primary key일치하는 item을 찾지 못한다면 실패(0)을 리턴
}
