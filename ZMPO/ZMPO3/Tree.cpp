#pragma once
#include "Tree.h"

Tree::Tree()
{
	poRoot = NULL;
}

Tree::~Tree()
{
	vClear(poRoot);
}

void Tree::vClear(Node* poNode)
{
	if (poNode != NULL)
	{
		vClear((*poNode).poLeft);
		vClear((*poNode).poRight);
		delete poNode;
	}
}

void Tree::vAddNodes(vector<string> &slistExpressionVector, string &sErrorInfo)
{
	this->slistExpressionVector = slistExpressionVector;

	for each(string sExpression in slistExpressionVector)
	{
		if (eGetCharType(sExpression[0]) == LETTER)
			slistVariableSet.insert(sExpression);
	}

	bool bIsCreated = true;
	poRoot = poAddNode(sRemoveLastElementFromExpressionVector(), sErrorInfo, bIsCreated);

	if (bIsCreated = false)
		sErrorInfo = "Nie udalo sie stworzyc drzewa \n";

	if (!this->slistExpressionVector.empty())
		sErrorInfo += "Nie udalo sie wczytac calego wyrazenia";
}

Node* Tree::poAddNode(string &sExpression, string &sErrorInfo, bool &bIsCreated)
{
	Node* poNewNode = NULL;
	bool bIsChildCreated;
	bIsCreated = true;
	

	switch (eGetCharType(sExpression[0]))
	{
	case LETTER:
		poNewNode = new NodeVariable(sExpression);
		break;

	case DIGIT:
		poNewNode = new NodeNumber(sExpression);
		break;

	case OPERATOR_ONE_ARGUMENT:
	{
		poNewNode = new NodeOperationOneArg(sExpression);
		NodeOperationOneArg* poNewNodeOperationOneArg = dynamic_cast <NodeOperationOneArg *>(poNewNode);

		(*poNewNodeOperationOneArg).vSetRightNode(poAddNode(sRemoveLastElementFromExpressionVector(), sErrorInfo, bIsChildCreated));
		if (bIsChildCreated == false)
		{
			sErrorInfo += "dla " + (*poNewNode).sExpression + "\n";
			(*poNewNodeOperationOneArg).vSetRightNode(poAddNode((*poNewNodeOperationOneArg).sGetNeutralValueForOperation(), sErrorInfo, bIsChildCreated));
		}
	}	break;

	case OPERATOR_TWO_ARGUMENT:
	{
		poNewNode = new NodeOperationTwoArg(sExpression);
		NodeOperationTwoArg* poNewNodeOperationTwoArg = dynamic_cast <NodeOperationTwoArg *>(poNewNode);

		(*poNewNodeOperationTwoArg).vSetRightNode(poAddNode(sRemoveLastElementFromExpressionVector(), sErrorInfo, bIsChildCreated));
		if (bIsChildCreated == false)
		{
			sErrorInfo += "prawego dla " + (*poNewNode).sExpression + "\n";
			(*poNewNodeOperationTwoArg).vSetRightNode(poAddNode((*poNewNodeOperationTwoArg).sGetNeutralValueForOperation(), sErrorInfo, bIsChildCreated));
		}

		(*poNewNodeOperationTwoArg).vSetLeftNode(poAddNode(sRemoveLastElementFromExpressionVector(), sErrorInfo, bIsChildCreated));
		if (bIsChildCreated == false)
		{
			sErrorInfo += "lewego dla " + (*poNewNode).sExpression + "\n";
			(*poNewNodeOperationTwoArg).vSetLeftNode(poAddNode((*poNewNodeOperationTwoArg).sGetNeutralValueForOperation(), sErrorInfo, bIsChildCreated));
		}
	}	break;

	default:
		sErrorInfo += "brak argumentu ";
		bIsCreated = false;
		break;
	}

	return poNewNode;
}

void Tree::vSetVariableValue(string sVariableName, double dVariableNewValue)
{
	vSetVariableValue(sVariableName, dVariableNewValue, poRoot);
}

void Tree::vSetVariableValue(string sVariableName, double dVariableNewValue, Node* poNode)
{
	if (poNode != NULL)
	{
		NodeVariable* poNodeVariable = dynamic_cast <NodeVariable*>(poNode);

		if (poNodeVariable != NULL && (*poNode).sExpression == sVariableName)
			(*poNodeVariable).vSetValue(dVariableNewValue);
			
		vSetVariableValue(sVariableName, dVariableNewValue, (*poNode).poLeft);
		vSetVariableValue(sVariableName, dVariableNewValue, (*poNode).poRight);
	}
}

double Tree::dGetValue(bool &bAreVariablesAssigned)
{ 
	if ((*poRoot).pdGetValue() == NULL)
	{
		bAreVariablesAssigned = false;
		return 0;
	}
	bAreVariablesAssigned = true;
	return *(*poRoot).pdGetValue();
}

set<string> Tree::slistGetVariableSet()
{
	return slistVariableSet;
}

string Tree::sGetPostfixForm()
{
	return sGetPostfixForm(poRoot);
}

string Tree::sGetPostfixForm(Node* poSubtree)
{
	string sPostfixForm;
	if (poSubtree != NULL)
	{
		sPostfixForm += " ";
		sPostfixForm += sGetPostfixForm((*poSubtree).poLeft);
		sPostfixForm += sGetPostfixForm((*poSubtree).poRight);
		sPostfixForm += (*poSubtree).sExpression;
	}
	return sPostfixForm;
}

string Tree::sGetInfixForm()
{
	return sGetInfixForm(poRoot);
}

string Tree::sGetInfixForm(Node* poSubtree)
{
	string sInfixForm;
	if (poSubtree != NULL)
	{
		sInfixForm += "(";
		sInfixForm += sGetInfixForm((*poSubtree).poLeft);
		sInfixForm += (*poSubtree).sExpression;
		sInfixForm += sGetInfixForm((*poSubtree).poRight);
		sInfixForm += ")";
	}
	return sInfixForm;
}

vector<string> Tree::slistGetLeafs()
{
	
	return slistGetLeafs(poRoot);
}

vector<string> Tree::slistGetLeafs(Node* poSubtree)
{
	vector<string> slistLeafsVector;
	if (poSubtree != NULL)
	{
		if ((*poSubtree).poLeft == NULL && (*poSubtree).poRight == NULL)
		{
			slistLeafsVector.push_back((*poSubtree).sExpression);
		}
		else
		{
			slistLeafsVector = slistGetLeafs((*poSubtree).poLeft);
			vector<string> slistSecondLeafsVector = slistGetLeafs((*poSubtree).poRight);

			string sLeafs = (*poSubtree).sExpression + "->";

			while (!slistSecondLeafsVector.empty())
			{
				slistLeafsVector.push_back(slistSecondLeafsVector.front());
				slistSecondLeafsVector.erase(slistSecondLeafsVector.begin());
			}

			vector<string> slistNewLeafsVector;
			while (!slistLeafsVector.empty())
			{
				string sLeafs = (*poSubtree).sExpression + "->";
				slistNewLeafsVector.push_back(sLeafs += slistLeafsVector.front());
				slistLeafsVector.erase(slistLeafsVector.begin());
			}
			slistLeafsVector = slistNewLeafsVector;
		}	
	}
	return slistLeafsVector;
}

string Tree::sRemoveLastElementFromExpressionVector()
{
	string sLastElement;
	
	if (!slistExpressionVector.empty())
	{
		sLastElement = slistExpressionVector.back();
		slistExpressionVector.pop_back();
	}
	else
		sLastElement = "";
	
	return sLastElement;
}
