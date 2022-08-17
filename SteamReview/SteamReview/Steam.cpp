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
	std::cout << "1 - Add a new game" << std::endl;
	std::cout << "2 - Category Manager" << std::endl;
	std::cout << "3 - Display Games" << std::endl;
	std::cout << "4 - Exit" << std::endl;
	std::cout << "Please choose an option to follow..." << std::endl;
	
	int UserInput;
	std::cin >> UserInput;
	ValidateInput(UserInput, 1, 4);

	switch (UserInput)
	{
	case 1:
		ActiveMenuCommand = EMenuCommand::AddGame;
		break;
	case 2:
		ActiveMenuCommand = EMenuCommand::CategoryManager;
		break;
	case 3:
		ActiveMenuCommand = EMenuCommand::DisplayGames;
		break;
	case 4:
		ActiveMenuCommand = EMenuCommand::Exit;
		break;
	default:
		break;
	}
}

//---------------------------------------------------------
void FSteam::OpenAddGame()
{
	//adding a new game
	FGame Game;
	AddNewGame(Game);

	// adding the new game into the category
	AddNewGameToCategory(Game);

	//Come bacck to main menu
	ComeBackMainManu();
	
};

//------------------------------------------------------
void FSteam::OpenCategoryManager()
{
	std::system("cls");
	std::cout << "-----------CATEGORY MANAGER-------------" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "1 - Create a new category" << std::endl;
	std::cout << "2 - Delete a category" << std::endl;
	std::cout << "3 - Main manu" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "choose an option" << std::endl;

	int UserInput;
	std::cin >> UserInput;
	ValidateInput(UserInput, 1, 3);

	if (UserInput == 1)
	{
		if (AddNewCategory())
		{
			std::cout << "The category was added succesfully!" << std::endl;
		}
		else
		{
			std::cout << "something is wrong, the category wasn't be created..." << std::endl;
		}
		//back to main menu
		ComeBackMainManu();
	}
	else if (UserInput == 2)
	{
		if (DeleteACategory())
		{
			std::cout << "The category was deleted succesfully!" << std::endl;
			
		}
		else
		{
			std::cout << "something is wrong, try again later" << std::endl;
		}

		//back to main menu
		ComeBackMainManu();
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
	for (int i = 0; i < CategoryContainer.GetCurrentCategoryAmount(); i++)
	{
		std::cout << "----------------------------------------------------------------" << std::endl;
		CategoryContainer.GetCategory(i).DisplayCategory();
	}
	std::cout << "----------------------------------------------------------------" << std::endl;
	
	//back to MainMenu
	ComeBackMainManu();
};

//------------------------------------------------------
void FSteam::AppRun()
{
	while (ActiveMenuCommand != EMenuCommand::Exit)
	{
		switch (ActiveMenuCommand)
		{
		case EMenuCommand::MainMenu:
			OpenMainMenu();
			break;
		case EMenuCommand::AddGame:
			OpenAddGame();
			break;
		case EMenuCommand::CategoryManager:
			OpenCategoryManager();
			break;
		case EMenuCommand::DisplayGames:
			OpenDisplayGames();
			break;
		case EMenuCommand::Exit:
			break;
		}
	}
}

//---------------------------------------------------------------
int FSteam::ValidateInput(int& InputValue, const int LowBoundValue, const int HighBoundValue)
{

	while (std::cin.fail() || (InputValue < LowBoundValue) || (InputValue > HighBoundValue))
	{
		std::cin.clear();
		std::cin.ignore(100, '\n');
		std::cout << "Invalid Option, please enter a valid Option " << std::endl;
		std::cin >> InputValue;
	}
	return InputValue;
};

//--------------------------------------------------------------
void FSteam::AddNewGame(FGame& InGame)
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

	std::cout << "------------------------------------" << std::endl;
	std::cout << "Please introduce the release date" << std::endl;
	std::cout << "------------------------------------" << std::endl;

	std::cout << "Please enter Day ";
	int InDay;
	std::cin >> InDay;
	ValidateInput(InDay, 1, 31);

	std::cout << "Please enter Month ";
	int InMonth;
	std::cin >> InMonth;
	ValidateInput(InMonth, 1, 12);

	std::cout << "Please enter Year ";
	int InYear;
	std::cin >> InYear;
	ValidateInput(InYear, 1990, 2022);

	//Creating a Game
	InGame = FGame(InGameName, InStudioName, InDay, InMonth, InYear);
};

