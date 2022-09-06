#pragma once

template <typename T, int N>
class TStaticArray
{
	static SizeArray = N;

	T StaticArray[SizeArray];
};