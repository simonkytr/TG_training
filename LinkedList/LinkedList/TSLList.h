#pragma once
#include <functional>

template <typename Type>
class TSLList
{
private:
	int Size = 0;
	struct FNode
	{
		Type Data;
		FNode* Next = nullptr;
	};
	FNode* Head = nullptr;
	FNode* Tail = nullptr;

public:
	TSLList()
	{
	}

	~TSLList()
	{
		Clear();
	}

	//-------------------------------CopyConstructor
	TSLList(const TSLList<Type>& Otherlist)
	{
		FNode* Temporal = Otherlist.Head;

		for (int i = 0; i < Otherlist.Size; i++)
		{
			AddTail(Temporal->Data);
			Temporal = Temporal->Next;
		}
	}

	//--------------------------------FIterator
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

	//-------------------------Access
	Type& operator[](const int Index)
	{
		FNode* Temporal = Head; 
		for (int i = 0; i < Index; i++)
		{
			Temporal = Temporal->Next;
		}
		return Temporal->Data;
	}

	const Type& operator[](const int Index) const
	{
		FNode* Temporal = Head;
		for (int i = 0; i < Index; i++)
		{
			Temporal = Temporal->Next;
		}
		return Temporal->Data;
	}

	//-----------------------------------------------
	TSLList& operator=(const TSLList<Type>& Otherlist)
	{
		Clear();
		FNode* CurrentNode = Otherlist.Head;

		for (int i = 0; i < Otherlist.Size; i++)
		{
			AddTail(CurrentNode->Data);
			CurrentNode = CurrentNode->Next;
		}
		return *this;

	}

	//-----------------------------------------------
	Type& GetHead()
	{
		return Head->Data;
	}

	const Type& GetHead() const
	{
		return Head->Data;
	}

	//-----------------------------------------------
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

		if (Head == nullptr)
		{
			Head = NewHead;	
		}
		else
		{
			NewHead->Next = Head;
		}
		Head = NewHead;
		Size++;
	}

	//-------------------------------------------------
	void AddTail(const Type& InTail)
	{
		if (Head == nullptr)
		{
			AddHead(InTail);
		}
		else
		{
			Tail->Next = new FNode;
			Tail->Next->Data = InTail;
			Tail = Tail->Next;
			Size++;
		}
	}
	
	//----------------------------------------------------
	void Insert(const Type& NewItem, const int Index)
	{
		if (Index < 0 || Index > Size)
		{
			return;
		}
		else if (Index == 0)
		{
			AddHead(NewItem);
		}
		else if(Index == Size)
		{
			AddTail(NewItem);
		}
		else
		{
			FNode* Temporal = Head;

			for (int i = 0; i < Index; i++)
			{
				Temporal = Temporal->Next;
			}

			FNode* NewNode = new FNode;
			NewNode->Data = Temporal->Data;
			Temporal->Data = NewItem;

			NewNode->Next = Temporal->Next;
			Temporal->Next = NewNode;

			Size++;
		}
	}
	//---------------------------------------------------------
	void RemoveHead()
	{
		if (Size != 0)
		{
			FNode* NewHead = Head->Next;
			delete Head;
			Head = NewHead;
			--Size;

			 if (Size == 1)
			{
				Head = nullptr;
				Tail = nullptr;
				--Size;
			}
		}		
	}

	//---------------------------------------------------------
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

		FNode* Temporal = Head;
		else (Index > 0 && Index < Size)
		{
			for (int i = 0; i < Index - 1; i++)
			{
				Temporal = Temporal->Next;
			}

			FNode* Current = Temporal->Next;
			Temporal->Next = Current->Next;

			if (Current == Tail)
			{
				Tail = Temporal;
			}
			delete Current;
			
			Size--;
		}
	}

	//----------------------------------------------------------
	void Clear()
	{
		FNode* NextItem;

		for (int i = 0; i < Size; i++)
		{
			NextItem = Head->Next;
			delete Head;
			Head = NextItem;
		}
		Size = 0;
		Head = nullptr;
		Tail = nullptr;
	}

	//----------------------------------------ForEach
	template<typename Pred>
	void ForEach(const Pred& Predicate)
	{
		for (Type& Temporal: *this)
		{
			Predicate(Temporal);
		}
	}

	//----------------------------------------Lambdas
	template< typename Pred>
	Type* FindByPredicate(const Pred& Predicate) const
	{
		for (Type& Temporal : *this)
		{
			if (Predicate(Temporal))
			{
				return &Temporal->Data;
			}
		}
		return nullptr;
	};

	//-------------------------------------------------
	template< typename Pred>
	TSLList<Type> FilterByPredicate(const Pred& Predicate)
	{
		TSLList <Type> FilterList;

		for(Type& Temporal : *this)
		{
			if (Predictate(Temporal))
			{
				FilterList.AddTail(Temporal);		
			}
		}

		return FilterList;
	};

	//-------------------------------------------------
	template< typename Pred>
	void RemoveAllByPredicate(const Pred& Predicate)
	{
		FNode* Temporal = Head;
		for (int i = 0; i < Size; i++)
		{
			if (Predictate(Temporal))
			{
				Remove(i);
				i--;
			}
			Temporal = Temporal->Next;
		}
	}

};