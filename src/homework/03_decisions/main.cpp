//write include statements
#include <iostream>
#include "decisions.h"

using std::cout;
using std::cin;
using std::string;

int main() 
{
	int grade;
	string letter_grade_if;
	string letter_grade_switch;
	
	cout<<"Enter a number grade: ";
	cin>>grade;

	letter_grade_if = get_letter_grade_using_if(grade);
	letter_grade_switch = get_letter_grade_using_switch(grade);

	cout<<"The letter grade using if is: "<<letter_grade_if<<"\n";
	cout<<"The letter grade using switch is: "<<letter_grade_switch<<"\n";

	return 0;
}