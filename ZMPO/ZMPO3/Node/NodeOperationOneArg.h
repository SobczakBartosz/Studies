#pragma once
#include "Node.h"

class NodeOperationOneArg : public Node
{
	friend class Tree;
public:
	NodeOperationOneArg(string sExpression);
	~NodeOperationOneArg();
	double*	pdGetValue();
	string sGetNeutralValueForOperation();
private:
	void	vSetRightNode(Node* poNode);
};
