#include <stdio.h>
#include <stdlib.h>

const int max=100;
int a[100][100],color[100],degree[100],NN[100],n,NNcount,unprocessed,i,j;

void getInput()
{
    printf("Rows/Columns: ");
    scanf("%d",&n);
    printf("Adjacency matrix: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
}

void init()
{
    for(i=0;i<n;i++)
    {
        color[i]=0;
        degree[i]=0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
            degree[i]++;
        }
    }
    NNcount=0;
    unprocessed=n;
}

int maxDegreeVertex()
{
    int max1=-1,max_i;
    for(i=0;i<n;i++)
    {
        if(!color[i])
        {
            if(degree[i]>max1)
            {
                max1=degree[i];
                max_i=i;
            }
        }
    }
    return max_i;
}

int maxDegreeInNN()
{
    int max=0,temp_y=0,temp;
    for(i=0;i<NNcount;i++)
    {
    temp=0;
    for(j=0;j<n;j++)
    {
        if(color[NN[j]]==0 && a[i][NN[j]]==1)
        temp++;
        if(temp>max)
        {
            max=temp;
            temp_y=NN[i];
        }
    }
    }
    return temp_y;
}

void updateNN(int color_number)
{
    NNcount=0;
    for(i=0;i<n;i++)
        if(!color[i])
        {
            NN[NNcount]=i;
            NNcount++;
        }

     for(i=0;i<n;i++)
            if(color[i]==color_number)
                for(j=0;j<NNcount;j++)
                    while(a[i][NN[j]]==1)
                    {
                        NN[j]=NN[NNcount-1];
                        NNcount--;
                    }
    }
/*inputs ::
rows/colms=7
adjacency matrix:
0 1 1 0 1 1 0
1 0 0 1 0 1 1
1 0 0 1 1 1 0
0 1 1 0 0 1 1
1 0 1 0 0 0 1
1 1 1 1 0 0 0
0 1 0 1 1 0 0
*/

void coloring()
{
    int color_number=0,x,y,verticesInCommon=0;
    while(unprocessed>0)
    {
        x=maxDegreeVertex();
        color_number++;
        color[x]=color_number;
        unprocessed--;
        updateNN(color_number);
        while(NNcount>0)
        {
            y=find(color_number,verticesInCommon);
            if(verticesInCommon==0)
            {
                y=maxDegreeInNN();
                color[y]=color_number;
                unprocessed--;
                updateNN(color_number);
            }
        }
    }
}

void scannedInit(int scanned[max])
{
    for(i=0;i<n;i++)
    {
        scanned[i]=0;
    }
}


int find(int color_number,int verticesCommon)
{
    verticesCommon=0;
    int temp_y,temp,x,k,y;
    int scanned[max];
    for(i=0;i<NNcount;i++)
    {
        temp_y=NN[i];
        temp=0;
        scannedInit(scanned);
        for(x=0;x<n;x++)
        {
            if(color[x]==color_number)
            {
                for(k=0;k<n;k++)
                {
                    if(color[k]==0 && scanned[k]==0)
                    {
                        if(a[x][k]==1 && a[temp_y][k]==1)
                        {
                            temp++;
                            scanned[k]=1;
                            if(temp>verticesCommon)
                            {
                                verticesCommon=temp;
                                y=temp_y;
                            }
                        }
                    }
                }
            }
        }
    }
    return y;
}

int main()
{
    getInput();
    init();
    coloring();
    for(i=0;i<n;i++)
        printf("%d %d\n",i+1,color[i]);
    return 0;
}
