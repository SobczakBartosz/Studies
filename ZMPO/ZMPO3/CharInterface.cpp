#include "CharInterface.h"

eCharTypes eGetCharType(char &cChar)
{
	if (bIsLetter(cChar))
		return LETTER;
	if (bIsDigit(cChar))
		return DIGIT;
	if (bIsOperatorOneArgument(cChar))
		return OPERATOR_ONE_ARGUMENT;
	if (bIsOperatorTwoArgument(cChar))
		return OPERATOR_TWO_ARGUMENT;
	if (cChar == ' ')
		return SPACE;
	return OTHER_CHAR;
}

bool bIsLetter(char &cChar)
{
	return (cChar >= 'a' && cChar <= 'z') || (cChar >= 'A' && cChar <= 'Z');
}

bool bIsDigit(char &cChar)
{
	return (cChar >= '0' && cChar <= '9');
}

bool bIsOperatorOneArgument(char &cChar)
{
	return cChar == '~';
}

bool bIsOperatorTwoArgument(char &cChar)
{
	return cChar == '+' || cChar == '-' || cChar == '*' || cChar == '/';
}


eOperationTypes eGetOperationType(char &cChar)
{
	if (bIsAddition(cChar))
		return ADDITION;
	if (bIsSubtraction(cChar))
		return SUBTRACTION;
	if (bIsMultiplication(cChar))
		return MULTIPLICATION;
	if (bIsDivision(cChar))
		return DIVISION;
	return OTHER_OPERATOR;
}

bool bIsAddition(char &cChar)
{
	return cChar == '+';
}

bool bIsSubtraction(char &cChar)
{
	return cChar == '-';
}

bool bIsMultiplication(char &cChar)
{
	return cChar == '*';
}

bool bIsDivision(char &cChar)
{
	return cChar == '/';
}