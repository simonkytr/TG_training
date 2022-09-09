#include "shape.h"
#include <iostream>

FShape::FShape()
{
	KindOfShape = "";
}

std::string FShape::GetKindOfShape() const
{
	return KindOfShape;
}

std::string FShape::PrintParameters() const
{
	return "";
}

 float FShape::GetArea() const
{
	 return 0;
}

float FShape::GetPerimeter() const
{
	return 0;
}
