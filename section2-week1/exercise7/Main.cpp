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


	cout << "Hey you, let's play Rock, Paper, Scissors!" << endl;
	cout << "1 - Rock\n2 - Paper\n3 - Scissors" << endl;
	cout << "choose you weapon: " << endl;

	enum Weapon
	{
		Rock, Paper, Scissors
	};
	srand(time(NULL));
	int WeaponUser, WeaponRandom;
	WeaponRandom =  rand() % 3;
	Weapon weapon = (Weapon)WeaponRandom;
	cin >> WeaponUser;


	enum Answer
	{
		tie, YouWin, YouLose
	};
	Answer answer = tie;
	
	//comparing the weapons
	switch (weapon)
	{
	case Rock:
		cout << "I have selected Rock" << endl;
		if (WeaponUser == 1)
		{
			 answer = tie;
		}
		else if (WeaponUser == 2)
		{
			 answer = YouWin;
		}
		else
		{
			 answer = YouLose;
		}
		break;
	case Paper:
		cout << "I have selected Paper" << endl;
		if (WeaponUser == 1)
		{
			 answer = YouLose;
		}
		else if (WeaponUser == 2)
		{
			 answer = tie;
		}
		else
		{
			 answer = YouWin;
		}
		break;
	case Scissors:
		cout << "I have selected Scissors" << endl;
		if (WeaponUser == 1)
		{
			 answer = YouWin;
		}
		else if (WeaponUser == 2)
		{
			 answer = YouLose;
		}
		else
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
	case YouWin:
		cout << "You win... you are awesome" << endl;
		break;
	default:
		break;
	}

}
