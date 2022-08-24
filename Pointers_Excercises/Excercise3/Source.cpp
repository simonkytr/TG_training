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