/*Exercise 6 - Pointer Arithmetic
Pointer arithmetic allows you to perform arithmetic operations on pointer types.
Create a program where you declare an array of 10 integers. Then, declare an int pointer and
initialize it to the array.

Loop through all of the elements in the array and initialize each entry in the array with a random
integer. You must use ONLY the pointer to loop through the array. Print each number to the
console.
Then, loop through the array BACKWARDS to get the sum of all the elements. Print the sum to
the console.
*/

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */ 

int main()
{

	int Array[10];
	int* ArrayPtr = Array;

	std::cout << "I've looped through the following numbers :" << std::endl;
	for (ArrayPtr = Array + 0; ArrayPtr < Array + 10; ArrayPtr++)
	{
		*ArrayPtr = rand() % 100;
		std::cout << *ArrayPtr << " ";
	}

	int Sum = 0;
	for (ArrayPtr -= 1; ArrayPtr > Array ; ArrayPtr--)
	{
		Sum += *ArrayPtr;
	}
	std::cout << "\nThe sum of all those numbers is: " << Sum << std::endl;
}
