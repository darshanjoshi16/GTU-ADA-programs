/* Practical Lab Assignment 5
Implementation of Prim's Algorithm for finding the minimum spanning tree */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//boolean  to represent the set of vertices included in MST. If a value  is true, then vertex v is included in MST, otherwise not.
#include<stdbool.h>



void main()
{
    int i,j,min,n,arb_n,edges=1,u,v;
    int min_cost = 0;
    clock_t start_time,end_time;

    printf("===============================================================");

    // take total number of vertices in the graph
    printf("\n Enter a total number of vertices:\n");
    scanf("%d",&n);

    // representation in two dimensional matrix
    int graph[n][n],select[n];

    printf("===============================================================");
    printf("\n Enter the adjacency matrix for graph:\n");
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)    
        {
            scanf("%d",&graph[i][j]);
        }
    }

    start_time = clock();

    //base boolean assignment for set.
    for(i=0;i<n;i++)
    {
        select[i]=false;
    }
    
    //taking the starting arbitary node from user
    printf("===============================================================");
    printf("\n Enter a arbitrary node:\n");
    scanf("%d",&arb_n);
    
    // assigning the true boolean for the edges in the optimal solution
    select[arb_n] = true;
    printf("\n\n");

    //every step, it considers all the edges that connect the two sets, and picks the minimum weight edge from these edges. 
    //After picking the edge, it moves the other endpoint of the edge to the set containing MST
    while (edges<n) 
    {
        min=999;
        for(i=0;i<n;i++) 
        {
            if(select[i]) 
            {
                for (j=0;j<n;j++) 
                {
                    if (!select[j] && graph[i][j]) 
                    {
                        if (min>graph[i][j]) 
                        {
                            min=graph[i][j];
                            u=i;
                            v=j;
                            min_cost += min;
                            
                        }
                    }
                }
            }
        }
        edges++;
        
        
        select[v]=true;

        printf("===============================================================");
       
       //printing the MST
        printf("\n edge (%d,%d) =%d\n",u,v,graph[u][v]);
        
    
    }

    printf("\n Minimum Cost = %d ", min_cost);
    end_time = clock() - start_time;
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    printf("\n ===============================================================");
    printf("\n Prim's Algorithm took %f seconds to create MST \n ",time_taken);
}