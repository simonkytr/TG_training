/*Exercise 5 - Arrays
Create an array of whatever size you want. Let the user input as many numbers as they want and populate the array with them. If they enter any invalid input, output the whole array of numbers and the sum of them all and the total numbers they input.

If the user exceeds the size of your array, tell them about it and then output the information.
*/

#include <iostream>




int main(){

	int numbers[10];
	int  sum=0;
	int size = 0;

	for ( int i = 0; i < 10; i++){
		//Error: interrup the loop
		if (std::cin.fail() || std::cin.bad()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');

			std::cout << "\ntotal number entered: " << size << std::endl;
			std::cout << "\nTotal sum of numbers entered: " << sum << std::endl;

			return 0;
		}
		

		std::cout << "insert any NUMBER: ";
		int insert;
		std::cin >> insert;
		numbers[i] = insert;
		sum  += insert;
		size++;

	}


	std::cout << "\ntotal number entered: " <<  size << std::endl;
	std::cout << "\nTotal sum of numbers entered: " << sum << std::endl;
}
