#pragma once
#include "DoublySortedLinkedList.h"

template<class T>
class DoublySortedLinkedList;

template<class T>
struct DoublyNodeType;

template<class T>
class DoublyIterator
{
	friend class DoublySortedLinkedList<T>;
public:
	DoublyIterator(const DoublySortedLinkedList<T>& list) : m_List(list), m_pCurPointer(list.m_pFirst)
	{};

	bool NotNull(); // list의 현재 원소가 Null이 아닌지 검사
	bool NextNotNull(); // list의 다음 원소가 Null이 아닌지 검사
	T First(); // list의 처음 node의 item을 리턴
	T Next(); // 다음 node로 이동하고 해당 node의 item을 리턴
	DoublyNodeType<T> GetCurrentNode(); // 현재 node를 리턴

	//추가 함수
	void ResetList();
private:
	const DoublySortedLinkedList<T>& m_List; // 사용할 리스트의 참조 변수
	DoublyNodeType<T>* m_pCurPointer; // Iterator 변수
};

template<class T>
inline bool DoublyIterator<T>::NotNull()
{
	if (this->m_pCurPointer == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
inline bool DoublyIterator<T>::NextNotNull()
{
	if (this->m_pCurPointer->next == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
inline T DoublyIterator<T>::First()
{
	return this->m_List.m_pFirst;
}

template<class T>
inline T DoublyIterator<T>::Next()
{
	this->m_pCurPointer = this->m_pCurPointer->next;
	return this->m_pCurPointer->data;
}

template<class T>
inline DoublyNodeType<T> DoublyIterator<T>::GetCurrentNode()
{
	return* this->m_pCurPointer;
}

template<class T>
inline void DoublyIterator<T>::ResetList()
{
	this->m_pCurPointer = this->m_List.m_pFirst;
}
