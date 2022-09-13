#include "Menu.h"

FMenu::FMenu()
{
	ActiveMenuCommand = EMenuCommand::MainMenu;
}

void FMenu::OpenMainMenu()
{
	std::system("cls");
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << "\t Welcome to Shape calculator" << std::endl;
	std::cout << "-----------------------------------------\n" << std::endl;

	std::cout << "Please select a valid option to continue" << std::endl;
	std::cout << "1- Build-in array" << std::endl;
	std::cout << "2- Static array" << std::endl;
	std::cout << "3- Dinamic array" << std::endl;
	std::cout << "4- Exit" << std::endl;
	std::cout << "-----------------------------------------\n" << std::endl;
	std::cout << "Enter a valid option: ";

	int UserInput;
	UserInput = ValidateInput(UserInput, 1, 3);

	switch (UserInput)
	{
	case 1:
		ActiveMenuCommand = EMenuCommand::BuildInArray;
		break;
	case 2:
		ActiveMenuCommand = EMenuCommand::StaticArray;
		break;
	case 3:
		ActiveMenuCommand = EMenuCommand::DynamicArray;
		break;
	case 4:
		ActiveMenuCommand = EMenuCommand::Exit;
		break;
	default:
		break;
	}
}


//---------------------------------------------------------------------------------
void FMenu::AskForBuildInArray()
{
	std::system("cls");
	std::cout << "Hello, how many shapes would you create?" << std::endl;

	int SizeArray;
	SizeArray = ValidateInput(SizeArray);

	FShape** Shapes = new FShape * [SizeArray];

	//Creating new Shape
	for (int i = 0; i < SizeArray; i++)
	{
		std::system("cls");
		std::cout << "shape #" << i + 1 << "\nWhat kind of shape Would you like create?" << std::endl;

		if (Shapes[i] = CreateShape())
		{
			std::cout << "The Shape was created succesfully" << std::endl;
		}
		else
		{
			std::cout << "The Shape wasn't created" << std::endl;
		}
	}


	//here is where it's going to print the shapes
	std::cout << "These are the shapes that you created: " << std::endl;
	std::system("cls");

	for (int i = 0; i < SizeArray; i++)
	{
		std::cout << "--------------------------------- " << std::endl;
		std::cout << "Shape #" << i + 1 << std::endl;
		PrintArray(*Shapes[i]);
	}

	//freeing Memory
	for (int i = 0; i < SizeArray; i++)
	{
		delete Shapes[i];
	}
	delete[] Shapes;

	//back to MainMenu
	ComeBackMainManu();
}


//---------------------------------------------------------------------------------
void FMenu::AskForStaticArray()
{
	TStaticArray<FShape*, 5> Shapes;

	for (int i = 0; i < 5; i++)
	{
		std::system("cls");
		std::cout << "shape #" << i + 1 << "\nWhat kind of shape Would you like create?" << std::endl;

		if (Shapes[i] = CreateShape())
		{
			std::cout << "The Shape was created succesfully" << std::endl;
		}
		else
		{
			std::cout << "The Shape wasn't created" << std::endl;
		}
	}

	std::system("cls");
	std::cout << "These are the shapes that you created: " << std::endl;

	for (int i = 0; i < 5; i++)
	{
		std::cout << "--------------------------------- " << std::endl;
		std::cout << "Shape #" << i + 1 << std::endl;

		std::cout << "--------------------------------- " << std::endl;
		std::cout << "Shape #" << i + 1 << std::endl;
		PrintArray(*Shapes[i]);
	}

	//freeing Memory
	for (int i = 0; i < 5; i++)
	{
		delete Shapes[i];
	}

	//back to MainMenu
	ComeBackMainManu();
}

