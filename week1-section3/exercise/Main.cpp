/*Exercise 7 - Lottery
Write a program that will simulate the lottery. Create two arrays of 5 integers. The first array should be populated with 5 random numbers from 1-20. For the second array, ask the user to input 5 numbers from 1-20. Make sure to handle invalid input and make sure numbers are not repeated.

For each number that is matched in the same index, give the user $10.
*/
#include <iostream>

#include <cstdlib>


int main()
{
	

	std::cout << "Welcome to the lottery!" << std::endl;
	
	int arrayInput[5];
	
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
		
		arrayRandom[i] = 1+ rand() % 20;
		

		std::cout << arrayRandom[i] << ", ";
	}


	int prize = 0;
	std::cout << "\n\ntus datos fueron: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << arrayInput[i] << ", ";
		if (arrayRandom[i] == arrayInput[i])
		{
			prize+10;
		}
	}
	std::cout << "\nYou winnings!!: $" << prize;
}