#include "UserInterface.h"

using namespace std;

UserInterface::UserInterface()
{

}

void UserInterface::vRun()
{
	vDisplayMenu();
	int eMenuOption = 0;

	while (eMenuOption != END_OF_PROGRAME)
	{
		cout << endl << "Wybierz opcje: ";
		eMenuOption = iGetUserIntegerInput();

		switch (eMenuOption)
		{
		case NEW_VECTOR:
		{
			vCreateNewVector();
		}break;

		case SET_lENGTH:
		{
			vSetTableLength();
		}break;

		case DELETE:
		{
			vDeleteTable();
		}break;

		case DELETE_VECTOR:
		{
			vDeleteVector();
		}break;

		case SET_NAME:
		{
			vSetTableName();
		}break;

		case ADD_CLONE_TO_VECTOR:
		{
			vAddClone();
		}break;

		case PRINT:
		{
			vPrintTable();
		}break;

		case SET_CELL:
		{
			vSetCellValue();
		}break;

		case SUM:
		{
			vSumOfTables();
		}break;

		case DIFFERENCE:
		{
			vDiffereceOfTables();
		}break;

		case PRODUCT:
		{
			vProductOfTables();
		}break;

		case DO_NOTHING:
		{
			vDoNothing();
		}break;

		case END_OF_PROGRAME:
		{

		}break;

		default:
		{
			cout << "Wprowadzono bledny numer opcji!" << endl;
		}break;
		}
		cout << endl << endl;
	}
}

UserInterface::~UserInterface()
{
	vDeleteVector();
}

void UserInterface::vDisplayMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Utworz nowe obiekty klasy CTable z domyslna nazwa" << endl;
	cout << "2. Zmien dlugosc tablicy dla wybranego z obiektow CTable" << endl;
	cout << "3. Skasuj wybrany obiektu typu CTable" << endl;
	cout << "4. Skasuj wszystkie obiekty typu CTable" << endl;
	cout << "5. Nadaj nowa nazwe dowolnemu z obiektow CTable" << endl;
	cout << "6. Sklonuj wybrany obiekt CTable i dodaj klona do puli obiektow klasy CTable" << endl;
	cout << "7. Wypisz na ekran wybrany obiekt CTable" << endl;
	cout << "8. Zmien wartosc wybranej komorki wybranego obiektu CTable" << endl;
	cout << "9. Dodaj sume 2 obiektow typu CTable do wektora" << endl;
	cout << "10. Dodaj roznice 2 obiektow typu CTable do wektora" << endl;
	cout << "11. Dodaj iloraz 2 obiektow typu CTable do wektora" << endl;
	cout << "12. Uzyj metody nic nie rob" << endl;
	cout << "13. Zakoncz program" << endl; 
}


void UserInterface::vCreateNewVector()
{
	int iCTablesNumber;

	cout << "Wprowadz ile obiektow chcesz utworzyc: " << endl;
	iCTablesNumber = iGetUserIntegerInput();

	if (iCTablesNumber > 0)
	{
		for (int i = 0; i < iCTablesNumber; i++)
		{
			CTable * tmp = new CTable();
			pcCTables.push_back(tmp);
		}
	} else
		cout << "Wprowadzono bledne dane!" << endl;
}

void UserInterface::vSetTableLength()
{
	int iCTableIndex, iNewTableLength;

	cout << "Wprowadz indeks obiektu ktory chcesz zmodyfikowac: ";
	iCTableIndex = iGetUserIntegerInput();
	cout << "Wprowadz nowa dlugosc tablicy: ";
	iNewTableLength = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex) && iNewTableLength >= 0)
		(*pcCTables[iCTableIndex]).vSetTableLength(iNewTableLength);
	else
		cout << "Wprowadzono bledne dane!" << endl;
}

void UserInterface::vDeleteTable()
{
	int iCTableIndex;

	cout << "wprowadz indeks obiektu ktory chcesz usunac: ";
	iCTableIndex = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex))
	{
		delete pcCTables[iCTableIndex];
		pcCTables.erase(pcCTables.begin() + iCTableIndex);
		cout << "usunieto obiekt z pozycji: " << iCTableIndex;
	} else
		cout << "nie usunieto obiektu, bledne dane";
}

void UserInterface::vDeleteVector()
{
	for each(CTable* pcCTable in pcCTables)
		delete pcCTable;
	pcCTables.clear();
}

