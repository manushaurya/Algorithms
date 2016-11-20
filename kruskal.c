#include <stdio.h>
int main()
{
      int n,i,j,ne=1,min,mincost=0,u,v,a,b;
      printf("Enter the number of vertex:\n");
      scanf("%d",&n);
      int cost[10][10],parent[10]={0};
      for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
      {
          scanf("%d",&cost[i][j]);
          if(cost[i][j]==0)
            cost[i][j]=999;
      }
      while(ne<n)
      {
          for(i=1,min=999;i<=n;i++)
            {for(j=1;j<=n;j++)
          {
              if(cost[i][j]<min)
              {
                  min=cost[i][j];
                  a=u=i;
                  b=v=j;
              }
          }
            }
         while(parent[u]!=0)
            u=parent[u];
         while(parent[v]!=0)
            v=parent[v];
            if(u!=v)
            {
                ne++;
                printf("%d\t%d\t%d\n",a,b,min);
                mincost+=min;
                parent[v]=u;
            }
            cost[a][b]=cost[b][a]=999;

      }
      printf("Min cost=%d",mincost);
      return 0;

}
