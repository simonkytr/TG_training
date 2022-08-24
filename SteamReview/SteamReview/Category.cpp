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
FCategory::~FCategory()
{
	//Destructor
};

//-------------------------------------------------
FCategory::FCategory(FCategory& OtherCategory)
{
	CategoryName = OtherCategory.CategoryName;
	memcpy_s(Games, sizeof(Games), OtherCategory.Games, sizeof(Games));
	GameCount = OtherCategory.GameCount;
};

//-------------------------------------------------
const std::string& FCategory::GetCategoryName() const
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
bool FCategory::GetGame(const int GameIndex, FGame& OutGame) const
{
	if (GameIndex < GameCount)
	{
		OutGame = Games[GameIndex];
		return true;
	}
	return false;
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
			std::cout << Games[i].GetGameName() << "\t" << Games[i].GetGameStudio() << "\t" << Games[i].GetDateReleaseFormat() << std::endl;
	}
};