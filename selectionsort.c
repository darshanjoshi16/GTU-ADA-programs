// Lab Assignment 1 
//Implementation and Time analysis of sorting Algorithms 
// Selection Sort 

#include<stdio.h> // Importing various header files for operation
#include<time.h>
#include <stdlib.h>

void selection_sort(int[],int); // defining Selection sort function
int main() 
{
    int n;
    
    printf("Enter total no. of elements : ");  //taking input of how many elements user wants
    scanf("%d",&n);
    
    int a[n], i;
    int randomNumber;
    
    clock_t start_time,end_time;
    
    for(i=n-1;i>=0;i--) // for loop for generation of random number elements  using rand function.
    {
        randomNumber = rand() ;
        a[i]=randomNumber;
    }

    start_time=clock(); // time analysis technique using time.h header file
    selection_sort(a,n);
    end_time=clock()-start_time;

    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    
    printf("selection_sort() took %f seconds to execute \n",time_taken);
    return 0;
}

void selection_sort(int arr[],int n) //Selection sort function
{
    //Scan array to find out the smallest element and swap it with the first element
    //Repeat this procedure for the remainder of the list starting at the second position and advancing each time
    
    int i, j, a, t, p;
    for (i = 0; i < n;i++) 
    {
        p = i;
        for (j = i; j < n;j++) 
        {
            if (arr[p] >arr[j])
            p = j;
        }
        if (p != 1) 
        {
            t = arr[i];
            arr[i] = arr[p];
            arr[p] = t;
        }
    }
}