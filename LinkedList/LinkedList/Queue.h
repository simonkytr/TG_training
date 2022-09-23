#pragma once
#include "TSLList.h"

template <typename Type>
class TQueue
{
private:
	TSLList<Type> QueueArray;
public:
	bool IsEmpty()
	{
		return Queue.IsEmpty();
	}

	void Enqueue(const Type& NewData)
	{
		QueueArray.AddTail(NewData);
	}

	void Dequeue()
	{
		QueueArray.RemoveHead();
	}

	void Front()
	{
		
			QueueArray.GetHead();
	}
};