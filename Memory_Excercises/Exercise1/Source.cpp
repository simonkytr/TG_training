/*Exercise 1 - Useless Program
Create an integer that will instantiate an integer to the heap and assign it whatever value you
like. Print the value of the integer and the memory address of that int.
Remember that when you’re allocating memory in the heap, you need to free it manually. This is
done with the delete keyword. Make sure to free the memory you allocated for your int before
exiting the program.*/

#include <iostream>

int main()
{
	int* Value = new int(60);
	std::cout << "I've dynamically allocated an integer. Its value is " << *Value << " and its memory address is " << Value << std::endl;
	delete Value;
}