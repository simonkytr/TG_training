#pragma once
#include <iostream>
#include "CategoryContainer.h"

class FSteam
{
private:
	FCategoryContainer CategoryContainer;
	FCategory Uncategorized;
	enum class EMenuCommand
	{
		MainMenu, AddGame, CategoryManager, DisplayGames, Exit
	};
	EMenuCommand ActiveMenuCommand;
	void OpenMainMenu();
	void OpenAddGame();
	void OpenCategoryManager();
	void OpenDisplayGames();

	int InputValidate(int InputToValid, const int IntLowValueToValid, const int IntHighValueToValid);

	FGame AddANewGame();
	bool AddNewGameToCategory(const FGame InGame, const int UserInput);
	bool AddNewCategory();
	bool DeleteACategory();

public:
	FSteam();
	void AppRun();
};