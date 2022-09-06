#include "shape.h"
#include <iostream>

FShape::FShape()
{
	KindOfShape = "";
}

std::string FShape::GetKindOfShape()
{
	return KindOfShape;
}

std::string FShape::PrintParameters() const
{
	return "";
}

 float FShape::CalculateArea()
{
	 std::cout << "here it is going to calculate the shape's Area" << std::endl;
	 return 0;
}

float FShape::CalculatePerimeter()
{
	std::cout << "here it is going to calculate the Perimeter's Area" << std::endl;
	return 0;
}
