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
	int value, random, answer;
	ans = 0;

	srand(time(NULL));
	random = rand() % (1 - 4);

	cout << "Hey you, let's play Rock, Paper, Scissors!" << endl;

	cout << "1 - Rock\n2 - Paper\n3 - Scissors" << endl;
	cout << "choose you weapon: " << endl;

	cin >> value;

	cout << "\nI have selected the weapon: " << random << endl;


	//comparing the weapons
	switch (value) 
	{
		case 1:
			cout << "You have selected Rock" << endl;
			if (random == 1) 
			{
				answer = 1; ;
			}
			if (random == 2)
			{
				answer = 3;
			}
			if (random == 3)
			{
				answer = 2;
			}
			break;
		case 2:
			cout << "You have selected paper" << endl;
			if (random == 1)
			{
				answer = 2;
			}
			if (random == 2)
			{
				answer = 1;
			}
			if (random == 3)
			{
				answer = 3;
			}
			break;
		case 3:
			cout << "You have selected Scissors" << endl;
			if (random == 1)
			{
				answer = 2;
			}
			if (random == 2)
			{
				answer = 3;
			}
			if (random == 3)
			{
				answer = 1;
			}
			break;
		default:
			cout << "You do not know how to play this game...";

	}

	//givin the beredict
	switch (answer)
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
