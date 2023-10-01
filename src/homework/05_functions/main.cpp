/*
Main Program Flow:

Menu

1- Get GC Content
2- Get DNA Complement
3- Exit

In main.cpp, write code that prompts user to enter 1 for Get GC Content, or 2 for Get DNA Complement.  
The program will prompt user for a DNA string and call either get gc content or get dna complement function and display the result. 
*/

#include "func.h"
using std::cout;
using std::cin;
using std::string;

int main() 
{	
	
	int choice = 0;

	string dna;

	do
	{
		cout<<"Make a Selection:\n  1-Get GC Content\n  2-Get DNA Complement\n  3-Exit\n\n";
		cin>>choice;

		switch (choice)
		{
		case 1:
			/*GC Content*/
			cout<<"\nEnter DNA: ";
			cin>>dna;
			cout<<"The GC Content of "<< dna <<" is: "<< get_gc_content(dna)<<"\n\n";
			break;
		case 2:
			/*DNA Complement*/
			cout<<"\nEnter DNA: ";
			cin>>dna;
			cout<<"The DNA Complement of "<< dna <<" is: "<< get_dna_complement(dna)<<"\n\n";
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
