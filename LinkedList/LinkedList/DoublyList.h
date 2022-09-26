#pragma once
#include <functional>

template <typename Type>
class TDLList
{
private:
	int Size = 0;
	struct FNode
	{
		Type Data;
		FNode* Next = nullptr;
		FNode* previous = nullptr;
	};
	FNode* Head = nullptr;
	FNode* Tail = nullptr;

public:
	TDLList() {}

	~TDLList() 
	{
		Clear();
	}

	//-----------------------------------CopyConstructor
	TDLList(const TDLList<Type>& OtherList)
	{
		Clear();
		FNode* CurrentNode = OtherList.Head;

		while(CurrentNode)
		{
			AddTail(CurrentNode->Data);
			CurrentNode = CurrentNode->Next;
		}
	}

	//------------------------------------Iterator
	class FIterator
	{
	private:
		FNode* Current;
	public:
		FIterator(FNode* NewCurrent)
		{
			Current = NewCurrent;
		}

		FIterator& operator++()
		{
			Current = Current->Next;
			return *this;
		}

		Type& operator*()
		{
			return Current->Data;
		}

		const Type& operator*() const
		{
			return Current->Data;
		}

		bool operator!=(const FIterator& Other)
		{
			return Current != Other.Current;
		}

		bool operator!=(const FIterator& Other) const
		{
			return Current != Other.Current;
		}
	};

	FIterator begin()
	{
		return FIterator(Head);
	}

	FIterator end()
	{
		return FIterator(nullptr);
	}
	

	//---------------------------------Access
	Type& operator[](const int Index)
	{
		FNode* Current;
		if (Index < Size / 2)
		{
			Current = Head;
			for (int i = 0; i < Index / 2; i++)
			{
				Current = Current->Next;
			}
			return Current->Data;
		}
		else
		{
			Current = Tail;
			for (int i = Size - 1; i < Index / 2; i--)
			{
				Current = Current->previous;
			}
			return Current->Data;
		}
	}

	const Type& operator[](const int Index) const
	{
		FNode* Current;
		if (Index < Size / 2)
		{
			Current = Head;
			for (int i = 0; i < Index; i++)
			{
				Current = Current->Next;
			}
			return Current->Data;
		}
		else
		{
			Current = Tail;
			for (int i = Size - 1; i > Index; i--)
			{
				Current = Current->previous;
			}
			return Current->Data;
		}
	}

	//-------------------------------------------------------
	TDLList& operator=(const TDLList<Type>& OtherList)
	{
		Clear();
		FNode* CurrentNode = OtherList.Head;

		for (int i = 0; i < OtherList.Size; i++)
		{
			AddTail(CurrentNode->Data);
			CurrentNode = CurrentNode->Next;
		}
		return *this;
	}

	//--------------------------------------------------------
	Type& GetHead()
	{
		return Head->Data;
	}

	const Type& GetHead() const
	{
		return Head->Data;
	}

	//---------------------------------------------------------
	Type& GetTail()
	{
		return Tail->Data;
	}

	const Type& GetTail() const
	{
		return Tail->Data;
	}

	//---------------------------------Size
	bool IsEmpty() const
	{
		return Size == 0;
	}

	//------------------------------------------------
	int GetSize() const
	{
		return Size;
	}

	//-----------------------------------Modifiers
	void AddHead(const Type& InHead)
	{
		FNode* NewHead = new FNode;
		NewHead->Data = InHead;

		if (!Head)
		{
			Tail = NewHead;
		}
		else
		{
			NewHead->Next = Head;
			Head->previous = NewHead;
			NewHead->previous = nullptr;
		}
		Head = NewHead;
		Size++;
	}

	//--------------------------------------------------
	void AddTail(const Type& InTail)
	{
		if (IsEmpty())
		{
			AddHead(InTail);
		}
		else
		{
			Tail->Next = new FNode;
			Tail->Next->Data = InTail;
			Tail->Next->previous = Tail;
			Tail = Tail->Next;
			
			Size++;
		}
	}

