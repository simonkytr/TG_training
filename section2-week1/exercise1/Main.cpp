/*
Write a simple game menu that will ask the user about their age.
Let them enter the game if their age is appropriate, but tell them they can’t enter otherwise.
*/
#include <iostream>
using namespace std;

int main() 
{
	int age;
	cout << "WELCOME WARRIOR, ARE YOU READY FOR THE ADVENTURE?\nTELL ME... how old are you?" << endl;
	cin >> age;

	if (age >= 18)
	{
		cout << "WELCOME AGAIN WARRIOR, THE MOST FANTASTIC ADVENTURE IS WAITING FOR YOU!!, LET'S START" << endl;
	}
	else
	{
		cout << "I'm sorry little boy, this adventure is not for you yet... BUT I HOPE TO SEE YOU SOON WHEN YOU BECOME A BIG WARRIOR!!" << endl;
	}
}

