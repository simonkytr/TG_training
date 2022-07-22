/*
* Create a printer class. This class should allow you to store a string and then output it in different formats. Ask the user to input a string and then show what your printer can do! Remember to use char arrays instead of strings and avoid the std namespace.Create a printer class. This class should allow you to store a string and then output it in different formats. Ask the user to input a string and then show what your printer can do! Remember to use char arrays instead of strings and avoid the std namespace.

You class should have the following methods:
Printer();
Printer(std::string outputString);
void Print();
void PrintReversed();
void PrintSpaced(int spaces);
void PrintVertically();
*/

#include <iostream>
#include<string>

class Printer
{
private:
	std::string WordEntry;
public:
	 Printer()
	{
		WordEntry = " ";
	};
	Printer (std::string OutputString) {
		WordEntry = OutputString;
	};
	void Print() {
		std::cout << WordEntry << std::endl;
	};

	void PrintReversed() {
		int size = 0;

		for (int i = 0; i < WordEntry.length(); i++)
		{
			if (WordEntry[i] == '\0')
			{
				break;
			}
			size++;
		}
		char wordReverse [30];

		for (int i = size - 1; i >= 0; i--)
		{
			wordReverse[size - 1 - i] = WordEntry[i];

		}

		wordReverse [size] = 0;
		std::cout << "This string reversed is: " << wordReverse << std::endl;
	};

	void PrintSpaced (int spaces) {
		std::cout << std::endl;
		std::cout << "\nInsert spaces between each letter" << std::endl;
		std::cin >> spaces;
		for (int i = 0; i < WordEntry.length(); i++)
		{
			std::cout << WordEntry[i];
			for (int iteration = 0; iteration < spaces; iteration++)
			{
				std::cout << " ";
			}
		}
	};

	void PrintVertically()
	{
		std::cout << std::endl;
		for (int i = 0; i < WordEntry.length(); i++)
		{
			std::cout << WordEntry[i] << std::endl;
		}
	}
};



int main()
{
	std::cout << "Welcome! Please enter a string: ";
	std::string Word;
	
	std::cin >> Word;

	int spaces = 0;

	for (int i = 0; i < 6; i++)
	{
		if (Word[i] == '\0')
		{
			break;
		}
		spaces++;
	}

	Printer printer(Word);
	printer.Print();
	printer.PrintReversed();
	
	printer.PrintSpaced (spaces);
	printer.PrintVertically();
}