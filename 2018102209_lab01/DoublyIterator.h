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

	bool NotNull(); // list�� ���� ���Ұ� Null�� �ƴ��� �˻�
	bool NextNotNull(); // list�� ���� ���Ұ� Null�� �ƴ��� �˻�
	T First(); // list�� ó�� node�� item�� ����
	T Next(); // ���� node�� �̵��ϰ� �ش� node�� item�� ����
	DoublyNodeType<T> GetCurrentNode(); // ���� node�� ����

	//�߰� �Լ�
	void ResetList();
private:
	const DoublySortedLinkedList<T>& m_List; // ����� ����Ʈ�� ���� ����
	DoublyNodeType<T>* m_pCurPointer; // Iterator ����
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
