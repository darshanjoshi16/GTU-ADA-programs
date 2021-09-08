
#include <bits/stdc++.h>
using namespace std;

clock_t start_time,end_time;

int knapSackRecursive(int W, int wt[],
				int val[], int i,
				int** dp)
{
	
	if (i < 0)
		return 0;
	if (dp[i][W] != -1)
		return dp[i][W];

	if (wt[i] > W) {

		
		dp[i][W] = knapSackRecursive(W, wt,
							val, i - 1,
							dp);
		return dp[i][W];
	}
	else {
		
		dp[i][W] = max(val[i]
					+ knapSackRecursive(W - wt[i],
								wt, val,
								i - 1, dp),
					knapSackRecursive(W, wt, val,
								i - 1, dp));

		
		return dp[i][W];
	}
}

int knapSack(int W, int wt[], int val[], int n)
{
	
	// double pointer to declare the table dynamically
	int** dp;
	dp = new int*[n];

	
	for (int i = 0; i < n; i++)
		dp[i] = new int[W + 1];

	// loop to initially filled the
	// table with -1
	for (int i = 0; i < n; i++)
		for (int j = 0; j < W + 1; j++)
			dp[i][j] = -1;
	return knapSackRecursive(W, wt, val, n - 1, dp);
	
}


int main()
{
	int n,W;
	int val[20],wt[20];
	

	cout<<"Enter number of items:";
    cin >> n;

    cout<<"\n ================================================================================================================"<<endl;
    cout<<"\n Enter value and weight of items"<<endl;
    for(int i = 0;i < n; ++i)
    {
      printf("\n ================================================================================================================");
      cout<<"\n Item No:"<<(i+1);
        
        printf("\n Enter Weight:- ");
        cin >> wt[i];
        
        printf("\n Enter Value:- ");
        cin >> val[i];
    }
 
    printf("\n Enter max capacity of knapsack: ");
    cin >> W;
	cout<<"\n ================================================================================================================"<<endl;
	start_time=clock();
	int max_profit = knapSack(W,wt,val,n);
	cout << "Maximum Profit: "<<max_profit<<endl;
	end_time = clock() - start_time;
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    printf("\n ================================================================================================================");
    printf("\n Knapsack Problem using Dynamic approach took %lf seconds to execute",time_taken);
    return 0;

	
	
	return 0;
}
