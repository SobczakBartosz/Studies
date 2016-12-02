#ifndef CTABLE_H
#define CTABLE_H

#include <string>

using namespace std;

#define DEFAULT_NAME "Domyslna nazwa"
#define DEFAULT_SIZE 10

class CTable
{
public:
	CTable();
	CTable(string sName);
	CTable(CTable &pcOther);
	~CTable();
	void    vSetName(string sName);
	void    vSetTableLength(int iNewTableLength);
	bool    bSetCellValue(int iCellIndex, int iNewCellValue);
	int     iGetCellValue(int iCellIndex, bool bIsCorrect);
	void	vRemoveCellValue(int iCellIndex);
	bool	bContains(int iCellValue);
	int*	piCloneTable(CTable &pcOther);
	string  sToString();
	CTable* operator =(CTable &pcOther);
	CTable* operator +(CTable &pcOther);
	CTable* operator -(CTable &pcOther);
	CTable* operator *(CTable &pcOther);

private:
	string sName;
	int * piTable = NULL;
	int iTableLength = 0;
};
#endif // CTABLE_H