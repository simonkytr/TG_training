#include <iostream>
#include "Category.h"

FCategory::FCategory()
{
	CategoryName = "";
	GameCount = 0;
};

//-------------------------------------------------
FCategory::FCategory(const std::string& InCategoryName)
{
	GameCount = 0;
	CategoryName = InCategoryName;
};

//-------------------------------------------------
std::string FCategory::GetCategoryName() const
{
	return CategoryName;
};
//-------------------------------------------------
bool FCategory::IsFull() const
{
	return GameCount == MaxGamesCount;
};

//-------------------------------------------------
bool FCategory::AddGame(const FGame& InGame)
{
	if (!IsFull() && IsValid())
	{
		Games[GameCount] = InGame;
		GameCount++;
		return true;
	}
	return false;
};

//-------------------------------------------------
const FGame& FCategory::GetGame(const int GameIndex) const
{
	if (GameIndex < GameCount)
	{
		return Games[GameIndex];
	}
	FGame VoidGame;
	return VoidGame;
};

//-------------------------------------------------
bool FCategory::IsValid() const
{
	return !CategoryName.empty();
};

//-------------------------------------------------
void FCategory::DisplayCategory() const
{
	std::cout << "\nCategory: " << CategoryName << std::endl;
	std::cout << "\nGame Name" << "\tDeveloper Studio" << "\tRelease Date" << std::endl;
	std::cout << "-----------------------------------------------------------------" << std::endl;
	for (int i = 0; i < MaxGamesCount; i++)
	{
		std::cout << Games[i].GetGameName() << "\t" << Games[i].GetGameStudio() << "\t" << Games[i].GetGameDateFormat() << std::endl;
	}
};