#pragma once
#include "shape.h"

class FCircle : public FShape
{
private:
	float Radius;

public:
	FCircle();
	FCircle(const float InRadius);

	virtual std::string PrintParameters() const override;
	virtual float CalculateArea() override;
	virtual float CalculatePerimeter() override;
};