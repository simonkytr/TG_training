/*
Exercise 4 - More Multiples of 10
Rewrite the previous program, but this time loop just outputs the multiples of 10, no need to output the sum of the rest of the numbers.

This time you can only use one for loop and it should not loop more than 10 times.
*/

#include <iostream>

int main() {

	std::cout << "These are the multyples of 100" << std::endl;

	for (int i = 10; i <= 100; i+=10)
	{
		//give the multiples of 10

		std::cout << i << ", ";

	}
	
}