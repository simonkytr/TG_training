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
	void InputValidate(int InputToValid);
	void InputValidate(int InputToValid, int IntLowValueToValid, int IntHighValueToValid);

public:
	FSteam();
	void AppRun();
};