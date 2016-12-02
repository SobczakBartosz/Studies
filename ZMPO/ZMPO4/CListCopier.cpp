#include "CListCopier.h"
void vDisplay(vector<int*> listpiVector);

CListCopier::CListCopier()
{

}

CListCopier::~CListCopier()
{
	for each(int* piInt in listpiVector)
		delete piInt;
	listpiVector.clear();
}

void CListCopier::vAddInt(int iNewInt)
{
	int* piInt = new int(iNewInt);
	listpiVector.push_back(piInt);
}
vector<int*> CListCopier::listpiGetVector()
{
	return listpiVector;
}

void CListCopier::operator =(CListCopier &pcOther)
{
	for each(int* piInt in pcOther.listpiVector)
	{
		int* piCopy = new int();
		*piCopy = *piInt;
		this->listpiVector.push_back(piCopy);
	}
}

CListCopier& CListCopier::operator +(CListCopier &pcOther)
{
	CListCopier* pcCListCopierSum = new CListCopier();

	for each(int* piInt in this->listpiVector)
	{
		int* piCopy = new int();
		*piCopy = *piInt;
		(*pcCListCopierSum).listpiVector.push_back(piCopy);
	}
			
	for each(int* piInt in pcOther.listpiVector)
	{
		int* piCopy = new int();
		*piCopy = *piInt;
		(*pcCListCopierSum).listpiVector.push_back(piCopy);
	}

	return (*pcCListCopierSum);
}



int main()
{
	CListCopier c_list_0, c_list_1, c_list_sum;

	c_list_0.vAddInt(0);
	c_list_0.vAddInt(1);
	c_list_0.vAddInt(2);
	c_list_0.vAddInt(3);

	c_list_1.vAddInt(5);
	c_list_1.vAddInt(6);
	c_list_1.vAddInt(7);

	c_list_sum = c_list_0 + c_list_1;

	
	cout << "c_list_0" << endl;
	vDisplay(c_list_0.listpiGetVector());
	cout << endl;

	cout << "c_list_1" << endl;
	vDisplay(c_list_1.listpiGetVector());
	cout << endl;

	cout << "c_list_sum" << endl;
	vDisplay(c_list_sum.listpiGetVector());
	cout << endl;
	
	int iWait;
	cin >> iWait;

	return 0;
}

void vDisplay(vector<int*> listpiVector)
{
	for each(int* piInt in listpiVector)
	{
		cout << *piInt << " ";
	}
}