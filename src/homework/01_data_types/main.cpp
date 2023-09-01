//write include statements
#include<iostream>
#include"data_types.h"

//write namespace using statement for cout
using std::cin; using std::cout;

int main()
{
	int num = 0;

	cout<<"Enter a number: ";
	cin>>num;

	int result = 0;
	result = multiply_numbers(num);

	cout<<"Result is: "<<result<<"\n";

	int num1 = 4;
	result = multiply_numbers(num1);

	cout<<"Result is: "<<result<<"\n";
	return 0;
}