//---------------------------------------------------------------------------------
void FMenu::AskForDynamicArray()
{
	std::system("cls");
	TDynamicArray<FShape*> Shapes;
	
	int UserInput = -1;
	do
	{
		std::cout << "What would you to do?" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "1 - Create a new shape" << std::endl;
		std::cout << "2 - print your shapes" << std::endl;
		std::cout << "3 - MainMenu" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Enter a valid option: ";

		UserInput = ValidateInput(UserInput, 1, 3);

		if (UserInput == 1)
		{
			std::system("cls");
			std::cout << "What kind of shape would you create?" << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "1 - Circle" << std::endl;
			std::cout << "2 - Square" << std::endl;
			std::cout << "-----------------------------------------------" << std::endl;
			std::cout << "Enter a valid option: ";

			int KindShape;
			KindShape = ValidateInput(UserInput, 1, 2);

			if (KindShape == 1)
			{
				std::system("cls");
				std::cout << "Insert circle's Radius: ";

				float InRadius;
				InRadius = ValidateInputFloat(InRadius);
				Shapes.PushBack(new FCircle(InRadius));
			}

			else
			{
				std::system("cls");
				std::cout << "Insert square's lenght: ";
				float InLenght;
				InLenght = ValidateInputFloat(InLenght);

				std::cout << "Insert square's heignt: ";
				float InHeight;
				InHeight = ValidateInputFloat(InHeight);

				Shapes.PushBack(new FSquare(InLenght, InHeight));
			}
			std::cout << "You shape was created succefully" << std::endl;
		}

		else if (UserInput == 2)
		{

			if (Shapes.IsEmpty())
			{
				std::system("cls");
				std::cout << "You don't create a shape yet..." << std::endl;
			}

			else
			{
				std::system("cls");
				std::cout << "These are the shapes that you created: " << std::endl;

				for (int i = 0; i < Shapes.GetSize(); i++)
				{
					std::cout << "--------------------------------- " << std::endl;
					std::cout << "Shape #" << i + 1 << std::endl;
					PrintArray(*Shapes[i]);
				}
			}

			std::cout << "Press 1... to back previus menu" << std::endl;
			int MenuInput;
			std::cin >> MenuInput;

			while (std::cin.fail() || MenuInput != 1)
			{
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "Invalid Option, please enter a valid Option " << std::endl;
				std::cin >> MenuInput;
				if (MenuInput == 1)
				{
					ActiveMenuCommand = EMenuCommand::DynamicArray;
				}
			}
		}

		else
		{
			//freeing Memory
			for (int i = 0; i < Shapes.GetSize(); i++)
			{
				delete Shapes[i];
			}
			ActiveMenuCommand = EMenuCommand::MainMenu;
		}

	} while (UserInput != 3);
}

FShape* FMenu::CreateShape()
{
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
		return new FCircle(InRadius);
		
			
	}
	else
	{
		std::cout << "Insert square's lenght: ";
		float InLenght;
		InLenght = ValidateInputFloat(InLenght);

		std::cout << "Insert square's heignt: ";
		float InHeight;
		InHeight = ValidateInputFloat(InHeight);

		return new FSquare(InLenght, InHeight);
	}
}

//---------------------------------------------------------------------------------
void FMenu::PrintArray(const FShape& Shape) const
{
	std::cout << "this Shape is a: " << Shape.GetKindOfShape() << std::endl;
	std::cout << Shape.PrintParameters() << std::endl;
	std::cout << "the Shape's area is: " << Shape.GetArea() << std::endl;
	std::cout << "the Shape's perimeter is: " << Shape.GetPerimeter() << std::endl;
	std::cout << "--------------------------------- " << std::endl;
};

//---------------------------------------------------------------------------------
void FMenu::RunApp()
{
	while (ActiveMenuCommand != EMenuCommand::Exit)
	{
		switch (ActiveMenuCommand)
		{
		case EMenuCommand::MainMenu:
			OpenMainMenu();
			break;
		case EMenuCommand::BuildInArray:
			AskForBuildInArray();
			break;
		case EMenuCommand::StaticArray:
			AskForStaticArray();
			break;
		case EMenuCommand::DynamicArray:
			AskForDynamicArray();
			break;
		case EMenuCommand::Exit:
			break;
		}
	}
}

//------------------------------------------------------------------------------
int FMenu::ValidateInput(int& UserInput, const int LowerBounce, const int HigherBounce)
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

//---------------------------------------------------------------------------------
int FMenu::ValidateInput(int& UserInput)
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
float FMenu::ValidateInputFloat(float& UserInput)
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

//-----------------------------------------------------------------------------
void FMenu::ComeBackMainManu()
{
	while (std::cin.bad())
	{
		//back to MainMenu
		std::cin.ignore(500, '\n');
		std::cout << "------------------------------------------\n" << std::endl;
		std::cout << "Press enter to come back to Main menu" << std::endl;
		if (std::cin.peek() == '\n')
		{
			ActiveMenuCommand = EMenuCommand::MainMenu;
			break;
		}
	}
}

