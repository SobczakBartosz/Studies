#pragma once
#include <string>

using namespace std;

class Node
{
	friend class Tree;

public:
	virtual double* pdGetValue() = 0;

protected:
	string sExpression;
	Node* poLeft;
	Node* poRight;
};
