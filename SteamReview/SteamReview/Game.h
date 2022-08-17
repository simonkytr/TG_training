#pragma once

#include <iostream>
class FGame
{
private:
	std::string NameGame;
	std::string GameStudio;
	int Day;
	int Month;
	int Year;
public:
	FGame();
	FGame(const std::string& NameRef, const std::string& GameStudioRef, const int& DayRef, const int& MonthRef, const int& YearRef);

	std::string GetGameName() const;
	std::string GetGameStudio() const;
	std::string GetGameDateFormat() const;

	bool IsValid() const;
};
