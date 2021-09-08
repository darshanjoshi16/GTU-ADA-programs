/* Lab Assignment 2
Implementation and Time analysis of factorial program using iterative and recursive method.
(2) Recursion Method */

#include<stdio.h> // Importing the header file
#include <time.h>

long long factorial_rec(int num); // defining the factorial function

int main(void)
{
    int n;
    clock_t start_time,end_time; // defining clock datatype variables
    long fact;
    
    printf("Enter a number: "); // taking the input from user
    scanf("%d", &n);
    
    start_time=clock(); // assigning the current system time to start
    fact=factorial_rec(n);
    end_time=clock()-start_time;// assign the current system time to end
    
    double time_taken=((double)end_time)/CLOCKS_PER_SEC; // taken the difference between the start and end time and converted in time taken for process
    
    printf("%d! = %lli", n,fact );
    printf("\nfactorial_recursion() took %f seconds to execute \n",time_taken);
    return 0;
}

long long factorial_rec(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return num * factorial_rec(num - 1); // recursive calling of the function
    }
}