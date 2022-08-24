/*Exercise 3 - Understanding Pointers 2

Create a program that will ask the user to enter two integers and assign the given values to two
separate integers.
Declare an int* variable and assign it to the memory address of the first integer. Now, using only
the pointer variable, print the value of the first integer and its memory address. Additionally, print
the value and the memory address of the pointer variable.
Then, assign the memory address of the second integer to the same pointer variable. Do the
same thing as before: using only the pointer variable, print the value of the integer, its memory
address, and the value and memory address of the pointer variable.
Do the results make sense to you?*/

#include <iostream>

int main()
{
	std::cout << "Please enter a value for variable a: ";
	int InputValueA;
	std::cin >> InputValueA;
	int* p = &InputValueA;

	std::cout << "Please enter a value for variable b: ";
	int InputValueB;
	std::cin >> InputValueB;
	

	std::cout << std::endl;

	std::cout << "Using pointer variable p, I've determined that: " << std::endl;
	std::cout << "The value of a is " << InputValueA << std::endl;
	std::cout << "The memory address of variable a is " << &InputValueA << std::endl;
	std::cout << "The value of variable p " << p << std::endl;
	std::cout << "The memory address of variable p " << &p << std::endl;

	std::cout << std::endl;

	p = &InputValueB;

	std::cout << "Using pointer variable p, I've determined that: " << std::endl;
	std::cout << "The value of b is " << InputValueB << std::endl;
	std::cout << "The memory address of variable a is " << &InputValueB << std::endl;
	std::cout << "The value of variable b " << p << std::endl;
	std::cout << "The memory address of variable p " << &p << std::endl;

}
