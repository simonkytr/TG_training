#include "Steam.h"
#include <iostream>
#include <string>

FSteam::FSteam()
{
	Uncategorized = FCategory("Uncategorized");
	ActiveMenuCommand = EMenuCommand::MainMenu;
};

//---------------------------------------------------------
void FSteam::OpenMainMenu()
{
	std::system("cls");
	std::cout << "--------------------WELCOME TO STEAM--------------------\n\nWhat do you want to do?\n----------------------------------------" << std::endl;
	std::cout << "1 - Add a new game\n2 - Category Manager\n3 - Display Games\n4 - Exit\nPlease choose an option to follow..." << std::endl;
	int InputUser;
	std::cin >> InputUser;
	InputValidate(InputUser, 0, 4);

	if (InputUser == 1)
	{
		ActiveMenuCommand = EMenuCommand::AddGame;
	}
	else if (InputUser == 2)
	{
		ActiveMenuCommand = EMenuCommand::CategoryManager;
	}
	else if (InputUser == 3)
	{
		ActiveMenuCommand = EMenuCommand::DisplayGames;
	}
	else
	{
		ActiveMenuCommand = EMenuCommand::Exit;
	}
}

//---------------------------------------------------------
void FSteam::OpenAddGame()
{
	std::system("cls");
	std::cout << "Let's add a new game!" << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	//adding the game
	std::cin.ignore(500, '\n');
	std::cout << "Please enter the game's name" << std::endl;
	std::string InGameName;
	std::getline(std::cin, InGameName);

	std::cout << "Please enter the name of the game's developer studio" << std::endl;
	std::string InStudioName;
	std::getline(std::cin, InStudioName);

	std::system("cls");
	std::cout << "Please introduce the release date" << std::endl;
	std::cout << "Please enter Day ";
	int InDay;
	std::cin >> InDay;
	InputValidate(InDay, 0, 31);

	std::cout << "Please enter Month ";
	int InMonth;
	std::cin >> InMonth;
	InputValidate(InMonth, 0, 12);

	std::cout << "Please enter Year ";
	int InYear;
	std::cin >> InYear;
	InputValidate(InYear, 1990, 2022);

	//Creating a Game
	FGame Game = FGame(InGameName, InStudioName, InDay, InMonth, InYear);

	//Menu to select if you want to add the game to a existing category or not
	std::system("cls");
	std::cout << "Would you like to add a game to an existing category?\n1 - Yes, please\n2 - No, Thanks\nPlease choose an option to follow" << std::endl;
	int UserInput;
	std::cin >> UserInput;
	InputValidate(UserInput, 1, 2);
	if (UserInput == 1)
	{
		//Choosing a category where the user going to add a game
		std::system("cls");
		std::cout << "------------------------------------------\nPlease Select the category where you want to add a game" << std::endl;
		CategoryContainer.PrintCategory();
		int CategoryChosen;
		std::cin >> CategoryChosen;
		InputValidate(CategoryChosen, 0, CategoryContainer.GetCurrentCategory());

		if (CategoryContainer.AddGameToCategory(CategoryChosen - 1, Game))
		{
			std::cout << "------------------------------------------\n" << std::endl;
			std::cout << "The game is going to add to the category: " << CategoryContainer.GetCategory(CategoryChosen - 1).GetCategoryName() << std::endl;
		}
		else
		{
			std::cout << "------------------------------------------\n" << std::endl;
			std::cout << "The game couldn't be added to the category: " << CategoryContainer.GetCategory(CategoryChosen - 1).GetCategoryName() << std::endl;
		}
	}
	else
	{
		std::cout << "The game is going to add to the category: " << Uncategorized.GetCategoryName() << std::endl;
		Uncategorized.AddGame(Game);
	}
	//back to MainMenu
	std::cin.ignore(500, '\n');
	std::cout << "------------------------------------------\n" << std::endl;
	std::cout << "Press enter to come back to Main menu" << std::endl;
	if (std::cin.peek() == '\n')
	{
		ActiveMenuCommand = EMenuCommand::MainMenu;
	}
};

