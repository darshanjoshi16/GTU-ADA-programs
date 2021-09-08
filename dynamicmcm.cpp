/* Practical Lab Assignment 11
Implementation of chain matrix multiplication using dynamic programming.*/

#include<bits/stdc++.h>
#include<time.h>

long int mat[20][20];
int s[20][20];
int i,j,n,p[20];

void optimal_s(int i,int j)
{
    if(i==j) {printf("A%d",i);}
    else 
    {
        printf("(");
        optimal_s(i,s[i][j]);
        optimal_s(s[i][j]+1,j);
        printf(")");
    }



}

void matrix_multiply(void)
{
    long int q;
    int k;

    for(i=n;i>0;i--)
    {
        for(j=i;j<=n;j++)
        {
            if(i==j){mat[i][j]=0;}
            else
            {
                for(k=i;k<j;k++)
                {
                    q = mat[i][k]+mat[k+1][j]+p[i-1]*p[j]*p[k];

                    if(q<mat[i][j])
                    {
                        mat[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
            
        }
    }
}

int Matrix_Chain_Order(int p[],int i ,int j)
{
    if(i==j){return 0;}
    
    int k;
    int min = INT_MAX;
    int count;

    for(k=i;k<j;k++)
    {
        count = Matrix_Chain_Order(p,i,k)+ Matrix_Chain_Order(p,k+1,j)+p[i-1]*p[j]*p[k];

        if(count<min){ min = count;}

    }

    return min;

}

int main()
{
    int k;
    clock_t start_time,end_time;
    printf("================MATRIX CHAIN MULTIPLICATION====================");
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            mat[i][i]=0;
            mat[i][j]=9999;
            s[i][j] = 0;

        }
    }

    printf("\n===================================================================");
    printf("\n Enter the dimensions:\n");

    for(k=0;k<=n;k++)
    {
        printf("P%d: ",k);
        scanf("%d",&p[k]);

    }
    start_time=clock();
    matrix_multiply();
    printf("\n===================================================================");
    printf("\n Sequence of the matrix : ");
    optimal_s(1,n);
    printf("\n===================================================================");
    printf("\nThe cost of the matrix : %d ",Matrix_Chain_Order(p, 1, n));
    end_time = clock() - start_time;
    
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    printf("\n===================================================================");
    printf("\n Dynamic Programming took %f seconds to execute \n ",time_taken);
    return 0;

}