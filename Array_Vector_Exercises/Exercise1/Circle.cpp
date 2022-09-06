#include "Circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>


FCircle::FCircle()
{
	Radius = 0;
}

FCircle::FCircle(float InRadius)
{
	Radius = InRadius;
}

float FCircle::CalculateArea()
{
	return M_PI * exp(Radius);
}


float FCircle::CalculatePerimeter()
{
	return 2.0f * M_PI * Radius;
}