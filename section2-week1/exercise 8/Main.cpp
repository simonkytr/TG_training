/*
* Exercise 8 - Magic 8 Ball
Write a program that will predict the future for the user. Tell them to ask a question and then create a prediction for them. Make sure to use an enum and a switch statement for this exercise
*/
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

using namespace std;

//value definition


int main()
{
	//enum variables
	enum answers {
		yes, no, maybe, perhaps
	};
	//inicialize variables
	answers ans = yes;


	int random;

	//selecting the answer
	srand(time(NULL));
	random = rand() % (1 - 5);

	char ask[100];
	cout << "Would you like to know what happens in your future?" << endl;
	cout << "\n+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "\nYou can ask to me any question... " << endl;
	cin >> ask;

	ans = (answers)random;
	cout << random << endl;

	
	//guessing the future
	switch (ans)
	{
	case yes:
		cout << "Hmmmm actually it's going to be";
		break;
	case no:
		cout << "I'm sorry, it'll never pass";
		break;
	case maybe:
		cout << "Maybe it happens, don't give up";
		break;
	case perhaps:
		cout << "Hmmmm it's not completly clear...";
		break;
	default:
		break;
	}

}

