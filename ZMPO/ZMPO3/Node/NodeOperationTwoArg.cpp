#include "NodeOperationTwoArg.h"

NodeOperationTwoArg::NodeOperationTwoArg(string sExpression)
{
	this->sExpression = sExpression;
	this->poLeft = NULL;
	this->poRight = NULL;
}

NodeOperationTwoArg::~NodeOperationTwoArg()
{

}

void NodeOperationTwoArg::vSetLeftNode(Node* poNode)
{
	this->poLeft = poNode;
}

void NodeOperationTwoArg::vSetRightNode(Node* poNode)
{
	this->poRight = poNode;
}

double* NodeOperationTwoArg::pdGetValue()
{
	if (poLeft == NULL || poRight == NULL || (*poLeft).pdGetValue() == NULL || (*poRight).pdGetValue() == NULL)
		return NULL;
	
	double* pdValue = new double();

	switch (eGetOperationType(sExpression[0]))
	{
		case ADDITION:
			*pdValue = *(*poLeft).pdGetValue() + *(*poRight).pdGetValue();
			break;

		case SUBTRACTION:
			*pdValue = *(*poLeft).pdGetValue() - *(*poRight).pdGetValue();
			break;

		case MULTIPLICATION:
			*pdValue = *(*poLeft).pdGetValue() * *(*poRight).pdGetValue();
			break;

		case DIVISION:
			*pdValue = *(*poLeft).pdGetValue() / *(*poRight).pdGetValue();
			break;

		default:
			pdValue = NULL;
			break;
	}

	return pdValue;
}

string NodeOperationTwoArg::sGetNeutralValueForOperation()
{
	string sNeutralValueForOperation;

	switch (eGetOperationType(sExpression[0]))
	{
	case ADDITION:
		sNeutralValueForOperation = "0";
		break;

	case SUBTRACTION:
		sNeutralValueForOperation = "0";
		break;

	case MULTIPLICATION:
		sNeutralValueForOperation = "1";
		break;

	case DIVISION:
		sNeutralValueForOperation = "1";
		break;

	default:
		sNeutralValueForOperation = "";
		break;
	}
	return sNeutralValueForOperation;
}