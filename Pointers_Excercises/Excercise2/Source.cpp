#include <iostream>

int main()
{
	std::cout << "Please enter a value for variable a: ";
	int InputValue;
	std::cin >> InputValue;
	std::cout << "The value of variable a is now: " << InputValue << std::endl;

	int* InputValuePtr = &InputValue;

	std::cout << "\nPlease enter a value for variable a: ";
	std::cin >> *InputValuePtr;
	std::cout << "The value of variable a is now: " << InputValue << std::endl;

	std::cout << "\nFun fact: I didn’t have to touch a directly to change its value :)" << std::endl;
}