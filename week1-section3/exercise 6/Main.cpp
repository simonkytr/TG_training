/*Exercise 6 - Arrays improved!
Rewrite the previous exercise, but this time only exit the application if the user inputs the ENTER key or when they exceed the max amount of numbers.

If the user enters any invalid input, tell them that they’ve entered an invalid input and that they must enter a number.

If the user just hits ENTER when asked for a number, output the same information as the previous exercise. 

Hint: You’ll need to look up stuff here, too. How would you detect invalid input and an enter key press.
*/
#include<iostream>
#include<conio.h>


int main()
{

	int numbers[10];
	int sum = 0;
	int insert;
	int size=0;

	

	while (size<10)
	{

		std::cout << "insert any NUMBER, (If you want to finish push ENTER): ";
		//finish pushing enter
		if (std::cin.peek() == '\n')break;
		std::cin >> insert;
		if (std::cin.fail() || std::cin.bad()) {
			std::cout << "Try again, no characters!! " << std::endl;;
			std::cin.clear();
			
		}
		else {
			sum = sum + insert;
			numbers[size] = insert;
			size++;
		}

		std::cin.ignore(1000, '\n');

	}
	
	std::cout << "\ntotal number entered: " << size << std::endl;
	std::cout << "\nTotal sum of numbers entered: " << sum << std::endl;

	return 0;

}