//------------------------------------------------------
void FSteam::OpenCategoryManager()
{
	std::system("cls");
	std::cout << "-----------CATEGORY MANAGER-------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "1 - Create a new category\n2 - Delete a category\n3 - Main manu" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "choose an option" << std::endl;

	int UserInput;
	std::cin >> UserInput;
	InputValidate(UserInput, 0, 4);

	if (UserInput == 1)
	{
		//creating a new category
		std::system("cls");
		std::cout << "Please enter the name for the new category" << std::endl;
		std::string CategoryName;
		std::cin.ignore(500, '\n');
		std::getline(std::cin, CategoryName);
		if (CategoryContainer.AddCategory(CategoryName))
		{
			std::cout << "The category " << CategoryName << " was added!" << std::endl;
		}
		else
		{
			std::cout << "The category " << CategoryName << " couldn't was added!" << std::endl;
		}
		//back to MainMenu
		std::cout << "Press enter to come back to Main menu" << std::endl;
		if (std::cin.peek() == '\n')
		{
			ActiveMenuCommand = EMenuCommand::MainMenu;
		}
	}
	else if (UserInput == 2)
	{
		//Deleting a category
		std::system("cls");
		CategoryContainer.PrintCategory();
		std::cout << "-----------------------------------------------" << std::endl;

		std::cout << "Selected the category to delete" << std::endl;
		int CategorySelected;
		std::cin >> CategorySelected;
		InputValidate(CategorySelected, 0, CategoryContainer.GetCurrentCategory());
		if (CategoryContainer.DeleteCategory(CategorySelected - 1))
		{
			std::cout << "the category " << CategoryContainer.GetCategory(CategorySelected - 1).GetCategoryName() << " Was deleted" << std::endl;
		}
		else
		{
			std::cout << "the category " << CategoryContainer.GetCategory(CategorySelected - 1).GetCategoryName() << "couldn't was deleted" << std::endl;
		}

		//back to MainMenu
		std::cin.ignore(500, '\n');
		std::cout << "...Press enter to come back to Main menu..." << std::endl;
		if (std::cin.peek() == '\n')
		{
			ActiveMenuCommand = EMenuCommand::MainMenu;
		}
	}
	else
	{
		ActiveMenuCommand = EMenuCommand::MainMenu;
	}
};

//------------------------------------------------------
void FSteam::OpenDisplayGames()
{
	std::system("cls");
	Uncategorized.DisplayCategory();
	for (int i = 0; i < CategoryContainer.GetCurrentCategory(); i++)
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		CategoryContainer.GetCategory(i).DisplayCategory();
	}

	std::cout << "----------------------------------------------------------------" << std::endl;
	//back to MainMenu
	std::cin.ignore(500, '\n');
	std::cout << "Press enter to come back to Main menu" << std::endl;
	if (std::cin.peek() == '\n')
	{
		ActiveMenuCommand = EMenuCommand::MainMenu;
	}
};

//------------------------------------------------------
void FSteam::AppRun()
{
	while (ActiveMenuCommand != EMenuCommand::Exit)
	{
		if (ActiveMenuCommand == EMenuCommand::MainMenu)
		{
			OpenMainMenu();
		}
		else if (ActiveMenuCommand == EMenuCommand::AddGame)
		{
			OpenAddGame();
		}
		else if (ActiveMenuCommand == EMenuCommand::CategoryManager)
		{
			OpenCategoryManager();
		}
		else if (ActiveMenuCommand == EMenuCommand::DisplayGames)
		{
			OpenDisplayGames();
		}
	}
}

//--------------------------------------------------------------
void FSteam::InputValidate(int InputToValid)
{
	while (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid value " << std::endl;
		std::cin >> InputToValid;
	}
};

//---------------------------------------------------------------
void FSteam::InputValidate(int InputToValid, const int IntLowValueToValid, const int IntHighValueToValid)
{
	while (std::cin.fail() || (InputToValid < IntLowValueToValid) || (InputToValid > IntHighValueToValid))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid Option " << std::endl;
		std::cin >> InputToValid;
	}
};