#pragma once

template<typename T>
class TDinamicArray
{
private:
	int SizeArray;
	int CapacityArray;

public:
	TDinamicArray()
	{
		SizeArray = 1;
		ArrayCapacity = 1;
		T* ArrayPtr = new T[SizeArray];
	};

	~TDinamicArray()
	{
		delete[] ArrayPtr;
	};
};