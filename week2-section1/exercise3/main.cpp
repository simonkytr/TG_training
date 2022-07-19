/*
Exercise 3 - Shapes and Areas
Create two classes: a Circle class and a Square class. For each class, take in the necessary information to calculate its area and perimeter.  Remember to validate input.

Ask the user if they want to create a circle or a square. For their pick, ask the necessary information to create the shape. Then, tell them the area and the perimeter of their shape.
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
	Circle(float InRadius)
	{
		radius = InRadius;
	}
	void CalculatePerimeter()
	{
		std::cout<<"Circle's perimeter: "<< 2 * 3.1416f * radius << std::endl;
	}

	void CalculateArea()
	{
		std::cout<< "Circle's area: "<<3.1416f * pow(radius, 2)<<std::endl;
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
	 Square(float InHeight, float InLenght)
	{
		height = InHeight;
		lenght = InLenght;
	}
	void CalculatePerimeter()
	{
		std::cout<<"Square's perimeter: "<< height + lenght + height + lenght << std::endl;
	}
	void CalculateArea()
	{
		std::cout << "Square's area: " << height * lenght << std::endl;
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
		float Radious;
		std::cin >> Radious;
		Circle circle(Radious);
		//circle.Circle(Radious);
		circle.CalculateArea();
		circle.CalculatePerimeter();
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
		square.CalculateArea();
		square.CalculatePerimeter();
	}
	break;


	default:
		std::cout << "please entry a valid option!" << std::endl;
		break;
	}
}