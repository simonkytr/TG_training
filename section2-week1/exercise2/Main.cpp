/*Exercise 2 - Even or Odd
Write a program that will ask the user for three numbers, then tell them whether the numbers are even or odd.
*/

#include <iostream>
using namespace std;

int main()
{
	int number, solve;
	cout << "do you want to prove my math skills? \n gimme 3 numbers and I say whether the numbers are even or odd " << endl;

	for (int i=0; i <= 2; i++)
	{
		cin >> number;
		solve = div(number, 2).rem;

		if (solve == 0)
		{
			cout << "This number is EVEN!" << endl;
		}
		else
		{
			cout << "This number is ODD!" << endl;
		}

	}
}