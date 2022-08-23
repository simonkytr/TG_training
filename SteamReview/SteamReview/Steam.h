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

	int GetValidateInput(const int LowBoundValue, const int HighBoundValue) const;

	void CreateNewGame(FGame& InGame) const;
	bool AddNewGameToCategory(const FGame& InGame);
	bool AddNewCategory();
	bool DeleteCategory();

	void ComeBackMainManu();

public:
	FSteam();
	FSteam(const FSteam& OtherSteam);
	void RunApp();
};