#include "NodeOperationOneArg.h"

NodeOperationOneArg::NodeOperationOneArg(string sExpression)
{
	this->sExpression = sExpression;
	this->poLeft = NULL;
	this->poRight = NULL;
}

NodeOperationOneArg::~NodeOperationOneArg()
{

}

void NodeOperationOneArg::vSetRightNode(Node* poNode)
{
	this->poRight = poNode;
}

double* NodeOperationOneArg::pdGetValue()
{
	if (poRight == NULL)
		return NULL;

	double* pdValue = new double();
	*pdValue = *(*poRight).pdGetValue() *(-1);

	return pdValue;
}

string NodeOperationOneArg::sGetNeutralValueForOperation()
{
	string sNeutralValueForOperation = "0";
	return sNeutralValueForOperation;
}