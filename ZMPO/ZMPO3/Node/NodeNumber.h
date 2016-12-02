#pragma once
#include "Node.h"

class NodeNumber : public Node
{
public:
	NodeNumber(string sExpression);
	~NodeNumber();
	double* pdGetValue();

private:
	double* pdValue;
};
