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

class Circle
{
private:

	float radius;

public:
	Circle()
	{
		radius = 0.0f;
	}
	Circle (float InRadius)
	{
		radius = InRadius;
	}
	float GetPerimeter() const
	{
		return 2.0f * 3.1416f * radius;
	}

	float GetArea()
	{
		return 3.1416f * pow(radius, 2);
	}
};

class Square
{
private:
	float height;
	float lenght;
public:
	 Square()
	{
		height = 0.0f;
		lenght = 0.0f;
	}
	 Square (float InHeight, float InLenght)
	{
		height = InHeight;
		lenght = InLenght;
	}
	float GetPerimeter() const
	{
		return height + lenght + height + lenght;
	}
	float GetArea() const
	{
		return height * lenght;
	}

};

int main()
{
	std::cout << "Welcome to create - a - shape, what type of shape do you want ?" << std::endl;
	std::cout << "1 - Circle\n2 - Square" << std::endl;
	
	int choice;
	std::cin >> choice;

	
	
	switch (choice)
	{
	case 1:
	{
		std::cout << "Enter radius for your circle " << std::endl;
		float Radius;
		std::cin >> Radius;
		Circle circle (Radius);
		std::cout << "Circle's area: " << circle.GetArea() << std::endl;
		std::cout << "Circle's perimeter: " << circle.GetPerimeter() << std::endl;
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
		Square square(Height, Lenght);
		std::cout << "square's perimeter: " << square.GetArea() << std::endl;
		std::cout << "square's perimeter: " << square.GetPerimeter() << std::endl;
	}
	break;


	default:
		std::cout << "please entry a valid option!" << std::endl;
		break;
	}
}