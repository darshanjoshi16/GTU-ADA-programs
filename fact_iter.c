/* Lab Assignment 2
Implementation and Time analysis of factorial program using iterative and recursive method.
(1) Iterative Method */

//Importing the header files for implementation
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//defining factorial function with iterative methods
int factorial_it(long x)
{
    long i,fact=1; // for x=3
    for(i=1;i<=x;i++) // This loop will run from i=1 to i=3.
    {
        fact=fact*i; // the value of i will be multiplying with fact
    }
    return fact;
}

void main()
{
    long num,fact,n;
    clock_t start_time,end_time; // defining clock datatype variables
    
    printf("Enter number:"); // taking the number from user for which they need factorial
    scanf("%ld",&num);
    start_time=clock(); // for intializing the system clock and time keeping
    fact=factorial_it(num);
    end_time=clock()-start_time;//time when the factorial process completed 
    
    long double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    printf("factorial of %ld is=%ld",num,fact);
    printf("\n%ld! took %lf seconds to execute \n",num,time_taken);
}