//Exercise 6 - User Input
//Write a program that will ask the user to enter their nameand their age, then output the days they’ve been alive(ignore leap years)

#include <iostream>

int main() {
	int age;
	char name[100];
	std::cout << "insert name" << std::endl;
	std::cin >> name;
	std::cout << "insert age" << std::endl;
	std::cin >> age;

	int dias = age * 365;
	
	
	std::cout << "wow " << name << " you have lived " << dias << " days" <<std::endl;
}