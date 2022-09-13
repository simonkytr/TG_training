#include "Square.h"
#include <string>
FSquare::FSquare()
{
	Lenght = 0;
	Height = 0;
	KindOfShape = "Square";
}

FSquare::FSquare(const float InLenght, const float InHeight)
{
	Lenght = InLenght;
	Height = InHeight;
	KindOfShape = "Square";
}

std::string FSquare::PrintParameters() const
{
	return "the square's lenght: " + std::to_string(Lenght) + "\nthe square's height: " + std::to_string(Height);
}

float FSquare::GetArea() const
{
	return Lenght * Height;
}

float FSquare::GetPerimeter() const
{
	return (Lenght * 2) + (Height * 2);
}
