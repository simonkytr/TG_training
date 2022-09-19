#pragma once
#include <functional>

template <typename Type>
class TSLList
{
private:
	int Size;
	struct FNode
	{
		Type Element;
		FNode* Next = nullptr;
	};
	FNode* Head = nullptr;
	FNode* Tail = nullptr;

public:
	TSLList()
	{
		Size = 0;
	}

	~TSLList()
	{
		Clear();
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
			return Current->Element;
		}

		const Type& operator*() const
		{
			return Current->Element;
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
		if(Head)
			return FIterator(Head);
		return FIterator(nullptr);
	}

	FIterator end()
	{
		return FIterator(nullptr);
	}

	//-------------------------------CopyConstructor
	TSLList(const TSLList<Type>& OtherTSLlist)
	{
		FNode* Temporal = OtherTSLlist.Head;

		for (int i = 0; i < Size; i++)
		{
			AddTail(Temporal->Element);
			Temporal = Temporal->Next;
		}
	}

	//-------------------------Access
	Type& operator[] (const int Index)
	{
		FNode* Temporal = Head; 
		for (int i = 0; i < Index; i++)
		{
			Temporal = Temporal->Next;
		}
		return Temporal->Element;
	}

	const Type& operator[] (const int Index) const
	{
		FNode* Temporal = Head;
		for (int i = 0; i < Index; i++)
		{
			Temporal = Temporal->Next;
		}
		return Temporal->Element;
	}

	//-----------------------------------------------
	TSLList& operator= (const TSLList<Type>& OtherTSLlist)
	{
		Clear();
		FNode* Temporal = OtherTSLlist.Head;

		for (int i = 0; i < Size; i++)
		{
			AddTail(Temporal->Element);
			Temporal = Temporal->Next;
		}
		return *this;

	}

	//-----------------------------------------------
	Type& GetHead()
	{
		return Head->Element;
	}

	const Type& GetHead() const
	{
		return Head->Element;
	}

	//-----------------------------------------------
	Type& GetTail()
	{
		return Tail->Element;
	}

	const Type& GetTail() const
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
	void AddHead(const Type& InHead)
	{
		FNode* NewHead = new FNode;
		NewHead->Element = InHead;

		if (Head == nullptr)
		{
			Head = NewHead;
			Tail = NewHead;
			Size++;
		}
		else
		{
			NewHead->Next = Head;
			Head = NewHead;
			Size++;
		}
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
			Tail->Next->Element = InTail;
			Tail = Tail->Next;
			Size++;
		}
	}
	
	//----------------------------------------------------
	void Insert(const Type& NewItem, const int Index)
	{
		if (Index == 0)
		{
			AddHead(NewItem);
		}
		else if(Index == Size)
		{
			AddTail(NewItem);
		}

		else if (Index > 0 && Index < Size)
		{
			FNode* Temporal = Head;
			FNode* Container = new FNode;

			for (int i = 0; i < Index; i++)
			{
				Temporal = Temporal->Next;
			}
			Container->Element = Temporal->Element;

			Temporal->Element = NewItem;
			Container->Next = Temporal->Next;
			Temporal->Next = Container;
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
		}

		else if (Size == 1)
		{
			delete Head;
			Head = nullptr;
			Tail = nullptr;
			--Size;
		}
	}

	//---------------------------------------------------------
	void Remove(const int Index)
	{
		FNode* Temporal = Head;

		if (Index >= 0 && Index <= Size)
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
	template<typename Function>
	void forEach(const Function& SomeFunction)
	{
		FNode* Temporal = Head;
		for (int i = 0; i < Size; i++)
		{
			SomeFunction(Temporal);
			Temporal = Temporal->Next;
		}
	}

	//----------------------------------------Lambdas
	template< typename Pred>
	Type* FindByPredicate(const Pred& Predictate)
	{
		FNode* Temporal = Head;
		for (int i = 0; i < Size; i++)
		{
			if (Predictate(Temporal))
			{
				return &Temporal->Element;
			}
			Temporal = Temporal->Next;
		}
		return nullptr;
	};

	//-------------------------------------------------
	template< typename Pred>
	TSLList<Type> FilterByPredicate(const Pred& Predicate)
	{
		FNode* Temporal;
		TSLList <Type> Filterlist;

		for(int i = 0; i < Size; i++)
		{
			if (Predictate(Temporal))
			{
				Filterlist.AddTail(Temporal);
				return Filterlist;				
			}
			Temporal = Temporal->Next;
		}
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
		return false;
	}

};