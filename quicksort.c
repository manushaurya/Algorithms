#include <stdio.h>
#include <stdlib.h>

void quicksort(int [],int,int);
void quicksort(int a[],int first,int last)
{
    int pivot,i,j,temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while((a[i]<=a[pivot]) && i<last)
            i=i+1;
            while(a[j]>a[pivot])
            j=j-1;
            if(i<j)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        quicksort(a,first,j-1);
        quicksort(a,j+1,last);
    }
}

int main()
{
    int i,j;
    printf("Enter no. of elements to be entered: ");
    scanf("%d",&i);
    int a[i];
    for(j=0;j<i;j++)
    {
        scanf("%d",&a[j]);
    }
    printf("Entered elements of the array are:\n");
    for(j=0;j<i;j++)
    printf("%d ",a[j]);
    printf("\n\n");
    quicksort(a,0,i-1);
    printf("Sorted array is:\n");
    for(j=0;j<i;j++)
    printf("%d ",a[j]);
    return 0;
}
