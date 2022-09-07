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
		T* StaticArrayPtr = &StaticArray;
		return StaticArrayPtr;
	};

	T GetData() const
	{
		T* StaticArrayPtr = &StaticArray;
		return StaticArrayPtr;
	};
};