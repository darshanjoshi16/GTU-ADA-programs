/* Practical Lab Assignment 8
Implement LCS problem using Dynamic Programming */

#include<stdio.h>

void main()
{
    int n1,n2;

    printf("Enter the Size of First String: ");
    scanf("%d",&n1);

    printf("Enter the Size of Second String: ");
    scanf("%d",&n2);

    char s1[n1+1],s2[n2+1];

    printf("Enter first string : ");
    
    for(int i=1;i<=n1;i++)
    {
        scanf("%c",&s1[i]);
    }

    printf("Enter Second string : ");
    
    for(int i=1;i<=n2;i++)
    {
        scanf("%c",&s2[i]);
    }

    int mat[n1+1][n2+1];
    char mat1[n1+1][n2+1];

    for(int i=0;i<=n1;i++)
    {
        mat[i][0]=0;
        mat1[i][0]='0';
    }

    for(int i=0;i<=n2;i++)
    {
        mat[0][i]=0;
        mat1[0][i]='0';
    }

    for(int i=1;i<=n1;i++)
    {
        for(int j=1;j<=n2;j++)
        {
            if(s1[i]==s2[j])
            {
                mat[i][j]=mat[i-1][j-1] + 1;
                mat1[i][j]='c';
            }

            else if(mat[i-1][j]>=mat[i][j-1])
            {
                mat[i][j]=mat[i-1][j];
                mat1[i][j]='|';
            }

            else if(mat[i-1][j]<mat[i][j-1])
            {
                mat[i][j]=mat[i][j-1];
                mat1[i][j]='-';
            }
        }
    }

    printf("\n Array of Values:\n");

    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }

    printf("\n Array of arrow direction: \n ");

    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            printf("%d",mat1[i][j]);
        }
        printf("\n");
    }

    char c1[n1];
    int k=0;

    for(int i=n1 ; i>=0 ; i--)
    {
        for(int j=n2;j>=0;j--)
        {
            if(mat1[i][j]=='|')
                break;

            if(mat1[i][j]=='c')
            {
                c1[k]=s2[j];k++;
                i=i-1;
                j=j-1;
            }
        }
    }

    printf("\n Subsequence of Characters:\n");

    for(int i=k-1;i>=0;i--)
    {
        printf("%c",c1[i]);
    }

    int size = sizeof c1/sizeof c1[0];
    printf("\nlength of LCS: %d",size-1);

}   