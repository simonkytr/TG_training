#pragma once
#include "TSLList.h"

template <typename Type>
class TStack
{
private:
	TSLList<Type> StackArray;
public:
	bool IsEmpty() const
	{
		return StackArray.IsEmpty();
	}

	void Push(const Type NewData)
	{
		StackArray.AddHead(NewData);
	}

	void Pop()
	{
		StackArray.RemoveHead();
	}

	Type& Top()
	{
		StackArray.GetHead();
	}

	const Type& Top() const
	{
		StackArray.GetHead();
	}
};

