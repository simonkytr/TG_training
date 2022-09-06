#pragma once
#include <iostream>

class FShape
{
protected:
	std::string KindOfShape;
public:
	FShape();
	
	virtual std::string GetKindOfShape();
	virtual std::string PrintParameters() const;

	virtual float CalculateArea();
	virtual float CalculatePerimeter();
};
