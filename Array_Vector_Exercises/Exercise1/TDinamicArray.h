#pragma once

template<typename T>
class TDinamicArray
{
private:
	int SizeArray;
	int CapacityArray;
	T* DinamicArray;

public:
	TDinamicArray()
	{
		SizeArray = 1;
		ArrayCapacity = 1;
		DinamicArray = new T[CapacityArray];
	};

	~TDinamicArray()
	{
		delete[] DinamicArray;
	};

	//----------------------------------------------------------------------
	T& operator[] (const int index)
	{
		return DinamicArray[i];
	}

	const T& operator[] (const int index) const
	{
		return DinamicArray[i];
	}

	//-----------------------------------------------------------------------
	T& Front()
	{
		return DinamicArray[0];
	}

	const T& Front() const
	{
		return DinamicArray[0];
	}

	//------------------------------------------------------------------------
	T& Back()
	{
		return DinamicArray[SizeArray - 1];
	}

	const T& Back() const
	{
		return DinamicArray[SizeArray - 1];
	}

	//-----------------------------------------------------------------------
	T* GetData()
	{
		return DinamicArray;
	}

	const T* GetData() const
	{
		return DinamicArray;
	}

	//------------------------------------------------------------------------
	bool IsEmpty()
	{
		if (SizeArray == 0)
		{
			return true;
		}
		return false;
	};

	//-------------------------------------------------------------------------
	int GetSize()
	{
		return SizeArray;
	}

	//-------------------------------------------------------------------------
	int GetCapacity()
	{
		return CapacityArray;
	}

	//-------------------------------------------------------------------------
	void Reserve()
	{
		if (SizeArray == CapacityArray)
		{
			CapacityArray = SizeArray + 1;
		}
	}

	//--------------------------------------------------------------------------
	void ShrinkToFit()
	{
		if (CapacityArray != SizeArray)
		{
			CapacityArray = SizeArray;
		}
	}
};