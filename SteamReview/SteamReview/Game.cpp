#include <iostream>
#include <string>
#include "Game.h"
FGame::FGame()
{
	NameGame = "";
	StudioGame = "";
	Day = 0;
	Month = 0;
	Year = 0;
};

//-----------------------------------------------------
FGame::FGame(const std::string InNameGame, const std::string InStudioGame, const int InDay, const int InMonth, const int InYear)
{
	NameGame = InNameGame;
	StudioGame = InStudioGame;
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
	return StudioGame;
};

//-----------------------------------------------------
std::string FGame::GetGameDateFormat() const
{
	return std::to_string(Year) + "/" + std::to_string(Month) + "/" + std::to_string(Day);
};

//-----------------------------------------------------
bool FGame::IsValid() const
{
	return (NameGame != "") && (StudioGame != "") && (Day <= 0) && (Month <= 0) && (Year <= 0);
};