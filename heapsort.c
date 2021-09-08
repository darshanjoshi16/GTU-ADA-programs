#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
        if (right < n && arr[right] > arr[largest])
            largest = right;
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) 
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
        for (int i = n - 1; i >= 0; i--) 
        {
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
        }
}

int main() 
{
    int arr[10000],n,i;
    
    clock_t start_time,end_time;
    int randomNumber;
    
    for(i=n-1;i>=0;i--)
    {
        randomNumber=rand() ;
        arr[i]=randomNumber;
    }
    
    printf("Enter number of elements: ");
    scanf("%ld",&n);
    
    start_time=clock();
    heapSort(arr, n);
    end_time=clock()-start_time;
    
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    
    printf("Heap_sort() took %f seconds to execute \n",time_taken);
    return 0;
}