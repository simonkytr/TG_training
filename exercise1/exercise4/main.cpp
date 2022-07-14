//Exercise 4 - Underflow and Overflow
//Write a program that will illustrate overflowand underflow.
//Hint: Use the limits from the previous exercise and try adding to the max limit, or subtracting from the min limit.


//Diego Guerrero
#include <iostream>

int main() {

	int overflow = SHRT_MAX + 1;
	int underflow = SHRT_MIN - 1;

	std::cout << "¡¡Esto pasa cuando no cuidas tus datos!!" << std::endl;

	std::cout << "---------------------------------------" << std::endl;

	std::cout << "El overflow sucede cuando usas una variable 'short' y el valor que utilizas es (" << SHRT_MAX << ")+1 \n El valor seria=" << overflow << std::endl;
	std::cout << "\nEl overflow sucede cuando usas una variable 'short' y el valor que utilizas es (" << SHRT_MAX << ")+1 \n El valor seria=" << underflow << std::endl;
}
