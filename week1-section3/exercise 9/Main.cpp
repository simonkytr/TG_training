/*
* Exercise 9 - String Reversal
We’ve seen that strings are just arrays of characters. Create a char array and initialize it with any message. The char array should have a size of 30 independently of the size of your string. Output your string and reverse it using a loop and a second char array, then output the reversed string. 

Do not hard code the size of your string when looping through it.

Do this twice: one time initializing the string with double quotes, and another time initializing it with single characters.

*/

#include <iostream>

int main()
{
	char word[30] = "Hello word!";
	std::cout <<"1.My string initialized with double quotes is: "<< word << std::endl;

	int size = 0;

	for (int i = 0; i < 30; i++)
	{
		if (word[i] == '\0')
		{
			break;
		}
		size++;
	}

	char wordReverse[30];

	for (int i = size - 1; i >= 0; i--)
	{
		wordReverse[size - 1 - i] = word[i];

	}
	
	wordReverse[size] = 0;
	std::cout << "This string reversed is: " << wordReverse << std::endl;


	//------------------------------------------------------------------------

	char word2[30] = {"D i e g o"};
	std::cout << "2.My string initialized with single characters is: " << word2 << std::endl;

	int size2 = 0;

	for (int i = 0; i < 30; i++)
	{
		if (word2[i] == '\0')
		{
			break;
		}
		size2++;
	}

	char wordReverse2[30];

	for (int i = size2 - 1; i >= 0; i--)
	{
		wordReverse2[size2 - 1 - i] = word2[i];

	}



	wordReverse2[size2] = 0;
	std::cout << "This string reversed is: " << wordReverse2;

}