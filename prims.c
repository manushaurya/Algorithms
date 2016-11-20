#include <stdio.h>
int main()
{
    int n,i,j,ne=1,min,mincost=0,u,v,a,b;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    int cost[n][n],visited[10]={0};
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
       visited[1]=1;

    while(ne<n)
    {
        for(i=1,min=999;i<=n;i++)
        for(j=1;j<=n;j++)
                if(cost[i][j]<min)
                if(visited[i]!=0)
                    {
                        min=cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                if(visited[u]==0||visited[v]==0)
                {
                printf("ne=%d\ta=%d\tb=%d\tmin=%d\n",ne++,a,b,min);
                mincost+=min;
                visited[b]=1;
            }
            cost[a][b]=cost[b][a]=999;


    }
    printf("Min cost %d",mincost);

return 0;
}
