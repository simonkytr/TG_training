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
	Message("unigned char", 0, UCHAR_MAX );
	Message("char", CHAR_MIN, CHAR_MAX);
	Message("short", SHRT_MIN, SHRT_MAX);
	Message("Usigned short", 0, USHRT_MAX );
	Message("int", INT_MIN, INT_MAX);
	Message("Usigned Int", 0, UINT_MAX );
	Message("LONG", LONG_MIN, LONG_MAX);
	Message("Usigned Long", 0, ULONG_MAX );
	Message("Long Long", LLONG_MIN, LLONG_MAX);
	Message("U. Long Log", 0, ULLONG_MAX);

	std::cout << "---------------------------------------------------" << std::endl;


	std::cin.get();
}
