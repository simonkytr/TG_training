/*Exercise 6 - Multiple Choice
Write a program where the user can make a choice out of a list of options. Make sure to use an enum and handle when the input is out of bounds.
*/

#include <iostream>
using namespace std;

int main()
{
	cout << "WELCOME PLAYER, choose your character" << endl;
	cout << "1 - Gardian\n2 - Wizard\n3 - Warrior\n4 - Healer" << endl;

	int cho;

	cin >> cho;

	switch (cho) {
	case 1:
		cout << "you have selected Gardian" << endl;
		cout << "You are going to protect the door";
		break;
	case 2:
		cout << "you have selected Wizard" << endl;
		cout << "you are going to prevent the trolls from advancing";
		break;
	case 3:
		cout << "you have selected Warrior" << endl;
		cout << "you are going to attack the enemy army";
		break;
	case 4:
		cout << "you have selected Healer" << endl;
		cout << "you are going to heal your wounded comrades";
		break;
	default:
		cout << "You are not ready for this war!!...";
	}
}