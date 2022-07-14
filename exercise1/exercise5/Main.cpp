//Exercise 5 - Basic Casting
//Write a program that will show the different effects of implicit / explicit casting


//implicit casting

#include <iostream>
int implicito() {
	//implicit casting
	int a = 4;
	int b = 7;

	std::cout << a / b << std::endl;
	std::cout << (float)a / b << std::endl;
	std::cout << a / (float)b << std::endl;
	return 0;	

}

void explicito() {
	//explicit casting

	int c = 5;
	float h = 9;
	float f = c;
	int e = h;

	std::cout << f << "   " << e;
	
}

int main() {

	implicito();
	explicito();
	std::cin.get();

}
