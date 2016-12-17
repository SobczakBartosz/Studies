#include <iostream>
#include "UserInterface.h"

using namespace std;

enum eListType
{
	INT				= 1,
	DOUBLE			= 2,
	FLOAT			= 3,
	CHAR			= 4,
	END_OF_PROGRAME = 5
};

void vDisplayMenu();
int	iGetUserIntegerInput();

int main()
{
	int eListType = 0;

	while (eListType != END_OF_PROGRAME)
	{
		vDisplayMenu();
		eListType = iGetUserIntegerInput();

		switch (eListType)
		{
		case INT:
		{
			UserInterface<int>* pUserInterface = new UserInterface<int>();
			(*pUserInterface).vRun();
			delete pUserInterface;
		}break;

		case DOUBLE:
		{
			UserInterface<double>* pUserInterface = new UserInterface<double>();
			(*pUserInterface).vRun();
			delete pUserInterface;
		}break;

		case FLOAT:
		{
			UserInterface<float>* pUserInterface = new UserInterface<float>();
			(*pUserInterface).vRun();
			delete pUserInterface;
		}break;

		case CHAR:
		{
			UserInterface<char>* pUserInterface = new UserInterface<char>();
			(*pUserInterface).vRun();
			delete pUserInterface;
		}break;

		case END_OF_PROGRAME:
		{
			
		}break;

		default:
		{
			cout << "Wprowadzono bledny numer opcji!" << endl;
		}break;
		}
		cout << endl;
	}

	return 0;
}

void	vDisplayMenu()
{
	cout << "Wpisz typ elementow na ktorym ma operowac lista:" << endl;
	cout << "1. int" << endl;
	cout << "2. double" << endl;
	cout << "3. float" << endl;
	cout << "4. char" << endl;
	cout << "5. Zakoncz program" << endl;
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