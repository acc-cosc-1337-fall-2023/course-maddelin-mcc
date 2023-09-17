/*
        MAIN MENU

1-Letter grade using if
2-Letter grade using switch
3-Exit

In options 1 and 2, prompt the user for a number and if the number is between 0 and 100 call the appropriate function; 
otherwise, display a message that the number is out of range.*/

//write include statements
#include <iostream>
#include "decisions.h"

using std::cout;
using std::cin;
using std::string;

int main() 
{
	int grade;
	int selection;
	string letter_grade_if;
	string letter_grade_switch;

	cout<<"	 MAIN MENU\n1-Letter grade using if\n2-Letter grade using switch\n3-Exit\n\n";
	cin>>selection;

	switch (selection)
	{
		case 1:
			cout<<"Enter a number grade: ";
			cin>>grade;
			if(grade>100 || grade < 0)
			{
				cout<<"Grade value is out of range\n";
			}
			else
			{
				letter_grade_if = get_letter_grade_using_if(grade);
				cout<<"The letter grade using if is: "<<letter_grade_if<<"\n";
			}
			break;
		case 2:
			cout<<"Enter a number grade: ";
			cin>>grade;
			if(grade>100 || grade < 0)
			{
				cout<<"Grade value is out of range\n";
			}
			else
			{
				letter_grade_switch = get_letter_grade_using_switch(grade);
				cout<<"The letter grade using switch is: "<<letter_grade_switch<<"\n";
			}
			break;
		default:
			break;
	}
	return 0;
}