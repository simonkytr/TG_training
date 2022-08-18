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
	~FCategoryContainer();
	FCategoryContainer(FCategoryContainer& OtherContainer);
	bool GetCategory(const int InCategoryIndex, FCategory& OutCategory) const;

	bool AddCategory(const FCategory& InCategory);
	bool DeleteCategory(const int InCategoryIndex);
	
	bool AddGameToCategory(const int IndexCategory, const FGame& InGame);
	void PrintCategories() const;

	int GetCurrentCategoryAmount() const;
	bool IsEmpy() const;
};