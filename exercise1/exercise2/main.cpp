//Exercise 2 - Data Type Sizes
//Write a program that will output the size of the different data types in c++.
//Hint: You can add an indent in your output by using the \t escape character.

#include <iostream>



int main()
{
	std::cout << "Type data -- Data Size" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << " char -- " << sizeof(char) << std::endl;
	std::cout << " int -- " << sizeof(int) << std::endl;
	std::cout << " short -- " << sizeof(short) << std::endl;
	std::cout << " float -- " << sizeof(float) << std::endl;
	std::cout << " boolean -- " << sizeof(bool) << std::endl;
	std::cout << " double -- " << sizeof(double) << std::endl;
	std::cout << " long -- " << sizeof(long) << std::endl;

	std::cin.get();
}

