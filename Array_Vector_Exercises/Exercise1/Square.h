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

	virtual float GetArea() const override;
	virtual float GetPerimeter() const override;
};