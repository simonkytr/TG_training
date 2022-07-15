/*Exercise 9 - Lowercase Vowel
Write a program that will receive an alphabetical character from the user. Then, tell them if the character is a lowercase vowel. Make sure to do this using a single if statement.
*/

#include <iostream>
using namespace std;

int main()
{
	char a;

	cout << "Do you know I can identify if your character is a lowercase vowel?" << endl;
	cout << "insert any character: ";
	cin >> a;

	//identify the character
	if ((islower(a)) && (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u'))
		{
			cout << "This character is a lowercase vowel"<<endl;
		}

	else {
		
		cout << "This character is not a vowel" << endl;
	}
	
}