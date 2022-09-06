#include <iostream>
#include "shape.h"
#include "Circle.h"
#include "Square.h"

//------------------------------------------------------------------------------
int ValidateInput(int& UserInput, const int LowerBounce, const int HigherBounce)
{
	std::cin >> UserInput;

	while (std::cin.fail() || UserInput < LowerBounce || UserInput > HigherBounce)
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid Option " << std::endl;
		std::cin >> UserInput;
	};
	return UserInput;
}

int ValidateInput(int& UserInput)
{
	std::cin >> UserInput;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid Option " << std::endl;
		std::cin >> UserInput;
	};
	return UserInput;
}

//------------------------------------------------------------------------------
float ValidateInputFloat(float& UserInput)
{
	std::cin >> UserInput;

	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid value " << std::endl;
		std::cin >> UserInput;
	};
	return UserInput;
}

//---------------------------------------------------------------------------------
void AskForBuildInArray()
{
	std::system("cls");
	std::cout << "Hello, how many shapes would you create?" << std::endl;

	int SizeArray;
	SizeArray = ValidateInput(SizeArray);

	FShape** BuidInArrayPtr = new FShape*[SizeArray];

	for (int i = 0; i < SizeArray; i++)
	{
		std::system("cls");
		std::cout << "shape #" << i + 1 << "\nWhat kind of shape Would you like create?" << std::endl;
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "1- Circle" << std::endl;
		std::cout << "2- Square" << std::endl;
		std::cout << "-------------------------------------" << std::endl;

		int UserInput;
		UserInput = ValidateInput(UserInput, 1, 2);

		if (UserInput == 1)
		{
			std::cout << "Insert circle's Radius: ";
			float InRadius;
			InRadius = ValidateInputFloat(InRadius);

			BuidInArrayPtr[i] = new FCircle(InRadius);
			
		}
		else
		{
			std::cout << "Insert square's lenght: ";
			float InLenght;
			InLenght = ValidateInputFloat(InLenght);

			std::cout << "Insert square's heignt: ";
			float InHeight;
			InHeight = ValidateInputFloat(InHeight);

			BuidInArrayPtr[i] = new FSquare(InLenght, InHeight);
		}
	}


	//Were is where it's going to print the shapes
	std::cout << "These are the shapes that you created: " << std::endl;
	std::system("cls");

	for (int i = 0; i < SizeArray; i++)
	{
		std::cout << "--------------------------------- " << std::endl;
		std::cout << "Shape #" << i + 1 << std::endl;
		
		std::cout << "this Shape is a: " << BuidInArrayPtr[i]->GetKindOfShape() << std::endl;
		std::cout << BuidInArrayPtr[i]->PrintParameters() << std::endl;
		std::cout << "the Shape's area is: " << BuidInArrayPtr[i]->CalculateArea() << std::endl;
		std::cout << "the Shape's perimeter is: " << BuidInArrayPtr[i]->CalculatePerimeter() << std::endl;
		std::cout << "--------------------------------- " << std::endl;
	}

	//freeing Memory
	for (int i = 0; i < SizeArray; i++)
	{
		delete BuidInArrayPtr[i];
	}
	delete[] BuidInArrayPtr;
}

//---------------------------------------------------------------------------------
void AskForStaticArray()
{
	
}

//---------------------------------------------------------------------------------
void AskForDinamicArray()
{

}

//---------------------------------------------------------------------------------
int main()
{
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "\t Welcome to Shape calculator" << std::endl;
	std::cout << "-----------------------------------------\n" << std::endl;
	
	std::cout << "Please select a valid option to continue" << std::endl;
	std::cout << "1- Build-in array" << std::endl;
	std::cout << "2- Static array" << std::endl;
	std::cout << "3- Dinamic array" << std::endl;
	
	int UserInput;
	UserInput = ValidateInput(UserInput, 1, 3);

	if (UserInput == 1)
	{
		AskForBuildInArray();
	}
	else if (UserInput == 2)
	{
		AskForStaticArray();
	}
	else
	{
		AskForDinamicArray();
	}
}