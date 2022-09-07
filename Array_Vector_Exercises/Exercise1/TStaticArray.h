#pragma once

template <typename T, const int N>
class TStaticArray
{
	static const SizeArray = N;
	T StaticArray[SizeArray];

	//---------------------------------------------------------
	T operator[int Index]
	{
		return StaticArray[Index];
	};

	T operator[int Index] const
	{
		return StaticArray[Index];
	};

	//---------------------------------------------------------
	T Front()
	{
		return StaticArray[0];
	};

	T Front() const
	{
		return StaticArray[0];
	};

	//---------------------------------------------------------
	T Back()
	{
		return StaticArray[SizeArray - 1];
	};

	T Back() const
	{
		return StaticArray[SizeArray - 1];
	};

	//---------------------------------------------------------
	T GetData()
	{
		return StaticArray;
	};

	T GetData() const
	{
		return StaticArray;
	};

	//---------------------------------------------------------
	bool IsEmpty()
	{
		if (SizeArray == 0)
		{
			return true;
		}
		return false;
	};

	//----------------------------------------------------------
	int GetSize()
	{
		return SizeArray;
	};

	//----------------------------------------------------------
	void Fill(T Type)
	{
		for (int i = 0; i < SizeArray; i++)
		{
			StaticArray[i] = Type;
		}
	};

	//----------------------------------------------------------
	void Swap(TStaticArray<T, N>& SwapArray)
	{
		T ArrayContainer[SizeArray];

		for (int i = 0; i < SizeArray; i++)
		{
			ArrayContainer[i] = StaticArray[i];
		}
		for (int i = 0; i < SizeArray; i++)
		{
			StaticArray[i] = SwapArray[i];
		}
		for (int i = 0; i < SizeArray; i++)
		{
			SwapArray[i] = ArrayContainer[i];
		}
	}
};