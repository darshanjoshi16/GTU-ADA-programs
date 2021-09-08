/* Practical Lab Assignment 6
Implementation of Kruskal's Algorithm for finding the minimum spanning tree*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//declaring all the the global parameters which are to be used throughout the execution
int i,j,k,a,b,u,v,n,ne=1;
clock_t start_time,end_time;
int min,mincost=0,cost[10][10],parent[10];
int find(int);
int uni(int,int);

void main()
{
	
	printf("\n\tImplementation of Kruskal's algorithm\n");
	printf("\n===============================================================================");
	printf("\nEnter the no. of vertices:");
	scanf("%d",&n);
	printf("\n===============================================================================");
	printf("\nEnter the cost adjacency matrix:\n");

	

	//Cost Adjacency Matrix is  used to represent weighted graphs. If adj[i][j] = w, then there is an edge from vertex i to vertex j with weight w.
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&cost[i][j]);
			if(cost[i][j]==0)
				cost[i][j]=999;
		}
	}
	printf("\n===============================================================================");
	printf("\n The edges of Minimum Cost Spanning Tree are\n");
	start_time = clock();
	while(ne < n)
	{    
		//This logic traverse through the matrix and by selecting the minimumm cost edges in particular row and collumns.
		for(i=1,min=999;i<=n;i++)
		{
			for(j=1;j <= n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
				}
			}
		}
		u=find(u);
		v=find(v);
		if(uni(u,v))
		{
			printf("%d edge (%d,%d) =%d\n",ne++,a,b,min);
			mincost +=min;
		}
		//adjacency value assigning
		cost[a][b]=cost[b][a]=999;
		
	}
	end_time = clock() - start_time;
	printf("\n\tMinimum cost = %d\n",mincost);
	
	
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    printf("\n ===============================================================");
    printf("\n Kruskal's Algorithm took %f seconds to create MST \n ",time_taken);
	getch();
}

// for finding the vertices according to index
int find(int i)
{
	while(parent[i])
	i=parent[i];
	return i;
}


int uni(int i,int j)
{
	if(i!=j)
	{
		parent[j]=i;
		return 1;
	}
	return 0;
}