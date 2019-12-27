#pragma once
#include <iostream>
#define maxsize 8

using namespace std;

class FullStack
{
public:
	void print()
	{
		cout << "FullStack exception thrown." << endl;
	}
};

class EmptyStack
{
public:
	void print()
	{
		cout << "EmptyStack exception thrown." << endl;
	}
};

/**
*	QList Class
*	@Author : MyeongHyun Lew
*	@Date : 2019-10-06
*/
template <class T>
class QList
{
public:
	/**
	*	@brief	최대크기로 생성
	*	@pre	최대크기가 정해져야함
	*	@post	최대크기의 배열이 만들어지고, 각 멤버변수들이 초기화됨
	*/
	QList();

	/**
	*	@brief	size에 해당하는 크기의 배열을 동적할당
	*	@post	size의 값에 해당되는 크기의 배열이 만들어짐,각 멤버변수들이 초기화됨
	*	@param	max	Set size of queue.
	*/
	QList(int max);

	~QList(); //destructor

	QList(const QList& C);

	/**
	*	@brief	determines whether QList is full or not.
	*	@post	none.
	*	@return	1 if the list is full. otherwise return 0.
	*/
	bool IsFull();
	/**
	*	@brief	determines whether QList is empty or not.
	*	@pre	QList should be initialized.
	*	@post	none.
	*	@return	1 if the list is empty. otherwise return 0.
	*/
	bool IsEmpty();

	/**
	*	@brief	Make QList empty.
	*	@pre	QList should be initialized.
	*	@post	iRear is positioned at iFront.
	*/
	void MakeEmpty();

	/**
	*	@brief	Enqueue item to QList.
	*	@pre	QList should be initialized.
	*	@post	item is enqueued to QList unless QList is not full.
	*	@param	item	item to add to QList.
	*/
	void EnQueue(T item);

	/**
	*	@brief	Dequeue item to QList.
	*	@pre	QList should be initialized.
	*	@post	item is Dequeued from QList unless QList is not empty.
				Also dequeued item is declared to param.
				iFront is added 1.
	*	@param	item	item which is given dequeued item.
	*/
	void DeQueue(T& item);

	/**
	*	@brief	Print all the items in the stack on screen
	*	@pre	QList has been initialized.
	*	@post	None.
	*/
	void Print();

	//추가 함수
	/**
	*	@brief	move m_curPointer to iFront.
	*	@pre	QList has been initialized.
	*	@post	m_curPointer is at iFront position.
	*/
	void ResetList();

	/**
	*	@brief	Get next item of QList.
	*	@pre	QList has been initialized.
	*	@post	1 is added to m_curPointer.
	*	@param	item	Next item of QList.
	*	@return true if the list is not empty. otherwise return false.
	*/
	int GetNextItem(T& item);

	/**
	*	@brief	Search item by matching primary key.
	*	@pre	param should have primary key.
	*	@post	Found item is copied to param. otherwise not copied.
	*	@param	item	search item target.
	*	@return Found item's index in QList. otherwise, return -1.
	*/
	int Search(T& item);

	/**
	*	@brief	Delete item by searching primary key.
	*	@pre	param should have primary key.
	*	@post	Found item is deleted from QList, iRear subtract 1.
				otherwise not deleted, iRear doesn't subtract.
	*	@param	item	delete item target.
	*	@return 1 if deleted. otherwise, return 0.
	*/
	int Delete(T item);

	/**
	*	@brief	replace item by searching primary key.
	*	@pre	param should have primary key.
	*	@post	item's data is replaced if found.
				otherwise not deleted.
	*	@param	item	replace item target.
	*	@return 1 if replaced. otherwise, return 0.
	*/
	int Replace(T& item);
	
	//추가 함수 - 2
	/**
	*	@brief	return Count of insert. if you add 5th song, it will return 5.
	*	@pre	m_insertCount should be initialized.
	*	@post	None.
	*	@return m_insertCount.
	*/
	int Count();

	QList<T>& operator = (const QList& item)
	{
		m_iFront = item.m_iFront;
		m_iRear = item.m_iRear;
		m_nMaxQueue = item.m_nMaxQueue;
		m_insertCount = item.m_insertCount;
		top = item.top;
		m_curPointer = item.m_curPointer;

		m_pItems = new T[maxsize];
		for (int i = 0; i < maxsize; i++)
		{
			m_pItems[i] = item.m_pItems[i];
		}
		return *this;
	}

	int GetRear();
	int GetFront();
private:
	int m_iFront;
	int m_iRear;
	int m_nMaxQueue;
	int m_curPointer;
	int m_insertCount;
	int top;
	T* m_pItems;
};

template<class T>
inline QList<T>::QList()
{
	top = 0;
	this->m_pItems = new T[maxsize];
	this->m_iFront = maxsize - 1;
	this->m_iRear = maxsize - 1;
	this->m_nMaxQueue = maxsize;
	this->m_insertCount = 1;
}

template<class T>
inline QList<T>::QList(int max)
{
	top = 0;
	this->m_pItems = new int[max];
	this->m_iFront = max - 1;
	this->m_iRear = max - 1;
	this->m_nMaxQueue = max;
	this->m_insertCount = 1;
}

