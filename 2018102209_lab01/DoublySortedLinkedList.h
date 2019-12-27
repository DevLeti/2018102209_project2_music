#pragma once
#include "DoublyIterator.h"
#define maxsize 10 // 최대 size

template<class T>
class DoublyIterator;

template <typename T>
struct DoublyNodeType
{
	T data; // data
	DoublyNodeType* prev; // Pointer of previous node
	DoublyNodeType* next; // Pointer of next node
};

template<class T>
class DoublySortedLinkedList
{
	friend class DoublyIterator<T>;
public:
	DoublySortedLinkedList(); // Default constructor
	~DoublySortedLinkedList(); // Destructor
	bool IsEmpty();// 리스트가 비어있는지 확인
	bool IsFull(); // 리스트가 가득 찼는지 확인
	void MakeEmpty(); // 리스트를 비움 (initialize)
	int GetLength() const; // 리스트가 보유하고 있는 item 개수 반환
	void Add(T item); // 새로운 레코드 추가
	int Delete(T item); // 기존 레코드 삭제
	void Replace(T item); // 기존 레코드 갱신
	int Get(T& item); // Primary key를 기준으로 데이터를 검색하고 해당 데이터를 가져옴
		
private:
	DoublyNodeType<T>* m_pFirst; // 리스트의 처음 노드를 가리키는 포인터
	DoublyNodeType<T>* m_pLast; // 리스트의 마지막 노드를 가리키는 포인터
	int m_nLength; // 리스트에 저장된 레코드 수
};

template<class T>
inline DoublySortedLinkedList<T>::DoublySortedLinkedList()
{
	this->m_pFirst = new DoublyNodeType<T>;
	this->m_pLast = new DoublyNodeType<T>;

	this->m_pFirst->next = this->m_pLast;
	this->m_pLast->prev = this->m_pFirst;
	
	this->m_pFirst->prev = nullptr;
	this->m_pLast->next = nullptr;
}

template<class T>
inline DoublySortedLinkedList<T>::~DoublySortedLinkedList()
{
}

template<class T>
inline bool DoublySortedLinkedList<T>::IsEmpty()
{
	if (this->m_nLength == 0) // length가 0이면
		return true; // true
	else //아니면
		return false; // false
}

template<class T>
inline bool DoublySortedLinkedList<T>::IsFull()
{
	if (this->m_nLength == maxsize)
		return true;
	else
		return false;
}

template<class T>
inline void DoublySortedLinkedList<T>::MakeEmpty()
{
	DoublyNodeType<T>* pItem;
	DoublyIterator<T> itor(*this);

	itor.Next();
	while (itor.NextNotNull())
	{
		pItem = itor.m_pCurPointer;
		itor.Next();
		delete pItem;
	}


	this->m_pFirst->next = this->m_pLast;
	this->m_pLast->prev = this->m_pFirst;
	this->m_nLength = 0;
}

template<class T>
inline int DoublySortedLinkedList<T>::GetLength() const
{
	return this->m_nLength;
}

template<class T>
inline void DoublySortedLinkedList<T>::Add(T item)
{
	if (this->IsEmpty())
	{
		DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
		pItem->data = item;
		pItem->prev = this->m_pFirst;
		pItem->next = this->m_pLast;

		this->m_pFirst->next = pItem;
		this->m_pLast->prev = pItem;
		this->m_nLength++;

		return;
	}
	else
	{
		DoublyIterator<T> itor(*this);
		itor.Next();//먼저 첫 데이터 값으로 옮김.
		while (1)
		{
			if (itor.NextNotNull()) //m_pLast에 도착하면 false나와서 빠져나오게 만듬.
			{
				if (item < itor.m_pCurPointer->data)
				{
					DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
					pItem->data = item;
					/*pItem->prev = this->m_pFirst;
					pItem->next = this->m_pLast;*/

					itor.m_pCurPointer->prev->next = pItem; //1 curpos 전의 node의 next를 pItem으로.
					pItem->prev = itor.m_pCurPointer->prev; //2 pItem의 prev를 curpos의 prev로.
					pItem->next = itor.m_pCurPointer; //3 pItem의 next를 curpos로.
					itor.m_pCurPointer->prev = pItem; //4 curpos의 prev를 pItem으로.
					this->m_nLength++;

					return;

				}
				else if (item == itor.m_pCurPointer->data)
					return;
				else // item > itor.m_pCurPointer->data
				{
					itor.Next();
					continue;
				}
			}
			else //input 값이 모든 list 값들보다 크다고 나오면
			{
				DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
				pItem->data = item;
				/*pItem->prev = this->m_pFirst;
				pItem->next = this->m_pLast;*/

				itor.m_pCurPointer->prev->next = pItem; //1 curpos 전의 node의 next를 pItem으로.
				pItem->prev = itor.m_pCurPointer->prev; //2 pItem의 prev를 curpos의 prev로.
				pItem->next = itor.m_pCurPointer; //3 pItem의 next를 curpos로.
				itor.m_pCurPointer->prev = pItem; //4 curpos의 prev를 pItem으로.
				this->m_nLength++;

				return;
			}
			return;
		}
	}
}

template<class T>
inline int DoublySortedLinkedList<T>::Delete(T item)
{
	DoublyIterator<T> itor(*this);

	itor.Next();
	while (itor.NextNotNull())
	{
		if (item == itor.m_pCurPointer->data)
		{
			DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
			pItem = itor.m_pCurPointer;
			//if (itor.m_pCurPointer->data == m_pFirst->next->data)
			//{
			itor.Next(); //다음 node로 이동해서 2번째 전 값이랑 이어주기.
			itor.m_pCurPointer->prev = itor.m_pCurPointer->prev->prev; //1
			itor.m_pCurPointer->prev->next = itor.m_pCurPointer; //2

			delete pItem;
			this->m_nLength--;
			return 1;
			//}
			
		}
		else //일치 하지 않으면
		{
			itor.Next();
		}
	}
	return 0;
}

template<class T>
inline void DoublySortedLinkedList<T>::Replace(T item)
{
	DoublyIterator<T> itor(*this);

	itor.Next();
	while (itor.NextNotNull())
		//true = 아직 값이 있는 node 가르키는중.
		//false = m_pLast 도착했다는 의미니까 끝내야함.
	{
		if (item == itor.m_pCurPointer->data)
		{
			itor.m_pCurPointer->data = item;
			return;
		}
		else
		{
			itor.Next();
		}
	}
	return;
}

template<class T>
inline int DoublySortedLinkedList<T>::Get(T& item)
{
	DoublyIterator<T> itor(*this);

	itor.Next(); //첫번째 값 가르킴
	while (itor.NextNotNull())
	{
		if (item == itor.m_pCurPointer->data)
		{
			item = itor.m_pCurPointer->data;
			return 1;
		}
		else
		{
			itor.Next();
		}
	}
	return 0;
}
