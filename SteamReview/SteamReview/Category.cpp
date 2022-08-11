#include <iostream>
#include "Category.h"

FCategory::FCategory()
{
	CategoryName = "";
	GameCount = 0;
};

//-------------------------------------------------
FCategory::FCategory(const std::string InCategoryName)
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
bool FCategory::IsCategoryFull() const
{
	return GameCount == MaxGamesCount;
};

//-------------------------------------------------
bool FCategory::AddGame(const FGame InGame)
{
	if (!IsCategoryFull() && IsCategoryValid())
	{
		Games[GameCount] = InGame;
		GameCount++;
		return true;
	}
	return false;
};

//-------------------------------------------------
FGame FCategory::GetGame(const int GameIndex) const
{
	return Games[GameIndex];
};

//-------------------------------------------------
bool FCategory::IsCategoryValid() const
{
	return CategoryName != "";
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