#pragma once
template <typename Type>
class TSLList
{
private:

	int Size = 0;
	struct FNode
	{
		Type Element;
		FNode* Next = nullptr;
	};
	FNode* Head = nullptr;
	FNode* Tail = nullptr;

public:

	//-------------------------Access
	Type& operator[] (const int Index)
	{
		FNode* Temporal = Head; 
		for (int i = 0; i < index; i++)
		{
			Temporal = Temporal->Next;
		}
		return Temporal->Element;
	}

	const Type& operator[] (const int Index) const
	{
		FNode* Temporal = Head;
		for (int i = 0; i < index; i++)
		{
			Temporal = Temporal->Next;
		}
		return Temporal->Element;
	}

	//-----------------------------------------------
	Type& Head()
	{
		return Head->Element;
	}

	const Type& Head() const
	{
		return Head->Element;
	}

	//-----------------------------------------------
	Type& Tail()
	{
		return Tail->Element;
	}

	const Type& Tail() const
	{
		return Tail->Element;
	}

	//---------------------------------Size
	bool IsEmpty()
	{
		return Size == 0;
	}

	//------------------------------------------------
	int GetSize()
	{
		return Size;
	}

	
};