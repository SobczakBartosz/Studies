#include "NodeVariable.h"

NodeVariable::NodeVariable(string sExpression)
{
	this->sExpression = sExpression;
	this->pdValue = NULL;
	this->poLeft = NULL;
	this->poRight = NULL;
}

NodeVariable::~NodeVariable()
{

}

double* NodeVariable::pdGetValue()
{
	return pdValue;
}

void NodeVariable::vSetValue(double dNewValue)
{
	if (pdValue == NULL)
		pdValue = new double();
	*pdValue = dNewValue;
}