#pragma once
#include <iostream>
#include "Game.h"
class FCategory
{
	/*La clase debería tener la funcionalidad de añadir nuevos juegos a su arreglo de juegos y debería tener una función para saber si le caben más juegos.
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
