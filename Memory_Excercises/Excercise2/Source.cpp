/*Exercise 2 - Understanding Stack vs Heap
Let’s compare the memory addresses of the stack and the heap.
First, create three int variables called stackInt1, stackInt2, and stackInt3. These variables should
be allocated in the stack. Initialize them to whatever value you want and then print their value
and memory addresses.
Then, create three more int variables and call them healpInt1, heapInt2, and heapInt3. These
variables should be allocated in the heap. Initialize them to whatever value you want and print
their value and memory addresses.
What can you notice from the memory addresses in the stack vs the memory addresses in the
heap? Print the answer to that question to the console (Yep, we’re doing quizzes in exercises
now).
Remember to free any memory you allocate in the heap.*/

#include <iostream>

int main()
{
	int StackInt1 = 10;
	int StackInt2 = 20;
	int StackInt3 = 30;

	std::cout << "I created three stack variables:" << std::endl;
	std::cout << "their values are:" << std::endl;
	std::cout << StackInt1 << std::endl;
	std::cout << StackInt2 << std::endl;
	std::cout << StackInt3 << std::endl;
	
	std::cout << "their memory addresses are:" << std::endl;
	std::cout << &StackInt1 << std::endl;
	std::cout << &StackInt2 << std::endl;
	std::cout << &StackInt3 << std::endl;

	int* HeapInt1 = new int(100);
	int* HeapInt2 = new int(200);
	int* HeapInt3 = new int(300);

	std::cout << "I created three heap variables:" << std::endl;
	std::cout << "their values are:" << std::endl;
	std::cout << *HeapInt1 << std::endl;
	std::cout << *HeapInt2 << std::endl;
	std::cout << *HeapInt3 << std::endl;
	

	std::cout << "their memory addresses are:" << std::endl;
	std::cout << HeapInt1 << std::endl;
	std::cout << HeapInt2 << std::endl;
	std::cout << HeapInt3 << std::endl;

	delete HeapInt1;
	delete HeapInt2;
	delete HeapInt3;

	std::cout << "What can you notice from the memory addresses in the stack vs the memory addresses in the heap ?" << std::endl;
	std::cout << "I can notice that the heap memory address has a more enormous Address value than the stack address value" << std::endl;

}