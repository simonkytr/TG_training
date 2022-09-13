#pragma once
template <typename Type>
class TSLList
{
private:

	int Size = 0;
	FNode* Head = nullptr;
	FNode* Tail = nullptr;

	struct FNode
	{
		Type Element;
		FNode* Next = nullptr;
	};

public:

	Type& operator[] (const int Index)
	{
		return TSLList[Index];
	}

	const Type& operator[] (const int Index) const
	{
		return TSLList[Index];
	}

	//-----------------------------------------------
	Type& Head()
	{
		return TSLList[0];
	}

	const Type& Head() const
	{
		return TSLList[0];
	}

	//-----------------------------------------------
	Type& Tail()
	{
		return TSLList[Size - 1];
	}

	const Type& Tail() const
	{
		return TSLList[Size - 1];
	}

	//-----------------------------------------------

};