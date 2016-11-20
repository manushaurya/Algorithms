#include<stdio.h>
#include<conio.h>
int a[10][10],visited[10],n,cost=0;
void get(){
int i,j;
printf("enter the number of cities: ");
scanf("%d",&n);
printf("\nentr the cost matrix\n");
for(i=0;i<n;i++)
{

    printf("\nenter the element of row:%d\n",i+1);
    for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    visited[i]=0;
}
printf("\n\nthe cost list is\n\n");
for(i=0;i<n;i++){
    printf("\n\n");
    for(j=0;j<n;j++)
        printf("\t%d",a[i][j]);
}
}
void mincost(int city){
int i,ncity;
visited[city]=1;
printf("%d-->",city+1);
ncity=least(city);
if(ncity==999)
{

    ncity=0;
    printf("%d",ncity+1);
    cost+=a[city][ncity];
    return;
}
mincost(ncity);
}
int least(int c){
int i,nc=999;
int min=999,kmin;
for(i=0;i<n;i++)
{

    if((a[c][i]!=0)&&(visited[i]==0))
if(a[c][i]<min){
    min=a[i][0]+a[c][i];
    kmin=a[c][i];
    nc=i;
}
}
if(min!=999)
    cost+=kmin;
return nc;
}
void put(){
printf("\n\nminimum cost is\n\n");
printf("%d",cost);
}
void main(){
get();
printf("\n\n the path is::");
mincost(0);
put();
}
