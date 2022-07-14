/*Exercise 8 - Temperature
Write a program that will ask for a temperature in Fahrenheit and convert it to Celsius, then ask for a temperature in Celsius and convert it to Fahrenheit
Hint: 
C = (F - 32.0) * 5.0 / 9.0
F = C * 9.0 / 5.0 + 32.0
*/
#include <iostream>
using namespace std;

int main()
{
	float f,f2, c,c2;
	cout << "insert a temperature in Fahrenheit ";
	cin >> f;
	c2 = (f - 32.0) * 5.0 / 9.0;
	cout << "In Celsius it is: " << c2 << endl;
	

	cout << "insert a temperature in Celsius ";
	cin >> c;
	f2 = c * 9.0 / 5.0 + 32.0;
	cout << "In Fahrenheit it is: " << f2;
	



}