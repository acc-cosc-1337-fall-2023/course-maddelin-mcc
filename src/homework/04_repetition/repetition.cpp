//add include statements
#include "repetition.h"
using std::cout; 

//add function(s) code here
int factorial(int num)
{
    int product = num;

    while (num > 1)
    {
        product = product * (num - 1);
        num--;
    }
    return product;
};

int gcd(int num1, int num2)
{
    int temp; 

    while (num1 != num2)
    {
        if( num1 < num2)
        {
            //swap num1 and num2
            temp = num1;
            num1 = num2;
            num2 = temp; 
        }
        else
        {   
            //subtract num2 from num1
            num1 = num1 - num2;
        }
    }
    return num1;
}
