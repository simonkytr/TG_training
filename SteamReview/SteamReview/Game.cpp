#include <iostream>
#include <string>
#include "Game.h"
FGame::FGame()
{
	Day = 0;
	Month = 0;
	Year = 0;
};

//-----------------------------------------------------
FGame::FGame(const std::string InNameGame, const std::string InGameStudio, const int InDay, const int InMonth, const int InYear)
{
	NameGame = InNameGame;
	GameStudio = InGameStudio;
	Day = InDay;
	Month = InMonth;
	Year = InYear;
};

//-----------------------------------------------------
std::string FGame::GetGameName() const
{
	return NameGame;
};
//-----------------------------------------------------
std::string FGame::GetGameStudio() const
{
	return GameStudio;
};

//-----------------------------------------------------
std::string FGame::GetGameDateFormat() const
{
	return std::to_string(Year) + "/" + std::to_string(Month) + "/" + std::to_string(Day);
};

//-----------------------------------------------------
bool FGame::IsValid() const
{
	return NameGame.empty() && GameStudio.empty() && Day <= 0 && Month <= 0 && Year <= 0;
};