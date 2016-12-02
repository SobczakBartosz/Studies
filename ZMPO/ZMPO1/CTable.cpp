#include "CTable.h"
#include <iostream>
#include <algorithm>

using namespace std;

CTable::CTable()
{
	iTableLength = DEFAULT_SIZE;
	piTable = new int[iTableLength];
	//for (int i = 0; i < iTableLength; i++)
	//	piTable[i] = 0;

	sName = DEFAULT_NAME;
	cout << "bezp: " << sName << endl;
}

CTable::CTable(string sName)
{
	iTableLength = DEFAULT_SIZE;
	piTable = new int[iTableLength];
	this->sName = sName;
	cout << "parametr: " << this->sName << endl;
}

CTable::CTable(CTable &pcOther)
{
	piTable = piCloneTable(pcOther);
	iTableLength = pcOther.iTableLength;

	sName = pcOther.sName + "_copy";
	cout << "kopiuj: " << sName << endl;
}

CTable::~CTable()
{
	cout << "usuwam: " << sName << endl;
	if (piTable != NULL)	
		delete[] piTable;
}

void CTable::vSetName(string sName)
{
	this->sName = sName;
}

void CTable::vSetTableLength(int iNewTableLength)
{
	int * piContainer = new int[iTableLength];
	for (int i = 0; i < iTableLength; i++)
		piContainer[i] = piTable[i];
	delete[] piTable;

	piTable = new int[iNewTableLength];
	for (int i = 0; i < min(iTableLength, iNewTableLength); i++)
		piTable[i] = piContainer[i];
	delete[] piContainer;

	iTableLength = iNewTableLength;
}

bool CTable::bSetCellValue(int iCellIndex, int iNewCellValue)
{
	if (iCellIndex >= iTableLength && iCellIndex < 0)
		return false;
	else
	{
		piTable[iCellIndex] = iNewCellValue;
		return true;
	}
}

int CTable::iGetCellValue(int iCellIndex, bool bIsCorrect)
{
	if (iCellIndex >= iTableLength && iCellIndex < 0)
		bIsCorrect = false;
	else
		bIsCorrect = true;

	if (bIsCorrect)
		return piTable[iCellIndex];
	else
		return 0;
}

void CTable::vRemoveCellValue(int iCellIndex)
{
	for (int i = iCellIndex; i < iTableLength-1; i++)
		bSetCellValue(i, iGetCellValue(i + 1, true));
	vSetTableLength(iTableLength - 1);
}

bool CTable::bContains(int iCellValue)
{
	bool bContains = false;
	for (int i = 0; i < iTableLength; i++)
		if (iGetCellValue(i, true) == iCellValue)
			bContains = true;
	return bContains;
}

int* CTable::piCloneTable(CTable &pcOther)
{
	int * piClone = new int[pcOther.iTableLength];

	for (int i = 0; i < pcOther.iTableLength; i++)
		piClone[i] = pcOther.piTable[i];

	return piClone;
}

string CTable::sToString()
{
	string sToString = sName + " len: " + to_string(iTableLength) + " values: ";
	for (int i = 0; i < iTableLength; i++)
		sToString += to_string(piTable[i]) + ", ";
	return sToString;
}

CTable* CTable::operator =(CTable &pcOther)
{
	return &pcOther;
}

CTable* CTable::operator +(CTable &pcOther)
{
	CTable * pcCTablesSum = new CTable((*this).sName + "+" + pcOther.sName);
	(*pcCTablesSum).vSetTableLength((*this).iTableLength + pcOther.iTableLength);

	for (int i = 0; i < (*this).iTableLength; i++)
		(*pcCTablesSum).bSetCellValue(i, (*this).iGetCellValue(i, true));

	for (int i = 0; i < pcOther.iTableLength; i++)
		(*pcCTablesSum).bSetCellValue((*this).iTableLength + i, pcOther.iGetCellValue(i, true));\
		
	return pcCTablesSum;
}

CTable* CTable::operator -(CTable &pcOther)
{
	CTable * pcCTablesDifference = new CTable((*this).sName + "-" + pcOther.sName);
	(*pcCTablesDifference).piTable = piCloneTable(*this);
	(*pcCTablesDifference).iTableLength = (*this).iTableLength;
			
	for(int i = (*pcCTablesDifference).iTableLength-1; i >= 0; i--)
		if (pcOther.bContains((*pcCTablesDifference).iGetCellValue(i, true)))
			(*pcCTablesDifference).vRemoveCellValue(i);
		

	return pcCTablesDifference;
}

CTable* CTable::operator *(CTable &pcOther)
{
	CTable * pcCTablesProduct = new CTable((*this).sName + "*" + pcOther.sName);
	(*pcCTablesProduct).piTable = piCloneTable(*this);
	(*pcCTablesProduct).iTableLength = (*this).iTableLength;

	for (int i = (*pcCTablesProduct).iTableLength - 1; i >= 0; i--)
		if (!pcOther.bContains((*pcCTablesProduct).iGetCellValue(i, true)))
			(*pcCTablesProduct).vRemoveCellValue(i);
			
	for(int i = (*pcCTablesProduct).iTableLength - 1; i >= 0; i--)
		for (int j = i-1; j >= 0 ; j--)
			if ((*pcCTablesProduct).iGetCellValue(i, true) == (*pcCTablesProduct).iGetCellValue(j, true))
				(*pcCTablesProduct).vRemoveCellValue(j);

	return pcCTablesProduct;
}
