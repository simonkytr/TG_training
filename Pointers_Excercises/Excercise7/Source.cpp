#include <iostream>

void IncrementNumber(int* NumberPtr)
{
	if (NumberPtr != nullptr)
	{
		(*NumberPtr)++;
	}
	else
	{
		std::cout << "That's not possible!!!";
	}
	
};

int main()
{
	int Value = 55;
	int* ValuePtr = nullptr;
	//ValuePtr = &Value;

	IncrementNumber(ValuePtr);

}