//----------------------------------------------------------------
bool FSteam::AddNewGameToCategory(const FGame& InGame)
{
	//Menu to select if you want to add the game to a existing category or not
	std::system("cls");
	std::cout << "Would you like to add a game to an existing category?" << std::endl;
	std::cout << "1 - Yes, please" << std::endl;
	std::cout << "2 - No, Thanks" << std::endl;
	std::cout << "Please choose an option to follow" << std::endl;

	int UserInput;
	std::cin >> UserInput;
	ValidateInput(UserInput, 1, 2);

	if (UserInput == 1)
	{
		if (!CategoryContainer.IsEmpy())
		{
			//Choosing a category where the user going to add a game
			std::system("cls");
			std::cout << "------------------------------------------\nPlease Select the category where you want to add a game" << std::endl;
			CategoryContainer.PrintCategories();

			int CategoryChosen;
			std::cin >> CategoryChosen;
			CategoryChosen = ValidateInput(CategoryChosen, 1, CategoryContainer.GetCurrentCategoryAmount()) - 1;

			//adding the game to category
			if (CategoryContainer.AddGameToCategory(CategoryChosen, InGame))
			{
				std::cout << "------------------------------------------\n" << std::endl;
				std::cout << "The game is going to add to the category: " << CategoryContainer.GetCategory(CategoryChosen).GetCategoryName() << std::endl;
				return true;
			}
			else
			{
				std::cout << "------------------------------------------\n" << std::endl;
				std::cout << "The game couldn't be added to the category: " << CategoryContainer.GetCategory(CategoryChosen).GetCategoryName() << std::endl;
				return false;
			}
		}
		else
		{
			//the User Haven't created any category before
			std::system("cls");
			std::cout << "------------------------------------------" << std::endl;
			std::cout << "Empy Category list" << std::endl;
			std::cout << "------------------------------------------" << std::endl;

			std::cout << "The game is going to add to the category: " << Uncategorized.GetCategoryName() << std::endl;
			Uncategorized.AddGame(InGame);
			return true;
		}
	}
	else
	{
		std::cout << "The game is going to add to the category: " << Uncategorized.GetCategoryName() << std::endl;
		Uncategorized.AddGame(InGame);
		return true;
	}
}

//------------------------------------------------------------------------
bool FSteam::AddNewCategory()
{
	//creating a new category
	std::system("cls");
	std::cout << "Please enter the name for the new category" << std::endl;

	std::string CategoryName;
	std::cin.ignore(500, '\n');
	std::getline(std::cin, CategoryName);

	return CategoryContainer.AddCategory(CategoryName);
};

//------------------------------------------------------------------------
bool FSteam::DeleteACategory()
{
	if (!CategoryContainer.IsEmpy())
	{
		//Deleting a category
		std::system("cls");
		CategoryContainer.PrintCategories();
		std::cout << "-----------------------------------------------" << std::endl;

		std::cout << "Selected the category to delete" << std::endl;
		int CategorySelected;
		std::cin >> CategorySelected;

		CategorySelected = ValidateInput(CategorySelected, 1, CategoryContainer.GetCurrentCategoryAmount()) - 1;
		return CategoryContainer.DeleteCategory(CategorySelected);
	}
	return false;
};

//-----------------------------------------------------------------------------
void FSteam::ComeBackMainManu()
{
	while (std::cin)
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
