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
FGame::FGame(const std::string& NameRef, const std::string& GameStudioRef, const int& DayRef, const int& MonthRef, const int& YearRef)
{
	NameGame = NameRef;
	GameStudio = GameStudioRef;
	Day = DayRef;
	Month = MonthRef;
	Year = YearRef;
};

//-----------------------------------------------------
FGame::~FGame()
{
	//Destructor
};

//-----------------------------------------------------
FGame::FGame(const FGame& OtherGame)
{
	NameGame = OtherGame.NameGame;
	GameStudio = OtherGame.GameStudio;
	Day = OtherGame.Day;
	Month = OtherGame.Month;
	Year = OtherGame.Year;
};

//-----------------------------------------------------
const std::string& FGame::GetGameName() const
{
	return NameGame;
};
//-----------------------------------------------------
const std::string& FGame::GetGameStudio() const
{
	return GameStudio;
};

//-----------------------------------------------------
std::string FGame::GetDateReleaseFormat() const
{
	return std::to_string(Year) + "/" + std::to_string(Month) + "/" + std::to_string(Day);
};

//-----------------------------------------------------
bool FGame::IsValid() const
{
	return !NameGame.empty() && !GameStudio.empty() && Day <= 0 && Month <= 0 && Month > 12 && Year <= 0;
};