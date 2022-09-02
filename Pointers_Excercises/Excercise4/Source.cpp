/*Exercise 4 - Understanding Pointers 3
Create a program where you declare an int variable and initialize it to whatever value you want.
Print the value to the console.
Then, create two int pointer variables that point to the variable you just created.
Dereference the first pointer and add one to the dereferenced value. Do the same thing with the
second pointer. Print the final value of your initial variable. Do these results make sense to you?*/

#include <iostream>

int main()
{
	int Value = 15;
	int* ValuePtrA = Value;
	int* ValuePtrB = Value;

	std::cout << "The value of my variable is " << *ValuePtrA << std::endl;

	*ValuePtrA += 1;
	*ValuePtrB += 1;

	std::cout << "The value of my variable after the pointer stuff I did is " << Value << std::endl;
}
