/*Exercises
Exercise 1 - Understanding Memory Addresses
Create a program that will ask the user to enter an integer and assign the given value to a
variable. Then, print the value to the console, and print the memory address of that variable.
Then, ask for another value and assign that value to the same variable. Print the value and the
memory address to the console.
Finally, ask for one more value. This time, assign the value to a different variable. Print the
value and the memory address to the console. Do the results make sense to you?*/

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
	
	std::cin >> InputValue;
	std::cout << "The value of your variable is: " << InputValue << std::endl;
	std::cout << "The memory address where your variable is stored is: " << &InputValue << std::endl;

	std::cout << "//////////////////////////////////////////" << std::endl;
	std::cout << "insert an integer value" << std::endl;
	
	int InputValue2;
	std::cin >> InputValue2;
	std::cout << "The value of your variable is: " << InputValue2 << std::endl;
	std::cout << "The memory address where your variable is stored is: " << &InputValue2 << std::endl;
}
