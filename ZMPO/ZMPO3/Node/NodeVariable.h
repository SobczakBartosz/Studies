#pragma once
#include "Node.h"

class NodeVariable : public Node
{
	friend class Tree;
public:
	NodeVariable(string sExpression);
	~NodeVariable();
	double*	 pdGetValue(); 
	
private:
	void	 vSetValue(double dNewValue);
	double* pdValue;
};
