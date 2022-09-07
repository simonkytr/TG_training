#pragma once

template<typename T>
class TDinamicArray
{
private:
	static int ArraySize;
	static int ArrayCapacity;

	T StaticArray[SizeArray];
public:
	TDinamicArray()
	{
		ArraySize = 1;
		ArrayCapacity = 1;
	};

	~TDinamicArray()
	{
		//Destructor
	};
};