/*Exercise 5 - Pointers and Arrays
Watch this extra resource video before starting: Link
Arrays are just values that are stored in a contiguous block of memory. That means that an
array variable is pretty much just a pointer that points to the first element of the array. You could
handle it the same way if you used a pointer directly.
Create a program where you declare an array of 10 integers. Then, using a for loop, access
every entry of the array by index and print the sum of all elements to the console.
Then, declare an int pointer and assign the array variable to this pointer (you don’t need to get
the memory address from the array variable, you can assign it directly).
Now, loop through the array, but this time instead of accessing the array elements from the
array itself, use the pointer variable. You can access the values in the same exact way you
accessed them when using an array. Print the sum to the console again.
Finally, make your loop iterate more times than the size of the array (something like 35
iterations) and print the sum of the value you get for all iterations. What’s the result? Does it
make sense?*/

#include <iostream>

int main()
{
	int Array[10] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int* ArrayPtr = Array;

	std::cout << "When I use this array: ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << ArrayPtr[i] << " ";
	}

	int Sum = 0;
	for (int i = 0; i < 10; i++)
	{
		Sum += Array[i];
	}
	std::cout << "\nThis is the sum when I loop through the array: " << Sum << std::endl;

	int Sum2 = 0;
	for (int i = 0; i < 10; i++)
	{
		Sum2 += ArrayPtr[i];
	}
	std::cout << "This is the sum when I loop through the array using a pointer: " << Sum2 << std::endl;

	int Sum3 = 0;
	for (int i = 0; i < 25; i++)
	{
		Sum3 += ArrayPtr[i];
	}
	std::cout << "This is the sum when I loop through the array using a pointer and out-of-bounds indices: " << Sum3 << std::endl;
}
