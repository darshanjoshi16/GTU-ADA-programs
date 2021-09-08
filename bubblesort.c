// Lab Assignment 1 
//Implementation and Time analysis of sorting Algorithms 
//(1) Bubblesort 



#include<stdio.h> // Importing various header files for operation
#include<time.h>
#include<stdlib.h>

void bubble_sort(long[],long); // defining Bubble sort function

int main()
{
   long a[10000],n,c,d,swap;
   clock_t start_time,end_time;
   printf("Enter number of elements: "); // taking input from users
   scanf("%ld",&n);
   int i;
   int randomnumber;

   for(i=n-1;i>=0;i--) // for loop for generating random numbers using rand function
   {
       randomnumber=rand();
       a[i]=randomnumber;   
   }

   start_time=clock(); // Time analysis technique for sorting algorithm using time.h header file
   bubble_sort(a,n);
   end_time = clock() - start_time;
   double time_taken=((double)end_time)/CLOCKS_PER_SEC;
   printf("bubble_sort() took %f seconds to execute \n ",time_taken);
   return 0;
}

void bubble_sort(long list[],long n) //Using Swapping with temp variables for sorting
{
    long c,d,temp;
    for(c=0;c<(n-1);c++)
    {
        for(d=0;d<n-c-1;d++)
        {
            if(list[d] > list[d+1])
            {
                temp=list[d]; //value of d index transfers to temp variable
                list[d]=list[d+1];//value of d+1 index transfers to d index
                list[d+1]=temp;//value of temp variable transfers to d+1 index

            }

        }
    }
}