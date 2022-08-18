#include "CategoryContainer.h"
#include <iostream>

FCategoryContainer::FCategoryContainer()
{
	CategoryCount = 0;
};

//---------------------------------------------------------
bool FCategoryContainer::AddCategory(const FCategory& InCategory)
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
FCategoryContainer::~FCategoryContainer()
{
	//Destructor
};

//--------------------------------------------------------
FCategoryContainer::FCategoryContainer(FCategoryContainer& OtherContainer)
{
	CategoryCount = OtherContainer.CategoryCount;
	memcpy_s(Categories, sizeof(Categories), OtherContainer.Categories, sizeof(OtherContainer.CategoryCount));
};

//---------------------------------------------------------
bool FCategoryContainer::DeleteCategory(const int InCategoryIndex)
{
	if (InCategoryIndex >= 0 && InCategoryIndex < CategoryCount)
	{
		for (int i = InCategoryIndex; i < CategoryCount - 1; i++)
		{
			Categories[i] = Categories[i + 1];
			CategoryCount--;
		}
		return true;
	}
	return false;
};

//---------------------------------------------------------
bool FCategoryContainer::GetCategory(const int InCategoryIndex, FCategory& OutCategory) const
{
	if (InCategoryIndex < CategoryCount)
	{
		OutCategory = Categories[InCategoryIndex];
		return true;
	}
	return false;
};

//----------------------------------------------------------
bool FCategoryContainer::AddGameToCategory(const int IndexCategory, const FGame& InGame)
{
	if (IndexCategory < CategoryCount && IndexCategory >= 0)
	{
		return Categories[IndexCategory].AddGame(InGame);
	}
	return false;
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
bool FCategoryContainer::IsEmpy() const
{
	return CategoryCount <= 0;
};