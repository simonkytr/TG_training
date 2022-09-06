#pragma once
#include "shape.h"
class FCircle : public FShape
{
private:
	float Radius;

public:
	FCircle();
	FCircle(const float InRadius);

	virtual float CalculateArea() override;
	virtual float CalculatePerimeter() override;
};