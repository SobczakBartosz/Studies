#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <conio.h>
#include <vector>
#include <boost/foreach.hpp>

#include "Tree.h"
#include "CharInterface.h"

using namespace std;

enum eMenuOptions
{
	NEW_TREE = 1,
	PRINT_VARIABLES = 2,
	SET_RANDOM_VARIABLE = 3,
	SET_ALL_VARIABLES = 4,
	PRINT_TREE_RESULT = 5,
	PRINT_POSTFIX = 6,
	PRINT_INFIX = 7,
	PRINT_LEAFS = 8,
	END_OF_PROGRAME = 9
};

class UserInterface 
{
public:
	UserInterface();
	~UserInterface();
	void vRun();

private:
	Tree* poTree;

	void			vDisplayMenu();
	void			vCreateNewTree();
	void			vPrintVariables();
	void			vSetRandomVariable();
	void			vSetAllVariables();
	void			vPrintTreeResult();
	void			vPrintPostfix();
	void			vPrintInfix();
	void			vPrintLeafs();

	vector<string>	slistGetExpressionVector(bool &bIsCorrect);
	int				iGetUserIntegerInput();
	double			dGetUserDoubleInput(bool &bIsCorrect);
};