	//--------------------------------------------------
	void Insert(const Type& NewData, const int Index)
	{
		if (Index < 0 || Index > Size)
		{
			return;
		}
		else if (Index == 0)
		{
			AddHead(NewData);
		}
		else
		{
			if (Index == Size)
			{
				AddTail(NewData);
			}
			else
			{
				FNode* NewNode = new FNode;
				NewNode->Data = NewData;

				FNode* Current = GetNode(Index);
				NewNode->previous = Current->previous;
				Current->previous->Next = NewNode;

				NewNode->Next = Current;
				Current->previous = NewNode;	

				Size++;
			}
		}
	}

	//-------------------------------------------------------
	void RemoveHead()
	{
		if (Size != 0)
		{
			FNode* NewNode = Head->Next;
			delete Head;
			Head = NewNode;

			if (Size == 1)
			{
				Head = nullptr;
				Tail = nullptr;
			}
			--Size;
		}
	}

	//--------------------------------------------------------
	void Remove(const int Index)
	{
		if (Index < 0 || Index > Size)
		{
			return;
		}
		if (Index == 0)
		{
			RemoveHead();
		}
		else
		{
			FNode* Current = GetNode(Index);
			
			Current->previous->Next = Current->Next;

			if (Current->Next != nullptr)
			{
				Current->Next->previous = Current->previous;
			}
			
			delete Current;
			Size--;
		}
	}

	//-----------------------------------------------------------
	void Clear()
	{
		while (Head)
		{
			RemoveHead();
		}
	}

	//----------------------------------------ForEach
	template<typename Pred>
	void ForEach(const Pred& Predicate)
	{
		for (Type& Temporal : *this)
		{
			Predicate(Temporal);
		}
	}

	//----------------------------------------Lambdas
	template< typename Pred>
	Type* FindByPredicate(const Pred& Predicate) const
	{
		for (Type& Current : *this)
		{
			if (Predicate(Current))
			{
				return &Current->Data;
			}
		}
		return nullptr;
	};

	//-------------------------------------------------
	template< typename Pred>
	TSLList<Type> FilterByPredicate(const Pred& Predicate)
	{
		TSLList <Type> FilterList;

		for (Type& Current : *this)
		{
			if (Predictate(Current))
			{
				FilterList.AddTail(Current);
			}
		}
		return FilterList;
	};

	//-------------------------------------------------
	template< typename Pred>
	TDLList<Type> FilterByPredicate(const Pred& Predicate)
	{
		TDLList <Type> FilterList;

		for (Type& Current : *this)
		{
			if (Predictate(Current))
			{
				FilterList.AddTail(Current);
			}
		}

		return FilterList;
	};

	//-------------------------------------------------
	template< typename Pred>
	void RemoveAllByPredicate(const Pred& Predicate)
	{
		FNode* Current = Head;
		for (int i = 0; i < Size; i++)
		{
			if (Predicate(Current))
			{
				Remove(i);
				i--;
			}
			Current = Current->Next;
		}
	}

	private:
		//-------------------------------------------------------
		FNode* GetNode(const int Index)
		{
			FNode* Current;
			if (Index < Size / 2)
			{
				Current = Head;
				for (int i = 0; i < Index; i++)
				{
					Current = Current->Next;
				}
				return Current;
			}
			else
			{
				Current = Tail;
				for (int i = Size - 1; i > Index; i--)
				{
					Current = Current->previous;
				}
				return Current;
			}
		}

		const FNode* GetNode(const int Index) const
		{
			FNode* Current;
			if (Index < Size / 2)
			{
				Current = Head;
				for (int i = 0; i < Index; i++)
				{
					Current = Current->Next;
				}
				return Current->Data;
			}
			else
			{
				Current = Tail;
				for (int i = Size - 1; i > Index; i--)
				{
					Current = Current->previous;
				}
				return Current->Data;
			}
		}

};