/*
Exercise 8 - Easier Lottery
Rewrite the previous lottery but now instead of getting $10 for each number matched in the exact same index, give the user $10 for any number that matches anywhere in the sequence.
*/
#include <iostream>

#include <cstdlib>


int main()
{

	std::cout << "Welcome to the lottery!" << std::endl;

	int arrayInput[5];
	int input;
	int prize = 0;

	for (int i = 0; i < 5; i++)
	{

		std::cout << "Please enter entry a number between (1-20): ";
		std::cin >> arrayInput[i];	

	}


	//random array
	std::cout << "Lottery results: ";
	int arrayRandom[5];
	for (int i = 0; i < 5; i++)
	{
		/* initialize random seed: */

		arrayRandom[i] = 1 + rand() % 20;
		for (int j = 0; j < 5; j++)
		{
			if (arrayInput[i] == arrayRandom[j]) prize+10;
		}

		std::cout << arrayRandom[i] << ", ";


	}

	std::cout << "\nYou winnings!!: $" << prize;
}