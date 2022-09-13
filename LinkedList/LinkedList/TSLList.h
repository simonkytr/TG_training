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

	//-----------------------------------Modifiers
	bool AddHead(const Type& InHead)
	{
		FNode* NewHead = new FNode;
		NewHead->Element = InHead;

		if (Head == nullptr)
		{
			Head = NewHead;
			return true;
		}
		else
		{
			NewHead->Next = Head;
			Head = NewHead;
			return true;
		}
		return false;
	}

	//-------------------------------------------------
	bool AddTail(const Type& InTail)
	{
		FNode* NewTail = new FNode;
		NewTail->Element = InTail;

		if (Tail == nullptr)
		{
			Tail = NewTail;
			return true;
		}
		else
		{
			NewTail->Next = Tail;
			Tail = NewTail;
			return true;
		}
		return false;
	}
	
	//----------------------------------------------------
	void Insert(const int Index, const Type& NewItem)
	{
		FNode* Temporal = Head;
		FNode* Container = new FNode;

		for (int i = 0; i < index; i++)
		{
			Temporal = Temporal->Next;
		}
		Container->Element = Temporal->Element;
		Temporal->Element = NewItem;
		Temporal->Next = Container;
		Size++;
	}

	//---------------------------------------------------------
	void Remove(const int Index)
	{
		FNode* Temporal = Head;

		for (int i = 0; i < index - 1; i++)
		{
			Temporal = Temporal->Next;
		}

		FNode* Current = Temporal->Next;
		Temporal->Next = Current->Next;
		delete Current;
		
	}

	//----------------------------------------------------------
	void Clear()
	{
		FNode* NextItem = new FNode;

		for (int i = 0; i < Size; i++)
		{
			NextItem = Head->Next;
			delete Head;
			Head = NextItem;
		}
	}

	//---------------------------------------------------------
};