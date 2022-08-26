/*Exercise 4 - Dynamic Allocation Dangers: Dangling Pointers
*There is another danger when using dynamic memory. Let’s see it:
*Allocate an int in the heap and assign it to an int pointer variable. Immediately after that, delete
*the allocated memory.
*We’ve previously discussed pointer validity. Check the validity of the pointer. If the pointer is
*valid, print “The pointer is valid!”. If it’s not, print “The pointer is not valid…”.
*Run your program. You’ll see that the pointer is valid. Try accessing the value of whatever the
*pointer is pointing to and you’ll most likely crash. You’ve got a false positive in your validation
*due to a dangling pointer.
*Print to the console why you think this is happening. It’s important to keep in mind that after
*freeing memory in the heap, any pointer that was pointing to it should be set to null. From now
*on, this will be expected in the exercises.*/

#include <iostream>

int main()
{
	int* Pointer = new int;
	delete Pointer;
	
	if (Pointer != nullptr)
	{
		std::cout << "The pointer is valid" << *Pointer << std::endl;
	}
	else
	{
		std::cout << "The pointe is invalid" << std::endl;
	}
	std::cout << "The pointer is working but the address that it was pointing to has been deleted";
};