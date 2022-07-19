/*Exercise 10 - Swapping
Write a program that will swap the value of two variables
*/

#include <iostream>
using namespace std;

int main()
{
	int a, b;

	cout << "insert 1 numbers ";

	cin >> a;

	cout << "insert 1 numbers ";

	cin >> b;

	cout << "your firts number is " << a << endl;
	cout << "your second number is " << b << endl;

	a = a * b;
	b = a / b;
	a = a / b;

	cout << "your second number is " << a << endl;
	cout << "your second number is " << b << endl;
}