#include<stdio.h>

void printArray(int a[],int length)
{
	int i = 0;
	for(;i<length;i++)
		printf("%d ",a[i]);
	printf("\n");
}

void swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main()
{
	int a[] = {2,-2,3,-3,8,-8,7,9,-9,0,-7};
	int size = sizeof(a)/sizeof(int),i=0,j=0;
	for(;i<size;i++)
	{
		for(j=i;j>0;j--)
		{
			if(a[j] < a[j-1])
				swap(&a[j],&a[j-1]);
			else
				break;
		}
	}
	printArray(a,size);
	return 0;
}
