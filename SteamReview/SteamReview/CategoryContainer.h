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
	const FCategory& GetCategory(const int InCategoryIndex) const;

	bool AddCategory(const FCategory& InCategory);
	bool DeleteCategory(const int InCategoryIndex);
	
	bool AddGameToCategory(const int IndexCategory, const FGame& InGame);
	void PrintCategories() const;

	int GetCurrentCategoryAmount() const;
	bool IsEmpy() const;
};