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
		CapacityArray = 1;
		DynamicArray = new T[CapacityArray];
	};

	~TDynamicArray()
	{
		delete[] DynamicArray;
	};

	TDynamicArray(const TDynamicArray<T>& OtherDynamicArray)
	{
		Append(DynamicArray);
	}

	TDynamicArray& operator= (const TDynamicArray<T>& OtherDynamicArray)
	{
		Clear();
		Append(OtherDynamicArray);
		return *this;
	}

	//----------------------------------------------------------------------
	T& operator[] (const int Index)
	{
		return DynamicArray[Index];
	}

	const T& operator[] (const int Index) const
	{
		return DynamicArray[Index];
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
		return SizeArray == 0;
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
		if (NewCapacity > CapacityArray)
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
			DynamicArray[SizeArray] = InType;
			SizeArray++;
		}
	}

	//-----------------------------------------------------------------------------
	void PopBack()
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
				
			for (int i = SizeArray; i > Index; i--)
			{
				DynamicArray[Index] = DynamicArray[i - 1];
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

	//----------------------------------------------------------------------------
	void Replace(const int Index, T& InType)
	{
		DynamicArray[Index] = InType;
	}

	//---------------------------------------------------------------------------
	void SwapIndex(const int Index1, const int Index2)
	{
		T SwapType = DynamicArray[Index1];
		DynamicArray[Index1] = DynamicArray[Index2];
		DynamicArray[Index2] = SwapType;		
	}

	//----------------------------------------------------------------------------
	void Split(TDynamicArray<T>& Array1, TDynamicArray<T>& Array2, const int Index)
	{
		if (!Array1.IsEmpty() && !Array2.IsEmpty())
		{
			Array1.Clear();
			Array2.Clear();
		}
		for (int i = 0; i < Index; i++)
		{
			Array1.Reserve(Index);
			Array1.PushBack(DynamicArray[i]);
		}
		for (int i = Index; i < CapacityArray; i++)
		{
			Array1.Reserve(CapacityArray - Index);
			Array2.PushBack(DynamicArray[i]);
		}
	}
};