/* Lab Assignment 2
Implement and Time Analysis of Linear and Binary search techniques
(1) Linear Search */

// importation of header files
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//defined the linear search function
void linear_search(long [],long,long);

//defined the main function
void main()
{
    long arr[100000], i, num, n;
    clock_t start_time,end_time;
    
    // Taken the amount of elements for array creation from the users.
    printf("Enter the array size : ");
    scanf("%ld",&n);
    
    for(i=0; i<n; i++)
    {
        arr[i]=n-i;
    }
    
    // The element user wants to search in the list
    printf("Enter the number to be search : ");
    scanf("%ld",&num);
    
    //Initializing the time in clock in start variable
    start_time=clock();
    
    //arr is name of array, n is value of total elements, num is the element user wants to search
    linear_search(arr,n,num); 
    
    //Finding the end time in clock and storing it into end_time variable
    end_time=clock()-start_time;
    
    //Time taken is the actual time taken in execution of linear search
    double time_taken=((double)end_time)/CLOCKS_PER_SEC; 
    printf("\nlinear_search took %f seconds to execute \n",time_taken);
}

void linear_search(long arr[],long n,long num)
{
    int i;
    long c=0,pos;
    for(i=0; i<n; i++)
    {
        if(arr[i]==num)
        {
            c=1; // the value of c becomes 1 when you find the element
            pos=i+1; //position is considered i+1 because of 0 indexing
            break;
        }
    }
    
    if(c!=0) // whenever the value of c becomes 1, it means you have found the desired element.
    {
    printf(" %ld found at position %ld",num,pos);
    }
}