// Lab Assignment 1 
//Implementation and Time analysis of sorting Algorithms 
//(2) Insertion Sort


#include<stdio.h> //importing header files
#include<stdlib.h>
#include<time.h>

void insertion_sort(int[],int); // defining insertion sort function

int main()
{
   int a[10000];
   clock_t start_time,end_time;
   int i,n;

   printf("Enter total number of elements: "); //taking input of how many elements user wants
   scanf("%d",&n);

   int randomnumber;

   for(i=n-1;i>=0;i--) // for loop for generation of random number elements  using rand function.
   {
       randomnumber=rand();
       a[i]=randomnumber;
   }

   start_time = clock(); // time analysis technique using time.h header file
   insertion_sort(a,n);
   end_time = clock() - start_time;

   double time_taken = ((double)end_time)/CLOCKS_PER_SEC;
   printf("insertion_sort() took %f seconds to execute \n",time_taken);
   return 0;  

}

void insertion_sort(int arr[], int size) //Insertion sort function
{
    //Remove a data item from the input list, insert it into the correct position in the already sorted list until no input elements remain
    
    int i,j,temp;
    
    for(i=0;i<size;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>arr[j+1]) 
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }

            else
            {
                break;
            }
        }
    }
}