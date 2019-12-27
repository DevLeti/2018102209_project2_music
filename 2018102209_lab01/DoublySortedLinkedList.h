#pragma once
#include "DoublyIterator.h"
#define maxsize 10 // �ִ� size

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
	bool IsEmpty();// ����Ʈ�� ����ִ��� Ȯ��
	bool IsFull(); // ����Ʈ�� ���� á���� Ȯ��
	void MakeEmpty(); // ����Ʈ�� ��� (initialize)
	int GetLength() const; // ����Ʈ�� �����ϰ� �ִ� item ���� ��ȯ
	void Add(T item); // ���ο� ���ڵ� �߰�
	int Delete(T item); // ���� ���ڵ� ����
	void Replace(T item); // ���� ���ڵ� ����
	int Get(T& item); // Primary key�� �������� �����͸� �˻��ϰ� �ش� �����͸� ������
		
private:
	DoublyNodeType<T>* m_pFirst; // ����Ʈ�� ó�� ��带 ����Ű�� ������
	DoublyNodeType<T>* m_pLast; // ����Ʈ�� ������ ��带 ����Ű�� ������
	int m_nLength; // ����Ʈ�� ����� ���ڵ� ��
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
	if (this->m_nLength == 0) // length�� 0�̸�
		return true; // true
	else //�ƴϸ�
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
		itor.Next();//���� ù ������ ������ �ű�.
		while (1)
		{
			if (itor.NextNotNull()) //m_pLast�� �����ϸ� false���ͼ� ���������� ����.
			{
				if (item < itor.m_pCurPointer->data)
				{
					DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
					pItem->data = item;
					/*pItem->prev = this->m_pFirst;
					pItem->next = this->m_pLast;*/

					itor.m_pCurPointer->prev->next = pItem; //1 curpos ���� node�� next�� pItem����.
					pItem->prev = itor.m_pCurPointer->prev; //2 pItem�� prev�� curpos�� prev��.
					pItem->next = itor.m_pCurPointer; //3 pItem�� next�� curpos��.
					itor.m_pCurPointer->prev = pItem; //4 curpos�� prev�� pItem����.
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
			else //input ���� ��� list ���麸�� ũ�ٰ� ������
			{
				DoublyNodeType<T>* pItem = new DoublyNodeType<T>;
				pItem->data = item;
				/*pItem->prev = this->m_pFirst;
				pItem->next = this->m_pLast;*/

				itor.m_pCurPointer->prev->next = pItem; //1 curpos ���� node�� next�� pItem����.
				pItem->prev = itor.m_pCurPointer->prev; //2 pItem�� prev�� curpos�� prev��.
				pItem->next = itor.m_pCurPointer; //3 pItem�� next�� curpos��.
				itor.m_pCurPointer->prev = pItem; //4 curpos�� prev�� pItem����.
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
			itor.Next(); //���� node�� �̵��ؼ� 2��° �� ���̶� �̾��ֱ�.
			itor.m_pCurPointer->prev = itor.m_pCurPointer->prev->prev; //1
			itor.m_pCurPointer->prev->next = itor.m_pCurPointer; //2

			delete pItem;
			this->m_nLength--;
			return 1;
			//}
			
		}
		else //��ġ ���� ������
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
		//true = ���� ���� �ִ� node ����Ű����.
		//false = m_pLast �����ߴٴ� �ǹ̴ϱ� ��������.
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

	itor.Next(); //ù��° �� ����Ŵ
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
