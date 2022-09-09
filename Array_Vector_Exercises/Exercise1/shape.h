#pragma once
#include <iostream>

class FShape
{
protected:
	std::string KindOfShape;
public:
	FShape();
	
	virtual std::string GetKindOfShape() const;
	virtual std::string PrintParameters() const;

	virtual float GetArea() const;
	virtual float GetPerimeter() const;
};
