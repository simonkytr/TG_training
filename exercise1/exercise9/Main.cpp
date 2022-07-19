/*Exercise 9 - Shopping
Write a program that will simulate a shop where you can buy different items. Let the user choose how many items of each type they want, and then output the final price. Make sure to combine integer and floating-point types
*/
#include <iostream>
using namespace std;

int main() 
{
	int price1, price2, price3; 

	price1 = 50;
	price2 = 500;
	price3 = 150;

	

	cout << "Welcome to my Weidystore"<< endl;
	cout << "--------------------------------"<< endl;
	cout << "everyone of our products have a excelent quality and price \nThese are our products in stock:\n\n\n" << endl;
	cout << "Gnomo blood(health+10): "<<price1<<" bucks\nWitch hood(+5mins invisibility): " << price1 << " bucks\n unicorn tail(+15 speed): " << price1 << " bucks\n\n" << endl;
	cout << "How many items 1 do you want?" << endl;
	cin >> item1;
	cout << "How many items 2 do you want?" << endl;
	cin >> item2;
	cout << "How many items 3 do you want?" << endl;
	cin >> item3;

	int op1, op2, op3;
	int item1, item2, item3;
	op1 = item1 * price1;
	op2 = item2 * price2;
	op3 = item3 * price3;
	
	int suma;
	suma = op1 + op2 + op3;

	cout << "processing...\n\n" << endl;
	cout << "you want to order\n\n" << item1 << " item 1: " << op1 << " bucks\n" << item2 << " item 2: " << op2 << " bucks\n" << item3 << " item 3: " << op3 << " bucks" << endl;
	cout << "your total cost: " << suma << " bucks";



}
