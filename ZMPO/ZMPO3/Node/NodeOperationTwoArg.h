#pragma once
#include "Node.h"
#include "CharInterface.h"

class NodeOperationTwoArg : public Node
{
	friend class Tree; 
public:
	NodeOperationTwoArg(string sExpression);
	~NodeOperationTwoArg();
	double* pdGetValue();
	string sGetNeutralValueForOperation();
private:
	void vSetLeftNode(Node* poNode);
	void vSetRightNode(Node* poNode);
};
