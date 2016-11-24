#include <stdio.h>
#include <stdlib.h>

void partition(int [],int, int);
void mergesort(int [],int, int, int);
int main()
{
    int n,i,a[30];
    printf("Enter the number of elements of the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the element %d : ",(i+1));
        scanf("%d",&a[i]);
    }
    printf("\nElements are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n\nSorted list is:\n");
    partition(a,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

void partition(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        partition(a,low,mid);
        partition(a,mid+1,high);
        mergesort(a,low,mid,high);
    }
}

void mergesort(int a[],int low, int mid, int high)
{
    int k;
    int l=low;
    int i=low;
    int m=mid+1;
    int temp[high-low+1];
    while((l<=mid)&&(m<=high))
    {
        if(a[l]<=a[m])
        {
            temp[i]=a[l];
            l=l+1;
        }
        else
        {
            temp[i]=a[m];
            m=m+1;
        }
        i=i+1;
    }
    if(l>mid)
    {
        for(k=m;k<=high;k++)
        {
            temp[i]=a[k];
            i=i+1;
        }
    }
    else{
        for(k=l;k<=mid;k++)
        {
            temp[i]=a[k];
            i=i+1;
        }
    }
    for(k=low;k<=high;k++)
    {
        a[k]=temp[k];
    }
}
