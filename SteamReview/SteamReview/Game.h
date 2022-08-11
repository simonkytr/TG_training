#pragma once

#include <iostream>
class FGame
{
private:
	std::string NameGame;
	std::string StudioGame;
	int Day;
	int Month;
	int Year;
public:
	FGame();
	FGame(const std::string InName, const std::string InStudio, const int InDay, const int InMonth, const int InYear);
	std::string GetGameName() const;
	std::string GetGameStudio() const;
	std::string GetGameDateFormat() const;
	bool IsValid() const;
};
