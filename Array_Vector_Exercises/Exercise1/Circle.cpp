#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

FCircle::FCircle()
{
	Radius = 0;
	KindOfShape = "Circle";
}

FCircle::FCircle(const float InRadius)
{
	Radius = InRadius;
	KindOfShape = "Circle";
}

std::string FCircle::PrintParameters() const
{
	return "the Circle's radius is: " + std::to_string(Radius);
};

float FCircle::GetArea() const
{
	return (float)M_PI * pow(Radius, 2);
}


float FCircle::GetPerimeter() const
{
	return 2.0f * (float)M_PI * Radius;
}