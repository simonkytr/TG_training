#pragma once
#include "shape.h"

class FSquare : public FShape
{
private:
	float Lenght;
	float Height;
	
public:
	FSquare();
	FSquare(const float InLenght, const float InHeight);

	virtual std::string PrintParameters() const override;

	virtual float CalculateArea() override;
	virtual float CalculatePerimeter() override;
};