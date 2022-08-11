#include "CategoryContainer.h"
#include <iostream>

FCategoryContainer::FCategoryContainer()
{
	CategoryCount = 0;
};

//---------------------------------------------------------
bool FCategoryContainer::AddCategory(FCategory InCategory)
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
bool FCategoryContainer::DeleteCategory(int InCategoryIndex) 
{
	if ((InCategoryIndex >= 0))
	{
		for (int i = InCategoryIndex; i < CategoryCount && i < MaxCategoryCount - 1; i++)
		{
			Categories[i] = Categories[i + 1];
			CategoryCount --;
		}
		return true;
	}
	return false;
};

//---------------------------------------------------------
FCategory FCategoryContainer::GetCategory(int InCategoryIndex) const
{
	return Categories[InCategoryIndex];
};

//----------------------------------------------------------
bool FCategoryContainer::AddGameToCategory(int IndexCategory, FGame InGame)
{
	return Categories[IndexCategory].AddGame(InGame);
};
	

//----------------------------------------------------------
void FCategoryContainer::PrintCategory() const
{
	std::cout << "These are the Categories that you have been created..." << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;
	for (int i = 0; i < CategoryCount; i++)
	{
		std::cout << "category #" << i + 1 << " - " << Categories[i].GetCategoryName() << std::endl;
	}
};

//-----------------------------------------------------------
int FCategoryContainer::GetCurrentCategory() const
{
	return CategoryCount;
}
