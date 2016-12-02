#include "UserInterface.h"
#include "CharInterface.h"

using namespace std;

UserInterface::UserInterface()
{
	poTree = NULL;
}

UserInterface::~UserInterface()
{
	if(poTree != NULL)
	delete poTree;
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
		case NEW_TREE:
		{
			vCreateNewTree();
		}break;

		case PRINT_VARIABLES:
		{
			vPrintVariables();
		}break;

		case SET_RANDOM_VARIABLE:
		{
			vSetRandomVariable();
		}break;

		case SET_ALL_VARIABLES:
		{
			vSetAllVariables();
		}break;

		case PRINT_TREE_RESULT:
		{
			vPrintTreeResult();
		}break;

		case PRINT_POSTFIX:
		{
			vPrintPostfix();
		}break;

		case PRINT_INFIX:
		{
			vPrintInfix();
		}break;

		case PRINT_LEAFS:
		{
			vPrintLeafs();
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
}

void UserInterface::vDisplayMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Wprowadz wyrazenie w postaci postfiksowej: " << endl;
	cout << "2. Wypisz zmienne znajdujace sie w wyrazeniu: " << endl;
	cout << "3. Przypisz wartosc do konkretnej zmiennej: " << endl;
	cout << "4. Przypisz wartosc do wszystkich zmiennych: " << endl;
	cout << "5. Oblicz wartosc wyrazenia: " << endl;
	cout << "6. Wypisz wyrazenie w postaci postfiksowej: " << endl;
	cout << "7. Wypisz wyrazenie w postaci infiksowej:" << endl;
	cout << "8. Wypisz liscie:" << endl;
	cout << "9. Zakoncz program" << endl;
}

void UserInterface::vCreateNewTree()
{
	string sErrorInfo;

	if (poTree != NULL)
		delete poTree;

	cout << "Wprowadz wyrazenie w postaci postfiksowej: " << endl;

	bool bIsCorrectInput = true;
	vector<string> slistExpressionVector = slistGetExpressionVector(bIsCorrectInput);

	if (bIsCorrectInput)
	{
		poTree = new Tree();
		(*poTree).vAddNodes(slistExpressionVector, sErrorInfo);

		if (sErrorInfo != "")
			cout << sErrorInfo << endl;
	}
	else
	{
		cout << "Bledne dane, znak: " << slistExpressionVector.back() << " nie jest dozwolony" << endl;
		slistExpressionVector.clear();
	}
}

void UserInterface::vPrintVariables()
{
	if (poTree != NULL)
	{
		cout << "Lista zmiennych: " << endl;

		set<string> slistVariableSet = (*poTree).slistGetVariableSet();
		BOOST_FOREACH(string sVariableName, slistVariableSet) 
			cout << sVariableName << endl;
	}
	else
		cout << "Brak drzewa" << endl;
}

void UserInterface::vSetRandomVariable()
{
	if (poTree != NULL)
	{
		string sVariableName;
		double dVariableNewValue;
		bool bIsIntValueCorrect;

		cout << "Wprowadz nazwe zmiennej: ";
		cin >> sVariableName;
		cout << "Wprowadz wartosc ktora chcesz przypisac zmiennej: ";
		dVariableNewValue = dGetUserDoubleInput(bIsIntValueCorrect);
		
		if (bIsIntValueCorrect)
		{
			set<string> slistVariableSet = (*poTree).slistGetVariableSet();

			if (slistVariableSet.find(sVariableName) != slistVariableSet.end())
				(*poTree).vSetVariableValue(sVariableName, dVariableNewValue);
			else
				cout << "Nie udalo sie przypisac danej wartosci do danej zmiennej" << endl;
		}
		else
			cout << "Wprowadzono bledna wartosc" << endl;
	}
	else
		cout << "Brak drzewa" << endl;
}

void UserInterface::vSetAllVariables()
{
	if (poTree != NULL)
	{
		double dVariableNewValue;
		bool bIsIntValueCorrect;

		set<string> slistVariableSet = (*poTree).slistGetVariableSet();
		BOOST_FOREACH(string sVariableName, slistVariableSet)
		{
			cout << "Wprowadz wartosc ktora chcesz przypisac zmiennej " << sVariableName << ":";
			dVariableNewValue = dGetUserDoubleInput(bIsIntValueCorrect);
			if (bIsIntValueCorrect)
			{
				(*poTree).vSetVariableValue(sVariableName, dVariableNewValue);
			}
			else
				cout << "Wprowadzono bledno wartosc dla zmiennej: " << sVariableName << endl;
		}
	}
	else
		cout << "Brak drzewa" << endl;
}

void UserInterface::vPrintTreeResult()
{
	if (poTree != NULL)
	{
		bool bAreVariablesAssigned;
		double dValue = (*poTree).dGetValue(bAreVariablesAssigned);
		
		if (bAreVariablesAssigned)
			cout << dValue << endl;
		else
			cout << "Nie wszystkie zmienne maja przypisane wartosci" << endl;
	}
	else
		cout << "Brak drzewa" << endl;
}

void UserInterface::vPrintPostfix()
{
	if (poTree != NULL)
	{
		cout << (*poTree).sGetPostfixForm() << endl;
	}
	else
		cout << "Brak drzewa" << endl;
}

void UserInterface::vPrintInfix()
{
	if (poTree != NULL)
	{
		cout << (*poTree).sGetInfixForm() << endl;
	}
	else
		cout << "Brak drzewa" << endl;
}

void UserInterface::vPrintLeafs()
{
	if (poTree != NULL)
	{
		vector<string>	slistLeafsVector = (*poTree).slistGetLeafs();
		while (!slistLeafsVector.empty())
		{
			cout << slistLeafsVector.front() << endl;
			slistLeafsVector.erase(slistLeafsVector.begin());
		}
	}
	else
		cout << "Brak drzewa" << endl;
}

vector<string> UserInterface::slistGetExpressionVector(bool &bIsCorrect)
{
	bIsCorrect = true;
	string sInput;
	vector<string> slistExpressionVector;
	
	cin.ignore();
	getline(cin, sInput);

	for (int i = 0; i < sInput.length() && bIsCorrect; i++)
	{
		string sVectorElement; 
		switch (eGetCharType(sInput[i]))
		{
			case LETTER:
				while (i < sInput.length() && eGetCharType(sInput[i]) == LETTER)
					sVectorElement += sInput[i++];
				i--;
				slistExpressionVector.push_back(sVectorElement);
				break;

			case DIGIT:
				while (i < sInput.length() && eGetCharType(sInput[i]) == DIGIT)
					sVectorElement += sInput[i++];
				i--;
				slistExpressionVector.push_back(sVectorElement);
				break;

			case OPERATOR_ONE_ARGUMENT:
				sVectorElement = sInput[i];
				slistExpressionVector.push_back(sVectorElement);
				break;

			case OPERATOR_TWO_ARGUMENT:
				sVectorElement = sInput[i];
				slistExpressionVector.push_back(sVectorElement);
				break;

			case SPACE:
				
				break;

			default: 
				bIsCorrect = false;
				slistExpressionVector.clear();
				sVectorElement = sInput[i];
				slistExpressionVector.push_back(sVectorElement); //vector will contain only one incorrect element
				break;
		}
	}
	return slistExpressionVector;
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

double UserInterface::dGetUserDoubleInput(bool &bIsCorrect)
{
	double dUserInput;

	if (!(cin >> dUserInput))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		bIsCorrect = false;
		return -1;
	}
	else
		bIsCorrect = true;
	return dUserInput;
} //return -1 when userInput is not a number