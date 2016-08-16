#include <stdio.h>
#include <stdlib.h>

void heapsort(int heap[],int n)
{
	int i,temp;
	heapify(heap,n);
	for(i=n;i>=1;i--)
	{
		temp=heap[1];
		heap[1]=heap[i];
		heap[i]=temp;
		reheapifydown(heap,1,i-1);
	}
}
void heapify(int heap[],int n)
{
	int i;
	int index=n/2;
	for(i=index;i>=1;i--)
	{
		reheapifydown(heap,i,n);
	}
}

void reheapifydown(int heap[],int start,int finish)
{
	int max,temp,index;
	int lchild=2*start;
	int rchild=lchild+1;
	if(lchild<=finish)
	{
		max=heap[lchild];
		index=lchild;
		if(rchild<=finish)
		{
			if(heap[rchild]>max)
			{
				max=heap[rchild];
				index=rchild;
			}
		}
		if(heap[start]<heap[index])
		{
			temp=heap[start];
			heap[start]=heap[index];
			heap[index]=temp;
			reheapifydown(heap,index,finish);
		}
	}
}

int main()
{
	int n,i;
	printf("Enter the no. of elements to be entered:\n");
	scanf("%d",&n);
	int a[n];
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Unsorted array is:\n");
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n\nSorted array is :\n");
	heapsort(a,n);
	for(i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
