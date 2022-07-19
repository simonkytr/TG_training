/*Exercise 7 - Operator Precedence
Write a program that will ask the user for three numbers (a,b,c) and output the following evaluations:
a + 1 * b + 2 - c
(a + 1) * (b + 2) - c
*/
#include <iostream>
using namespace std;

int main() 
{
	 
	cout << "HI MATHRAT!! Today let's prove the c++'s arimetics skilss " << endl;
	cout << "gimme number a: ";
	int a;
	cin >> a;
	cout << "gimme number b: ";
	int b;
	cin >> b;
	cout << "gimme number c: ";
	int c;
	cin >> c;
	
	int solve1;
	solve1 = a + (1 * b) + 2 - c;
	
	int solve2;
	solve2 = (a + 1) * (b + 2) - c;

	cout << "The answer to (a + 1 * b + 2 - c) is " << solve1 << endl;
	cout << "The answer to ((a + 1) * (b + 2) - c) is " << solve2;
	
}
