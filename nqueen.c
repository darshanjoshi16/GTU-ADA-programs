#include<stdio.h>
int N;
int board[100][100];

int is_attacking(int i,int j)
{
    int k,l;
    for (k=0;k<N;k++)
    {
        if((board[i][k]==1)||(board[k][j]==1)) {return 1;}
    }

    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
            if(((k+l)==(i+j))||((k-l)==(i-j)))
            {
                if(board[k][l]==1) {return 1;}
            }
        }
    }
    return 0;
}

int N_Queen(int n)
{
    int i,j;
    if(n==0) {return 1;}
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if((!is_attacking(i,j)) && (board[i][j]!=1))
            {
                board[i][j] = 1; 
                if(N_Queen(n-1)==1) {return 1;}
                board[i][j] = 0;
            }
        }
    }
    return 0;

}

int main()
{
    printf("=========N-QUEEN PROBLEM USING BACKTRACKING=======");
    printf("\n Enter the value of N for NxN chessboard:"); 
    scanf("%d",&N);

    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            board[i][j]=0;
        }
    }

    N_Queen(N); 

    printf("\n=================================================");
    printf("\n ============OUTPUT TABLE====================\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++) 
        {   
            printf("%d\t",board[i][j]);
        }
    
        printf("\n");
    }
}
