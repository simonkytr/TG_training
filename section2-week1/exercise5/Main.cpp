/*Exercise 5 - Coin Flip
Write a simple coin flip program.
Ask the user for their guess on the result, then tell them whether they guessed right or wrong.
*/

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main()
{
	int coin, v1;

	/* initialize random seed: */
	srand(time(NULL));
	v1 = rand() % (1 - 3);

	cout << "welcome to flip-a-coin!" << endl;
	cout << "1 - Tails \n2 - Head" << endl;
	cout << "can you guess right?" << endl;
	cin >> coin;

	//lanzamiento
	

	cout << "\nactual result: " <<v1<< endl;
	cout << "\nyou guest result: " <<coin<< endl;

	

	if (coin == v1)
	{
		cout << "\nCongratulations, you guessed right!!!";
	}
	else {
		cout << "\nhahahaha that's wrong, loser";
	}

	
}