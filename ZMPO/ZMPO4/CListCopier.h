#pragma once
#include <vector>
#include <iostream>

using namespace std;

class CListCopier
{
public:
	CListCopier();
	~CListCopier();
	void			vAddInt(int iNewInt);
	vector<int*>	listpiGetVector();
	void			operator =(CListCopier &pcOther);
	CListCopier	&	operator +(CListCopier &pcOther);

private:
	vector<int*> listpiVector;

};// CListCopier