template<typename T>
inline QList<T>::QList(const QList& item)
{
	this->m_iFront = item.m_iFront;
	this->m_iRear = item.m_iRear;
	this->top = item.top;
	this->m_CulPointer = item.m_CulPointer;
	this->m_nMaxQueue = item.m_nMaxQueue;
	this->m_insertCount = item.m_insertCount;
	
	this->m_pItems = new T[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		this->m_pItems[i] = item.m_pItems[i];
	}

}

template<class T>
inline QList<T>::~QList()
{
	delete[] this->m_pItems;
}

template<class T>
inline bool QList<T>::IsFull()
{
	if ((this->m_iRear + 1) % this->m_nMaxQueue == this->m_iFront)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline bool QList<T>::IsEmpty()
{
	if (this->m_iFront == this->m_iRear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
inline void QList<T>::MakeEmpty()
{
	this->m_iRear = this->m_iFront;
}

template<class T>
inline void QList<T>::EnQueue(T item)
{
	if (!IsFull())
	{
		this->top++;
		this->m_iRear = (this->m_iRear + 1) % this->m_nMaxQueue;
		this->m_pItems[this->m_iRear] = item;
		this->m_insertCount++;
	}
	else
	{
		this->m_iRear = (this->m_iFront + 1) % this->m_nMaxQueue;
		this->m_pItems[this->m_iRear] = item;
		this->m_insertCount++;
	}
}

template<class T>
inline void QList<T>::DeQueue(T& item)
{
	if (!IsEmpty())
	{
		this->top--;
		this->m_iFront = (this->m_iFront + 1) % this->m_nMaxQueue;
		item = this->m_pItems[this->m_iFront];
	}
	else
	{
		cout << "List is Empty." << endl;
		/*throw EmptyStack();*/
	}
}

template<class T>
inline void QList<T>::Print()
{
	if (!IsEmpty())
	{
		int iFront = this->m_iFront;
		int iRear = this->m_iRear;
		cout << "QList :" << endl;
		while (iFront != iRear)
		{
			cout << m_pItems[(iFront + 1) % m_nMaxQueue] << " - ";
			iFront = (iFront + 1) % m_nMaxQueue;
		}
		cout << endl;
	}
	else
	{
		throw EmptyStack();
	}
}

template<class T>
inline void QList<T>::ResetList()
{
	this->m_curPointer = this->m_iFront;
}

template<class T>
inline int QList<T>::GetNextItem(T& item)
{
	if (!IsEmpty())
	{
		this->m_curPointer = (this->m_curPointer + 1) % this->m_nMaxQueue;
		item = m_pItems[this->m_curPointer];
	}

	return this->m_curPointer;

	/*if (!IsEmpty())
	{
		if (this->m_curPointer == this->m_iRear)
		{
			this->m_curPointer = (this->m_iFront + 1) % this->m_nMaxQueue;
			item = this->m_pItems[this->m_curPointer];
			return true;
		}
		else
		{
			this->m_curPointer = (this->m_curPointer + 1) % this->m_nMaxQueue;
			item = this->m_pItems[this->m_curPointer];
			return true;
		}
	}
	else
	{
		return false;
	}*/
}

//못찾으면 -1 찾으면 index return
template<class T>
inline int QList<T>::Search(T& item)
{
	this->ResetList();
	if (!IsEmpty())
	{
		while (this->m_curPointer != this->m_iRear)
		{
			T searchItem;
			this->GetNextItem(searchItem);
			if (item == searchItem) // 연산자 오버로딩으로 대응
			{
				item = searchItem;
				return m_curPointer;
			}
		}
		return -1;
	}
	else
	{
		throw EmptyStack();
	}
}

template<class T>
inline int QList<T>::Delete(T item)
{
	if (!IsEmpty())
	{
		T searchResult;
		searchResult = item;
		if (this->Search(searchResult) != -1)
		{
			int last = this->m_iRear;
			int deletePointer = this->m_curPointer;
			while (last != deletePointer)
			{
				/*if (deletePointer - 1 == -1)
				{
					deletePointer = this->iRear;
				}
				else
				{
					deletePointer--;
				}*/
				this->m_pItems[deletePointer] = this->m_pItems[(deletePointer + 1) % this->m_nMaxQueue];
				deletePointer = (deletePointer + 1) % this->m_nMaxQueue;
			}

			if (this->m_iRear - 1 == -1)
			{
				this->m_iRear = this->m_nMaxQueue - 1;
			}
			else
			{
				this->m_iRear--;
			}
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		throw EmptyStack();
	}
}

template<class T>
inline int QList<T>::Replace(T& item)
{
	if (!IsEmpty())
	{
		T searchItem;
		searchItem = item;
		if (this->Search(searchItem) != -1)
		{
			this->m_pItems[this->m_curPointer] = item;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		throw EmptyStack();
	}
}

template<class T>
inline int QList<T>::Count()
{
	return this->m_insertCount;
}

template<class T>
inline int QList<T>::GetRear()
{
	return this->m_iRear;
}

template<class T>
inline int QList<T>::GetFront()
{
	return this->m_iFront;
}
