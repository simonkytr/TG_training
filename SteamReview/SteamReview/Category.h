#pragma once
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

	bool AddGame(const FGame InGame);
	FGame GetGame(const int GameIndex) const;

	bool IsFull() const;
	bool IsValid() const;

	std::string GetCategoryName() const;
	void DisplayCategory() const;
};
