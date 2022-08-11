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
	bool AddCategory(const FCategory InCategory);
	bool DeleteCategory(const int InCategoryIndex);
	FCategory GetCategory(const int InCategoryIndex) const;
	bool AddGameToCategory(const int IndexCategory, const FGame InGame);
	void PrintCategory() const;
	int GetCurrentCategory() const;
};