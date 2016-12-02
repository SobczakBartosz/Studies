#pragma once

enum eCharTypes
{
	LETTER					= 1,
	DIGIT					= 2,
	OPERATOR_ONE_ARGUMENT	= 3,
	OPERATOR_TWO_ARGUMENT	= 4,
	SPACE					= 5,
	OTHER_CHAR					= 6
};

enum eOperationTypes
{
	ADDITION				= 1,
	SUBTRACTION				= 2,
	MULTIPLICATION			= 3,
	DIVISION				= 4,
	OTHER_OPERATOR			= 5
};

eCharTypes		eGetCharType(char &cChar);
bool			bIsLetter(char &cChar);
bool			bIsDigit(char &cChar);
bool			bIsOperatorOneArgument(char &cChar);
bool			bIsOperatorTwoArgument(char &cChar);

eOperationTypes	eGetOperationType(char &cChar);
bool			bIsAddition(char &cChar);
bool			bIsSubtraction(char &cChar);
bool			bIsMultiplication(char &cChar);
bool			bIsDivision(char &cChar);