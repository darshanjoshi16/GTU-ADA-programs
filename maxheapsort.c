#include<stdio.h>
#include<time.h>

int i,j;

void max_heapify(int ar[],int n,int i)
{
    int left,right,largest;
    left =  2*i+1;
    right = 2*i+2;
    largest = i;

    if(left<n && ar[left]>ar[largest])
    {
        largest=left;
    }
    
    if(right<n && ar[right]>ar[largest])
    {
        largest=right;
    }
    
    if(largest!=i)
    {
        int temp;
        temp=ar[i];
        ar[i]=ar[largest];
        ar[largest]=temp;
        max_heapify(ar,n,largest);
    }

}

void max_heap(int ar[],int n)
{
    for(i=n/2-1;i>=0;i--)
    {
        max_heapify(ar,n,i);
    }
}

void heap_sort(int ar[],int n)
{
    max_heap(ar,n);
    int i;
    for(i=n-1;i>=0;i--)
    {
        int temp;
        temp=ar[i];
        ar[i]=ar[0];
        ar[0]=temp;
        max_heapify(ar,i,0);
    }
}

void main()
{
    int n;
    clock_t start_time,end_time;
    printf("=============================================================");
    printf("\n Heap Sort Implementation");
    printf("\n=============================================================");

    printf("\n Enter the number of elements you want to sort: ");
    scanf("%d",&n);

    int arr[n];

    for(i=0;i<n;i++)
    {
        printf("Enter the %dth element: ",i+1);
        scanf("%d",&arr[i]);
    }

    start_time = clock();
    heap_sort(arr,n);
    end_time = clock() - start_time;

     long double time_taken=((double)end_time)/CLOCKS_PER_SEC; 

    printf("\n=============================================================");
    printf("\n Sorted Array is given as per below: ");

    for(i=0;i<n;i++)
    {
        printf("\n %d",arr[i]);
    }

    printf("\n=============================================================");
    printf("\n Heap Sort takes %.9Lf to execute",time_taken);
    

}