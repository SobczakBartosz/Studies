#pragma once

#include "TempDoubleLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

enum eMenuOptions
{
	ADD_TO_INDEX	= 1,
	ADD_TO_BEGIN	= 2,
	ADD_TO_END		= 3,
	PRINT			= 4,
	PRINT_ELEMENT	= 5,
	PRINT_INDEX		= 6,
	DELETE_TO_INDEX = 7,
	DELETE_TO_BEGIN = 8,
	DELETE_TO_END	= 9,
	PRINT_LENGTH	= 10,
	CONCENCRATE		= 11,
	END_OF_INTERFACE = 12
};

template <typename T>
class UserInterface {
public:
	UserInterface()
	{
		pTList = new TempDoubleLinkedList<T>();
	}

	void vRun()
	{
		vDisplayMenu();
		int eMenuOption = 0;

		while (eMenuOption != END_OF_INTERFACE)
		{
			cout << endl << "Wybierz opcje: ";
			eMenuOption = iGetUserIntegerInput();

			switch (eMenuOption)
			{

			case ADD_TO_INDEX:
			{
				vAddToIndex();
			}break;

			case ADD_TO_BEGIN:
			{
				vAddToBegin();
			}break;

			case ADD_TO_END:
			{
				vAddToEnd();
			}break;

			case PRINT:
			{
				vPrintList();
			}break;

			case PRINT_ELEMENT:
			{
				vPrintElement();
			}break;

			case PRINT_INDEX:
			{
				vPrintIndex();
			}break;

			case DELETE_TO_INDEX:
			{
				vDeleteToIndex();
			}break;

			case DELETE_TO_BEGIN:
			{
				vDeleteToBegin();
			}break;

			case DELETE_TO_END:
			{
				vDeleteToEnd();
			}break;

			case PRINT_LENGTH:
			{
				vPrintLength();
			}break;

			case CONCENCRATE:
			{
				vConcencrete();
			}break;

			case END_OF_INTERFACE:
			{

			}break;

			default:
			{
				cout << "Wprowadzono bledny numer opcji!" << endl;
			}break;
			}
			cout << endl;
		}
	}

	~UserInterface()
	{
		delete pTList;
	}

private:
	TempDoubleLinkedList<T>* pTList;

	void	vDisplayMenu()
	{
		cout << "Menu:" << endl;
		cout << "1. Dodaj element do listy na wybranym indeksie" << endl;
		cout << "2. Dodaj element do poczatku listy" << endl;
		cout << "3. Dodaj element do konca listy" << endl;
		cout << "4. Wydrukuj liste" << endl;
		cout << "5. Wydrukuj wybrany element" << endl;
		cout << "6. Wydrukuj indeks wybranego elementu" << endl;
		cout << "7. Usun element na wybranym indeksie" << endl;
		cout << "8. Usun element na poczatku listy" << endl;
		cout << "9. Usun element na koncu listy" << endl;
		cout << "10. Wydrukuj ilosc elementow" << endl;
		cout << "11. Usun powtorzenia elementow znajdujacych sie obok siebie" << endl;
		cout << "12. Zmien typ listy/zakoncz program" << endl;
	}
	
	void	vAddToIndex()
	{
		T TNewValue;
		int iIndex;
		bool bIndexCorrect = false;
		
		cout << "Wprowadz wartosc nowego elementu: ";
		TNewValue = TGetUserInput(bIndexCorrect);

		cout << "Wprowadz indeks na ktory chcesz wstawic nowy element: ";
		iIndex = iGetUserIntegerInput();

		if (bIndexCorrect && (*pTList).bInsertToIndex(TNewValue, iIndex))
		{
			cout << "Dodawanie powiodlo sie";
		}else
			cout << "Wprowadzono bledne dane!";
	}

	void	vAddToBegin()
	{
		T TNewValue;
		bool bIndexCorrect = false;

		cout << "Wprowadz wartosc nowego elementu: ";
		TNewValue = TGetUserInput(bIndexCorrect);

		if (bIndexCorrect)
		{
			(*pTList).vInsertToBegin(TNewValue);
			cout << "Dodawanie powiodlo sie";
		}
		else
			cout << "Wprowadzono bledne dane!";
	}

	void	vAddToEnd()
	{
		T TNewValue;
		bool bIndexCorrect = false;

		cout << "Wprowadz wartosc nowego elementu: ";
		TNewValue = TGetUserInput(bIndexCorrect);

		if (bIndexCorrect)
		{
			(*pTList).vInsertToEnd(TNewValue);
			cout << "Dodawanie powiodlo sie";
		}
		else
			cout << "Wprowadzono bledne dane!";
	}

	void	vPrintList()
	{
		for(int i = 0; i < (*pTList).iGetLength(); i++)
			cout << (*pTList).TGetElement(i) << " " ;
	}

	void	vPrintElement()
	{
		int iIndex;

		cout << "Wprowadz indeks elementu ktory chcesz pobrac: ";
		iIndex = iGetUserIntegerInput();

		if (bIsObjectAtListIndex(iIndex))
		{
			cout << "Elementu na pozycji: " << iIndex << " to: " << (*pTList).TGetElement(iIndex);
		}
		else
			cout << "Brak elementu na wskazanym indeksie w liscie";
	}

	void	vPrintIndex()
	{
		T TElementValue;
		bool bIndexCorrect = false;

		cout << "Wprowadz wartosc elementu ktorego chcesz poznac indeks: ";
		TElementValue = TGetUserInput(bIndexCorrect);

		if (bIndexCorrect)
		{
			int iSearchedIndex = (*pTList).iGetIndex(TElementValue);
			if(iSearchedIndex != -1)
				cout << "Indeks elementu: " << TElementValue << " to: " << iSearchedIndex;
			else
				cout << "Brak elementu w liscie";
		}
		else
			cout << "Wprowadzono bledne dane!";
	}
	
	void	vDeleteToIndex()
	{
		int iIndex;
		bool bIndexCorrect = false;

		cout << "Wprowadz indeks z ktorego chcesz usunac element: ";
		iIndex = iGetUserIntegerInput();

		if ((*pTList).bRemoveToIndex(iIndex))
		{
			cout << "Usunieto element";
		}
		else
			cout << "Usuwanie nie powiodlo sie!";
	}

	void	vDeleteToBegin()
	{
		if ((*pTList).bRemoveToBegin())
		{
			cout << "Usunieto element";
		}
		else
			cout << "Usuwanie nie powiodlo sie!";
	}

	void	vDeleteToEnd()
	{
		if ((*pTList).bRemoveToEnd())
		{
			cout << "Usunieto element";
		}
		else
			cout << "Usuwanie nie powiodlo sie!";
	}

	void	vPrintLength()
	{
		cout << (*pTList).iGetLength() << endl;
	}
	
	void	vConcencrete()
	{
		if (typeid(int) == typeid((*pTList).TGetElement(0)))
			(*pTList).vConcentrate();
		else
			cout << "not int";
	}

	int		iGetUserIntegerInput()
	{
		int iUserInput;
	
		if (!(cin >> iUserInput))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return -1;
		}
		else
			return iUserInput;
	} //return -1 when userInput is not a number

	T		TGetUserInput(bool &bIsCorrect)
	{
		T TUserInput;

		if (!(cin >> TUserInput))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			bIsCorrect = false;
		}
		else
			bIsCorrect = true;
		
		return TUserInput;
	}

	bool	bIsObjectAtListIndex(int iIndex)
	{
		return (iIndex >= 0 && iIndex < (*pTList).iGetLength());
	}
};

