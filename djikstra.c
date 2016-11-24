#include <stdio.h>
#include <stdlib.h>
#define infinity 999

void dij(int n,int v,int cost[10][10],int dist[])
{
    int u,i,flag[20],min,count,w;
    for(i=1;i<=n;i++)
    {
        flag[i]=0;
        dist[i]=cost[v][i];
        count=2;
    }
    while(count<=n)
    {
        min=99;
        for(w=1;w<=n;w++)
        if(dist[w]<min && !flag[w])
        {
            min=dist[w];
            u=w;
            flag[u]=1;
            count++;
        }
        for(w=1;w<=n;w++)
        if(((dist[u]+cost[u][w])<dist[w]) && !flag[w])
        dist[w]=dist[u]+cost[u][w];
    }
}

int main()
{
    int v,n,i,j,cost[10][10],dist[10];
    printf("Enter the no. of nodes:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
        scanf("%d",&cost[i][j]);
        if(cost[i][j]==0)
        cost[i][j]=infinity;
    }
    printf("Enter the source vertex:");
    scanf("%d",&v);
    dij(n,v,cost,dist);
    for(i=1;i<=n;i++)
    if(i!=v)
    printf("%d->%d=%d\n",v,i,dist[i]);
    return 0;
}
/*Input::
No. of nodes=5
0 2 0 0 6
0 0 4 0 3
0 0 0 2 0
0 0 0 0 0
0 0 2 1 0
Source Vertex=1
Output::
1->2=2
1->3=6
1->4=6
1->5=5
*/
