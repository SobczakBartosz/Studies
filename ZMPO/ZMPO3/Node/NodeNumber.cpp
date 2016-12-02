#include "NodeNumber.h"

NodeNumber::NodeNumber(string sExpression)
{
	this->sExpression = sExpression;
	pdValue = new double();
	*pdValue = stod(sExpression);
	this->poLeft = NULL;
	this->poRight = NULL;
}

NodeNumber::~NodeNumber()
{

}

double* NodeNumber::pdGetValue()
{
	return this->pdValue;
}