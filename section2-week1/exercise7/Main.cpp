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
	int value, random;


	cout << "Hey you, let's play Rock, Paper, Scissors!" << endl;
	cout << "1 - Rock\n2 - Paper\n3 - Scissors" << endl;
	cout << "choose you weapon: " << endl;

	enum Weapon
	{
		Rock, Paper, Scissors
	};
	srand(time(NULL));
	random = rand() % (1 - 4);
	Weapon weapon = (Weapon)random;

	cin >> value;


	enum Answers
	{
		tie, YouWin, YouLose
	};
	Answers answer = tie;
	
	//comparing the weapons
	switch (weapon)
	{
	case Rock:
		cout << "I have selected Rock" << endl;
		if (value == 1)
		{
			 answer = tie;
		}
		if (value == 2)
		{
			 answer = YouWin;
		}
		if (value == 3)
		{
			 answer = YouLose;
		}
		break;
	case Paper:
		cout << "I have selected Paper" << endl;
		if (value == 1)
		{
			 answer = YouLose;
		}
		if (value == 2)
		{
			 answer = tie;
		}
		if (value == 3)
		{
			 answer = YouWin;
		}
		break;
	case Scissors:
		cout << "I have selected Scissors" << endl;
		if (value == 1)
		{
			 answer = YouWin;
		}
		if (value == 2)
		{
			 answer = YouLose;
		}
		if (value == 3)
		{
			 answer = tie;
		}
		break;
	default:
		break;
	}

	//giving the veredict
	switch (answer)
	{
	case tie:
		cout << "it's a tie" << endl;
		break;
	case YouLose:
		cout << "HAHHAHAAH you lose, LOSER" << endl;
		break;
	case 3:
		cout << "You win... you are awesome" << endl;
		break;
	default:
		break;
	}

}
