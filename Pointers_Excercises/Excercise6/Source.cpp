#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */ 

int main()
{

	int Array[10];
	int* ArrayPtr = Array;

	std::cout << "I've looped through the following numbers :" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		ArrayPtr[i] = rand() % 100;
		std::cout << ArrayPtr[i] << " ";
	}

	std::cout << "\nI've looped through the following numbers (BACKWARDS) :" << std::endl;
	int Sum = 0;
	for (int i = 10; i > 0; i--)
	{
		std::cout << ArrayPtr[i - 1] << " ";
		Sum += ArrayPtr[i - 1];
	}
	std::cout << "\nThe sum of all those numbers is: " << Sum << std::endl;
}