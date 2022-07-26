/*
Exercise 3 - Shapes and Areas
Create two classes: a Circle class and a Square class. For each class, take in the necessary information to calculate its area and perimeter.  Remember to validate input.

Ask the user if they want to create a circle or a square. For their pick, ask the necessary information to create the shape. Then, tell them the area and the perimeter of their shape.

Your class should have the following methods:
ExampleShape();
ExampleShape( Params );
float GetArea();
float GetPerimeter()
*/

#include <iostream>
#include <cmath>
#include <iomanip>

class FCircle
{
private:
	float Radius;
public:
	FCircle()
	{
		Radius = 0.0f;
	}
	FCircle (float InRadius)
	{
		Radius = InRadius;
	}
//---------------------------------------
	float GetPerimeter() const
	{
		return 2.0f * 3.1416f * Radius;
	}
//--------------------------------------
	float GetArea() const
	{
		return 3.1416f * pow(Radius, 2);
	}
};

class FSquare
{
private:
	float Height;
	float Lenght;
public:
	 FSquare()
	{
		Height = 0.0f;
		Lenght = 0.0f;
	}
	 FSquare (float InHeight, float InLenght)
	{
		Height = InHeight;
		Lenght = InLenght;
	}
 //----------------------------------------
	float GetPerimeter() const
	{
		return Height + Lenght + Height + Lenght;
	}
//-------------------------------------------
	float GetArea() const
	{
		return Height * Lenght;
	}

};

int main()
{
	std::cout << "Welcome to create - a - shape, what type of shape do you want ?" << std::endl;
	std::cout << "1 - Circle\n2 - Square" << std::endl;
	int Choice;
	std::cin >> Choice;
	switch (Choice)
	{
	case 1:
	{
		std::cout << "Enter radius for your circle " << std::endl;
		float Radius;
		std::cin >> Radius;
		FCircle Circle (Radius);
		std::cout << "Circle's area: " << Circle.GetArea() << std::endl;
		std::cout << "Circle's perimeter: " << Circle.GetPerimeter() << std::endl;
	}
		break;
	case 2:
	{
		std::cout << "Enter Height for the square " << std::endl;
		float Height;
		std::cin >> Height;
		std::cout << "Enter Lenght for the square " << std::endl;
		float Lenght;
		std::cin >> Lenght;
		FSquare Square(Height, Lenght);
		std::cout << "square's perimeter: " << Square.GetArea() << std::endl;
		std::cout << "square's perimeter: " << Square.GetPerimeter() << std::endl;
	}
	break;
	default:
		std::cout << "please entry a valid option!" << std::endl;
		break;
	}
}