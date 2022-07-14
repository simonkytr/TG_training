/*Exercise 7 - Operator Precedence
Write a program that will ask the user for three numbers (a,b,c) and output the following evaluations:
a + 1 * b + 2 - c
(a + 1) * (b + 2) - c
*/
#include <iostream>
using namespace std;

int main() 
{
	int a, b, c, x1, x2;
	cout << "HI MATHRAT!! Today let's prove the c++'s arimetics skilss " << endl;
	cout << "gimme number a: ";
	cin >> a;
	cout << "gimme number b: ";
	cin >> b;
	cout << "gimme number c: ";
	cin >> c;

	x1 = a + (1 * b) + 2 - c;
	x2 = (a + 1) * (b + 2) - c;

	cout << "The answer to (a + 1 * b + 2 - c) is " << x1 << endl;
	cout << "The answer to ((a + 1) * (b + 2) - c) is " << x2;
	
}