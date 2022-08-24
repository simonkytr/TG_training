#include<iostream>

int main()
{
	std::cout << "//////////////////////////////////////////" << std::endl;
	std::cout << "insert an integer value" << std::endl;
	int InputValue;
	std::cin >> InputValue;
	std::cout << "The value of your variable is: " << InputValue << std::endl;
	std::cout << "The memory address where your variable is stored is: " << &InputValue << std::endl;

	std::cout << "//////////////////////////////////////////" << std::endl;
	std::cout << "insert an integer value" << std::endl;
	int InputValue2;
	std::cin >> InputValue2;
	std::cout << "The value of your variable is: " << InputValue2 << std::endl;
	std::cout << "The memory address where your variable is stored is: " << &InputValue2 << std::endl;

	std::cout << "//////////////////////////////////////////" << std::endl;
	std::cout << "insert an integer value" << std::endl;
	int InputValue3;
	std::cin >> InputValue3;
	std::cout << "The value of your variable is: " << InputValue3 << std::endl;
	std::cout << "The memory address where your variable is stored is: " << &InputValue3 << std::endl;
}