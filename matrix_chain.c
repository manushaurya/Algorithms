#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int matrix_chain_order(int p[],int n)
{
    int i,j,l,m[10][10],q,k;
    for(i=1;i<=n;i++)
    {
        m[i][i]=0;
    }
    for(l=2;l<n;l++)
    {
        for(i=1;i<=((n-l)+1);i++)
        {
            j=(i+l)-1;
            m[i][j]=INT_MAX;
            for(k=i;k<=j-1;k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                }
            }
        }
    }
    return m[1][n-1];
}
int main()
{
    int arr[]={30,35,15,5,10,20,25},size,m;
    size=sizeof(arr)/sizeof(arr[0]);
    m=matrix_chain_order(arr,size);
    printf("The min number of mul is %d",m);
    return 0;
}
/*output=15125*/
