/*Exercise 4 - True or False
Write a quiz program for the user.
The program should ask a series of true or false questions to the user.
For each answer, tell the user if they were correct or incorrect.
At the end of the quiz, tell them their final grade (grade should be 0-5)
*/

#include <iostream>
using namespace std;

int main()
{
	int answer1 = 0;
	int answer2 = 0;
	int answer3 = 1;
	int answer4 = 0;
	int answer5 = 1;

	int answer;
	int score = 0;



	cout << "Welcome new participant!!\nLet's start this Quiz\n(answer 0 to false ore 1 to true)" << endl;

	//question 1
	cout << "\nColombia's capital city is Quito?" << endl;
	cin >> answer;
	if (answer1 == answer)
	{
		cout << "that's correct" << endl;
		score++;
	}
	else {
		cout << "that's wrong" << endl;
	}

	//question2
	cout << "\nthere are 40 stars on the EEUU's flag" << endl;
	cin >> answer;
	if (answer2 == answer)
	{
		cout << "that's correct" << endl;
		score++;
	}
	else {
		cout << "that's wrong" << endl;
	}


	//question3
	cout << "\nis the cheetah the fastest animal on the earth?" << endl;
	cin >> answer;
	if (answer3 == answer)
	{
		cout << "that's correct" << endl;
		score++;
	}
	else {
		cout << "that's wrong" << endl;
	}


	//question4
	cout << "\nthe earth is located in the Andromeda galaxy?" << endl;
	cin >> answer;
	if (answer4 == answer)
	{
		cout << "that's correct" << endl;
		score++;
	}
	else {
		cout << "that's wrong" << endl;
	}


	//question4
	cout << "\nwe're in the XXI century?" << endl;
	cin >> answer;
	if (answer5 == answer)
	{
		cout << "that's correct" << endl;
		score++;
	}
	else {
		cout << "that's wrong" << endl;
	}

	cout << "thanks for playing with me, your score was: " << score << endl;
}

