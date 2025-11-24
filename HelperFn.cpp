
#include "HelperFn.h"

bool IsValue (string input)
{
	// checks if the input string is a double value
	// return true if it's double value, false otherwise

	// Double values can be: 12.5, -12.5, -23, -23. , -23.0 …etc.

	//TODO: complete this function

	double D = 0;
	while (1)
	{
		stringstream ss(input);
		if (ss >> D)
		{
			char Remaining;
			if (!(ss >> Remaining))
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}

bool IsVariable (string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	if (isalpha(input[0]) || input[0] == '_')
	{
		for (int i = 1; i < input.size(); i++)
		{
			if (!(isalpha(input[i])) && !(isdigit(input[i])) && input[i] != '_')
				return false;
		}

		return true;
	}
	// Variable names must start with an alphabetic letter (small or capital) or an underscore (_). 
	// After the first initial letter, variable names can contain letters, numbers and underscores.  
	// No spaces or special characters, however, are allowed.

	//TODO: complete this function
	else
		return false;
}

OpType ValueORVariable (string input)
{
	if (IsValue(input))
		return VALUE_OP;
	else
		if (IsVariable(input))
			return VARIABLE_OP;
		else
			return INVALID_OP;
	// checks if the input string is a double value or a variable name
	// chand returns enum "OpType" (the enum is declared in the .h)

	//TODO: complete this function

	
}
