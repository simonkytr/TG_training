#pragma once
#include <iostream>
#include "Category.h"

class FCategoryContainer
{
private:
	static const int MaxCategoryCount = 6;
	FCategory Categories[MaxCategoryCount];
	int CategoryCount;
public:
	FCategoryContainer();
	bool AddCategory(FCategory InCategory);
	bool DeleteCategory(int InCategoryIndex);
	FCategory GetCategory(int InCategoryIndex) const;
	bool AddGameToCategory(int IndexCategory, FGame InGame);
	void PrintCategory() const;
	int GetCurrentCategory() const;
};
