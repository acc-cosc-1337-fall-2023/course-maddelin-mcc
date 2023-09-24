//write include statements
#include "repetition.h"

using std::cout; using std::cin;
//write using statements

int main() 
{
	int choice = 0;

	int num;
	int num1;
	int num2;
	do
	{
		cout<<"Make a Selection:\n  1-Factorial\n  2-Greatest Common Divisor\n  3-Exit\n\n";
		cin>>choice;

		switch (choice)
		{
		case 1:
			/*Factorial*/
			cout<<"\nEnter num: ";
			cin>>num;
			cout<<"The factorial of "<< num <<" is: "<< factorial(num)<<"\n\n";
			break;
		case 2:
			/*GCD*/

			cout<<"\nEnter num1: ";
			cin>>num1;
			cout<<"\nEnter num2: ";
			cin>>num2;
			cout<<"The greatest common denominator is: "<<gcd(num1, num2)<<"\n\n";
			break;
		case 3:
			cout<<"Are you sure you want to exit? Enter 3 again to continue, 0 to go back\n";
			cin>>choice;
			break;
		default:
			break;
		}
	}
	while( choice != 3 );

	return 0;
}
