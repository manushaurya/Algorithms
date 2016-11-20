#include <stdio.h>
#include <stdlib.h>

void job(int d[],int p[],int n)
{
    int i,j,m,k=n+1,t=0;
    for(i=1;i<=n;i++)
    {
        printf("i=%d\tp[%d]=%d\n",i,i,p[i]);
        if(t<p[i])
        {
            t=0;
        }
        t=p[i];
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(d[i]!=d[j]){
                m=p[i]+p[j];
                if(d[i]>d[j])
                {
                    printf("k=%d\ti=%d\tj=%d\ti=%d\tm=%d\n",k,i,j,j,i,m);
                }
            }
            else
            {
                printf("k=%d\ti=%d\tj=%d\ti=%d\tj=%d\tm=%d\n",k,i,j,i,j,m);
                k++;
            }
            if(m>t)
            t=m;
        }
    }
    printf("Max_Profit=%d",t);
}

int main()
{
    int n,i;
    printf("Enter the no. of jobs\n");
    scanf("%d",&n);
    int d[n],p[n];
    printf("Enter the deadline:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&d[i]);
    printf("Enter the profit:\n");
    for(i=1;i<=n;i++)
    scanf("%d",&p[i]);
    job(d,p,n);
}
