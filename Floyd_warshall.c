#include <stdio.h>
#include <stdlib.h>
#define INFINITY 999
#define MAX 50

int minimum(int a,int b)
{
    if(a<=b)
    return a;
    else
    return b;
}

void display(int matrix[MAX][MAX],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n,i,j,k,path[MAX][MAX],adj[MAX][MAX];
    printf("Enter the vertices: ");
    scanf("%d",&n);
    printf("Enter the matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
        }
    }
    printf("The matrix is:\n");
    display(adj,n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(adj[i][j]==INFINITY)
            path[i][j]=7;
            else
            path[i][j]=adj[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                path[i][j]=minimum(path[i][j],path[i][k]+path[k][j]);
            }
        }
    }
    printf("Output:\n");
    display(path,n);
    return 0;
}

/*inputs::
Vertices=3
0 4 11
6 0 2
3 999 0
*/
