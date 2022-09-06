#include "Square.h"

FSquare::FSquare()
{
	Lenght = 0;
	Height = 0;
}

FSquare::FSquare(const float InLenght, const float InHeight)
{
	Lenght = InLenght;
	Height = InHeight;
}

float FSquare::CalculateArea()
{
	return Lenght * Height;
}

float FSquare::CalculatePerimeter()
{
	return (Lenght * 2) + (Height * 2);
}
