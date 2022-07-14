#include <iostream>
//Diego Guerrero
//Exercise 3 - Integral Limits
//Write a program that will output the upperand lower limits of integral types.
//Hint: Use #include <climits> to have access to macros that will output these limits.

#include <climits>

void Message(const char* a, int b, int c)
{
	//tabla items
	std::cout << a << "\t\t\t " << b << "\t\t\t  " << c << std::endl;
}


int main()
{
	std::cout << "Tabla of integral data type lower and uppr limits in c++" << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;

	std::cout << "Data Type  \t   ----  \tLower Limit \t ----  \tUpper Limit" << std::endl;

	std::cout << "---------------------------------------------------" << std::endl;


	Message("signed char", SCHAR_MIN, SCHAR_MAX);
	Message("unigned char", -UCHAR_MAX / 2, UCHAR_MAX / 2);
	Message("char", CHAR_MIN, CHAR_MAX);
	Message("short", SHRT_MIN, SHRT_MAX);
	Message("Usigned short", -USHRT_MAX / 2, USHRT_MAX / 2);
	Message("int", INT_MIN, INT_MAX);
	Message("Usigned Int", UINT_MAX / 2, UINT_MAX / 2);
	Message("LONG", LONG_MIN, LONG_MAX);
	Message("Usigned Long", ULONG_MAX / 2, ULONG_MAX / 2);
	Message("Long Long", LLONG_MIN, LLONG_MAX);
	Message("U. Long Log", ULLONG_MAX / 2, ULLONG_MAX / 2);

	std::cout << "---------------------------------------------------" << std::endl;


	std::cin.get();
}