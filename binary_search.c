/* Lab Assignment 2
Implementation and time analysis techniques for searching techniques
(2) Binary Search. */

//Importation of Header files
#include<stdio.h>
#include <time.h>

// for performing binary search,it is must that all elements in array should be sorted
// defined the sorting function
void sort(long a[],long n)
{
  long i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
       if(a[i]>a[j])
       {
         //swapping method for sorting the elements by assigning the value to temp variable
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
       }
    }
  } 
}

//defined the binary search function
long binary_search(long p,long q,long k[],long x) // p is lower bound, q is upper bound, k is sorted array and x is element we need to search
{
  long mid,loc; // mid is the middle index for array and loc is location for array

  if(p>q) // lower bound can not be greater than upper bound
    return -1;
  else
    mid=(p+q)/2; // giving the indexing for middle element of array

  if(x<k[mid]) // if the wanted element is less than the element of middle index then the upper bound restricts to the lefter side from middle index
  {
    loc=binary_search(p,mid-1,k,x); 
  }
  else if(x>k[mid])
  {
   loc=binary_search(mid+1,q,k,x);// if the wanted element is greater than the element of middle index then the lower bound restricts to the right side from middle index
  }
 else
 {
   loc=mid; // otherwise if the element found at middle index only, then it assigns the mid value to location 
   return (loc+1); // returns the index of wanted element.
 }
}

void main()
{
  long a[100000],n,i,x,loc;
  clock_t start_time,end_time;
  
  // taking the size of array from users
  printf("Enter the size of array:\n");
  scanf("%ld",&n);

 // for giving values to array indexes 
  for (i = 0; i < n; i++)
  {
    a[i]=n-i;
  }
  
  //called the sorting function
  sort(a,n);
  
  // The element taken from user wants to search
  printf("Enter the element to search:\n");
  scanf("%ld",&x);
  
  // initializing the start clock time to variable start_time
  start_time=clock();
  
  // loc = location of element, 0 is lower bound,n-1 is upper bound,x is the element user needs to search,a is the sorted array
  loc=binary_search(0,n-1,a,x);
  
  // finding the end time after execution of operation
  end_time=clock()-start_time;
  
  //the total time of execution for operation of binary search
  double time_taken=((double)end_time)/CLOCKS_PER_SEC;
  
  printf("\n binary_search took %f seconds to execute \n",time_taken);
  printf("Location: %ld\n",loc);
}