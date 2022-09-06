#include <iostream>

int ValidateInput(const int LowerBounce, const int HigherBounce)
{
	int UserInput;
	std::cin >> UserInput;

	while (std::cin.fail() && UserInput < LowerBounce && UserInput > HigherBounce)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid Option " << std::endl;
		std::cin >> UserInput;
	};
	return UserInput;
}

void Main()
{
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "\t Welcome to Shape calculator" << std::endl;
	std::cout << "-----------------------------------------\n" << std::endl;
	
	std::cout << "Please select a valid option to continue" << std::endl;
	std::cout << "1- Build-in array" << std::endl;
	std::cout << "2- Static array" << std::endl;
	std::cout << "3- Dinamic array" << std::endl;
	
	int UserInput = ValidateInput(1, 3);
}