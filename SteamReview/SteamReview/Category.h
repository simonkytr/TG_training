#pragma once
#include <iostream>
#include "Game.h"
class FCategory
{
	/*La clase deber�a tener la funcionalidad de a�adir nuevos juegos a su arreglo de juegos y deber�a tener una funci�n para saber si le caben m�s juegos.
*/
private:
	static const int MaxGamesCount = 6;
	std::string CategoryName;
	FGame Games[MaxGamesCount];
	int GameCount;

public:
	FCategory();
	FCategory(const std::string InCategoryName);
	std::string GetCategoryName() const;
	bool AddGame(const FGame InGame);
	FGame GetGame(const int GameIndex) const;
	bool IsCategoryFull() const;
	bool IsCategoryValid() const;
	void DisplayCategory() const;
};
