#include <iostream>

int main()
{
	int Value = 15;
	int* ValuePtrA = &Value;
	int* ValuePtrB = &Value;

	std::cout << "The value of my variable is " << *ValuePtrA << std::endl;

	*ValuePtrA = 6;
	*ValuePtrB = 2;

	std::cout << "The value of my variable after the pointer stuff I did is " << Value << std::endl;
}