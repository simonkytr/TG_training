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