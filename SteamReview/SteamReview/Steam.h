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

	int ValidateInput(int InputValue, const int LowBoundValue, const int HighBoundValue);

	FGame AddNewGame();
	bool AddNewGameToCategory(const FGame InGame);
	bool AddNewCategory();
	bool DeleteACategory();

	void ComeBackMainManu();

public:
	FSteam();
	void AppRun();
};