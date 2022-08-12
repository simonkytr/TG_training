#include "CategoryContainer.h"
#include <iostream>

FCategoryContainer::FCategoryContainer()
{
	CategoryCount = 0;
};

//---------------------------------------------------------
bool FCategoryContainer::AddCategory(const FCategory InCategory)
{
	if (CategoryCount < MaxCategoryCount)
	{
		Categories[CategoryCount] = InCategory;
		CategoryCount++;
		return true;
	}
	return false;
};

//---------------------------------------------------------
bool FCategoryContainer::DeleteCategory(const int InCategoryIndex)
{
	if (InCategoryIndex >= 0)
	{
		for (int i = InCategoryIndex; i < CategoryCount && i < MaxCategoryCount - 1; i++)
		{
			Categories[i] = Categories[i + 1];
			CategoryCount--;
		}
		return true;
	}
	return false;
};

//---------------------------------------------------------
FCategory FCategoryContainer::GetCategory(const int InCategoryIndex) const
{
	return Categories[InCategoryIndex];
};

//----------------------------------------------------------
bool FCategoryContainer::AddGameToCategory(const int IndexCategory, const FGame InGame)
{
	return Categories[IndexCategory].AddGame(InGame);
};


//----------------------------------------------------------
void FCategoryContainer::PrintCategories() const
{
	std::cout << "These are the Categories that you have been created..." << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	for (int i = 0; i < CategoryCount; i++)
	{
		std::cout << "category #" << i + 1 << " - " << Categories[i].GetCategoryName() << std::endl;
	}
};

//-----------------------------------------------------------
int FCategoryContainer::GetCurrentCategoryAmount() const
{
	return CategoryCount;
};

//-----------------------------------------------------------
bool FCategoryContainer::IsEmpy()
{
	return CategoryCount <= 0;
};