void UserInterface::vSetTableName()
{
	int iCTableIndex;
	string iNewTableName;

	cout << "Wprowadz indeks obiektu ktory chcesz zmodyfikowac: ";
	iCTableIndex = iGetUserIntegerInput();
	cout << "Wprowadz nowa nazwe obiektu: ";
	cin >> iNewTableName;

	if (bIsObjectAtVectorIndex(iCTableIndex))
		(*pcCTables[iCTableIndex]).vSetName(iNewTableName);
	else
		cout << "Wprowadzono bledne dane!" << endl;
}

void UserInterface::vAddClone()
{
	int iCTablesNumber;

	cout << "Wprowadz index obiektu ktory chcesz sklonowac: ";
	iCTablesNumber = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTablesNumber))
	{
		CTable * cClone = new CTable((*pcCTables[iCTablesNumber]));	
		pcCTables.push_back(cClone);
	}
	else
		cout << "Wprowadzono bledne dane!" << endl;
}

void UserInterface::vPrintTable()
{
	int iCTableIndex;

	cout << "Wprowadz indeks obiektu ktory chcesz wydrukowac: ";
	iCTableIndex = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex))
		cout << (*pcCTables[iCTableIndex]).sToString();
	else
		cout << "Wprowadzono bledne dane!";
}

void UserInterface::vSetCellValue()
{
	int iCTableIndex, iCellIndex, iNewCellValue;

	cout << "Wprowadz indeks obiektu ktory chcesz zmodyfikowac: ";
	iCTableIndex = iGetUserIntegerInput();
	cout << "Wprowadz indeks komorki ktora chcesz zmodyfikowac: ";
	iCellIndex = iGetUserIntegerInput();
	cout << "Wprowadz nowa wartosc komorki: ";
	iNewCellValue = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex) && (*pcCTables[iCTableIndex]).bSetCellValue(iCellIndex, iNewCellValue))
		cout << endl;
	else
		cout << "Wprowadzono bledne dane!";
}

void UserInterface::vSumOfTables()
{
	int iCTableIndex1, iCTableIndex2;

	cout << "wprowadz indeksy obiektow ktore chcesz dodac: " << endl;
	cout << "Pierwszy indeks: ";
	iCTableIndex1 = iGetUserIntegerInput();
	cout << "Drugi indeks: ";
	iCTableIndex2 = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex1) && bIsObjectAtVectorIndex(iCTableIndex2))
	{
		CTable * pcCTablesSum = (*pcCTables[iCTableIndex1]) + (*pcCTables[iCTableIndex2]);
		pcCTables.push_back(pcCTablesSum);
	}
	else
		cout << "Wprowadzono bledne dane!";
}

void UserInterface::vDiffereceOfTables()
{
	int iCTableIndex1, iCTableIndex2;

	cout << "wprowadz indeksy obiektow ktore chcesz odjac: " << endl;
	cout << "Pierwszy indeks: ";
	iCTableIndex1 = iGetUserIntegerInput();
	cout << "Drugi indeks: ";
	iCTableIndex2 = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex1) && bIsObjectAtVectorIndex(iCTableIndex2))
	{
		CTable * pcCTablesDifference = (*pcCTables[iCTableIndex1]) - (*pcCTables[iCTableIndex2]);
		pcCTables.push_back(pcCTablesDifference);
	}
	else
		cout << "Wprowadzono bledne dane!";
}

void UserInterface::vProductOfTables()
{
	int iCTableIndex1, iCTableIndex2;

	cout << "wprowadz indeksy obiektow ktore chcesz pomnozyc: " << endl;
	cout << "Pierwszy indeks: ";
	iCTableIndex1 = iGetUserIntegerInput();
	cout << "Drugi indeks: ";
	iCTableIndex2 = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex1) && bIsObjectAtVectorIndex(iCTableIndex2))
	{
		CTable * pcCTablesProduct = (*pcCTables[iCTableIndex1]) * (*pcCTables[iCTableIndex2]);
		pcCTables.push_back(pcCTablesProduct);
	}
	else
		cout << "Wprowadzono bledne dane!";
}

void UserInterface::vDoNothing()
{
	int iCTableIndex;

	cout << "Wprowadz indeks obiektu z ktorym nie chcesz nic zrobic: ";
	iCTableIndex = iGetUserIntegerInput();

	if (bIsObjectAtVectorIndex(iCTableIndex))
		vDoNothing(*(pcCTables[iCTableIndex]));
	else
		cout << "Wprowadzono bledne dane!";
}

void UserInterface::vDoNothing(CTable cCTable)
{

}

int UserInterface::iGetUserIntegerInput()
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

bool UserInterface::bIsObjectAtVectorIndex(int iIndex)
{
	return (iIndex >= 0 && iIndex < pcCTables.size());
}

