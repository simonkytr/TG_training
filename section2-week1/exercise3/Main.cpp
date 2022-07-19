/*Exercise 3 - Positive, Negative, or Zero
Write a program that will ask the user for a number and determine if it is a positive number, a negative number, or zero.
*/
#include <iostream>
using namespace std;

int main()
{
	int number;

	cout << "do you want to prove my math skills? \n gimme a number and I say whether the number is a negative number, a positive number or cero " << endl;

	cin >> number;

	if (number < 0)
	{
		cout << "this number is negative " << endl;
	}
	else if (number == 0)
	{
		cout << "this number is cero " << endl;
	}
	else
	{
		cout << "this number is positive " << endl;
	}

}
