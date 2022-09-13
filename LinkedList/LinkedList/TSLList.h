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

	

};