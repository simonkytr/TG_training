/*
* Exercise 1 - Understanding classes
Create a class called FirstClass with a public constructor and destructor. Have the constructor output “I’m in the constructor!” and have the destructor output “I’m in the destructor!”. Then, instantiate 5 classes and run your program, are the constructor and destructor calls where you expected them to be?

Now create a loop of at least five iterations. For each iteration, instantiate your class once. Run your program, are the constructor and destructor calls where you expected them to be?
*/

#include <iostream>

class FMyFirtsClass
{
public:
	FMyFirtsClass()
	{
		std::cout << "I'm in the constructor! " << std::endl;
	};
	~FMyFirtsClass()
	{
		std::cout << "I'm in the destructor! " << std::endl;
	};
};

void InitializeClass() {
	FMyFirtsClass firstClass;
	FMyFirtsClass secondClass;
	FMyFirtsClass thirdClass;
	FMyFirtsClass fourthClass;
	FMyFirtsClass fifthClass;

}

void InitializeClassLoop() {
	int numberClass = 0;
	for (int i = 0; i < 5; i++)
	{
		numberClass++;
		FMyFirtsClass firstClass;
		std::cout << "initilized " << numberClass << "th class" << std::endl;
	}
}

int main() 
{
	InitializeClass();

	InitializeClassLoop();
}

