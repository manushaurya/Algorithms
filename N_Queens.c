#include <stdio.h>
#include <stdlib.h>
int nqueens(int n)
{
    int count=0;
    int k=1,x[n];
    x[k]=0;
    while(k!=0)
    {
        x[k]+=1;
        while((x[k]<=n) && (!place(x,k)))
        {
            x[k]+=1;
        }
        if(x[k]<=n)
        {
            if(k==n)
            {
                count=count+1;
                printf("Count is %d\n",count);
                print_solution(n,x);
            }
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
        k--;
    }
}

int place(int x[],int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        if((x[i]==x[n]) || (i-x[i])==(n-x[n]) || (i+x[i])==(n+x[n]))
        return 0;
    }
    return 1;
}

int print_solution(int n,int x[])
{
    int i,j;
    char c[n][n];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            c[i][j]='*';
        }
    }
    for(i=1;i<=n;i++)
    {
        c[i][x[i]]='Q';
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("%c ",c[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the no. of queens: ");
    scanf("%d",&n);
    nqueens(n);
    return 0;
}
/*input
no. of queens=4*/
