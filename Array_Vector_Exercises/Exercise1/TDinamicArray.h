#pragma once

template<typename T>
class TDynamicArray
{
private:
	int SizeArray;
	int CapacityArray;
	T* DynamicArray;

public:
	TDynamicArray()
	{
		SizeArray = 0;
		ArrayCapacity = 1;
		DynamicArray = new T[CapacityArray];
	};

	~TDynamicArray()
	{
		delete[] DynamicArray;
	};

	//----------------------------------------------------------------------
	T& operator[] (const int index)
	{
		return DynamicArray[i];
	}

	const T& operator[] (const int index) const
	{
		return DynamicArray[i];
	}

	//-----------------------------------------------------------------------
	T& Front()
	{
		return DynamicArray[0];
	}

	const T& Front() const
	{
		return DynamicArray[0];
	}

	//------------------------------------------------------------------------
	T& Back()
	{
		return DynamicArray[SizeArray - 1];
	}

	const T& Back() const
	{
		return DynamicArray[SizeArray - 1];
	}

	//-----------------------------------------------------------------------
	T* GetData()
	{
		return DynamicArray;
	}

	const T* GetData() const
	{
		return DynamicArray;
	}

	//------------------------------------------------------------------------
	bool IsEmpty() const
	{
		if (SizeArray == 0)
		{
			return true;
		}
		return false;
	};

	//-------------------------------------------------------------------------
	int GetSize() const
	{
		return SizeArray;
	}

	//-------------------------------------------------------------------------
	int GetCapacity() const
	{
		return CapacityArray;
	}

	//-------------------------------------------------------------------------
	void Reserve(const int NewCapacity)
	{
		if (NewCapacitye > CapacityArray)
		{
			T* ContainerArray = new T[NewCapacity];

			for (int i = 0; i < SizeArray; i++)
			{
				ContainerArray[i] = DynamicArray[i];
			}
			delete[] DynamicArray;

			DynamicArray = ContainerArray;
			CapacityArray = NewCapacity;
		}
	}

	//--------------------------------------------------------------------------
	void ShrinkToFit()
	{
		if (CapacityArray != SizeArray)
		{
			T* ContainerArray = new T[SizeArray];

			for (int i = 0; i < SizeArray; i++)
			{
				ContainerArray[i] = DynamicArray[i];
			}
			delete[] DynamicArray;

			DynamicArray = ContainerArray;
		}
	}

	//--------------------------------------------------------------------------
	void Clear()
	{
		SizeArray = 0;
	}

	//--------------------------------------------------------------------------
	void PushBack(const T& InType)
	{
		if (SizeArray == CapacityArray)
		{
			Reserve(CapacityArray * 2);
			DynamicArray[SizeArray] = InType;
			SizeArray++;
		}
		else
		{
			DynamicArray[size] = InType;
			SizeArray++;
		}
	}

	//-----------------------------------------------------------------------------
	void Pushpop()
	{
		if (SizeArray != 0)
		{
			SizeArray--;
		}
	}

	//-----------------------------------------------------------------------------
	void Insert(const int Index, const T& InType)
	{
		if (Index < SizeArray && Index >= 0)
		{
			if (SizeArray == CapacityArray)
			{
				Reserve(CapacityArray * 2);
			}
				
			for (int i = 0; i < SizeArray; i++)
			{
				DynamicArray[Index + 1] = DynamicArray[Index];
			}
			DynamicArray[Index] = InType;
			SizeArray++;	
		}
	}

	//-----------------------------------------------------------------------------
	void Erase(const int Index)
	{
		for (int i = 0; i < SizeArray - 1; i++)
		{
			DynamicArray[Index] = DynamicArray[Index + 1];
		}
		SizeArray--;
	}

	//----------------------------------------------------------------------------
	void Resize(const int NewSize)
	{
		SizeArray = NewSize;
	}

	//--------------------------------------------------------------------------
	void Append(const TDynamicArray<T>& AppendArray)
	{
		Reserve(AppendArray.GetSize() + SizeArray);
		for (int i = 0; i < AppendArray.GetSize(); i++)
		{
			PushBack(AppendArray[i]);
		}
	}
};