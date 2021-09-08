// Lab Assignment 1 
//Implementation and Time analysis of sorting Algorithms 
//(4) Merge Sort

#include<stdio.h> //importing header files
#include<stdlib.h>
#include<time.h>

int arr[10000], n, b[10000];

void MergeSort(int low, int high); // defining Merge sort function
void Merge(int low, int mid, int high); // defining Merge function for merging the elements.

int main()
{

    int i;
    clock_t start_time,end_time;
    
    printf("Enter number of elements:"); //taking input of how many elements user wants
    scanf("%ld",&n);
    
    int randomNumber;
    
    for(i=n-1;i>=0;i--) // for loop for generation of random number elements  using rand function.
    {
        randomNumber = rand() ;
        arr[i]=randomNumber;
    }
    
    start_time=clock(); // time analysis technique using time.h header file
    MergeSort(0, n-1);
    end_time=clock()-start_time;
    
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    
    printf("Merge_sort() took %f seconds to execute \n",time_taken);
    return 0;
}

void MergeSort(int low, int high) //Merge Sort Function
{
    if(low<high)
    {
    int mid=(low+high)/2;
    MergeSort(low, mid);
    MergeSort(mid+1, high);
    Merge(low, mid, high);
    }
}

void Merge(int low, int mid, int high)
//To sort A[p . . r]:
// Divide by splitting into two subarrays A[p . . q] and A[q + 1 . . r], where q is the halfway point of A[p . . r].
// Conquer by recursively sorting the two subarrays A[p . . q] and A[q + 1 . . r].
 //Combine by merging the two sorted subarrays A[p . . q] and A[q + 1 . . r] to produce a single sorted subarray A[p . . r].
{
    int h=low;
    int i=low;
    int j=mid+1;
    int k;

    while((h<=mid) && (j<=high))
    {
        if(arr[h]<=arr[j])
        {
            b[i]=arr[h];
            h++;
        }
        else
        {
            b[i]=arr[j];
            j++;
        }
        i++;
    }

    if(h>mid)
    {
        for(k=j; k<=high;k++)
        {
            b[i]=arr[k];
            i++;
        }
    }

    else
    {
        for(k=h; k<=mid; k++)
        {
            b[i]=arr[k];
            i++;
        }
    }

    for(k=low; k<=high; k++)
    {
        arr[k]=b[k];
    }
}