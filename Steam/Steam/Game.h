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
	FGame(std::string InName, std::string InStudio, int InDay, int InMonth, int InYear);
	std::string GetGameName() const;
	std::string GetGameStudio() const;
	std::string GetGameDateFormat() const;
	bool IsValid() const;
};
	
