#include <stdio.h>

int a[] = {9,8,7,6,5,4,3,2,1};
int size = (sizeof(a)/sizeof(int));

void printArray(int a[])
{
	int i = 0;
	for(;i<size;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int partition(int start, int end)
{
	int i=start;
	while(1)
	{
		while(a[++i] < a[start])
		{
			if(i == end)
				break;
		}
		while(a[start] < a[end])
			end--;
		if(i >= end)
			break;
		swap(&a[i],&a[end]);
	}
	if(start!=end)
		swap(&a[end],&a[start]);
	return end;
}

void recursiveQSort(int start, int end)
{
	if(start>=end)
		return;
	int pivot = partition(start,end);
	recursiveQSort(start,pivot-1);
	recursiveQSort(pivot+1,end);
}

int main()
{
	recursiveQSort(0,size-1);
	printArray(a);
	return 0;
}
