/*Exercise 7 - Rock, Paper, Scissors
Write a simple rock, paper, scissors game.
Ask the user for their guess on the result, then tell them whether they guessed right or wrong.
*/

#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main()
{
	int value, v1, ans;
	ans = 0;

	srand(time(NULL));
	v1 = rand() % (1 - 4);

	cout << "Hey you, let's play Rock, Paper, Scissors!" << endl;

	cout << "1 - Rock\n2 - Paper\n3 - Scissors" << endl;
	cout << "choose you weapon: " << endl;

	cin >> value;

	cout << "\nI have selected the weapon: " << v1 << endl;


	//comparing the weapons
	switch (value) 
	{
		case 1:
			cout << "You have selected Rock" << endl;
			if (v1 == 1) 
			{
				ans = 1; ;
			}
			if (v1 == 2)
			{
				ans = 3;
			}
			if (v1 == 3)
			{
				ans = 2;
			}
			break;
		case 2:
			cout << "You have selected paper" << endl;
			if (v1 == 1)
			{
				ans = 2;
			}
			if (v1 == 2)
			{
				ans = 1;
			}
			if (v1 == 3)
			{
				ans = 3;
			}
			break;
		case 3:
			cout << "You have selected Scissors" << endl;
			if (v1 == 1)
			{
				ans = 2;
			}
			if (v1 == 2)
			{
				ans = 3;
			}
			if (v1 == 3)
			{
				ans = 1;
			}
			break;
		default:
			cout << "You do not know how to play this game...";

	}

	//givin the beredict
	switch (ans)
	{
	case 1:
		cout << "it's a tie" << endl;
		break;
	case 2:
		cout << "HAHHAHAAH you lose, LOSER" << endl;
		break;
	case 3:
		cout << "You win... you are awesome" << endl;
		break;
	default:
		break;
	}
	

	


}