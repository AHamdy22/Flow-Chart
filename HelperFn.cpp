
#include "HelperFn.h"

bool IsValue(string input)
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

bool IsVariable(string input)
{
	// checks if the input string is a variable name
	// return true if it can be a variable name, false otherwise

	//testing if variable name is a keyword
	if (
		input == "alignas" || input == "alignof" || input == "and" || input == "and_eq" ||
		input == "asm" || input == "auto" || input == "bitand" || input == "bitor" ||
		input == "bool" || input == "break" || input == "case" || input == "catch" ||
		input == "char" || input == "char16_t" || input == "char32_t" || input == "class" ||
		input == "compl" || input == "const" || input == "constexpr" ||
		input == "const_cast" || input == "continue" || input == "decltype" ||
		input == "default" || input == "delete" || input == "do" || input == "double" ||
		input == "dynamic_cast" || input == "else" || input == "enum" ||
		input == "explicit" || input == "export" || input == "extern" || input == "false" ||
		input == "float" || input == "for" || input == "friend" || input == "goto" ||
		input == "if" || input == "inline" || input == "int" || input == "long" ||
		input == "mutable" || input == "namespace" || input == "new" || input == "noexcept" ||
		input == "not" || input == "not_eq" || input == "nullptr" || input == "operator" ||
		input == "or" || input == "or_eq" || input == "private" || input == "protected" ||
		input == "public" || input == "register" || input == "reinterpret_cast" ||
		input == "return" || input == "short" || input == "signed" || input == "sizeof" ||
		input == "static" || input == "static_assert" || input == "static_cast" ||
		input == "struct" || input == "switch" || input == "template" || input == "this" ||
		input == "throw" || input == "true" || input == "try" || input == "typedef" ||
		input == "typeid" || input == "typename" || input == "union" || input == "unsigned" ||
		input == "using" || input == "virtual" || input == "void" || input == "volatile" ||
		input == "wchar_t" || input == "while" || input == "xor" || input == "xor_eq"
		)
	{
		return false;
	}
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

OpType ValueORVariable(string input)
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
