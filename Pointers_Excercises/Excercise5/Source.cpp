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