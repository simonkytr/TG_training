/*Exercise 3 - Multiples of 10
Write a program that will output multiples of 10 between 1 and 100. Use a for-loop that goes through numbers 1-100.	

At the end of the program, output the sum of all the numbers that were NOT multiples of 10. Do NOT use an else statement for this program and do NOT use more than one loop.

*/
#include <iostream>

int main() {

	
	int sum=0;
	int multiples=0;
	std::cout << "These the multyples of 100" << std::endl;

	for (int i = 0; i <= 100; i++)
	{
		//give the multiples of 10

		if (i % 10 == 0) {
			std::cout << i << ", ";
			multiples = + i;
			continue;
		}
		sum += i;//sum of the rest of the numbers
	}
	std::cout << std::endl << "Sum of the rest of numbers: "<< sum;//difference between the rest of the numbers and the multiples of 10
	std::cin.get();
}