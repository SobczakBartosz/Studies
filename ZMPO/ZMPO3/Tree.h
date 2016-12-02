#pragma once
#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include "Node.h"
#include "NodeNumber.h"
#include "NodeVariable.h"
#include "NodeOperationOneArg.h"
#include "NodeOperationTwoArg.h"
#include "CharInterface.h"

using namespace std;

class Tree
{
public:
	Tree();
	~Tree();
	void vAddNodes(vector<string> &slistExpressionVector, string &sErrorInfo);
	set<string> slistGetVariableSet();
	void		vSetVariableValue(string sVariableName, double dVariableNewValue);

	double			dGetValue(bool &bAreVariablesAssigned);
	string			sGetPostfixForm();
	string			sGetInfixForm();
	vector<string>	slistGetLeafs();

private:
	Node* poRoot;
	vector<string> slistExpressionVector;
	set<string> slistVariableSet;

	void			vClear(Node* poNode);
	Node*			poAddNode(string &sExpression, string &sErrorInfo, bool &bIsCreated);
	void			vSetVariableValue(string sVariableName, double dVariableNewValue, Node* poNode);
	string			sGetPostfixForm(Node* poSubtree);
	string			sGetInfixForm(Node* poSubtree);
	vector<string>	slistGetLeafs(Node* poSubtree);
	string			sRemoveLastElementFromExpressionVector();
};
