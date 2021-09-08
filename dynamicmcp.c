#include<stdio.h>

void main()
{
    int W,i,j,n;
    int c,s,e;
    int d[10];
    int B[10][20];
    
    printf("=====================================");
    printf("\n Making Coin Change Problem using Dynamic Programming");
    printf("\n =====================================");

    printf("\n Enter the numbers of coin: ");
    scanf("%d",&n);
    
    printf("=====================================");
    printf("\n Enter the change values: ");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }
    
    printf("=====================================");
    printf("\n Change for the value:  ");
    scanf("%d",&W);

    for(i=0;i<=W;i++)
    {
        B[0][i] = 999;
    }

    for(i=1;i<=n;i++)
    {
        B[i][0] = 0;
        for(j=1;j<=W;j++)
        {
            if(d[i]<=j)
            {
                if(1+B[i][j-d[i]] < B[i-1][j])
                {
                    B[i][j] = (1+B[i][j-d[i]]);
                }
                else
                {
                    B[i][j] = B[i-1][j];
                }
            }

            else
            {
                B[i][j] = B[i-1][j];

            }
        } 
    }

    printf("i\\j\t");

    for(j=0;j<=W;j++)
    {
        printf("%d\t",j);
    }

    printf("\n");
    
    for(i=1;i<=n;i++)
    {
        printf("%d\t",i);
    
        for(j=0;j<=W;j++)
        {
            printf("%d\t",B[i][j]);
        }
    
        printf("\n");
    }

    printf("\n");
    c=B[n][W];
    s=n;
    e=W;

   
    int count=0;
    printf("=====================================");
    printf("\n Coin:");

    while(c!=0)
    {
        if(c==B[s-1][e])
        {
            s=s-1;
            c=B[s][e];
        }
        else
        {
            e=e-d[s];
            c=B[s][e];
            printf("%d\t ",d[s]);
            count+=1;
        }
    }
    printf("\n =====================================");
    printf("\n Total coins for change: %d",count);

}
