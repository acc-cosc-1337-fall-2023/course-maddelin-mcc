#include <iostream>
#include "hwexpressions.h"

using std::cout;
using std::cin;

int main()
{
    double meal_amount;
    double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

    cout<<"\nRestaurant Receipt\n\nEnter the Meal Amount: $";
    cin>>meal_amount;
    tax_amount = get_sales_tax_amount(meal_amount);
    
    cout<<"Enter Tip Percentage: ";
    cin>>tip_rate;
    tip_amount = get_tip_amount(meal_amount, tip_rate);
	total = meal_amount+tax_amount+tip_amount;

	cout
	<<"\n\n**********************\nReceipt\n**********************\n"
    <<"\nMeal Amount: $"<<meal_amount
	<<"\nSales Tax:   $"<<tax_amount
	<<"\nTip:         $"<<tip_amount
	<<"\nTotal:       $"<<total
	<<"\n\nThank you!\n*********************\n";

    return 0;
}