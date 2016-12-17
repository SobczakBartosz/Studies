#pragma once
#include <iostream>

template <class T>    
class TempDoubleLinkedList             
{    
private:
	template <class T>
	class TempNode
	{
		friend class TempDoubleLinkedList<T>;
		
		TempNode(T TValue)
		{
			this->TValue = TValue;
			prev = NULL;
			next = NULL;
		}
		
		~TempNode()
		{
			//mo¿e to zmieniæ?
		}

	private:
		T TValue;
		TempNode<T>* prev;
		TempNode<T>* next;
	};
 
public:               
	TempDoubleLinkedList(void)
	{
		pTHead = NULL;
		iLength = 0;
	}

	~TempDoubleLinkedList(void)
	{
		while (pTHead != NULL)
			bRemoveToEnd();
	}

	bool bInsertToIndex(T TNewElement, int iInsertIndex)
	{
		if (iInsertIndex == 0)
			vInsertToBegin(TNewElement);
		else if (iInsertIndex == iLength)
			vInsertToEnd(TNewElement);
		else if (iInsertIndex > 0 && iInsertIndex < iLength)
		{
			TempNode<T>* pTNewNode = new TempNode<T>(TNewElement);
			TempNode<T>* pTCurrent = pTHead;
			int iCurrentIndex = 0;

			while (pTCurrent != NULL && iCurrentIndex != iInsertIndex)
			{
				pTCurrent = (*pTCurrent).next;
				iCurrentIndex++;
			}

			(*pTNewNode).prev = (*pTCurrent).prev;
			(*pTNewNode).next = pTCurrent;

			(*(*pTCurrent).prev).next = pTNewNode;
			(*pTCurrent).prev = pTNewNode;
			iLength++;
		}
		else
			return false;
		return true;
	}

	void vInsertToBegin(T TNewElement)
	{
		TempNode<T>* pTNewNode = new TempNode<T>(TNewElement);
		
		(*pTNewNode).prev = NULL;
		(*pTNewNode).next = pTHead;

		if (pTHead != NULL)
			(*pTHead).prev = pTNewNode;

		pTHead = pTNewNode;

		iLength++;
	}

	void vInsertToEnd(T TNewElement)
	{
		TempNode<T>* pTCurrent = pTHead;
		TempNode<T>* pTNewNode = new TempNode<T>(TNewElement);

		if (iLength == 0)
			vInsertToBegin(TNewElement);
		else
		{
			for (int i = 1; i < iLength; i++)
				pTCurrent = (*pTCurrent).next;

			(*pTNewNode).prev = pTCurrent;
			(*pTNewNode).next = NULL;

			(*pTCurrent).next = pTNewNode;
			iLength++;
		}
	}

	T TGetElement(int iSearchedIndex)
	{
			TempNode<T>* pTCurrent = pTHead;
			int iCurrentIndex = 0;

			while (pTCurrent != NULL && iCurrentIndex != iSearchedIndex)
			{
				pTCurrent = (*pTCurrent).next;
				iCurrentIndex++;
			}
			return (*pTCurrent).TValue;
	}

	int iGetIndex(T TSearchedElement)
	{
		TempNode<T>* pTCurrent = pTHead;
		int iIndex = 0;

		while (pTCurrent != NULL && (*pTCurrent).TValue != TSearchedElement)
		{
			pTCurrent = (*pTCurrent).next;
			iIndex++;
		}
		return iIndex == iLength ? -1 : iIndex;
	} //return -1 when list do not contain the specified element, return index of first element == TSearchedElement

	bool bRemoveToIndex(int iRemoveIndex)
	{
		if (iRemoveIndex == 0)
			return bRemoveToBegin();
		else if (iRemoveIndex == iLength-1)
			return bRemoveToEnd();
		else if (iRemoveIndex > 0 && iRemoveIndex < iLength-1)
		{
			TempNode<T>* pTCurrent = pTHead;
			int iCurrentIndex = 0;

			while (pTCurrent != NULL && iCurrentIndex != iRemoveIndex)
			{
				pTCurrent = (*pTCurrent).next;
				iCurrentIndex++;
			}

			(*(*pTCurrent).prev).next = (*pTCurrent).next;
			(*(*pTCurrent).next).prev = (*pTCurrent).prev;
			
			delete pTCurrent;
			iLength--;
		}
		else
			return false;
		return true;
	}

	bool bRemoveToBegin()
	{
		if (pTHead == NULL)
			return false;
		else if (iLength == 1)
			pTHead = NULL;
		else
		{
			TempNode<T>* pTRemoveNode = pTHead;
			pTHead = (*pTHead).next;

			delete pTRemoveNode;
		}
		iLength--;
		return true;
	}

	bool bRemoveToEnd()
	{
		cout << iLength << endl;
		if (pTHead == NULL)
			return false;
		else
		{
			TempNode<T>* pTRemoveNode = pTHead;

			if (iLength == 1)
				bRemoveToBegin();
			else
			{
				for (int i = 1; i < iLength; i++)
					pTRemoveNode = (*pTRemoveNode).next;

				(*(*pTRemoveNode).prev).next = NULL;
				delete pTRemoveNode;
				iLength--;
			}
		}
		return true;
	}

	int iGetLength()
	{
		return iLength;
	}

	void vConcentrate()
	{
		for (int i = 0; i < iLength; i++)
			for (int j = i+1; j < iLength; j++)
			{
				if (TGetElement(i) == TGetElement(j))
				{
					bRemoveToIndex(j);
					j--;
				}
			}
	}

private:
	TempNode<T>* pTHead;
	int iLength;
};


