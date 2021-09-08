// Lab Assignment 1 
//Implementation and Time analysis of sorting Algorithms 
//(5) Quick Sort

#include<stdio.h>  //importing header files
#include<time.h>
#include<stdlib.h>

int arr[10000], n; 
int partition(int arr[], int m, int p); //defining partition function
void swaping(int arr[], int i, int j); //defining swapping function 
void QuickSort(int arr[], int p, int q); //defining Quick Sort Function

int main()
{
    int i;
    
    int randomNumber;
    clock_t start_time,end_time;
    
    printf("Enter number of elements: \n"); //taking input of how many elements user wants
    scanf("%ld",&n);
    
    for(i=n-1;i>=0;i--) // for loop for generation of random number elements  using rand function.
    {
        randomNumber = rand() ;
        arr[i]=randomNumber;
    }
    
    start_time=clock();  // time analysis technique using time.h header file
    QuickSort(arr, 0, n-1);
    end_time=clock()-start_time;
    
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;

    printf("quick_sort() took %f seconds to execute \n",time_taken);
    return 0;
}

//Quicksort is based on the three-step process of divide-and-conquer.
//To sort the subarray A[p . . r]:


int partition(int arr[], int m, int p) //Partition Function
{
   // Divide: Partition A[p . . r], into two (possibly empty) subarrays A[p . . q − 1] and A[q + 1 . .r], 
   //such that each element in the first subarray A[p . . q − 1] is ≤ A[q] and A[q] is ≤ eachelement in the second subarray A[q + 1 . . r]

    int v=arr[m];
    int i=m;
    int j=p;
    do
    {
        do
        i++;
        while(arr[i]<v);
        do
        j--;
        while(arr[j]>v);
        if(i<j)
        swaping(arr, i, j);
    }
    while(i<=j);
    arr[m]=arr[j];
    arr[j]=v;
    return j;
}

void swaping(int arr[], int i, int j)
{
    int p;
    p=arr[i];
    arr[i]=arr[j];
    arr[j]=p;
}

void QuickSort(int arr[], int p, int q)
//The quicksort algorithm is a sorting algorithm that works by selecting a pivot point, and thereafter partitioning the number set, or array, around the pivot point
{
    if(p<q)
    {
        int j=partition(arr, p, q+1);
        QuickSort(arr, p, j-1);
        QuickSort(arr, j+1, q);
    }
}