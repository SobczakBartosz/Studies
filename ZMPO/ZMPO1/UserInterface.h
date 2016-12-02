#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "CTable.h"
#include <vector>
#include <iostream>

using namespace std;

enum eMenuOptions
{
	NEW_VECTOR = 1,
	SET_lENGTH = 2,
	DELETE = 3,
	DELETE_VECTOR = 4,
	SET_NAME = 5,
	ADD_CLONE_TO_VECTOR = 6,
	PRINT = 7,
	SET_CELL = 8,
	SUM = 9,
	DIFFERENCE = 10,
	PRODUCT = 11,
	DO_NOTHING = 12,
	END_OF_PROGRAME = 13
};
	
class UserInterface{
public:
	UserInterface();
	void vRun();
	~UserInterface();
	
private:
	vector <CTable*> pcCTables;

	void	vDisplayMenu();
	void	vCreateNewVector();
	void	vSetTableLength();
	void	vDeleteTable();
	void	vDeleteVector();
	void	vSetTableName();
	void	vAddClone();
	void	vPrintTable();
	void	vSetCellValue();
	void	vSumOfTables();
	void	vDiffereceOfTables();
	void	vProductOfTables();
	void	vDoNothing();
	void	vDoNothing(CTable cCTable);
	int		iGetUserIntegerInput();
	bool	bIsObjectAtVectorIndex(int iIndex);
};

#endif // USERINTERFACE_H