#include <stdio.h>
#include <stdlib.h>

void knapsack(int n, double weight[],double profit[],int capacity)
{
    int i;
    double x[n],tp=0;
    int u=capacity;
    for(i=0;i<=n-1;i++)
        {
            x[i]=0;
        }
    for(i=0;i<=n-1;i++)
    {
        if(weight[i]>u)
        {break;}
        else
        {
            x[i]=1.0;
            tp=tp+profit[i];
            u=u-weight[i];
        }
    }
    if(i<n)
    {x[i]=u/weight[i];}
    tp=tp+(x[i]*profit[i]);
    printf("\n\n");
    for(i=0;i<=n-1;i++)
    printf("%.2lf",x[i]);
    printf("\n Maximum profit: %lf\n\n",tp);

}

int main()
{
    int n,capacity,i,j;
    printf("Enter the no. of objects:\n");
    scanf("%d",&n);
    double weight[n],profit[n],ratio[n];
    printf("Enter the weight and profit of each object:\n" );
    for(i=0;i<=n-1;i++)
    scanf("%lf%lf",&weight[i],&profit[i]);
    printf("Enter the capacity of knapsack:\n");
    scanf("%d",&capacity);
    for(i=0;i<=n-1;i++)
    ratio[i]=profit[i]/weight[i];
    for(i=0;i<=n-1;i++)
    {
        for(j=i+1;j<=n-1;j++)
        {
            if(ratio[i]<ratio[j])
            {
                double temp=ratio[j];
            ratio[j]=ratio[i];
            ratio[i]=temp;

            temp=weight[j];
            weight[j]=weight[i];
            weight[i]=temp;

            temp=profit[j];
            profit[j]=profit[i];
            profit[i]=temp;
            }

        }
    }
    knapsack(n,weight,profit,capacity);
    return 0;
}

/*Inputs:
 No. of object =3
 weight  profit
 18      25
 15      24
 10      15
 capacity=20
 */
 /*Output::
 Result vector:
 1.0 0.5 0.0
 profit=31.5*/
