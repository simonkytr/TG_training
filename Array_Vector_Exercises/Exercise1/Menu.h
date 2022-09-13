#pragma once
#include <iostream>
#include "shape.h"
#include "Circle.h"
#include "Square.h"
#include "TStaticArray.h"
#include "TDinamicArray.h"

class FMenu
{
private:
	enum class EMenuCommand
	{
		MainMenu, BuildInArray, StaticArray, DynamicArray, Exit
	};
	EMenuCommand ActiveMenuCommand;

	void OpenMainMenu();
	void AskForBuildInArray();
	void AskForStaticArray();
	void AskForDynamicArray();

	void PrintArray(const FShape& Shape) const;
	FShape* CreateShape();

	int ValidateInput(int& UserInput, const int LowerBounce, const int HigherBounce);
	int ValidateInput(int& UserInput);
	float ValidateInputFloat(float& UserInput);

	void ComeBackMainManu();

public:
	FMenu();
	void RunApp();

};