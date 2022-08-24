/*Exercise 2 - Understanding Pointers
Create a program that will ask the user for an integer value. Assign the value to an integer
variable.
Then, create an int* variable and assign it to the memory address of the integer variable.
Ask the user to enter a new value for the variable. Then, using only the pointer variable, change
the value of the integer variable to the new value.
Print the resulting value of variable a.*/

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
