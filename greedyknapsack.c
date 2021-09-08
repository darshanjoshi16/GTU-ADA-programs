/*Practical Lab Assignment 4
Implementation of a knapsack problem using greedy algorithm */


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n;

// swap function using reference pointer passing
void swap(float *a,float *b)
{
    float temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

//function for printing the output with feasible solution and in asked format
void profit_print(float *ans,float *weight,float *value,float *o)
{
    printf("\n");
    int i,f;
    float profit=0,feasible[n];
    printf(" Item No. \t \t Weight. \t \t Value.");

    for(i=0;i<n;i++)
    {
        printf("\n");
        printf(" %f \t\t %f \t\t  %f ",o[i],ans[i]*weight[i],value[i]);
        printf("\n");

        profit += (ans[i]*value[i]);
    }

    printf("\n \t \t \t Your Profit is: %.2f \n",profit);

    for(i=0;i<n;i++)
    {
        f=o[i];
        f--;
        feasible[f]=ans[i];
    }

    printf("\n \t The feasible solution is: ");
    printf("(");

    for(i=0;i<n;i++)
    {
        printf("%.2f",feasible[i]);
        if(i != (n-1))
        {
            printf(",");
        }
    }

    printf(")");

}

//first approach of solving knapsack problem by greedy way: Taking large profitable object first
void large_profit_first(float *weight,float *value,float max_weight)
{
    int i,j;
    float ans[n],profit,o[n];
    
    for(i=0;i<n;i++)
    {
        o[i]=i+1;
    }
    //sorting the objects 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(value[i]>value[j])
            {
                swap(&value[i],&value[j]);
                swap(&weight[i],&weight[j]);
                swap(&o[i],&o[j]);
            }
        }
    }
    //checking if the object satisfies the criteria of largest profit first.if it satisfy,we take it in knapsack and deduct the weight of object from capacity.
    for(i=0;i<n;i++)
    {
        if((max_weight-weight[i])>=0)
        {
            ans[i]=1;
            max_weight-=weight[i];
        }
        else
        {
            ans[i]=((float)(max_weight)/weight[i]);
            max_weight=0;
        }
    }
    // calling function for printing output
    profit_print(ans,weight,value,o);
}

//Second Approach of solving problem greedy way: taking the least weight object so we can maximize the quantity    
void least_weight_first(float *weight,float *value,float max_weight)
{
    int i,j;
    float o[n];
    float ans[n],profit;
    
    for(i=0;i<n;i++)
    {
        o[i]=i+1;
    }
    
    //sorting of objects
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(weight[j]>weight[j+1])
            {
                swap(&value[j],&value[j+1]);
                swap(&weight[j],&weight[j+1]);
                swap(&o[j],&o[j+1]);
            }
        }
    }

    //checking if the object satisfies the least weight approach, if it satisfies, we do same process as above function's process.
    for(i=0;i<n;i++)
    {
        if((max_weight-weight[i])>=0)
        {
            ans[i]=1;
            max_weight-=weight[i];
        }
        else
        {
            ans[i]=((float)(max_weight)/weight[i]);
            max_weight=0;
            break;
        }
    }
    //calling the function for printing the output
    profit_print(ans,weight,value,o);
}

//third approach of solving knapsack problem using Greedy: Taking the objects according to their value/weight ratio
void large_profit_weight_ratio(float *weight,float *value,float max_weight)
{
    float rt[n],ans[n],profit,o[n];
    int i,j;
    
    for(i=0;i<n;i++)
    {
     o[i]=i+1;
    }
    
    for(i=0;i<n;i++)
    {
        rt[i]= (value[i]/weight[i]);
    }
    //sorting the objects
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rt[i]>rt[j])
            {
                swap(&rt[i],&rt[j]);
                swap(&value[i],&value[j]);
                swap(&weight[i],&weight[j]);
                swap(&o[i],&o[j]);
            }
        }
    }
    //checking if object satisfies the condition of largest value weight ratio, if satisfy we can repeat the process as per above functions.
    for(i=0;i<n;i++)
    {
        if((max_weight-weight[i])>=0)
        {
            ans[i]=1;
            max_weight-=weight[i];
        }
        else
        {
            ans[i] =((float)(max_weight)/(weight[i]));
            max_weight=0;
        }
    }
    
    profit_print(ans,weight,value,o);
}

int main()
{
    printf("================================================KNAPSACK USING GREEDY===========================================");
    printf("\n Enter the  total number of items to be entered: ");
    scanf("%d",&n);
    float weight[n],value[n];
    clock_t start_time,end_time;
    int c,i,max_weight;
    printf("\n================================================================================================================");

    for(i=0;i<n;i++)
    {
        printf("\n Item No: %d \n",(i+1));
        
        printf("\n Enter Weight:- ");
        scanf("%f",&weight[i]);
        
        printf("\n Enter Value:- ");
        scanf("%f",&value[i]);

        printf("\n ================================================================================================================"); 

    }

    printf("\n Enter the maximum amount of weight capacity:- ");
    scanf("%d",&max_weight);

    printf("\n ================================================================================================================");

    printf("\n 1.Largest Profit First\n 2.Least Weight First\n 3.Largest Profit to weight Ratio");
    printf("\n Enter the choice you want to perform : ");
    scanf("%d",&c);
   
    switch(c)
    {
        case 1:
        start_time=clock();
        large_profit_first(weight,value,max_weight);
        end_time = clock() - start_time;
        break;

        case 2:
        start_time=clock();
        least_weight_first(weight,value,max_weight);
        end_time = clock() - start_time;
        break;

        case 3:
        start_time=clock();
        large_profit_weight_ratio(weight,value,max_weight);
        end_time = clock() - start_time;
        break;

        default:
        printf("Invalid Choice,Please Enter the valid choice");
    }
    
    double time_taken=((double)end_time)/CLOCKS_PER_SEC;
    printf("\n====================================================");
    printf("\n Knapsack Problem using Greedy approach took %lf seconds to execute",time_taken);

    return 0;

}