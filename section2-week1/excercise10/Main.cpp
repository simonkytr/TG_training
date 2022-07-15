/*Exercise 10 - Anything but Lowercase Vowel
Rewrite the previous exercise but this time check that the given character is NOT a lowercase vowel. Use the same conditions you used previously and only change the relational operators. You are not allowed to use a negation operator to wrap the whole set of conditions.
Hint: You might want to look up DeMorgan’s Law for this one.
*/

#include <iostream>
using namespace std;

int main()
{
	char a;

	cout << "Do you know I can identify if your character is a lowercase vowel ? " << endl;
	cout << "insert any character: ";
	cin >> a;

	//identify the character
	if (isupper(a)) {
		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		{
			cout << "This character is not a lowercase vowel" << endl;
		}

	}
	else {
		if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
		{
			cout << "This character is a lowercase vowel" << endl;
		}
		
	}
