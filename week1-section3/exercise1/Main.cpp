/*Exercise 1 - Input Validation
Write a program that will ask the user to enter a number between 1-10. Keep asking the same question until a valid input is given. Add an annoyed comment if they take more than a certain number of tries.
Hint: We haven’t seen anything about input validation, this is a good chance to look up something you don’t know by yourself. See where google takes you.
*/

#include <iostream>

int main()
{
	int number, iteration, actual;
	iteration = 0;

	std::cout << "Can you guess the number that I am thinking??\n++++++++++++++++++++++\n";
	actual = 5;//value to guess

	while ( iteration < 5 )
	{
		if (std::cin.fail() || std::cin.bad()) {
			std::cout << "Try again, no characters!! " << std::endl;;
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a number between 1 - 10: ";
			number = std::cin.peek();
		}
		
		std::cout << "\nPlease enter a number between 1 - 10: ";
		std::cin >> number;

			if (number == actual && (iteration < 3)) {
				std::cout << "Wow you guessed right, AWESOME!! ";
				break;
			}
			if ((number == actual) && (iteration >= 3))
			{
				std::cout << "FINALLY, I started to have my doubts about you";//annoying message
				break;
			}

			else {
				if (iteration == 4)
				{
					std::cout << "\nYou've lost your attempts. I'm sorry... LOSER!\n";//annoying message
				}
				//continue guessing
				iteration++;
				
			}
		
	}
}