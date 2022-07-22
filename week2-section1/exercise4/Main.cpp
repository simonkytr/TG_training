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

class FPrinter
{
private:
	std::string WordEntry;
public:
	 FPrinter()
	{
		WordEntry = " ";
	};
	FPrinter (std::string OutputString) {
		WordEntry = OutputString;
	};
	void Print() const
	{
		std::cout << WordEntry << std::endl;
	};

	void PrintReversed() const
	{
		int Size = 0;

		for (int i = 0; i < WordEntry.length(); i++)
		{
			if (WordEntry[i] == '\0')
			{
				break;
			}
			Size++;
		}
		char wordReverse [30];

		for (int i = Size - 1; i >= 0; i--)
		{
			wordReverse[Size - 1 - i] = WordEntry[i];

		}

		wordReverse [Size] = 0;
		std::cout << "This string reversed is: " << wordReverse << std::endl;
	};

	void PrintSpaced (int spaces) const
	{
		std::cout << std::endl;
		
		for (int i = 0; i < WordEntry.length(); i++)
		{
			std::cout << WordEntry[i];
			for (int iteration = 0; iteration < spaces; iteration++)
			{
				std::cout << " ";
			}
		}
	};

	void PrintVertically() const
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
	//The printer is Working
	FPrinter printer(Word);
	printer.Print();
	printer.PrintReversed();
	//the printer is asking about how many spaces between each letter
	std::cout << "\nInsert spaces between each letter" << std::endl;
	int spaces;
	std::cin >> spaces;
	printer.PrintSpaced (spaces);
	printer.PrintVertically();
}